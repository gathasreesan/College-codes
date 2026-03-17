#include<stdio.h>
#include<stdlib.h>

int main()
{
int req[7]={82,170,43,140,24,16,190};
int head=50,total=0,i;

for(i=0;i<7;i++)
{
total+=abs(req[i]-head);
head=req[i];
}

printf("Total head movement = %d",total);
return 0;
}