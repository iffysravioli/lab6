
#include <stdio.h>
#include <stdlib.h>

// Task 1: Comparer function for qsort
int comparer(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    return (int_a > int_b) - (int_a < int_b);
}

// Test data array and qsort demonstration (example implementation)
void sort_demo() {
    int array[] = {3, 10, 2, 8, 1, 6, 0, 4, 14};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    
    qsort(array, array_size, sizeof(int), comparer);

    printf("Sorted array:\n");
    for (size_t i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Task 2: Function Pointer based operation selector without conditionals
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    // Run Task 1 demo
    printf("Running Task 1 - qsort with comparer function:\n");
    sort_demo();

    // Task 2
    int a = 6, b = 3;
    int (*operations[4])(int, int) = { add, subtract, multiply, divide };

    printf("Running Task 2:\n");
    printf("Operand ‘a’ : %d | Operand ‘b’ : %d\n", a, b);
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
    
    char choice;
    scanf(" %c", &choice);

    if (choice >= '0' && choice <= '3') {
        int result = operations[choice - '0'](a, b);
        printf("Result: %d\n", result);
    } else if (choice == '4') {
        printf("Exiting program.\n");
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}