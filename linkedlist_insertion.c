#include <stdio.h>
#include <stdlib.h>
struct node
{
int info;
struct node* next;
};
int main()
{
  struct node* start, *second,*temp;
start=NULL;
start=(struct node*)malloc(sizeof(struct node));
second=(struct node*) malloc(sizeof(struct node));
printf("Enter item :");
scanf("%d",&start->info);
second->next=NULL;
temp=start;
printf("Elements are:");
while(temp!=NULL)
{
printf("%d",temp->info);
temp=temp->next;
}
}
