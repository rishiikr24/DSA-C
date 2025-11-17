#include <stdio.h>
#include <stdlib.h>
int* insert(int* arr, int n, int pos, int val);
int* delete_element(int* arr, int n, int pos);
void print_array(int* arr, int n);

int main() {
    int n, pos, val;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position and value to insert: ");
    scanf("%d %d", &pos, &val);
    arr = insert(arr, n, pos, val);
    if (arr != NULL) {
        n++; 
        printf("\nArray after insertion: ");
        print_array(arr, n);
    } else {
        return 1; 
    }
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    arr = delete_element(arr, n, pos);
    if (arr != NULL) {
        n--; 
        printf("Array after deletion: ");
        print_array(arr, n);
    } else {
        return 1; 
    }
    free(arr);
    return 0;
}


int* insert(int* arr, int n, int pos, int value) {
    
    if (pos < 0 || pos > n) {
        printf("Error: Invalid position for insertion.\n");
        return arr; 
    }
    int* temp = (int*)realloc(arr, (n + 1) * sizeof(int));
    if (temp == NULL) {
        printf("Error: Memory reallocation failed during insert!\n");
        // free(arr); // yeha pe free krna pr sakhta hai 
        return NULL; 
    }
    arr = temp;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;

    return arr; 
}

int* delete_element(int* arr, int n, int pos) {
    
    if (pos < 0 || pos >= n) {
        printf("Error: Invalid position for deletion.\n");
        return arr; 
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    int* temp = (int*)realloc(arr, (n - 1) * sizeof(int));
    if (temp == NULL && (n - 1) > 0) { 
        printf("Error: Memory reallocation failed during delete!\n");
        // free(arr);
        return NULL; 
    }
    arr = temp;

    return arr; 
}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}