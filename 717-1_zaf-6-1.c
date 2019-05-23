#include <stdio.h>

int sorting_function(int *arr, int arr_len) {
	if (arr && arr_len) 
    	{
		int jump = arr_len;
		int swapped = 1;
		while (jump > 1) 
		{
			if (jump > 1)
				jump /= 1.2473309;
			for (int i = 0; i + jump < arr_len; ++i)
			{
				if (arr[i + jump] > arr[i]) 
				{
					int tmp;
					tmp = arr[i];
					arr[i] = arr[i + jump];
					arr[i +	jump] = tmp;
				}
			}
		}
    	}
	return 1;	
}

int main() {
	int n;
	scanf("%d", &n);	
	if (n == 0) return 0;
	int arr[n];
	for (int i=0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sorting_function(arr, n);
	printf("%d", arr[n-1]);
	for (int i=n-2; i >= 0; i--) {
		printf(" %d", arr[i]);
	}
	printf("\n");
	return 0;
}

