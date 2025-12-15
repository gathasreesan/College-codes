#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int removearray(int arr[100],int n){
int pos=-1,e,i;
printf("ENTER THE ELEMENT TO BE REMOVED:");
scanf("%d",&e);
for(i=0;i<n;i++){
if(arr[i]==e){
pos=i;
break;
}
}
if(pos==-1){
printf("ELEMENT NOT FOUND");
return n;
}
for(i=pos;i<n-1;i++){
arr[i]=arr[i+1];
}
return n-1;
}

void displayarray(int s[100],int n){
int i;
for(i=0;i<n;i++){
printf("ARRAY[%d] :%d \n",i,s[i]);
}
}

int nextarray(int arr[100], int n){
int pos=-1, e, i;
printf("enter the element whose greater is to be found: ");
scanf("%d", &e);
for(i=0;i<n;i++){
if(arr[i] == e){
pos = i;
break;
}
}
if(pos == -1){
printf("ELEMENT NOT FOUND\n");
return n;
}
for(i = pos + 1; i < n; i++){
if(arr[i] > arr[pos]){
printf("NEXT GREATER ELEMENT: %d\n", arr[i]);
return n;
}
}
printf("NO GREATER ELEMENT FOUND\n");
return n;
}

struct Node{
int data;
struct Node *next;
struct Node *link;
};

struct Node* createnode(int val){
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=val;
newnode->next=NULL;
return newnode;
}

struct Node* removelinked(struct Node *head){
int e;
printf("ENTER THE ELEMENT TO BE REMOVED:");
scanf("%d",&e);
struct Node *temp=head,*prev=NULL;
while(temp!=NULL)
{
if(temp->data==e)
{
if(prev==NULL)
{
head=temp->next;
free(temp);
return head;
}else
{
prev->next=temp->next;
free(temp);
return head;
}
}
prev=temp;
temp=temp->next;
}
printf("ELEMENT NOT FOUND");
return head;
}

void displaylinked(struct Node *head){
int i=0;
struct Node *temp=head;
while(temp!=NULL)
{
printf("linked list[%d] :%d \n",i,temp->data);
temp=temp->next;
i++;
}
}

void nextlinked(struct Node *head){
int e;
printf("enter thr element whose greater is to be found :");
scanf("%d",&e);
struct Node *temp=head;
while(temp!=NULL)
{
if(temp->data==e)
{
struct Node *temp1=temp->next;
while(temp1!=NULL)
{
if(temp1->data>temp->data){
printf("NEXT GREATER ELEMENT:%d",temp1->data);
return;
}
temp1=temp1->next;
}
printf("NO GREATER ELEMENT FOUND");
return;
}
temp=temp->next;
}
printf("ELEMENT NOT FOUND");
}

int main(){
int s[100],n,i,val;
struct Node *head=NULL,*temp;
clock_t start, end;
start = clock();
printf("Enter the number of elements:");
scanf("%d",&n);
printf("ENTER THE ELEMENTS :");
for(i=0;i<n;i++){
scanf("%d",&s[i]);
if(head==NULL){
head=createnode(s[i]);
temp=head;
}else{
temp->next=createnode(s[i]);
temp=temp->next;
}
}
printf("\t ARRAY\n");
start=clock();
n=removearray(s,n);
end=clock();
double time_removearray = ((double)(end - start)) / CLOCKS_PER_SEC;
displayarray(s,n);
start=clock();
n=nextarray(s,n);
end=clock();
double time_nextarray = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\t LINKED LIST\n");
start=clock();
head=removelinked(head);
end=clock();
double time_removelinked = ((double)(end - start)) / CLOCKS_PER_SEC;
displaylinked(head);
start=clock();
nextlinked(head);
end=clock();
double time_nextlinked = ((double)(end - start)) / CLOCKS_PER_SEC;
printf(" TIME TAKEN BY ARRAY");
printf("\nCPU time used for removing array = %f seconds\n", time_removearray);
printf("\nCPU time used for geting the next greater value from array = %f seconds\n", time_nextarray);
printf("TIME TAKEN BY LINKED LIST");
printf("\nCPU time used for removing from LINKED LIST = %f seconds\n", time_removelinked);
printf("\nCPU time used for geting the next greater value from LINKED LIST = %f seconds\n", time_nextlinked);
printf("SPACE");
int space = sizeof(s);
printf("\nSPACE OF ARRAY : %d",space);
int total_space = n* sizeof(struct Node);
printf("\nSPACE OF LINKED LIST : %d",total_space);
return 0;
}
