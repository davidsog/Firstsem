#include <stdio.h>
//#include <stdlib.h>

int puts(const char *string)
{
    if ( *string == '\0' )
        return 0;
    while ( *string != '\0')
    {
        putchar(*string);
        string++;
    }
    putchar('\n');
    return 1;
}

char * strchr( const char *string, int symbol)
{
    char *x;

    if ( *string == '\0' )
        return NULL;
    while ( *string != '\0' )
    {
        if ( *string == symbol )
        {
            *x = *string;
            return x;
        }
        string++;
    }    
    return NULL;
}

int main()
{
    const char s[] = "Hello world!!!!!";
    char *x = NULL;

    x = strchr(s, 'e');
    if (strchr(s, 'e'))
        printf("Good\n");
    else
        printf("(\n");
   // printf("%s", x);        
    return 0;
}
