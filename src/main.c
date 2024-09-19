#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TEXT_ADD_PERSON "1. Add a new person"
#define TEXT_REMOVE_PERSON "2. Remove a person"
#define TEXT_UPDATE_PERSON "3. Update a person"
#define TEXT_LIST_PERSON "4. List all persons"
#define TEXT_FIND_PERSON "5. Find a person"
#define TEXT_EXIT "6. exit program"
#define TEXT_CURSOR "> "

void print_menu(void);
bool option_select(int option);

void person_add_new(void);
void person_delete(void);
void person_update(void);
void person_list(void);
void person_find(void);

int main(void)
{
    int option;
    do
    {
        print_menu();
        scanf("%d", &option);
        getchar();

    } while (option_select(option));

    return EXIT_SUCCESS;
}

void print_menu(void)
{
    printf("%s\n", TEXT_ADD_PERSON);
    printf("%s\n", TEXT_REMOVE_PERSON);
    printf("%s\n", TEXT_UPDATE_PERSON);
    printf("%s\n", TEXT_LIST_PERSON);
    printf("%s\n", TEXT_FIND_PERSON);
    printf("%s\n", TEXT_EXIT);
    printf("%s", TEXT_CURSOR);
}

bool option_select(int option)
{
    bool status = true;
    switch (option)
    {
    case 1:
        person_add_new();
        break;
    case 2:
        person_delete();
        break;
    case 3:
        person_update();
        break;
    case 4:
        person_list();
        break;
    case 5:
        person_find();
        break;
    case 6:
        status = false;
        break;
    default:
        break;
    }

    return status;
}

void person_add_new(void)
{
    printf("Add a new User\n");
}
void person_delete(void)
{
    printf("Remove a User\n");
}
void person_update(void)
{
    printf("Update a User\n");
}
void person_list(void)
{
    printf("List all Users\n");
}
void person_find(void)
{
    printf("Find a User\n");
}