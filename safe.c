#include <stdio.h>
#include "modone.h"
#include "general.h"
#include <string.h>

#define BUFFER_SIZE 100

int main(void)
{
    char buffer[BUFFER_SIZE];

    char options[][50] = {"Sanitização e Validação", "Cifragem e Decifragem", "Logs e Auditoria", "Sair"};
    char options_module_1[][50] = {"Leitura Segura", "Data Masking", "Validador de Senhas", "Voltar"};
    char options_module_2[][50] = {"Leitura Segura", "Data Masking", "Validador de Senhas", "Voltar"};
    char options_module_3[][50] = {"Leitura Segura", "Data Masking", "Validador de Senhas", "Voltar"};

    int choice;
    int local_choice;
    do {
        choice = menu(options, 4, "MENU PRINCIPAL");
        
        switch (choice)
        {
            case 1:
                do {
                    local_choice = menu(options_module_1, 4, "Sanitização e Validação");
                    printf("Você escolheu %s\n", options_module_1[local_choice - 1]);
                    
                    switch(local_choice)
                    {
                        case 1:
                            sgets(buffer, BUFFER_SIZE, "Digite seu texto: ");
                            printf("Seu texto seguro e tratado é: %s\n", buffer);
                            break;
                        case 2:
                            sgets(buffer, BUFFER_SIZE, "Digite seu dado: ");
                            data_masking(buffer, strlen(buffer));
                            printf("Seu dado mascarado é: %s\n", buffer);
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
                            break;
                        case 4:
                            printf("Voltando...\n");
                            break;
                    }
                    printf("Pressione qualquer tecla...");
                    getchar();

                } while (local_choice != 4);
                break;

            case 2:
                do {
                    local_choice = menu(options_module_2, 4, "Cifragem e Decifragem");
                    printf("Você escolheu %s\n", options_module_1[local_choice - 1]);
                } while (local_choice != 4);
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