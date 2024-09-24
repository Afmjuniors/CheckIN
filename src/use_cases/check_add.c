#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <database.h>
#include <check.h>


int last_check_type();

void use_case_check_in_new(void)
{
    check_t check;
    int last_type = last_check_type();
    int new_type = 1;
    if (last_type == 1)
    {
        new_type = 2;
    }

    FILE *f;
    check = check_create(new_type);

    if (db_is_database_exists() == false)
    {
        f = fopen(DB_DATABASE_FILE, "w");
    }
    else
    {
        f = fopen(DB_DATABASE_FILE, "a");
    }

    char format[250] = "";
    if (new_type == 1)
    {
        snprintf(format, 250, DB_DATABASE_FORMAT, check.computer_name, check.date_time, check.timestamp, check.type_check, " - ");
    }
    else
    {
        snprintf(format, 250, DB_DATABASE_FORMAT, check.computer_name, check.date_time, check.timestamp, check.type_check, check.description);
    }

    // Criptografar o conteúdo antes de salvar
    encrypt(format, strlen(format), KEY); // Aplicando XOR com chave simples (0xAA)

    fprintf(f, "%s\n", format); // Salva o conteúdo criptografado com '\n' no final
    fclose(f);
}

int last_check_type()
{
    check_t check;

    if (db_is_database_exists())
    {
        FILE *f = fopen(DB_DATABASE_FILE, "r");

        if (f == NULL)
        {
            perror("Erro ao abrir o arquivo");
            return 0; // Retorna check vazio em caso de erro
        }

        fseek(f, 0, SEEK_END);     // Move o ponteiro do arquivo para o final
        long file_size = ftell(f); // Obtém o tamanho do arquivo
        if (file_size == 0)
        {
            // Se o arquivo está vazio, retorne um check vazio
            fclose(f);
            return 0;
        }

        rewind(f); // Volta o ponteiro para o início do arquivo

        char *buffer = (char *)calloc(1, file_size + 1); // Aloca o buffer dinamicamente baseado no tamanho do arquivo
        char *last_line = NULL;
        char *current_line = NULL;

        while (fgets(buffer, file_size, f) != NULL)
        {
            if (last_line)
            {
                free(last_line); // Libera a linha anterior
            }
            last_line = strdup(buffer); // Copia a linha atual para `last_line`
        }

        if (last_line)
        {
            decrypt(last_line, strlen(last_line), KEY);
            check_parser(last_line, &check);
            free(last_line);
        }

        free(buffer); // Libera o buffer dinâmico
        fclose(f);
    }

    return check.type_check;
}