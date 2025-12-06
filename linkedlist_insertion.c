#include <stdio.h>
#include <stdlib.h>
struct node
{
int info;
struct node* next;
};
void inser_beg(list,start)
{
struct *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
if (ptr ==NULL)
{
printf("overdlow error");
}
else
{
ptr->info=item;
ptr->next=start;
start=ptr;
}
}
int main()
{
  struct node* start, *second,*temp;
start=NULL;
start=(struct node*)malloc(sizeof(struct node));
second=(struct node*) malloc(sizeof(struct node));
printf("Enter item :");
scanf("%d",&start->info);
insert_beg(32,start);
second->next=NULL;
temp=start;
printf("Elements are:");
while(temp!=NULL)
{
printf("%d",temp->info);
temp=temp->next;
}
}
