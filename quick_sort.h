
#define MAXq 100
void quick(int arr[],int low,int up);
int partition(int arr[], int low, int up);
void mainquick()
{
				int arr[MAXq],n,i;

				printf("Enter the number of elements : ");
				scanf("%d",&n);

				for(i=0;i<n;i++)
				{
								printf("Enter element %d : ",i+1);
								scanf("%d",&arr[i]);
				}

				quick(arr,0,n-1);

				printf("Sorted list is :\n");
				for(i=0;i<n;i++)
								printf("%d\n",arr[i]);
				printf("\n");

}

void quick(int arr[],int low,int up)
{
				int pivloc;
				printf("\n");

				if(low>=up)
								return ;

				pivloc = partition(arr,low,up);
				quick(arr,low,pivloc-1);
				quick(arr,pivloc+1,up);
}

int partition(int arr[], int low, int up)
{
				int temp,i,j,pivot;

				i=low+1;
				j=up;

				pivot=arr[low];
				while( i <= j )
				{
								while( (arr[i] < pivot) && (i<up) )
												i++;

								while( arr[j] > pivot )
												j--;

								if(i < j)
								{
												temp=arr[i];
												arr[i]=arr[j];
												arr[j]=temp;
												i++;
												j--;
								}
								else
								{
												i++;

								}

				}


				arr[low]=arr[j];
				arr[j]=pivot;

				return j;
}
