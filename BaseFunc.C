#include <stdio.h>
#include <stdlib.h>

int puts(const char *string)
{
    int i = 0;
    char ch = '\0';

    if ( string == NULL )
        return 0;
    
    while ( ch = string[i]/*) != '\0'*/)
    {
        putchar(ch);
        i++;
    }

    putchar('\n');

    return i;
}

const char * strchr( const char *string, int symbol)
{
    if ( string == NULL )
        return NULL;

    char currSymbol = '\0';

    while ( currSymbol = *string )
    {
        if ( currSymbol == symbol )
            return string;
        string++;
    }    

    return NULL;
}

int strlen( const char* str )
{
    if ( str == NULL )
        return NULL;

    char currSymbol = '\0';
    int len = 0;

    while ( currSymbol = str[len] )
        len++;    

    return len;
}

char *strcpy( char *dest, const char *str )
{
    int i = 0;

    if ( str == NULL )
        return NULL;

    while ( str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }

    return dest;
}

char *strncpy( char *dest, const char *str, size_t count )
{
    int i = 0;

    if ( str == NULL )
        return NULL;

    if ( dest == NULL )
        return NULL;

    while ( str[i] != '\0' && count > i)
    {
        dest[i] = str[i];
        i++;
    }

    return dest; 
}

char *strcat( char *dest, const char *str )
{
    int i = 0, size = strlen(dest);

    if ( dest == NULL )
        return NULL;

    if ( str == NULL ) 
        return NULL; 

    while ( size > i )
    {
        dest[i] = '\0';
        i++;
    }

    i = 0;
    while ( str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }

    return dest;
}

char * strncat( char * dest, const char * str, size_t num )
{
    int i = 0, size = strlen(dest);

    if ( dest == NULL )
        return NULL;

    if ( str == NULL ) 
        return NULL; 

    while ( size > i )
    {
        dest[i] = '\0';
        i++;
    }

    i = 0;
    while ( *str != '\0' && i < num)
    {
        dest[i] = str[i];
        i++; 
    }

    return dest;
}

char * fgets( char * string, int num, FILE * filestream )
{
    int i = 0, buffer_size = 3030;
    char str[buffer_size]; 

    if ( num < 0 )
        return NULL;

    for (i = 0; i < buffer_size; i++)
         str[i] = NULL;

    if (filestream == NULL)
         return NULL;

    i = 0;
    while ( (str[i] = fgetc(filestream)) != EOF)
        i++;
    str[i - 1] = '\0';
    i = 0;

    while (str[i] != '\0' && num > i)
    {
        *string = str[i];
        string++;  
        i++;    
    } 

    return string;    
}

char * strdup( const char *str1 )
{
    int i = 0, buffer_size = 3030;
    char *str;
    str = (char *)calloc( buffer_size, sizeof(char) );

    if ( str1 == NULL )
        return NULL;

   /* for (i = 0; i < buffer_size; i++)
        i [str] = NULL; // *(str + i) = *(i + str) = i [str];*/
    //не нужно, т к calloc освобождает память

    strncpy(str, str1, buffer_size);

    return str;
}



int main()
{
    int i = 0;
    char str[100];
    const char s[] = "Hello world!!!!!";
    //const char *x = NULL;
    
    for (i = 0; i < 100; i++)
        str[i] = NULL;
 
     FILE *f = NULL;
     char name[] = "FILE.txt";
     f = fopen(name, "r");

    printf("%i \n", strlen(s));
    //puts(strchr(s, 'o')); 
    fgets(str, 20, f);

    strncpy(str, "Hahahahahah", 80);
    strncat(str, s, 10);     
    puts(str);
    puts(strdup(s));
    return 0;
}
