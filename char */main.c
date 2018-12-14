//
//  main.c
//  char *
//
//  Created by Zac on 2018/12/1.
//  Copyright © 2018 gonglx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int mystrlen(const char * src)
{
    int len = 0;
    while (*src++)
    {
        len++;
    }
    return len;
}

char * mystrcpy(char * dest,const char * src)
{
    char *temp = dest;
    while ((*dest++ = *src++));
    return temp;
}

char * mystrcat(char * dest, const char * src)
{
    char * temp = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return temp;
    
}

int mystrcmp(char * dest , const char * src)
{
    for (; *dest && *src && *dest == *src; dest++,src++){};
        return *dest - *src;
}

char *mystrchr(char *dest,char src)
{
    while (*dest != src)
    {
        dest++;
    }
    return dest;
}

char *mystrstr(char * dest, char * src)
{
    while (*dest && *src)
    {
        for (int i = 0; *(dest+i) && *(src+i); i++)
        {
            if (*(dest+i+1) == '\0')
            {
                return dest;
            }
        }
        dest++;
    }
    return NULL;
}

int mystrstrlen(char * dest, char  src)
{
    int len = 0;
    while (*dest)
    {
        if (*dest == src)
        {
            len++;
        }
        dest++;
    }
    return len;
}

int main(int argc, const char * argv[])
{

    char *dest = "caina";
    char *src = "cbana";
    
    int ret =  mystrcmp(dest, src);
    printf("%d \n",ret);
    
    return 0;
}
