#include <stdio.h>
int main() {
    int n, i, num;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to delete: ");
    scanf("%d", &num);

    int found = 0;   // instead of pos = -1

    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            found = 1;
            break;   // stop at first match
        }
    }

    if(!found) {
        printf("Element not found!\n");
    } else {
        for(int j = i; j < n-1; j++)
            arr[j] = arr[j+1];
        n--; // reduce array size

        printf("Array after deletion: ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
