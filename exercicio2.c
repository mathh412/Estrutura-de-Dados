/*
Implemente, em linguagem C, uma versão recursiva do Bubble Sort.
Não esqueça de testar seu código com vetores gerados de forma
(pseudo) aleatória.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort (int *v,int tam)
{
if(tam<=1)
{
return;
}
for(int i = 0;i<tam-1;i++)
{
if(v[i]>v[i+1])
{
 int troca= v[i+1];
 v[i+1]=v[i];
v[i]=troca;    
}
}
bubbleSort(v,tam-1);
}

int main()
{
srand(time(NULL));
int *v;
v= malloc(10*sizeof(int));
for(int i=0;i<10;i++)
{
*(v+i)=(rand()%50)+1;    
}   
for(int i=0;i<10;i++)
{
printf("%d ",*(v+i));
}
printf("\n");
bubbleSort(v,10);
for(int i=0;i<10;i++)
{
printf("%d ",*(v+i));    
}
free(v);
return 0;
}
