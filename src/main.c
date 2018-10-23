#include "ft_malloc.h"

int     main(int argc, char **argv)
{
    char *str1 = NULL;
    char *str2 = NULL;
    char *str3 = NULL;
    char *str4 = NULL;
    
    str1 = (char *)ft_malloc(sizeof(char) * 8);
    str2 = (char *)ft_malloc(sizeof(char) * 200);
    str3 = (char *)malloc(sizeof(char) * 8);
    str4 = (char *)malloc(sizeof(char) * 200);
    int i = 0;
    while (i < 199)
    {
        if (i < 7)
        {
            str1[i] = '*';
            str3[i] = '*';
        }
        if (i == 7)
        {
            str1[i] = '*';
            str3[i] = '*';
        }
        str2[i] = '*';
        str4[i] = '*';
    }
    str2[i] = '*';
    str4[i] = '*';
    ft_printf(2, "%p\n%p\n%p\n%p\n", str1, str2, str3, str4);
    return (0);
}