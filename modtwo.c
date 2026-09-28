#include "options.h"
#include "general.h"
#include "modthree.h"
#include <stdio.h>

void cipher(char *buffer, int size, short isCaesar);

int encryption_menu(char *buffer, int size)
{
    int local_choice = menu(options_module_2, 3, "Cifragem e Decifragem");
    printf("Você escolheu %s\n", options_module_2[local_choice - 1]);
    switch(local_choice)
    {
        case 1:
            printf("CIFRA DE CESAR\n");
            cipher(buffer, size, 1);
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                printf("%c", buffer[i]);
            }
            add_log("Caesar's Cipher");
            break;
        
        case 2:
            printf("CIFRA XOR\n");
            cipher(buffer, size, 0);
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                printf("%02x", buffer[i]);
            }
            add_log("Stream Cipher");
            break;
    }
    printf("\n");
    printf("Pressione enter...");
    getchar();
    return local_choice;
}

char caesar(char letter, int shift, short mode)
{
    if (mode) shift *= -1; 
    if (letter >= 65 && letter <= 90)
        return (letter - 'A' + shift + 26) % 26 + 'A';
    else if (letter >= 97 && letter <= 122)
        return (letter - 'a' + shift + 26) % 26 + 'a';
}

char stream(char letter, char key)
{
    return letter ^ key;
}

void cipher(char *buffer, int size, short isCaesar)
{
    char options[][50] = {"Cifrar", "Decifrar"};
    int shift;
    char key;
    int mode;

    if (isCaesar)
    {
        mode = menu(options, 2, "CIFRAGEM E DECIFRAGEM") - 1;
        printf("Você escolheu %s!\n", options[mode]);
    }    
    
    if (isCaesar) {
        printf("Informe o deslocamento: ");
        scanf("%i", &shift);
    } else {
        printf("Informe uma chave [1 char]: ");
        scanf("%c", &key);
    }
    getchar();
    sgets(buffer, size, "Informe um texto: ");

    if (isCaesar)
    { 
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            buffer[i] = caesar(buffer[i], shift, mode);
        }
    } else {
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            buffer[i] = stream(buffer[i], key);
        }
    }
}