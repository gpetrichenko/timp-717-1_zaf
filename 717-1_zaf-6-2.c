#include <stdio.h>

void Shell(int *arr, int arr_len)
{
    int i, j, tmp;
    for (int step = arr_len / 2; step > 0; step /= 2)
        for (i = step; i < arr_len; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
}
 
int main()
{
	int n;
	scanf("%d", &n);	
	if (n == 0) return 0;
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	Shell(arr, n);
	printf("%d", arr[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
	return 0;
}
