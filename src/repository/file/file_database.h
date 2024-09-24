#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include <repository.h>
#include <stdbool.h>

#define DB_DATABASE_FORMAT     "%s; %ld; %s; %s; %s;\n"
#define DB_DATABASE_FILE       "database.txt"

repository_base *file_create_database(void);
bool file_is_database_exists(void);

#endif /* FILE_DATABASE_H */
