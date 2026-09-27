#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
int menu(char (*options)[50], int size, char *title);
void sgets(char *data_holder, int size_data_holder, char *input_message);
void data_masking(char *data, int size);

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
                            
                            printf("Seu texto é: %s\n", buffer);
                            printf("Pressione qualquer tecla para voltar ao menu anterior...");
                            getchar();
                            
                            break;
                        case 2:
                            sgets(buffer, BUFFER_SIZE, "Digite seu dado: ");
                            data_masking(buffer, BUFFER_SIZE);
                            break;
                        case 3:
                            printf("Bla\n");
                            break;
                        case 4:
                            printf("Voltando...\n");
                            break;
                    }

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
    printf("%s", input_message);
    
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void data_masking(char *data, int size)
{

}