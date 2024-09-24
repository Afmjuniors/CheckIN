#include <repository_factory.h>
#include <stdlib.h>
#include <string.h>
#include <file_database.h>

typedef struct{
    const char *name;
    repository_base *(*database_create)(void);

} database_t;

database_t databases[] = {
{.name = "file", .database_create= file_create_database}

};
const unsigned int database_amount = sizeof(databases) / sizeof(databases[0]);

repository_base *repository_create(const char *type){
    repository_base *repository = NULL;

for (int i = 0; i < database_amount; i++)
{
        if(strncmp(databases[i].name, type, strlen(databases[i].name))== 0){

        repository = databases[i].database_create();
        break;

    }
}

    return repository;
}
