#include "file_database.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool file_is_database_exists(void);
static int file_count_items(void);
static bool file_store(void *object, store_action_t *store);
static bool file_store_list(void *object, const check_t *check_list, int items_amount);
static bool file_recover_list(void *object, check_t **check_list, int *items_amount);
static void check_parser(const char *buffer, check_t *check);

static bool file_insert(void *object, const check_t *check);

static bool file_insert(void *object, const check_t *check)
{
    FILE *f;
    if (!file_is_database_exists())
    {
        f = fopen(DB_DATABASE_FILE, "w");
    }
    else
    {
        f = fopen(DB_DATABASE_FILE, "a");
    }

    const char *type_str = (check->type == check_in) ? "check_in" : "check_out";
    char format[200] = "";
    
    snprintf(format, 200, DB_DATABASE_FORMAT, check->computer_name, check->timestamp, check->date_time, type_str, check->description);
    fprintf(f, "%s", format);
    fclose(f);

    return true;
}

static bool file_store(void *object, store_action_t *store)
{
    bool state = false;

    switch (store->action)
    {
    case repo_insert:
        state = file_insert(object, store->check);
        break;
    case repo_update:
        state = file_store_list(object, store->check, store->amount);
        break;
    default:
        break;
    }

    return state;
}

static bool file_store_list(void *object, const check_t *check_list, int items_amount)
{
    FILE *f = fopen(DB_DATABASE_FILE, "w");
    for (int i = 0; i < items_amount; i++)
    {
        if (check_list[i].computer_name[0] == '\0' || check_list[i].date_time[0] == '\0')
            continue;

        const char *type_str = (check_list[i].type == check_in) ? "check_in" : "check_out";
        fprintf(f, DB_DATABASE_FORMAT, check_list[i].computer_name, check_list[i].timestamp, check_list[i].date_time, type_str, check_list[i].description);
    }
    fclose(f);
    return true;
}

static bool file_recover_list(void *object, check_t **check_list, int *items_amount)
{
    int items = file_count_items();
    *items_amount = items;

    check_t *_check_list = (check_t *)malloc(sizeof(check_t) * items);
    if (_check_list == NULL)
        return false;

    FILE *f = fopen(DB_DATABASE_FILE, "r");

    for (int i = 0; i < items; i++)
    {
        char buffer[240] = "";
        if (fgets(buffer, 240, f) != NULL)
        {
            check_parser(buffer, &_check_list[i]);
        }
    }

    *check_list = _check_list;
    fclose(f);

    return true;
}

repository_base *file_create_database(void)
{
    repository_base *repository = (repository_base *)malloc(sizeof(repository_base));
    if (repository)
    {
        repository->object = NULL;
        repository->store = file_store;
        repository->recover_list = file_recover_list;
    }
    return repository;
}

bool file_is_database_exists(void)
{
    bool status = false;
    FILE *f = fopen(DB_DATABASE_FILE, "r");
    if (f != NULL)
    {
        fclose(f);
        status = true;
    }
    return status;
}

int file_count_items(void)
{
    FILE *f;
    int items = 0;

    if (file_is_database_exists())
    {
        f = fopen(DB_DATABASE_FILE, "r");
    }
    else
    {
        return -1;
    }

    char c = fgetc(f);
    while (c != EOF)
    {
        if (c == '\n')
            items++;
        c = fgetc(f);
    }

    fclose(f);
    return items;
}

static void check_parser(const char *buffer, check_t *check)
{
    char *temp = (char *)buffer;
    if (check == NULL || buffer == NULL)
        return;

    char *data = strtok(temp, ";");
    strncpy(check->computer_name, data, CHECK_COMPUTER_NAME_LEN);
    data = strtok(NULL, ";");
    strncpy(check->date_time, data, CHECK_DATETIME_LEN);
    data = strtok(NULL, ";");
    check->timestamp = atol(data);
    data = strtok(NULL, ";");
    if (strcmp(data, "check_in") == 0)
        check->type = check_in;
    else
        check->type = check_out;
    data = strtok(NULL, ";");
    strncpy(check->description, data, CHECK_DESCRIPTION_LEN);
}
