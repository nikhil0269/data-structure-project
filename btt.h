

typedef enum {false,true} boolean;

struct node1 *in_succ(struct node1 *p);
struct node1 *in_pred(struct node1 *p);
struct node1 *insertbtt(struct node1 *root, int ikey);
struct node1 *del(struct node1 *root, int dkey);
struct node1 *case_a(struct node1 *root, struct node1 *par,struct node1 *ptr);
struct node1 *case_b(struct node1 *root,struct node1 *par,struct node1 *ptr);
struct node1 *case_c(struct node1 *root, struct node1 *par,struct node1 *ptr);

void inorderbtt( struct node1 *root);
void preorder( struct node1 *root);

struct node1
{
				struct node1 *left;
				boolean lthread;
				int info;
				boolean rthread;
				struct node1 *right;
};

void mainbtt( )
{
				int choice,num;
				struct node1 *root=NULL;

				while(1)
				{
								printf("\n");
								printf("1.Insert\n");
								printf("2.Delete\n");
								printf("3.Inorder Traversal\n");
								printf("4.Preorder Traversal\n");
								printf("5.Quit\n");
								printf("Enter your choice : ");
								scanf("%d",&choice);

								switch(choice)
								{
												case 1:
																printf("Enter the number to be inserted : ");
																scanf("%d",&num);
																root = insertbtt(root,num);
																break;
												case 2:
																printf("Enter the number to be deleted : ");
																scanf("%d",&num);
																root = del(root,num);
																break;
												case 3:
																inorderbtt(root);
																break;
												case 4:
																preorder(root);
																break;
												case 5:
																exit(1);
												default:
																printf("Wrong choice\n");
								}/*End of switch */
				}/*End of while */
}/*End of main( )*/

struct node1 *insertbtt(struct node1 *root, int ikey)
{       
				struct node1 *tmp,*par,*ptr;

				int found=0;

				ptr = root;
				par = NULL;

				while( ptr!=NULL )
				{
								if( ikey == ptr->info)
								{
												found =1;
												break;
								}
								par = ptr;
								if(ikey < ptr->info)
								{
												if(ptr->lthread == false)
																ptr = ptr->left;	
												else 
																break;
								}
								else 
								{
												if(ptr->rthread == false)
																ptr = ptr->right;
												else 
																break;
								}
				}

				if(found)
								printf("Duplicate key");
				else
				{

								tmp=(struct node1 *)malloc(sizeof(struct node1));
								tmp->info=ikey;
								tmp->lthread = true;
								tmp->rthread = true;
								if(par==NULL)
								{
												root=tmp;
												tmp->left=NULL;
												tmp->right=NULL;
								}
								else if( ikey < par->info )
								{
												tmp->left=par->left;
												tmp->right=par;
												par->lthread=false;
												par->left=tmp;
								}
								else
								{
												tmp->left=par;
												tmp->right=par->right;
												par->rthread=false;
												par->right=tmp;
								}	
				}
				return root;
}/*End of insert( )*/

struct node1 *del(struct node1 *root, int dkey)
{
				struct node1 *par,*ptr;

				int found=0;

				ptr = root;
				par = NULL;

				while( ptr!=NULL)
				{
								if( dkey == ptr->info)
								{
												found =1;
												break;
								}
								par = ptr;
								if(dkey < ptr->info)
								{
												if(ptr->lthread == false)
																ptr = ptr->left;	
												else 
																break;
								}
								else 
								{
												if(ptr->rthread == false)
																ptr = ptr->right;
												else 
																break;
								}
				}

				if(found==0)
								printf("dkey not present in tree");
				else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
								root = case_c(root,par,ptr);	
				else if(ptr->lthread==false )/*only left child*/
								root = case_b(root, par,ptr);
				else if(ptr->rthread==false)/*only right child*/
								root = case_b(root, par,ptr);
				else /*no child*/
								root = case_a(root,par,ptr);
				return root;
}/*End of del( )*/

struct node1 *case_a(struct node1 *root, struct node1 *par,struct node1 *ptr )
{
				if(par==NULL) /*root node to be deleted*/
								root=NULL;
				else if(ptr==par->left)
				{
								par->lthread=true;
								par->left=ptr->left;
				}
				else
				{
								par->rthread=true;
								par->right=ptr->right;
				}
				free(ptr);
				return root;
}/*End of case_a( )*/

struct node1 *case_b(struct node1 *root,struct node1 *par,struct node1 *ptr)
{
				struct node1 *child,*s,*p;

				/*Initialize child*/
				if(ptr->lthread==false) 
								child=ptr->left;
				else                
								child=ptr->right;


				if(par==NULL )   
								root=child;
				else if( ptr==par->left) 
								par->left=child;
				else                     
								par->right=child;

				s=in_succ(ptr);
				p=in_pred(ptr);

				if(ptr->lthread==false) /*if ptr has left subtree */
								p->right=s;
				else                         
				{
								if(ptr->rthread==false) /*if ptr has right subtree*/
												s->left=p;
				}

				free(ptr);
				return root;
}
struct node1 *case_c(struct node1 *root, struct node1 *par,struct node1 *ptr)
{
				struct node1 *succ,*parsucc;
				parsucc = ptr;
				succ = ptr->right;
				while(succ->left!=NULL)
				{
								parsucc = succ;
								succ = succ->left;
				}

				ptr->info = succ->info;

				if(succ->lthread==true && succ->rthread==true)
								root = case_a(root, parsucc,succ);
				else	
								root = case_b(root, parsucc,succ);
				return root;
}
struct node1 *in_succ(struct node1 *ptr)
{
				if(ptr->rthread==true)
								return ptr->right; 
				else
				{
								ptr=ptr->right;
								while(ptr->lthread==false)
												ptr=ptr->left;
								return ptr;
				}
}
struct node1 *in_pred(struct node1 *ptr)
{
				if(ptr->lthread==true)
								return ptr->left;
				else
				{
								ptr=ptr->left;
								while(ptr->rthread==false)
												ptr=ptr->right;
								return ptr;
				}
}

void inorderbtt( struct node1 *root)
{
				struct node1 *ptr;
				if(root == NULL )
				{
								printf("Tree is empty");
								return;
				}

				ptr=root;
				/*Find the leftmost node */
				while(ptr->lthread==false)
								ptr=ptr->left;

				while( ptr!=NULL )
				{
								printf("%d ",ptr->info);	
								ptr=in_succ(ptr);
				} 
}

void preorder(struct node1 *root )
{
				struct node1 *ptr;
				if(root==NULL)
				{
								printf("Tree is empty");
								return;
				}
				ptr=root;

				while(ptr!=NULL)
				{
								printf("%d ",ptr->info);
								if(ptr->lthread==false)
												ptr=ptr->left;
								else if(ptr->rthread==false)
												ptr=ptr->right;
								else
								{
												while(ptr!=NULL && ptr->rthread==true)
																ptr=ptr->right;
												if(ptr!=NULL)
																ptr=ptr->right;
								}
				}
}









