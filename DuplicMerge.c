#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}	

void mergeSort(int arr[], int l, int r)
{
	if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int CheckDuplicate(int arr[], int low, int high, int length)
{
	mergeSort(arr, low, high);
	for(int i = 0; i < length; i++)
	{
		if(arr[i] == arr[i+1])
			return 1;
	}
	return 0;
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
		int result = CheckDuplicate(arr, 0, n - 1, n);
		if(result)
			printf("Duplicates found\n");
		else
			printf("No Duplicates found\n");
	}
	return 0;
}
