#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void saxpy(size_t n, float alpha, const float x[n], float y[restrict n]);

#define MAX_SIZE 20
float x[MAX_SIZE];
float y[MAX_SIZE];

// Helper function to fill arrays with random values
void fill_array(float* array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        array[i] = (float)(rand() % 100 - 50) / 10.0f; // Random floats in range [-5.0, 5.0]
    }
}

// Helper function to print arrays
void print_array(const char* name, const float* array, size_t n) {
    printf("%s: ", name);
    for (size_t i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Declaration of the `saxpy` assembly function
// void saxpy(size_t n, float alpha, const float x[n], float y[n]);
extern void saxpy(size_t n, float alpha, const float* x, float* y);

int main(int argc, char** argv) {
    size_t n = 10; // Default number of elements
    float alpha = 2.5f; // Scaling factor for SAXPY

    // Adjust size via command-line argument
    if (argc > 1) {
        n = strtoul(argv[1], NULL, 0);
        if (n > MAX_SIZE) n = MAX_SIZE; // Limit to MAX_SIZE
    }

    // Seed random number generator and fill test arrays
    srand((unsigned int)time(NULL));
    fill_array(x, n);
    fill_array(y, n);

    // Print initial values
    printf("Initial arrays:\n");
    print_array("x", x, n);
    print_array("y", y, n);

    // Call the SAXPY function
    saxpy(n, alpha, x, y);

    // Print results
    printf("\nAfter SAXPY (y = %.2f * x + y):\n", alpha);
    print_array("y", y, n);

    return EXIT_SUCCESS;
}