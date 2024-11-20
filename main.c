#include <stdio.h>
#include <string.h>
#define STR_SIZE 20
int main(int, char **)
{
    char str[STR_SIZE] = "Hello";
    printf("%d\n", strlen(str));
    printf("sizeof %d\n", sizeof(str));
    return 0;
}
