#include <stdio.h>
#include "general.h"
#include "options.h"
#include <string.h>

void add_log(char *log);
int buscar_logs();
void ler_logs();

int history_menu()
{
    int local_choice = menu(options_module_3, 3, "Logs e Auditoria");
    printf("Você escolheu %s\n", options_module_3[local_choice - 1]);
    switch (local_choice)
    {
        case 1:
            ler_logs();
            add_log("Logs Reading");
            break;
        case 2:
            if (buscar_logs()) {
                printf("Termo encontrado!\n");
            } else {
                printf("Termo não encontrado!\n");
            }
            add_log("Logs Searching");
            break;
    }
    printf("Pressione enter...");
    getchar();
    return local_choice;
}

void ler_logs()
{
    if (!last_history_pos)
    {
        printf("Não há logs para exibição.");
    } else {
        for (int i = 1; i < last_history_pos; i++)
        {
            printf("%i - %s\n", i, history[i]);
        }
    }
}

int buscar_logs()
{
    char log[100];
    sgets(log, 100, "Informe o termo que deseja procurar nos logs: ");
    for (int i = 0; i < last_history_pos; i++)
    {
        if (strcmp(history[i], log))
        {
            return 1;
        }
    }
    return 0;
}

void add_log(char *log)
{
    strcpy(history[last_history_pos + 1], log);
    last_history_pos++;
}