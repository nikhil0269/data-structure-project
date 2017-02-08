//selection sort program
#include<stdio.h>
//#define MAX 5
int selecti[MAX];
void select_sort()
{

printf("The sorted array is \n");
int i,j,temp;
for(i=0;i<MAX-1;i++)
{
for(j=i+1;j<MAX;j++)
{
if(selecti[i]>selecti[j])
{
temp=selecti[i];
selecti[i]=selecti[j];
selecti[j]=temp;
}
}
}
}
void shows()
{
int i;
for(i=0;i<MAX;i++)
printf("%d ",selecti[i]);
}
void mains()
{
int i;
printf("Enter an array\n");
for(i=0;i<MAX;i++)
scanf("%d",&selecti[i]);
select_sort();
shows();
}
