#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include <use_cases.h>

void use_case_check_in(repository_base *repository)
{
            printf("entrou aki1");

    store_action_t store;
    check_t check = check_create(check_in);

    store.action = repo_insert;
    store.id = -1;
    store.amount = 1;
    store.check = &check;

    repository->store(repository->object, &store);
}

void use_case_check_in_m(repository_base *repository)
{
            printf("entrou aki1");

    store_action_t store;
    check_t check = check_create_m(check_in);

    store.action = repo_insert;
    store.id = -1;
    store.amount = 1;
    store.check = &check;

    repository->store(repository->object, &store);
}
