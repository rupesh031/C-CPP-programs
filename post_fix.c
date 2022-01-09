#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define multiply(x,y) (x*y)

void main()
{
    char s[50];
    printf("enter post-fix exp ");
    fgets(s,50,stdin);
    double stack[20];
    int top=-1;
    int i;
    int digit=0;
    for(i=0;i<=strlen(s)-2;i++)
    {
       
        if (isdigit(s[i]))
        {
            char c=s[i];
            digit=digit*10+atoi(&c);
        }
        if(!strncmp(&s[i],",",1))
        {
            if (digit!=0)
            {
            stack[++top]=(digit);
            digit=0;
            }
            
        }
        if(!strncmp(&s[i],"*",1)) stack[top]=stack[top]*stack[--top];
        if (!strncmp(&s[i],"/",1)) stack[top]=stack[top-1]/stack[top--];
        if (!strncmp(&s[i],"+",1)) stack[top]=stack[top]+stack[--top];
        if (!strncmp(&s[i],"-",1)) stack[top]=stack[top-1]-stack[top--];
    }
    printf("%lf \n",stack[top]);
}