#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <database.h>
#include <check.h>


void use_case_check_find(void)
{
    if (db_is_database_exists())
    {
        FILE *f = fopen(DB_DATABASE_FILE, "r");
        check_t check;

        if (f == NULL)
        {
            perror("Erro ao abrir o arquivo");
            return;
        }

        fseek(f, 0, SEEK_END);
        long file_size = ftell(f);
        if (file_size == 0)
        {
            fclose(f);
             perror("Erro ao abrir o arquivo");
            return;
        }
        rewind(f);

        char *buffer = (char *)calloc(1, file_size + 1); 
        char *last_line = NULL;

        while (fgets(buffer, file_size, f) != NULL)
        {
            if (last_line)
            {
                free(last_line); 
            }
            last_line = strdup(buffer); 
        }

        if (last_line)
        {

            decrypt(last_line, strlen(last_line), KEY); 
            check_parser(last_line, &check);  
            free(last_line);  

        }

        free(buffer);
        fclose(f);

        if (check.type_check == 1)
        {
            printf("***** ULTIMO PONTO *****\n******** CHECK IN *******\nNome do computador: %s  \nData: %s \nTimestamp: %d \nTipo: Check In\n", 
                    check.computer_name, check.date_time, check.timestamp);
        }
        else
        {
            printf("***** ULTIMO PONTO *****\n******** CHECK OUT ******\nNome do computador: %s  \nData: %s \nTimestamp: %d \nTipo: Check Out \nDescrição: %s\n", 
                    check.computer_name, check.date_time, check.timestamp, check.description);
        }
    }
}

