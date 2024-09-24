#include <menu.h>
#include <stdio.h>
#include <use_cases.h>

static menu_options_struct_t options[] = 
    {
        {.option = menu_option_add,    .command = use_case_check_in_new},
        {.option = menu_option_find,   .command = use_case_check_find},
        {.option = menu_option_quit,   .command = use_case_check_quit}
    };

void menu_print(void)
{
    printf("%s\n", MENU_TEXT_ADD);
    printf("%s\n", MENU_TEXT_FIND);
    printf("%s\n", MENU_TEXT_EXIT);
    printf("%s",   MENU_TEXT_CURSOR);    
}

bool menu_option_select(int option)
{
    bool status = true;

    int list_size = sizeof(options) / sizeof(options[0]);

    for (int i = 0; i < list_size; i++)
    {
        if(option == options[i].option)
        {
            options[i].command();
            break;
        }
    }

    return status;
}