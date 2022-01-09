#include <stdio.h>
#include <string.h>

void main()
{
    char exp[50];
    char stack[50][1];
    fgets(exp,50,stdin);
    int top=-1;
    int i;
    for(i=0;i<=strlen(exp)-2;i++)
    {
        if (!strncmp(&exp[i],"(",1)||!strncmp(&exp[i],"{",1)||!strncmp(&exp[i],"[",1)) 
        {
             stack[++top][0]=exp[i];

        }
        if(!strncmp(&exp[i],")",1)||!strncmp(&exp[i],"}",1)||!strncmp(&exp[i],"]",1))
        {
            if(!strncmp(&exp[i],")",1) && !strncmp(&stack[top][0],"(",1)) top--;
            else if(!strncmp(&exp[i],"}",1) && !strncmp(&stack[top][0],"{",1)) top--;
            else if(!strncmp(&exp[i],"]",1) && !strncmp(&stack[top][0],"[",1)) top--;
            else break;
        }
        
    }
    if (top==-1)
    {
        printf("\nbalanced");
    }
    else
    {
     printf("\nnot balanced");
    }

}