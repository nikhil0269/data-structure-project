

struct nodecr
{
				int info;
				struct nodecr *link;
}*rear=NULL;

void insertcr(int item);
int delcr();
void displaycr();
int isEmptycr();
int peekcr();

main_cir_listq()
{
				int choice,item;
				while(1)
				{
								printf("1.insertcr\n");
								printf("2.delcrete\n");
								printf("3.peekcr\n");
								printf("4.displaycr\n");
								printf("5.Quit\n");
								printf("Enter your choice : ");
								scanf("%d",&choice);

								switch(choice)
								{
												case 1:
																printf("Enter the element for insertcrion : ");
																scanf("%d",&item);
																insertcr(item);
																break;
												case 2:
																printf("delcreted element is %d\n",delcr());	
																break;
												case 3:
																printf("Item at the front of queue is %d\n",peekcr());
																break;
												case 4:
																displaycr();
																break;
												case 5:
																exit(1);
												default:
																printf("Wrong choice\n");
								}/*End of switch*/
				}/*End of while*/
}/*End of main()*/

void insertcr(int item)
{
				struct nodecr *tmp;
				tmp=(struct nodecr *)malloc(sizeof(struct nodecr));
				tmp->info=item;
				if(tmp==NULL)
				{
								printf("Memory not available\n");
								return;
				}

				if( isEmptycr() ) /*If queue is empty */
				{
								rear=tmp;
								tmp->link=rear;
				}
				else
				{
								tmp->link=rear->link;
								rear->link=tmp;
								rear=tmp;
				}
}/*End of insertcr()*/

delcr()
{
				int item;
				struct nodecr *tmp;
				if( isEmptycr() )
				{
								printf("Queue underflow\n");
								exit(1);
				}
				if(rear->link==rear)  /*If only one element*/
				{
								tmp=rear;
								rear=NULL;
				}
				else
				{
								tmp=rear->link;
								rear->link=rear->link->link;
				}
				item=tmp->info;
				free(tmp);
				return item;
}/*End of delcr()*/

int peekcr()
{
				if( isEmptycr() )
				{
								printf("Queue underflow\n");
								exit(1);
				}
				return rear->link->info;
}/* End of peekcr() */

int isEmptycr()
{
				if( rear == NULL )
								return 1;
				else
								return 0;
}/*End of isEmptycr()*/


void displaycr()
{
				struct nodecr *p;
				if(isEmptycr())
				{
								printf("Queue is empty\n");
								return;
				}
				printf("Queue is :\n");
				p=rear->link;
				do
				{
								printf("%d ",p->info);
								p=p->link;
				}while(p!=rear->link);
				printf("\n");
}/*End of displaycr()*/

