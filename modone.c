#include "modone.h"
#include "modthree.h"
#include "general.h"
#include "options.h"
#include <stdio.h>
#include <string.h>

void data_masking(char *data, int size)
{
    size -= 4;
    for (int i = 0; i < size; i++)
    {
        data[i] = '*'; 
    }
}

int validate_password(char *password, int size)
{
    int hasLowerCase = 0, hasUpperCase = 0, hasNumbers = 0;

    if (size < 8)
    {
        return 1;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (password[i] >= 65 && password[i] <= 90)
        {
            hasUpperCase = 1;
        }
        else if (password[i] >= 97 && password[i] <= 122)
        {
            hasLowerCase = 1;
        }
        else if (password[i] >= 48 && password[i] <= 57)
        {
            hasNumbers = 1;
        }
    }
    
    if (!hasLowerCase)
    {
        return 2;
    } else if (!hasUpperCase)
    {
        return 3;
    } else if (!hasNumbers)
    {
        return 4;
    } else
    {
        return 0;
    }
}

int sanitization_menu(char *buffer, int BUFFER_SIZE)
{
    int local_choice = menu(options_module_1, 4, "Sanitização e Validação");
    printf("Você escolheu %s\n", options_module_1[local_choice - 1]);
    
    switch(local_choice)
    {
        case 1:
            sgets(buffer, BUFFER_SIZE, "Digite seu texto: ");
            printf("Seu texto seguro e tratado é: %s\n", buffer);
            add_log("Safe Read Text");
            break;
        case 2:
            sgets(buffer, BUFFER_SIZE, "Digite seu dado: ");
            data_masking(buffer, strlen(buffer));
            printf("Seu dado mascarado é: %s\n", buffer);    
            add_log("Masked Data");
            break;
        case 3:
            sgets(buffer, BUFFER_SIZE, "Digite uma senha: ");
            switch(validate_password(buffer, strlen(buffer)))
            {
                case 0:
                    printf("Sua senha segue os padrões mínimos.\n");
                    break;
                    
                case 1:
                    printf("Sua senha precisa ter ao menos 8 caracteres.\n");
                    break;

                case 2:
                    printf("Sua senha precisa ter ao menos uma letra minúscula.\n");
                    break;
                
                case 3:
                    printf("Sua senha precisa ter ao menos uma letra maiúscula.\n");
                    break;

                case 4:
                    printf("Sua senha precisa ter ao menos um dígito numérico.\n");
            }
            add_log("Validated password");
            break;
        case 4:
            printf("Voltando...\n");
            break;
    }
    printf("Pressione enter...");
    getchar();

    return local_choice;
}