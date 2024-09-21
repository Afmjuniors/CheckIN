#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include <repository.h>

#define DB_DATABASE_FORMAT     "%s, %s, %d\n"
#define DB_DATABASE_FILE       "database.txt"

repository_base *file_crerare_database(void);

#endif /* FILE_DATABASE_H */