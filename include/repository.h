#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <person.h>
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
    person_t *person;
    int id;
    int amount;

} store_action_t;

typedef struct
{
    void *object;
    bool (*store)(void *object,  store_action_t *action);
    bool (*recover_list)(void *object, person_t **person_list, int *items_amount);
} repository_base;

bool person_store(repository_base *repository,  store_action_t *action);
// bool person_store_list(repository_base *repository, const person_t *person_list, int items_amount);
bool person_recover_list(repository_base *repository, const person_t **person_list, int *items_amount);

#endif // !REPOSITORY_H