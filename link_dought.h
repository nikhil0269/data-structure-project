#include<stdio.h>
struct node
{
	int info;
		struct node *prev;
		struct node *next;
		
		};
struct node *addtoempty2(struct node *start,int data);
struct node *addatbeg2(struct node *start,int data);
struct node *reverse2(struct node *start);
void fun2()
{
				struct node *start=NULL;
				int ch,data,item,pos;

				while(1)
				{
								printf("1.Create List\n");
								printf("2.Display\n");
								printf("3.Search\n");
								printf("4. Add at beginning\n");
								printf("5.Add at end\n");
								printf("6.Add after node\n");
								printf("7.Add before node\n");
								printf("8.Add at position\n");
								printf("9.Delete\n");
								printf("10.Reverse\n");
								printf("Enter your choice : ");
								scanf("%d",&ch);

								switch(ch)
								{
												case 1:
																start=create_list2(start);
																break;
												case 2:
																display2(start);
																break;
												case 3:
																printf("Enter the element to be searched : ");
																scanf("%d",&data);
																search2(start,data);
																break;
												case 4:
																printf("Enter the element to be inserted : ");
																scanf("%d",&data);
																start=addatbeg2(start,data);
																break;
												case 5:
																printf("Enter the element to be inserted : ");
																scanf("%d",&data);
																start=addatend2(start,data);
																break;
												case 6:
																printf("Enter the element to be inserted : ");
																scanf("%d",&data);
																printf("Enter the element after which to insert : ");
																scanf("%d",&item);
																start=addafter2(start,data,item);
																break;
struct node *create_list2(struct node *start) 
{ 
				int i,n,data; 
				printf("Enter the number of nodes : "); 
				scanf("%d",&n); 
				start=NULL; 
				if(n==0) 
								return start; 
				printf("Enter the element to be inserted : "); 
				scanf("%d",&data); 
				start=addtoempty2(start,data); 

				for(i=2;i<=n;i++) 
				{ 
								printf("Enter the element to be inserted : "); 
								scanf("%d",&data); 
								start=addatend2(start,data);	 
				} 
				return start;}
				void display2(struct node *start) 
				{ 
								struct node *p; 
								if(start==NULL) 
								{ 
												printf("List is empty\n"); 
												return; 
								} 
								p=start; 
								printf("List is :\n"); 
								while(p!=NULL) 
								{ 
												printf("%d ",p->info); 
												p=p->next; 
								} 
								printf("\n");
								struct node *addtoempty2(struct node *start,int data) 
								{ 
												struct node *tmp; 
												tmp=(struct node *)malloc(sizeof(struct node)); 
												tmp->info=data; 
												tmp->prev=NULL; 
												tmp->next=NULL; 
												start=tmp; 
												return start;
												struct node *addatbeg2(struct node *start,int data) 
												{ 
																struct node *tmp; 
																tmp = (struct node *)malloc(sizeof(struct node)); 
																tmp->info=data; 
																tmp->prev=NULL; 
																tmp->next=start; 
																start->prev=tmp; 
																start=tmp; 
																return start;
																struct node *addatend2(struct node *start,int data) 
																{ 
																				struct node *tmp,*p; 
																				tmp=(struct node *)malloc(sizeof(struct node)); 
																				tmp->info=data; 
																				p=start; 
																				while(p->next!=NULL) 
																								p=p->next; 
																				p->next=tmp; 
																				tmp->next=NULL; 
																				tmp->prev=p; 
																				return start;
																				struct node *addafter2(struct node *start,int data,int item) 
																				{ 
																								struct node *tmp,*p; 
																								tmp=(struct node *)malloc(sizeof(struct node)); 
																								tmp->info=data; 
																								p=start; 
																								while(p!=NULL) 
																								{ 
																												if(p->info==item) 
																												{ 
																																tmp->prev=p; 
																																tmp->next=p->next; 
																																if(p->next!=NULL) 
																																				p->next->prev=tmp; 
																																p->next=tmp; 
																																return start;	 
																												} 
																												p=p->next; 
																								} 
																								printf("%d not present in the list\n\n",item); 
																								return start;
																								struct node *addbefore2(struct node *start,int data,int item) 
																								{ 
																												struct node *tmp,*q; 
																												if(start==NULL ) 
																												{ 
																																printf("List is empty\n"); 
																																return start; 
																												} 
																												if(start->info==item) 
																												{ 
																																tmp = (struct node *)malloc(sizeof(struct node)); 
																																tmp->info=data; 
																																tmp->prev=NULL; 
																																tmp->next=start; 
																																start->prev=tmp; 
																																start=tmp; 
																																return start; 
																												} 
																												q=start; 
																												while(q!=NULL) 
																												{ 
																																if(q->info==item) 
																																{ 
																																				tmp=(struct node *)malloc(sizeof(struct node)); 
																																				tmp->info=data; 
																																				tmp->prev=q->prev; 
																																				tmp->next = q; 
																																				q->prev->next=tmp; 
																																				q->prev=tmp; 
																																				return start; 
																																}	 
																																q=q->next; 
																												} 
																												printf("%d not present in the list\n",item); 
																												return start;
																												struct node *del2(struct node *start,int data) 
																												{ 
																																struct node *tmp; 
																																if(start==NULL) 
																																{ 
																																				printf("List is empty\n"); 
																																				return start; 
																																} 
																																if(start->next==NULL)	/*only one node in the list*/ 
																																				if(start->info==data) 
																																				{ 
																																								tmp=start; 
																																								start=NULL; 
																																								free(tmp); 
																																								return start; 
																																				} 
																																				else 
																																				{ 
																																								printf("Element %d not found\n",data); 
																																								return start; 
																																				} 

																																if(start->info==data) 
																																{ 
																																				tmp=start; 
																																				start=start->next;  
																																				start->prev=NULL; 
																																				free(tmp); 
																																				return start; 
																																} 

																																tmp=start->next; 
																																while(tmp->next!=NULL ) 
																																{ 
																																				if(tmp->info==data)     
																																				{ 
																																								tmp->prev->next=tmp->next; 
																																								tmp->next->prev=tmp->prev; 
																																								free(tmp); 
																																								return start; 
																																				} 
																																				tmp=tmp->next; 
																																} 

																																if(tmp->info==data) 
																																{ 
																																				tmp->prev->next=NULL; 
																																				free(tmp); 
																																				return start; 
																																} 
																																printf("Element %d not found\n",data); 
																																return start; 
																												}

																												struct node *reverse2(struct node *start) 
																												{ 
																																struct node *p1,*p2; 
																																p1=start; 
																																p2=p1->next; 
																																p1->next=NULL; 
																																p1->prev=p2; 
																																while(p2!=NULL) 
																																{ 
																																				p2->prev=p2->next; 
																																				p2->next=p1; 
																																				p1=p2; 
																																				p2=p2->prev; 
																																} 
																																start=p1; 
																																printf("List reversed\n"); 
																																return start; 
																												}

