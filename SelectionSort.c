#include <stdio.h>
void SelectionSort(int arr[], int length)
{
	int comp = 0, swap = 0; 
	for(int i = 0; i < length - 1; i++)
	{
		int min = i;
		int temp = arr[i];
		for(int j = i+1; j < length; j++)
		{
			comp++;
			if(arr[min] > arr[j])
				min = j;
		}
		if(arr[i] != arr[min])
			swap++;
		arr[i] = arr[min];
		arr[min] = temp;
	}
	for(int k = 0; k < length; k++)
		printf("%d ",arr[k]);
	printf("\nComparisons: %d\n", comp);
	printf("Swaps: %d\n", swap);
}

int main()
{
	int t;
	printf("Test cases: ");
	scanf("%d", &t);
	while(t--)
	{
		int n;
		printf("Size: ");
		scanf("%d", &n);
		int arr[n];
		printf("Enter elements: ");
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		SelectionSort(arr, n);
	}
	return 0;
}
		
