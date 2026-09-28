#include "options.h"

char options[][50] = {"Sanitização e Validação", "Cifragem e Decifragem", "Logs e Auditoria", "Sair"};
char options_module_1[][50] = {"Leitura Segura", "Data Masking", "Validador de Senhas", "Voltar"};
char options_module_2[][50] = {"Cifra de CESAR", "Cifra XOR", "Voltar"};
char options_module_3[][50] = {"Ler Logs", "Buscar Logs", "Voltar"};
char history[255][100];
int last_history_pos = 0;