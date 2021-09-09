#include <stdio.h>
#include <stdlib.h>

int puts(const char *string)
{
    int i = 0;

    if ( string == NULL )
        return 0;
    
    while ( *string != '\0')
    {
        putchar(*string);
        string++;
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

    while ( currSymbol = *str )
    {
        len++;
        str++;    
    }

    return len;
}

char *strcpy( char *dest, const char *str )
{
    if ( str == NULL )
        return NULL;

    while ( *str != '\0')
    {
        *dest = *str;
        str++;
        dest++;
    }

    return dest;
}

char *strncpy( char *dest, const char *str, size_t count )
{
    int i = 0;

    if ( count < 0 )
        return NULL;

    if ( str == NULL )
        return NULL;

    while ( *str != '\0' && count > i)
    {
        *dest = *str;
        str++;
        dest++;
        i++;
    }

    return dest; 
}

char *strcat( char *dest, const char *str )
{
    if ( dest == NULL )
        return NULL;

    if ( str == NULL ) 
        return NULL; 

    while ( *dest != '\0' )
        dest++;

    while ( *str != '\0')
    {
        *dest = *str;
        str++;
        dest++;
    }

    return dest;
}

char * strncat( char * dest, const char * str, size_t num )
{
    int i = 0;

    if ( num < 0 )
        return NULL;

    if ( dest == NULL )
        return NULL;

    if ( str == NULL ) 
        return NULL; 

    while ( *dest != '\0' )
        dest++;

    while ( *str != '\0' && i < num)
    {
        *dest = *str;
        str++;
        dest++;
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

    fread(str, sizeof(char), buffer_size , filestream);

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

    for (i = 0; i < buffer_size; i++)
        i [str] = NULL; // *(str + i) = *(i + str) = i [str];

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
 
     //FILE *f = NULL;
    // char name[] = "FILE.txt";
  //   f = fopen(name, "r");

     
//    fgets(str, 20, f);

    //strcpy(str, "Hahahahahah");     
    //puts(str);
    //strncat(str, s, 6);
    puts(strdup(s));
    return 0;
}

//x = strchr(s, 'e');
    //if (strchr(s, 'e'))
    //    printf("Good\n");
    //else
    //    printf("(\n");
    //printf("%c\n", *x);
    //printf("%i \n", strlen(s)); 
