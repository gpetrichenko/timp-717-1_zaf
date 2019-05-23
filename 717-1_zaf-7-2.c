#include <stdio.h>

void siftDown(int *array, int root, int bottom){
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (array[root * 2] > array[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (array[root] < array[maxChild]) {
            int temp = array[root];
            array[root] = array[maxChild];
            array[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void heap_sorting(int *array, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        siftDown(array, i, n - 1);
    for (int i = n - 1; i >= 1; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        siftDown(array, 0, i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    heap_sorting(array, n);
    printf("%d", array[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", array[i]);
    printf("\n");
    return 0;
}

