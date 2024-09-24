#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include <use_cases.h>

check_t use_case_last_type(repository_base *repository)
{
    check_t *check_list = NULL;
    int items = 0;

    repository->recover_list(repository->object, &check_list, &items);

    if (items > 0)
    {
        check_t last_check = check_list[items - 1];
        free(check_list);
        return last_check;
    }
    else
    {
        // Retorna um "check_t" vazio caso não haja registros
        check_t empty_check = {0};
        return empty_check;
    }
}
