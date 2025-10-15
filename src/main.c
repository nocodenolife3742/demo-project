#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASAN: Null pointer dereference
void asan_null_deref() {
    int *p = NULL;
    *p = 42;
}

// ASAN: Heap buffer overflow
void asan_heap_overflow() {
    char *heap_buf = malloc(10);
    heap_buf[10] = 'a'; // overflow
    free(heap_buf);
}

// ASAN: Stack buffer overflow
void asan_stack_overflow() {
    char stack_buf[10];
    stack_buf[10] = 'a'; // overflow
}

// ASAN: Use after free
void asan_use_after_free() {
    char *uaf_buf = malloc(10);
    free(uaf_buf);
    uaf_buf[0] = 'a'; // use after free
}

// UBSAN: Signed integer overflow
void ubsan_int_overflow() {
    int k = 0x7fffffff;
    k++;
}

// UBSAN: Division by zero
void ubsan_div_zero() {
    int x = 1;
    int y = 0;
    int z = x / y;
    (void)z; // Suppress unused variable warning
}

// UBSAN: Shift out of bounds
void ubsan_shift_oob() {
    int x = 1;
    int y = x << 32; // Assuming 32-bit int
    (void)y; // Suppress unused variable warning
}

void example_snippet(const char *input) {
    asan_null_deref();
    asan_heap_overflow();
    asan_stack_overflow();
    asan_use_after_free();
    ubsan_int_overflow();
    ubsan_div_zero();
    ubsan_shift_oob();
}

int main(int argc, char *argv[]) {
    // read input from argv[1]
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    // read file content
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char buffer[256];
    size_t len = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[len] = '\0';
    fclose(file);
    example_snippet(buffer);

    return 0;
}