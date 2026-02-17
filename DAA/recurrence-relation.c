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
int ch,n;
clock_t s,e;
double t;
printf("ENTER THE NUMBER:");
scanf("%d",&n);
printf("\nFACTORIAL:\n");
factcall=0;
s=clock();
printf("Result=%d\n",factorial(n));
e=clock();
t=(double)(e-s)/CLOCKS_PER_SEC;
printf("Calls=%d\nTime=%f\n",factcall,t);
printf("\nFIBONNACI:\n");
fibcall=0;
s=clock();
printf("Result=%d\n",fibonacci(n));
e=clock();
t=(double)(e-s)/CLOCKS_PER_SEC;
printf("Calls=%d\nTime=%f\n",fibcall,t);
printf("\nTOWER OF HANOI:\n");
hanoicall=0;
s=clock();
hanoi(n,'A','C','B');
e=clock();
t=(double)(e-s)/CLOCKS_PER_SEC;
printf("Calls=%d\nTime=%f\n",hanoicall,t);
return 0;
}
