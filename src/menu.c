#include <menu.h>
#include <stdio.h>
#include <use_cases.h>

static menu_options_struct_t options_out[] = 
    {
        {.option = menu_option_check_out, .command = menu_option_check_out},
        {.option = menu_option_check_out_m,   .command = menu_option_check_out_m},
        {.option = menu_option_list_checks,   .command = use_case_check_list},
        {.option = menu_option_quit,   .command = use_case_check_quit}
    };


    static menu_options_struct_t options_in[] = 
    {
        
        {.option = menu_option_check_in,    .command = use_case_check_in},
        {.option = menu_option_check_in_m, .command = use_case_check_in_m},
        {.option = menu_option_list_checks,   .command = use_case_check_list},
        {.option = menu_option_quit,   .command = use_case_check_quit}
    };



bool menu_option_select(int option, repository_base *repository, bool is_in)
{
    bool status = true;
    
    menu_options_struct_t options[4];

    if (is_in)
    {
        memcpy(options, options_in, sizeof(options));
    }
    else
    {
        memcpy(options, options_out, sizeof(options));
    }

    int list_size = sizeof(options) / sizeof(options[0]);

    for (int i = 0; i < list_size; i++)
    {
        if (option == options[i].option)
        {
            options[i].command(repository);
            break;
        }
    }

    return status;
}