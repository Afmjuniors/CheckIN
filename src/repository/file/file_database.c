#include "file_database.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static bool file_is_database_exists(void);
static int file_count_items(void);
static bool file_store(void *object, store_action_t *store);
static bool file_store_list(void *object, const check_t *check_list, int items_amount);
static bool file_recover_list(void *object, check_t **check_list, int *items_amount);
static void check_parser(const char *buffer, check_t *check);

static bool file_insert(void *object, const check_t *check);

static bool file_insert(void *object, const check_t *check)
{
    FILE *f;
    if (file_is_database_exists() == false)
    {
        f = fopen(DB_DATABASE_FILE, "w");
    }
    else
    {
        f = fopen(DB_DATABASE_FILE, "a");
    }
    char format[200] = "";
    
    snprintf(format, 200, DB_DATABASE_FORMAT, check->id, check->date_time, check->timestamp, check->type ,check->description);
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
            case repo_delete:
            case repo_update:
        state = file_store_list(object, store->check, store->amount);
        break;
    
    
    
    default:
        break;
    }

    return state;

}
static bool file_store_list(void *object,  const check_t *check_list, int items_amount)
{
    FILE *f;

    f = fopen(DB_DATABASE_FILE, "w");
    for (int i = 0; i < items_amount; i++)
    {
        if (check_list[i].name[0] == '\0' || check_list[i].address[0] == '\0')
            continue;

        fprintf(f, DB_DATABASE_FORMAT, check_list[i].name, check_list[i].address, check_list[i].age);
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
        fgets(buffer, 240, f);

        check_parser(buffer, &_check_list[i]);
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
    if(f != NULL)
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

    if(file_is_database_exists())
    {
        f = fopen(DB_DATABASE_FILE, "r");
    }
    else 
        return -1;

    char c = fgetc(f);
    while(c != EOF)
    {
        if(c == '\n')
            items++;
        c = fgetc(f);
    }

    fclose(f);

    return items;
}

static void check_parser(const char *buffer, check_t *check)
{
    char *temp = (char *)buffer;
    if(check == NULL || buffer == NULL)
        return ;

    char *data = strtok(temp, ",");
    strncpy(check->name, data, check_NAME_LEN);
    data = strtok(NULL, ",");
    strncpy(check->address, data, check_ADDRESS_LEN);
    data = strtok(NULL, ",");
    check->age = atoi(data);
}

// void getComputerName(char *name, size_t len) {
//     FILE *fp = popen("hostname", "r");
//     if (fp == NULL) {
//         perror("Falha ao obter o nome do computador");
//         exit(1);
//     }
//     fgets(name, len, fp);
//     // Remove o \n do final da string
//     name[strcspn(name, "\n")] = 0;
//     pclose(fp);
// }
// void getCurrentTimestamp(char *timestamp, size_t len) {
//     time_t now = time(NULL);
//     strftime(timestamp, len, "%Y-%m-%d %H:%M:%S", localtime(&now));
// }
// int fileExists(const char *filename) {
//     FILE *file = fopen(filename, "r");
//     if (file) {
//         fclose(file);
//         return 1;
//     }
//     return 0;
// }

// void addEntry(const char *type, const char *comment) {
//     FILE *file = fopen(FILENAME, "a");
//     if (file == NULL) {
//         perror("Falha ao abrir o arquivo");
//         exit(1);
//     }

//     char computerName[256];
//     char timestamp[20];
//     getComputerName(computerName, sizeof(computerName));
//     getCurrentTimestamp(timestamp, sizeof(timestamp));

//     // Escreve no arquivo: ID do usuário (nome do PC), data, timestamp e tipo (check-in ou check-out)
//     fprintf(file, "%s,%s,%s,%s,%s\n", computerName, timestamp, timestamp, type, comment);

//     fclose(file);
// }

// void checkIn() {
//     char comment[256];
//     printf("Digite um comentário sobre o trabalho de hoje: ");
//     fgets(comment, sizeof(comment), stdin);
//     comment[strcspn(comment, "\n")] = 0;

//     addEntry("check-in", comment);
//     printf("Check-in realizado com sucesso!\n");
// }

// // Função para processar check-out
// void checkOut() {
//     char comment[256];
//     printf("Digite um comentário final sobre o trabalho de hoje: ");
//     fgets(comment, sizeof(comment), stdin);
//     comment[strcspn(comment, "\n")] = 0;

//     addEntry("check-out", comment);
//     printf("Check-out realizado com sucesso!\n");
// }