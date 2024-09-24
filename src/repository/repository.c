#include <repository.h>
#include <stdlib.h>

bool check_store(repository_base *repository, store_action_t *action)
{
    if (repository == NULL || repository->store == NULL)
        return false;

    return repository->store(repository->object, action);
}

bool check_recover_list(repository_base *repository, check_t **check_list, int *items_amount)
{
    if (repository == NULL || repository->recover_list == NULL)
        return false;

    return repository->recover_list(repository->object, check_list, items_amount);
}
