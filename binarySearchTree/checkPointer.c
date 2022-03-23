#include<stdio.h>
#include<string.h>
void  main()
{
    char *str="dfhh";
    char st1[]="ety";
    *(str+1)='a';
    puts(str);
    printf("%c",*(str+1));
}