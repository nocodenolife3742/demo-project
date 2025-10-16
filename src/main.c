#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void null_deref()
{
    int *p = NULL;
    *p = 42;
}

void heap_overflow()
{
    char *heap_buf = malloc(10);
    heap_buf[10] = 'a';
    free(heap_buf);
}

void stack_overflow()
{
    char stack_buf[10];
    stack_buf[10] = 'a';
}

void div_zero()
{
    int x = 1;
    int y = 0;
    int z = x / y;
}

void example_snippet(const char *input)
{
    if (strncmp(input, "a", 1) == 0)
    {
        null_deref();
    }
    if (strncmp(input, "b", 1) == 0)
    {
        heap_overflow();
    }
    if (strncmp(input, "c", 1) == 0)
    {
        stack_overflow();
    }
    if (strncmp(input, "d", 1) == 0)
    {
        div_zero();
    }
}

int main(int argc, char *argv[])
{
    // read input from argv[1]
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    // read file content
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
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