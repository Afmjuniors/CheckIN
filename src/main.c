#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <menu.h>
#include <repository_factory.h>
#include "file_database.h"

// Função para converter o tipo de check em string
const char* get_check_type_string(type_check_t type) {
    return (type == check_in) ? "Check-in" : "Check-out";
}

check_t use_case_last_type_main(repository_base *repository);

int main(void)
{
    int option;
    repository_base *repository = repository_create("file");

    if (repository == NULL) {
        return EXIT_FAILURE;
    }

    while (true) {
        bool type = false;

        // Verifica se o arquivo de banco de dados existe
        if (file_is_database_exists()) {
            check_t last_check = use_case_last_type_main(repository);

            // Verifica se o último check é válido (se não for vazio)
            if (last_check.type != 0) {
                // Imprime informações sobre o último check
                printf("\n Tipo: %s, Data/Hora: %s, Computador: %s \n",
                    get_check_type_string(last_check.type),
                    last_check.date_time,
                    last_check.computer_name);

                // Imprime o menu com base no tipo do último check
                if (last_check.type != check_in) {
                    printf("Último check foi de entrada. Mostrando menu de saída...\n");
                    menu_print_out();
                    type = false;
                } else {
                    printf("Último check foi de saída. Mostrando menu de entrada...\n");
                    menu_print_in();
                    type = true;
                }
            } else {
                printf("Nenhum check encontrado no banco de dados.\n");
                type = true;
                menu_print_in(); // Exibe menu de entrada se não houver último check
            }
        } else {
            printf("Banco de dados não encontrado. Exibindo menu de entrada...\n");
            type = true;
            menu_print_in();
        }

        // Verifica a entrada do usuário
        if (scanf("%d", &option) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            continue; // Volta para o início do loop
        }

        // Executa a opção selecionada
        menu_option_select(option, repository, type);
    }

    free(repository);
    
    return EXIT_SUCCESS;
}

// Função para recuperar o último check
check_t use_case_last_type_main(repository_base *repository)
{
    check_t *check_list = NULL;
    int items = 0;

    repository->recover_list(repository->object, &check_list, &items);

    if (items > 0) {
        check_t last_check = check_list[items - 1]; // Pega o último item da lista
        free(check_list); // Libera a memória alocada para a lista
        return last_check;
    } else {
        // Retorna um "check_t" vazio caso não haja registros
        check_t empty_check = {0};  // Inicializa todas as variáveis com zero/NULL
        return empty_check;
    }
}


void menu_print_in(void)
{
    
    printf("%s\n", MENU_TEXT_CHECK_IN);
    printf("%s\n", MENU_TEXT_CHECK_IN_MANUAL);
    printf("%s\n", MENU_TEXT_LIST_CHECKS);
    printf("%s\n", MENU_TEXT_EXIT);
    printf("%s",   MENU_TEXT_CURSOR);    
}

void menu_print_out(void)
{
    printf("%s\n", MENU_TEXT_CHECK_OUT);
    printf("%s\n", MENU_TEXT_CHECK_OUT_MANUAL);
    printf("%s\n", MENU_TEXT_LIST_CHECKS);
    printf("%s\n", MENU_TEXT_EXIT);
    printf("%s",   MENU_TEXT_CURSOR);    
}

