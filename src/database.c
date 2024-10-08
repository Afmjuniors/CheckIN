#include <database.h>
#include <stdio.h>

bool db_is_database_exists(void)
{
    bool status = false;

    FILE *f = fopen(DB_DATABASE_FILE, "r");
    if(f != NULL)
    {
        fclose(f);
        status = true;
    }

    return status;
}

void encrypt(char *data, size_t data_len, int key) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] += key;  
    }
}

void decrypt(char *data, size_t data_len, int key) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] -= key; 
    }
}

int db_count_items(void)
{
    FILE *f;
    int items = 0;

    if(db_is_database_exists())
    {
        f = fopen(DB_DATABASE_FILE, "r");
    }
    else 
        return -1;

    char c = fgetc(f);
    while(c != EOF)
    {
        if(c == '\n')
            items++;
        c = fgetc(f);
    }

    fclose(f);

    return items;
}