#include <stdio.h>

#define ABC 5

#define CODE \
    printf("preprocessed print.");

// Iterative PPD.
#define LOOP(v, s, e) for (int v = s; v <= e; v++) {
#define ENDLOOP }

#define PRINT(a) printf("Looping through %d.\n", a);

// Variadic PPD.
#define LOG_ERROR(format, ...) \
    fprintf(stderr, format, __VA_ARGS__)

// Nested Loop PPDs.
#define LOOP_2(X, ...) \
    printf("%s\n", #X);\

#define LOOP_1(X, ...) \
    printf("%s\n", #X);\
    LOOP_2(__VA_ARGS__)

int main(int argc, char** argv)
{
    int x = 2;
    int y = ABC;
    int z = x + y;
    printf("Result is: %d\n", z);

    CODE
    LOOP(counter, 1, 10)
        PRINT(counter)
    ENDLOOP

    LOG_ERROR("This is a text error: %d\n", 404);

    LOOP_1(copy, paste)

    // Conditional Compilation
    //#define CONDITION // Uncommenting this line will change the output.
    // Allowing this macro during compile time: 'gcc -DCONDITION -E macros.c'
    #ifndef CONDITION
        printf("Condition is not set!\n");
    #endif
    #ifdef CONDITION
        printf("Condition is set!\n");
    #endif

    return 0;
}

void test_func()
{
    printf("This is a test function. \n");
}