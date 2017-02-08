
//#define MAX 10

int queue_arr[MAX];
int rearq=-1;
int frontq=-1;

void insertq(int item);
int delq();
int peekq();
void displayq();
int isfullq();
int isemptyq();

mainqueue()
{
				int choice,item;
				while(1)
				{
								printf("1.insertq\n");
								printf("2.delqete\n");
								printf("3.displayq element at the frontq\n");
								printf("4.displayq all elements of the queue\n");
								printf("5.Quit\n");
								printf("Enter your choice : ");
								scanf("%d",&choice);

								switch(choice)
								{
												case 1:
																printf("Input the element for adding in queue : ");
																scanf("%d",&item);
																insertq(item);
																break;
												case 2:
																item=delq();
																printf("delqeted element is  %d\n",item);
																break;
												case 3:
																printf("Element at the frontq is %d\n",peekq());
																break;
												case 4:
																displayq();
																break;
																
																
								}
								if(choice==5) break;
				}
}

void insertq(int item)
{
				if( isfullq() )
				{
								printf("Queue Overflow\n");
								return;
				}
				if( frontq == -1 )
								frontq=0;
				rearq=rearq+1;
				queue_arr[rearq]=item ;
}

int delq()
{
				int item;
				if( isemptyq() )
				{
								printf("Queue Underflow\n");
								exit(1);
				}
				item=queue_arr[frontq];
				frontq=frontq+1;
				return item;
}

int peekq()
{
				if( isemptyq() )
				{
								printf("Queue Underflow\n");
								exit(1);
				}
				return queue_arr[frontq];
}

int isemptyq()
{
				if( frontq==-1 || frontq==rearq+1 )
								return 1;
				else
								return 0;
}

int isfullq()
{
				if( rearq==MAX-1 )
								return 1;
				else
								return 0;
}

void displayq()
{
				int i;
				if ( isemptyq() )
				{
								printf("Queue is empty\n");
								return;
				}
				printf("Queue is :\n\n");
				for(i=frontq;i<=rearq;i++)
								printf("%d  ",queue_arr[i]);
				printf("\n\n");
}




