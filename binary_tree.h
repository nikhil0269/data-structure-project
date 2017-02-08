#include<stdio.h>
				void preordered(int tree[],int n,int k)
{if(k>n)
				return;
				if(tree[k]>1000)
								return;
				else
				{printf("%d\n",tree[k]);}
				preordered(tree,n,2*k);
				preordered(tree,n,2*k+1);
}
				void inordered(int tree[],int n,int k)
{if(k>n)
				return;

				if(tree[k]>1000)
								return;
				inordered(tree,n,2*k);
				if(tree[k]<=1000)
								printf("%d\n",tree[k]);
				inordered(tree,n,2*k+1);
}
				void postordered(int tree[],int n,int k)
{if(k>n)
				return;
				if(tree[k]>1000)
								return;
				postordered(tree,n,2*k);
				postordered(tree,n,2*k+1);
				if(tree[k]<=1000)
								printf("%d\n",tree[k]);}

int mainbintree()
{int n,i,j,data,data2;
				printf("enter the number of nodes\n");
				scanf("%d",&n);



				int tree[n+1];
				for(i=1;i<=n;i++)
								scanf("%d",&tree[i]);
				printf("\n\n");

				for(i=1;i<=n;i++)
								printf("%d\n",tree[i]);
				printf("\n\n");
				printf("preordre\n");
				preordered(tree,n,1);
				printf("\n");
				printf("postordered\n");
				postordered(tree,n,1);
				printf("\n");
				printf("inordered\n");
				inordered(tree,n,1);
				printf("the number whose ancestors required\n");
				scanf("%d",&data);
				for(j=1;j<=n+1;j++)
				{if(tree[j]==data)
								break;}

				while(j!=1)
				{j=j/2;
								printf("%d\n",tree[j]);


				}
				printf("the data whose decentent required\n");
				scanf("%d",&data2);
				for(i=1;i<=n+1;i++)
				{if(tree[i]==data);
								break;}
				preordered(tree,n,i);


}
