#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

float* x;
float* y;

void fill_array(float* array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        array[i] = (float)(rand() % 100 - 50) / 10.0f;
    }
}

void print_array(const char* name, const float* array, size_t n) {
    printf("%s: ", name);
    for (size_t i = 0; i < (n > 10 ? 10 : n); i++) {
        printf("%.2f ", array[i]);
    }
    if (n > 10) printf("...");
    printf("\n");
}

extern void saxpy(size_t n, float alpha, const float* x, float* y);

int main(int argc, char** argv) {
    size_t n = 1000000; // Default size
    float alpha = 2.5f;

    if (argc > 1) {
        n = strtoul(argv[1], NULL, 0);
    }

    x = malloc(n * sizeof(float));
    y = malloc(n * sizeof(float));
    if (!x || !y) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    srand((unsigned int)time(NULL));
    fill_array(x, n);
    fill_array(y, n);

    printf("Initial arrays (first 10 elements):\n");
    print_array("x", x, n);
    print_array("y", y, n);

    struct timeval start, end;
    gettimeofday(&start, NULL);
    saxpy(n, alpha, x, y);
    gettimeofday(&end, NULL);

    printf("\nAfter SAXPY (y = %.2f * x + y):\n", alpha);
    print_array("y", y, n);

    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
    printf("\nExecution time: %ld microseconds (%.3f milliseconds)\n", elapsed_time, elapsed_time / 1000.0);

    free(x);
    free(y);
    return EXIT_SUCCESS;
}
