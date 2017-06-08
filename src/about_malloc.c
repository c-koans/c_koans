#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdlib.h>

int* malloc_func() {
	int* return_ptr = malloc(sizeof(int));
	*return_ptr = 15;
	return return_ptr;
}

Test(c_koans, malloc_intro) {
	/*
     * In C, there are 2 ways to allocate space for a variable:
     * 1. int i = 5; This allocates sizeof(int) bytes on the stack.
     * 2. int* i = malloc(sizeof(int)). malloc (from stdlib.h) allocates a specified number of bytes on the heap and returns a void pointer to the beginning of the allocated space. If a malloc call is successful, it is guaranteed that the space has as least as many bytes that were requested. If it isn't (e.g. no more heap space), malloc sets the errno and returns NULL. malloc does not clear out the space it returns, so it's unsafe to make any assumptions about the contents. Type 'man malloc' into your terminal to find out more.
     */
	int* i = malloc(sizeof(int));
	*i = 5;
	cr_assert_eq(*i, 6);

	/*
     * If you allocate space for a variable on the stack in a function call, it'll be allocated in the function's stack frame. This means the space won't be valid after the function returns.
     * Space that was malloc'ed, however, is valid after functions return because it is allocated on the heap. Therefore, functions that need to return new pointers should allocate space for them using malloc.
     */
	int* return_ptr = malloc_func(); // goto line 5
	cr_assert_eq(*return_ptr, 15);


}
