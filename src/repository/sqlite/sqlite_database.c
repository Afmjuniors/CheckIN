#include <sqlite_database.h>
#include <stdlib.h>

static bool sqlite_store(repository_base *repository,  store_action_t *action);
static bool sqlite_recover_list(repository_base *repository, const person_t **person_list, int *items_amount);

repository_base *sqlite_create_database(void){
    repository_base *repository = (repository_base *)malloc(sizeof(repository_base));
    if (repository)
    {
        repository->object = NULL;
        repository->store = sqlite_store;
        repository->recover_list = sqlite_recover_list;
    }
    return repository;
}

static bool sqlite_store(repository_base *repository,  store_action_t *action){
    return false;
}
static bool sqlite_recover_list(repository_base *repository, const person_t **person_list, int *items_amount){
    return false;

}