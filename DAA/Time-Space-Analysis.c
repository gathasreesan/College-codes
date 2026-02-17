#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
        printf("ELEMENT NOT FOUND\n");
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
        printf("ARRAY[%d] : %d\n",i,s[i]);
    }
}
void nextarray(int arr[100], int n){
    int pos=-1, e, i;
    printf("Enter the element whose greater is to be found: ");
    scanf("%d", &e);
    for(i=0;i<n;i++){
        if(arr[i] == e){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        printf("ELEMENT NOT FOUND\n");
        return;
    }
    for(i = pos + 1; i < n; i++){
        if(arr[i] > arr[pos]){
            printf("NEXT GREATER ELEMENT: %d\n", arr[i]);
            return;
        }
    }
    printf("NO GREATER ELEMENT FOUND\n");
}
struct Node{
    int data;
    struct Node *next;
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
    while(temp!=NULL){
        if(temp->data==e){
            if(prev==NULL){
                head=temp->next;
            }else{
                prev->next=temp->next;
            }
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("ELEMENT NOT FOUND\n");
    return head;
}
void displaylinked(struct Node *head){
    int i=0;
    struct Node *temp=head;
    while(temp!=NULL){
        printf("Linked List[%d] : %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}
void nextlinked(struct Node *head){
    int e;
    printf("Enter the element whose greater is to be found: ");
    scanf("%d",&e);
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->data==e){
            struct Node *temp1=temp->next;
            while(temp1!=NULL){
                if(temp1->data > temp->data){
                    printf("NEXT GREATER ELEMENT: %d\n",temp1->data);
                    return;
                }
                temp1=temp1->next;
            }
            printf("NO GREATER ELEMENT FOUND\n");
            return;
        }
        temp=temp->next;
    }
    printf("ELEMENT NOT FOUND\n");
}
int main(){
    int s[100], n, i, original_n;
    struct Node *head=NULL,*temp;
    clock_t start, end;
    double time_removearray, time_nextarray;
    double time_removelinked, time_nextlinked;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    original_n = n;
    srand(time(NULL));
    printf("RANDOMLY GENERATED ELEMENTS:\n");
    for(i=0;i<n;i++){
        s[i] = rand() % 100;
        printf("%d ", s[i]);
        if(head==NULL){
            head=createnode(s[i]);
            temp=head;
        }else{
            temp->next=createnode(s[i]);
            temp=temp->next;
        }
    }
    printf("\n");
    printf("\n----- ARRAY -----\n");
    start = clock();
    n = removearray(s, n);
    end = clock();
    time_removearray = ((double)(end - start)) / CLOCKS_PER_SEC;
    displayarray(s, n);
    start = clock();
    nextarray(s, n);
    end = clock();
    time_nextarray = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n----- LINKED LIST -----\n");
    start = clock();
    head = removelinked(head);
    end = clock();
    time_removelinked = ((double)(end - start)) / CLOCKS_PER_SEC;
    displaylinked(head);
    start = clock();
    nextlinked(head);
    end = clock();
    time_nextlinked = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n----- TIME TAKEN -----\n");
    printf("Array remove(i): %f seconds\n", time_removearray);
    printf("Array next(i): %f seconds\n", time_nextarray);
    printf("Linked List remove(i): %f seconds\n", time_removelinked);
    printf("Linked List next(i): %f seconds\n", time_nextlinked);

    printf("\n----- SPACE ANALYSIS -----\n");
    printf("Space per node (Array): %lu bytes\n", (unsigned long)sizeof(int));
    printf("Space per node (Linked List): %lu bytes\n", (unsigned long)sizeof(struct Node));
    printf("Total space used by Array: %d bytes\n", original_n * (int)sizeof(int));
    printf("Total space used by Linked List: %d bytes\n", original_n * (int)sizeof(struct Node));
    return 0;
}

