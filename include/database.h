#ifndef DATABASE_H
#define DATABASE_H
#include <stdbool.h>

#define DB_DATABASE_FORMAT     "%s, %s, %d, %d, %s"
#define DB_DATABASE_FILE       "database.txt"
#define KEY 12  // Uma chave simples para o XOR


bool db_is_database_exists(void);
int db_count_items(void);
void encrypt(char *data, size_t data_len, int key);
void decrypt(char *data, size_t data_len, int key);

#endif /* DATABASE_H */