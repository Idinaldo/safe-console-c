#include "modone.h"
#include "general.h"

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