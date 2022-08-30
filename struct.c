#include <stdio.h>
#include <string.h>
typedef struct address
{
    int houseno;
    int blockno;
    char city[100];
    char state[100];
} add;
void printadd(struct address add);
int main()
{
    struct address adds[3];
    printf("enter info for person 1:");
    fgets(adds[0].city, 100, stdin);
    fgets(adds[0].state, 100, stdin);
    scanf("%d", &adds[0].houseno);
    scanf("%d", &adds[0].blockno);
    printf("enter info for person 2:");
    scanf("%d", &adds[1].houseno);
    scanf("%d", &adds[1].blockno);
    fgets(adds[1].city, 100, stdin);
    fgets(adds[1].state, 100, stdin);
    printf("enter info for person 3:");
    fgets(adds[2].city, 100, stdin);
    fgets(adds[2].state, 100, stdin);
    scanf("%d", &adds[2].blockno);
    scanf("%d", &adds[2].houseno);
    printf("final");
    printadd(adds[0]);
    printadd(adds[1]);
    printadd(adds[2]);

    return 0;
}
void printadd(struct address add)
{
    printf("address:%d,%d,%s,%s", add.houseno, add.blockno, add.city, add.state);
}