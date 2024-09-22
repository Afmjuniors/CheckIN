#include <menu.h>
#include <stdio.h>
#include <use_cases.h>

static menu_options_struct_t options_out[] = 
    {
        {.option = menu_option_check_out, .command = use_case_person_update},
        {.option = menu_option_check_out_m,   .command = use_case_person_list},
        {.option = menu_option_list_checks,   .command = use_case_person_find},
        {.option = menu_option_quit,   .command = use_case_person_quit}
    };


    static menu_options_struct_t options_in[] = 
    {
        {.option = menu_option_check_in,    .command = use_case_person_add_new},
        {.option = menu_option_check_in_m, .command = use_case_person_delete},
        {.option = menu_option_list_checks,   .command = use_case_person_find},
        {.option = menu_option_quit,   .command = use_case_person_quit}
    };

void menu_print_in(void)
{
    printf("%s\n", MENU_TEXT_CHECK_IN);
    printf("%s\n", MENU_TEXT_CHECK_OUT_MANUAL);
    printf("%s\n", MENU_TEXT_LIST_CHECKS);
    printf("%s\n", MENU_TEXT_EXIT);
    printf("%s",   MENU_TEXT_CURSOR);    
}

void menu_print_out(void)
{
    printf("%s\n", MENU_TEXT_CHECK_OUT);
    printf("%s\n", MENU_TEXT_CHECK_OUT_MANUAL);
    printf("%s\n", MENU_TEXT_LIST_CHECKS);
    printf("%s\n", MENU_TEXT_EXIT);
    printf("%s",   MENU_TEXT_CURSOR);    
}



bool menu_option_select(int option, repository_base *repository)
{
    bool status = true;

    int list_size = sizeof(options_in) / sizeof(options_in[0]);

    for (int i = 0; i < list_size; i++)
    {
        if(option == options_in[i].option)
        {
            options_in[i].command(repository);
            break;
        }
    }

    return status;
}