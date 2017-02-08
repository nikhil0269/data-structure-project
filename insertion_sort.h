//insertion sort
#include<stdio.h>
//#define MAX 5
int insert[MAX];
void insert_sort()
{
int i,j,k,temp;
for(i=1;i<MAX;i++)
{
for(j=0;j<i;j++)
{
if(insert[j]>insert[i])
{
temp=insert[i];
for(k=i;k>=j+1;k--)
{
insert[k]=insert[k-1];
}
insert[j]=temp;
}

}
}
}
void showi()
{
int i;
for(i=0;i<MAX;i++)
printf("%d ",insert[i]);
}
void maini()
{
printf("Enter an array\n");
int i;
for(i=0;i<MAX;i++)
scanf("%d",&insert[i]);
insert_sort();
showi();
}
