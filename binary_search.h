

int BinarySearch(int arr[], int n, int item); 

void mainbinary() 
{ 
				int i, n, item, arr[MAX2], index; 
				printf("Enter the number of elements : "); 
				scanf("%d",&n); 
				printf("Enter the elements : \n"); 
				for(i=0; i<n; i++) 
								scanf("%d", &arr[i] ); 

				printf("Enter the item to be searched : "); 
				scanf("%d", &item); 

				index = BinarySearch(arr, n, item); 

				if(index == -1) 
								printf("%d not found in array\n", item); 
				else 
								printf("%d found at position %d\n", item, index); 
}

int BinarySearch(int arr[], int size, int item) 
{ 
				int low=0, up=size-1, mid; 
				while(low<=up) 
				{ 
								mid = (low+up)/2; 
								if(item>arr[mid]) 
												low = mid+1;
								else if(item<arr[mid]) 
												up = mid-1;		
								else 
												return mid; 
				} 
				return -1; 
} 
