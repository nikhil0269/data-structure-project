#include<stdio.h>
void push2(int);
void push1(int);
int isempty();
int isempty1();
int pop1();
int pop2();
void display(int);
void display2(int);
int top=-1;
int max=10;
int top1=10;
int a[10];
int isempty();
int isfull();
void main_two_stack()
{
				int k,item;
				while(1)
				{
				printf("1.push in stack 1\n2.pop in stack 1\n3.display stack 1\n4.push in stack 2.\n5.pop in stack 2\n6.display stack 2\n7.exit\n");
								scanf("%d",&k);
								switch(k)
								{
												case 1:
																printf("enter the element\n");
																scanf("%d",&item);
																push2(item);
																break;

												case 2:
																if(isempty())
																{
																				printf("stack is empty\n");
																				break;
																}
																printf("element removed is %d\n",pop2());
																break;

												case 3:

																display(top);
																break;

												case 4:

																printf("enter the element\n");
																scanf("%d",&item);
																push1(item);
																break;

												case 5:

																if(isempty1())
																{
																				printf("stack is empty\n");
																				break;
																}
																printf("element removed is %d\n",pop1());
																break;



												case 6:

																display2(top1);
																break;

												case 7:
																return;}}}
void push2(int item)
{
				if(!isfull())
				{
								top++;
								a[top]=item;
								
				}
				else
				{
								printf("stack1 is full\n");
								
				}
}
int isfull()
{
				if(top==top1-1)
								return 1;
				else
								return 0;
}
int isempty()
{
				if(top==-1)
								return 1;
				else
								return 0;
}
int pop2()
{int i;
				if(!isempty())
				{i=a[top];
								top--;
								return i;
				}}
void display(int i)
{
				if(isempty())
				{
								printf("stack1 is empty\n");
								
				}
				int j;
				for(j=i;j>=0;j--)
								printf("%d\n",a[j]);
}
int isfull1()
{
				if(top1==top+1)
								return 1;
				else
								return 0;
}


void push1(int item)
{
				if(!isfull1())
				{
								top1--;
								a[top1]=item;
								
				}
				else
				{
								printf("stack2 is full\n");
							
				}
}


int isempty1()
{
				int item;
				if(top1==max)
								return 1;
				else
								return 0;
}


void display2(int i)
{
				if(isempty1())
				{
								printf("stack2 is empty\n");
								
				}
				int j;
				for(j=i;j<max;j++)
								printf("%d\n",a[j]);
}
int pop1()
{
				int i;
				if(!isempty1())
				{i=a[top1];
								top1++;
								return i;
								printf("\n\n%d\n\n",i);
				}



}













