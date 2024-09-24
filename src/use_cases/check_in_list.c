#include <stdio.h>
#include <use_cases.h>
#include <stdlib.h>




void use_case_check_list(repository_base *repository)
{
    check_t *check_list;
    int items;
    repository->recover_list(repository->object, &check_list, &items);

    for (int i = 0; i < items; i++)
    {
        const char *type_str = check_list[i].type == check_in ? "Check-in" : "Check-out";

        if (check_list[i].type == check_in)
        {
            printf("Found: %s %s\n", type_str, check_list[i].date_time);
        }
        else
        {
            printf("Found: %s %s %s\n", type_str, check_list[i].date_time, check_list[i].description);
        }
    }
    free(check_list);
}
