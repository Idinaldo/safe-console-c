#include <string.h>
#include "general.h"
#include <stdio.h>

int menu(char (*options)[50], int size, char *title)
{
    printf("\033[2J\033[H");
    int padding = (40 - strlen(title)) / 2;

    printf("========================================\n");
    printf("%*s%s\n", padding, "", title);
    printf("========================================\n");

    int option;
    for (int i = 0; i < size; i++)
    {
        printf("%i - %s\n", i + 1, options[i]);
    }

    do {
        printf("Digite sua escolha: ");
        scanf("%i", &option);
        getchar();
    } while (option < 1 || option > size);

    return option;
}

void sgets(char *buffer, int size, char *input_message)
{
    getchar();
    printf("%s", input_message);
    
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}