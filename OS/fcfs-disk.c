#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
int request[]={82,170,43,140,24,16,190}; 
int head=50; 
int total=0; 
int n= 7; 
for(int i = 0; i < n; i++) 
{ 
total += abs(head - request[i]); 
head =request[i]; 
} 
printf("Total Seek Time = %d", total); 
return 0; 
}