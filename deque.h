#include<stdio.h>
int pushd(int);
int popd();
void displayd(int);
void displayd1(int);
int top;
int MAXD=10;
int top10=10;
int a[10];
int isEmptyd();
int isfulld();
void maindq()
{        
        
				int k,item;
				while(1)
				{
								printf("1.pushd in stack 1\n2.popd in stack 1\n3.displayd stack 1\n4.pushd in stack 2.\n5.popd in stack 2\n6.displayd stack 2\n7.exit\n");
								scanf("%d",&k);
								switch(k)
								{
												case 1:
																printf("enter the element\n");
																scanf("%d",&item);
																pushd(item);
																break;

												case 2:
																if(isEmptyd())
																{
																				printf("stack is empty\n");
																				break;
																}
																printf("element removed is %d\n",popd());
																break;

												case 3:

																displayd(top);
																break;

												case 4:

																printf("enter the element\n");
																scanf("%d",&item);
																pushd1(item);
																break;

												case 5:

																if(isEmptyd1())
																{
																				printf("stack is empty\n");
																				break;
																}
																printf("element removed is %d\n",popd1());
																break;



												case 6:

																displayd1(top10);
																break;

												case 7:
																return;}}}
int pushd(int item)
{
				if(!isfulld())
				{
								top++;
								a[top]=item;
								return 0;
				}
				else
				{
								printf("stack1 is full\n");
								return;
				}
}
int isfulld()
{
				if(top==top10-1)
								return 1;
				else
								return 0;
}
int isEmptyd()
{
				if(top==-1)
								return 1;
				else
								return 0;
}
int popd()
{int i;
				if(!isEmptyd())
				{i=a[top];
								top--;
								return i;
				}}
void displayd(int i)
{
				if(isEmptyd())
				{
								printf("stack1 is empty\n");
								
				}
				int j;
				for(j=i;j>=0;j--)
								printf("%d\n",a[j]);
}
int isfulld1()
{
				if(top10==top+1)
								return 1;
				else
								return 0;
}


int pushd1(int item)
{
				if(!isfulld1())
				{
								top10--;
								a[top10]=item;
								return 0;
				}
				else
				{
								printf("stack2 is full\n");
								return 0;
				}
}


int isEmptyd1()
{
				int item;
				if(top10==MAXD)
								return 1;
				else
								return 0;
}


void displayd1(int i)
{
				if(isEmptyd1())
				{
								printf("stack2 is empty\n");
								return;
				}
				int j;
				for(j=i;j<MAXD;j++)
								printf("%d\n",a[j]);
}
int popd1()
{
				int i;
				if(!isEmptyd1())
				{i=a[top10];
								top10++;
								return i;
								printf("\n\n%d\n\n",i);
				}


}
