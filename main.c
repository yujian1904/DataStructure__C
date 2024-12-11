#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 10
char *m_getline(FILE *stream);
int main(int, char **)
{
    char *str = m_getline(stdin);
    puts(str);

    free(str);
    return 0;
}

char *m_getline(FILE *stream)
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
            size++;
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