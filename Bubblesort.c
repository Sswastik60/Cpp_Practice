#include <stdio.h>
//use bubble sort to arrange elements in ascending and descending order using switch case 

int main(){
    int n, i, j, temp, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Choose sorting order:\n1. Ascending\n2. Descending\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            for(i = 0; i < n-1; i++){
                for(j = 0; j < n-i-1; j++){
                    if(arr[j] > arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            printf("Array in ascending order: ");
            for(i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            break;
        case 2:
            for(i = 0; i < n-1; i++){
                for(j = 0; j < n-i-1; j++){
                    if(arr[j] < arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            printf("Array in descending order: ");
            for(i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}