#include<stdio.h>
#include<stdlib.h>
int is_emptyb();
int n;
struct nodeB
{
struct nodeB*lchild;
int data;
struct nodeB*rchild;
};

typedef struct nodeB sn;

void insertB(sn**bt,int val)
{
if(*bt==NULL)
{
*bt=(sn*)malloc(sizeof(sn));
(*bt)->lchild=NULL;
(*bt)->rchild=NULL;
(*bt)->data=val;
}
else
{
if(val<((*bt)->data))
{
insertB(&((*bt)->lchild),val);
}
else
{
insertB(&((*bt)->rchild),val);
}
}

}

void inorderB(sn*root)
{
if(root==NULL)
{
return;
}
inorderB(root->lchild);
printf("%d ",root->data);
inorderB(root->rchild);
}

void preorderB(sn*root)
{
if(root==NULL)
return ;
printf("%d ",root->data);
preorderB(root->lchild);
preorderB(root->rchild);
}

void postorderB(sn*root)
{
if(root==NULL)
return ;
postorderB(root->lchild);
postorderB(root->rchild);
printf("%d ",root->data);
}
int f,r;
sn* queue[100];
f=-1;r=-1;

void ins_q(sn*node)
{
if(r==99)
printf("queue overflow\n");
if(f==-1)
f=0;
r++;
queue[r]=node;
}

sn* del_q()
{
sn*node;
if(is_emptyb())
printf("underflow\n");
node=queue[f];
f++;
return node;
}

int is_emptyb()
{
if((f==-1)||(f==r+1))
return 1;
else return 0;
}
void levelorderB(sn*root)                     //level order traversing
{
if(root!=NULL)
printf("%d ",root->data);
ins_q(root);
while(1)
{
root=del_q();
if(root->lchild!=NULL)
{
printf("%d ",root->lchild->data);
ins_q(root->lchild);
}
if(root->rchild!=NULL)
{
printf("%d ",root->rchild->data);
ins_q(root->rchild);
}
if(is_emptyb())
break;
}
}

sn* searchB(sn*root,int val)                            // searchB in binary tree
{
if(root==NULL)
return NULL ;
if(val==root->data)
{
//printf("%d is in the tree",val);
return root;
}
else if(val<root->data)
return searchB(root->lchild,val);
else
return searchB(root->rchild,val);
} 

void mainB()
{
int i,val,num;
sn*bt,*searchB_node;
bt=NULL;    //empty tree
printf("Enter no. of nodes you want to insertB\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter value: ");
scanf("%d",&val);
insertB(&bt,val);
}
printf("preorderB traversing is :");
preorderB(bt);

printf("postorderB traversing is :");
postorderB(bt);

printf("inorderB traversing is :");
inorderB(bt);

printf("Level order traversing is :");
levelorderB(bt);

//printf("Enter a number you want to searchB in the binary tree : ");
//scanf("%d",&num);
//searchB_node=searchB(bt,num);
//printf("number :%d ",searchB_node->data);


}
