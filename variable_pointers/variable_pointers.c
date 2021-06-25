#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 3


void print_bytes(void* data, size_t length);
int* create_int_at_stack(int default_value);


int main(int argc, char** argv)
{
    int var = 100;
    int* ptr = 0;
    ptr = &var;
    *ptr = 5;
    printf("%d\n", var);

    // Array iteration via pointers.
    int arr[ARR_SIZE];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    int* arrPtr = &arr[0];
    //int* arrPtr = arr; // Alternative to upper line.
    while(1)
    {
        if(arrPtr == &arr[ARR_SIZE])
            break;
        printf("Mem address of array item %d: %u\n", *arrPtr, arrPtr);
        arrPtr++;
    }

    // Generic pointers. (void*)
    int i1 = 9;
    double d1 = 18.9;

    print_bytes(&i1, sizeof(int));
    print_bytes(&d1, sizeof(double));

    int* stack_integer = NULL;
    stack_integer = create_int_at_stack(50);

    printf("Stack integer value is: %d", *stack_integer);
    free(stack_integer);

    return 0;
}

void print_bytes(void* data, size_t length)
{
    char delim = ' ';
    unsigned char* ptr = data;
    
    for(size_t i = 0; i < length; i++)
    {
        printf("%c 0x%x", delim, *ptr);
        ptr++;
    }
    printf("\n");
}

int* create_int_at_stack(int default_value)
{
    int* var_ptr = (int*) malloc(sizeof(int));
    *var_ptr = default_value;
    return var_ptr;
}

