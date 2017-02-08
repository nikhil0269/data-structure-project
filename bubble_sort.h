//program of bubble sorting
#include<stdio.h>
#define MAX 5

int bubble[MAX];
void bubble_sort()
{
int i,j,temp;
printf("Unsorted data\n");
for(i=0;i<5;i++)
printf("%d ",bubble[i]);
printf("\n");
for(i=0;i<MAX-1;i++)
{
for(j=0;j<MAX-1-i;j++)
{
if(bubble[j]>bubble[j+1])
{
temp=bubble[j];
bubble[j]=bubble[j+1];
bubble[j+1]=temp;
}
}
}
}
void showb()
{
int i;
for(i=0;i<MAX;i++)
printf("%d ",bubble[i]);
}
void mainb()
{
int i;
printf("Enter an array\n");
for(i=0;i<MAX;i++)
scanf("%d",&bubble[i]);
bubble_sort();

printf("sorted data\n");
showb();
}
