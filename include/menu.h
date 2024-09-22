#ifndef MENU_H
#define MENU_H

#include <stdbool.h>
#include <repository.h>

#define MENU_INITAL_MESSAGE_NO_ENTRY "Bem vindo ao sistema de pontos da Techdriven Digital!\nSelecione um opção para fazer a entrada no seu dia."
#define MENU_INITAL_MESSAGE_WITH_ENTRY "Estou vendo aqui que você ja fez sua checagem de entrada!\n Selecione um opção para fazer a saida de seu dia."
#define MENU_MESSAGE_DESCRIPTION "Agora que você ja acabou o seu dia, me informe sobre o que você trabalhou, Nome do projeto e a descrição de suas ações."
#define MENU_TEXT_CHECK_IN "1. Fazer entrada automatica"
#define MENU_TEXT_CHECK_IN_MANUAL "2. Colocar a hora de entrada"
#define MENU_TEXT_CHECK_OUT "1. Sair com a data automatica"
#define MENU_TEXT_CHECK_OUT_MANUAL "2. Colocar a hora de saida"
#define MENU_TEXT_LIST_CHECKS "3. Mostrar ultimas entradas"
#define MENU_TEXT_EXIT "6. exit program"
#define MENU_TEXT_CURSOR "> "

typedef enum
{
    menu_option_check_in = 1,
    menu_option_check_in_m,
    menu_option_check_out,
    menu_option_check_out_m,
    menu_option_list_checks,
    menu_option_quit
} menu_option_t;

typedef void (*menu_option_base)(repository_base *repository);

typedef struct
{
    menu_option_t option;
    menu_option_base command;
} menu_options_struct_t;

bool menu_option_select(int option, repository_base *repository);
void menu_print_in(void);
void menu_print_out(void);

#endif /* MENU_H */