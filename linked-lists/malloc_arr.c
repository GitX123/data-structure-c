#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0; // num of elements
    int *arr; // pointer of array

    printf("Number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));
    if(!arr) {
        printf("Memory allocation failed.");
        return 1;
    }

    for(int i=0; i<n; i++) {
        printf("Element %d = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray content: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}