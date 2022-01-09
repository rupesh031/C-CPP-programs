#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char exp_stack[50];
int top = -1;
char post_fix[50];
int last = -1;
int order(char c)
{
    if (!strncmp(&c, "+", 1) || !strncmp(&c, "-", 1))
        return 1;
    else if ((!strncmp(&c, "*", 1) || !strncmp(&c, "/", 1)))
        return 2;
    else if (!strncmp(&c, "^", 1))
        return 3;
    /*else if ((!strncmp(&c, "(", 1) || !strncmp(&c, ")", 1)))
        return 4;*/
    else
        return -1;
}
void chk_stack(char c)
{
    if (!strncmp(&c, "(", 1)) 
    {
        exp_stack[++top] = c;
        return;
    }
    if (!strncmp(&c, ")", 1))
    {
        while(strncmp(&exp_stack[top], "(", 1))
        {
            post_fix[++last] = exp_stack[top--];
          strncat(&post_fix[++last],",",1);
            
        }
        top--;
        return;
    }
    if (order(c) > order(exp_stack[top]) || top == -1)
    {
        exp_stack[++top] = c;
        return;
    }
    else
    {
        while (order(c) < order(exp_stack[top]))
        {
           post_fix[++last] = exp_stack[top--];
           strncat(&post_fix[++last],",",1);
            

            if ( top==-1 || !strncmp(&exp_stack[top], "(", 1) )
            {
                break;
            }
        }
        exp_stack[++top] = c;
        return;
    }
}

double calculate(char s[50])
{
    double stack[20];
    int top1 = -1;
    int i;
    int digit = 0;
    for (i = 0; i <= strlen(s) - 1; i++)
    {

        if (isdigit(s[i]))
        {
            char c = s[i];
            digit = digit * 10 + atoi(&c);
        }
        if (!strncmp(&s[i], ",", 1))
        {
            if (digit != 0)
            {
                stack[++top1] = digit;
                digit = 0;
            }
        }
        if (!strncmp(&s[i], "*", 1))
            stack[top1] = stack[top1 - 1] * stack[top1--];
        if (!strncmp(&s[i], "/", 1))
            stack[top1] = stack[top1 - 1] / stack[top1--];
        if (!strncmp(&s[i], "+", 1))
            stack[top1] = stack[top1 - 1] + stack[top1--];
        if (!strncmp(&s[i], "-", 1))
            stack[top1] = stack[top1 - 1] - stack[top1--];
        if (!strncmp(&s[i], "^", 1))
            {
                double base= stack[top1 - 1];
                double power=stack[top1];
                double result=pow(base,power);
                stack[top1-1] = result;
                top1--;

            }
    }
    return stack[top1];
}

void main()
{
    char exp[50];
    printf("enter infix exp");
    fgets(exp, 50, stdin);
    int i;
    for (i = 0; i <= strlen(exp) - 2; i++)
    {
        char c = exp[i];
        if(!strncmp(&c," ",1))
        continue;
        if (isalnum(c))
        {
            post_fix[++last] = c;
        }
        else
        {
            if(strncmp(&post_fix[last],",",1))
                strncat(&post_fix[++last],",",1);
            if (top != -1)
                chk_stack(c);
            else
                exp_stack[++top] = c;
        }
    }
    while (top >= 0)
    {
        strncat(&post_fix[++last],",",1);
        post_fix[++last] = exp_stack[top--];
        
    }
    printf("%s \n", post_fix);
    //printf("%lf",calculate(post_fix));
}
