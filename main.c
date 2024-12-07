#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 10
char *mygets(FILE *stream);
int main(int, char **)
{
    char *str = mygets(stdin);
    puts(str);

    free(str);
    return 0;
}

char *mygets(FILE *stream)
{
    long long cur = 0;
    int size = 5;
    char *str = (char *)malloc(sizeof(char) * size);
    char ch;
    while ((ch = getc(stream)) != '\n' && ch != '\0')
    {
        if (cur < size)
        {
            str[cur] = ch;
        }
        else
        {
            size += 5;
            str = (char *)realloc(str, size);
            str[cur] = ch;
        }
        cur++;
    }
    if (ch == '\n')
    {
        str[cur] = '\0';
    }
    return str;
}