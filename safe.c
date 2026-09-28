#include <stdio.h>
#include "modone.h"
#include "general.h"
#include "options.h"
#include "modtwo.h"
#include <string.h>

#define BUFFER_SIZE 100

int main(void)
{
    char buffer[BUFFER_SIZE];

    int choice;
    int local_choice;
    do {
        choice = menu(options, 4, "MENU PRINCIPAL");
        
        switch (choice)
        {
            case 1:
                do {
                    local_choice = sanitization_menu(buffer, BUFFER_SIZE);
                } while (local_choice != 4);
                break;

            case 2:
                do {
                    local_choice = encryption_menu(buffer, BUFFER_SIZE);
                } while (local_choice != 3);
                break;

            case 3:
                do {
                    local_choice = menu(options_module_3, 4, "Logs e Auditoria");
                    printf("Você escolheu %s\n", options_module_1[local_choice - 1]);
                } while (local_choice != 4);
                break;

            case 4:
                printf("Obrigado por utilizar o Safe Console!\n");
                printf("by @Idinaldo\n");
                break;            
     }

    } while (choice != 4);

    return 0;
}