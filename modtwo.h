#ifndef MODTWO_H
#define MODTWO_H

char caesar(char letter, int shift);
char stream(char letter, char key);
int encryption_menu(char *buffer, int size);
void cipher(char *buffer, int size, short cipher_type);

#endif