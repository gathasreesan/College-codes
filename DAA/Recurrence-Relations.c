#include <stdio.h>
#include <time.h>

int factcall=0;
int fibcall=0;
int hanoicall=0;
int factorial(int n)
{
factcall++;
if(n==0||n==1) return 1;
return n*factorial(n-1);
}
int fibonacci(int n)
{
fibcall++;
if(n<=1) return n;
return fibonacci(n-1)+fibonacci(n-2);
}
void hanoi(int n,char from,char to,char aux)
{
hanoicall++;
if(n==1) return;
hanoi(n-1,from,aux,to);
hanoi(n-1,aux,to,from);
}
int main()
{
int ch,n,z;
clock_t s,e;
z=1;
double t;
while(z>0){
printf("\n1.Factorial\n2.Fibonacci\n3.Tower of Hanoi\n4.Exit\n");
scanf("%d",&ch);
if(ch==4) 
break;
printf("ENTER THE NUMBER : ");
scanf("%d",&n);
if(ch==1){
factcall=0;
s=clock();
printf("Result=%d\n",factorial(n));
e=clock();
t=(double)(e-s)/CLOCKS_PER_SEC;
printf("Calls=%d\nTime=%f\n",factcall,t);
}
else if(ch==2){
fibcall=0;
s=clock();
printf("Result=%d\n",fibonacci(n));
e=clock();
t=(double)(e-s)/CLOCKS_PER_SEC;
printf("Calls=%d\nTime=%f\n",fibcall,t);
}
else if(ch==3){
hanoicall=0;
s=clock();
hanoi(n,'A','C','B');
e=clock();
t=(double)(e-s)/CLOCKS_PER_SEC;
printf("Calls=%d\nTime=%f\n",hanoicall,t);
}
}
return 0;
}
