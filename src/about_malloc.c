#include "c_koans.h"
#include <stdbool.h>
#include <stdlib.h>

int *malloc_func()
{
    int *return_ptr = malloc(sizeof(int));
    *return_ptr = 15;
    return return_ptr;
}

Test(about_malloc, malloc_intro)
{
    /*
        In C, there are 2 ways to allocate space for a variable:
        1. int i = 5; This allocates sizeof(int) bytes on the stack.

        2. int* i = malloc(sizeof(int)).
        malloc (from stdlib.h) allocates a
        specified number of bytes on the heap and returns a void pointer to the
        beginning of the allocated space. If a malloc call is successful, it is
        guaranteed that the space has as least as many bytes that were requested
        If it isn't (e.g. no more heap space), malloc sets the errno and returns
        NULL. malloc does not clear out the space it returns, so it's unsafe to
        make any assumptions about the contents.

        Type 'man malloc' into your terminal to find out more.
    */
    int *i = malloc(sizeof(int));
    *i = 5;
    cr_assert_eq(*i, TODO, "What is the value of i on the heap?");

    /*
        If you allocate space for a variable on the stack in a function call,
        it'll be allocated in the function's stack frame. This means the space
        won't be valid after the function returns.

        Space that was malloc'ed, however, is valid after functions return
        because it is allocated on the heap. Therefore, functions that need
        to return new pointers should allocate space for them using malloc.
    */
    int *return_ptr = malloc_func(); /* goto line 6 */
    cr_assert_eq(*return_ptr, TODO, "What is the value of return_ptr on the heap?");
}

Test(about_malloc, free)
{
    /*
        Dynamic memory in C is manually managed.

        This means that every time you malloc for space on the heap, you have to
        also free that memory, or else your program will have a memory leak.
    */

    int *ip = malloc(sizeof(int));

    *ip = 10;

    /*
        The free function takes a void* as an argument and silently does the
        operation, not returning any value.
        The only constraint for this function is that the pointer must be valid:
        the pointer must have been returned by a previous call to the an alloc
        function, and the pointer must not point to space that has already been
        freed.
        The pointer may be NULL. This will cause free to not do anything and
        return.
    */
    free(ip);

    /*
        Since we have just freed ip, it is a good idea to set ip to NULL to
        show that we are done using it.
    */
    ip = NULL;

    cr_assert_eq(
        ip, (void *)TODO_NZ, "What is ip now? What would happen if we \
        dereference ip?");
}

Test(about_malloc, calloc)
{
    /*
        The next function in the alloc family is calloc. Calloc does the same
        operation as malloc, but it initialized the memory to 0, meaning that
        every byte is 0x00.
    */

    char *s = calloc(10, sizeof(char));

    /*
        Calloc is very useful for initializing strings, since the initalized
        memory will be a valid C-string of length 0.
    */

    cr_assert_eq(strlen(s), TODO_NZ, "What is the length of an empty string?");
    strcpy(s, "foo");

    cr_assert_eq(strlen(s), TODO, "What is the new length?");
}

Test(about_malloc, realloc)
{
    /*
        The final function in the family of alloc functions is realloc.

        Realloc changes the size of a block to a larger or smaller size,
        preserving the bytes in the range of the previous size.

        Realloc may move the block entirely, and if it does this, the area
        that it was moved from is freed.
    */

    void *ip = malloc(sizeof(int));
    *(int *)ip = 0xDEADBEEF;

    ip = realloc(ip, sizeof(long));

    cr_assert_eq(
        *(unsigned long *)ip, TODO, "What bytes of ip were preserved \
        when it is increased in size?");

    ip = realloc(ip, sizeof(short));

    /* Hint: our VMs are little endian */
    cr_assert_eq(*(unsigned short *)ip, TODO, "What bytes were preserved now?");
}
