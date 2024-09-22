#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <check.h>
#include <stdbool.h>

typedef enum
{
    repo_insert,
    repo_update,
    repo_delete

} repo_action_t;

typedef struct
{
    repo_action_t action;
    check_t *check;
    int id;
    int amount;

} store_action_t;

typedef struct
{
    void *object;
    bool (*store)(void *object,  store_action_t *action);
    bool (*recover_list)(void *object, check_t **check_list, int *items_amount);
} repository_base;

bool check_store(repository_base *repository,  store_action_t *action);
bool check_recover_list(repository_base *repository, const check_t **check_list, int *items_amount);

#endif // !REPOSITORY_H