#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

#define MENU_TEXT_ADD     "1. Registrar novo ponto"
#define MENU_TEXT_FIND    "2. Mostrar ultimo registro"
#define MENU_TEXT_EXIT           "3. Sair do programa"
#define MENU_TEXT_CURSOR         "> "

typedef enum 
{
    menu_option_add = 1,
    menu_option_find,
    menu_option_quit
} menu_option_t;

typedef void (*menu_option_base)(void);

typedef struct 
{
    menu_option_t option;
    menu_option_base command;
} menu_options_struct_t;

bool menu_option_select(int option);
void menu_print(void);
#endif /* MENU_H */