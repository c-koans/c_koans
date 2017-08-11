#include "c_koans.h"
#include <string.h>

int global_var = 0;

int string_compare(const void *s1, const void *s2) {
    /*
     * The comparison function must match the declaration in the prototype
     * exactly. This is why, even though we are comparing 2 strings, the
     * arguments must be void pointers.
     *
     * The actual arguments passed into this function is the address of each
     * element in the array, which in this case is a char **, this is why we
     * must cast the argument to a char ** and dereference it once for strcmp
     * to work.
     */
    return strcmp(*(char **)s1, *(char **)s2);
}

void double_an_int(int *i) {
	/* The '*' operator for dereference has a higher precedence than the other
	 * arithmetic operators, therefore it will be muliplying and assigning the
	 * int that is pointer to by i.
	 */
	*i *= 2;
}

int modify_global() {
    /*
     * We modify the global variable, located in the .data section,
     * visible to the entire program.
     */
    global_var++;
    return global_var;
}

int modify_local() {
    /*
     * We modify the local variable, located and initialzed on the stack.
     * every call, it will be initalized and modified in the same fashion.
     */
    int i = 0;
    i++;
    return i;
}

int modify_local_static() {
    /*
     * Local static variables will be initialized only once and be located
     * in the .data section. Local static variables can only be referenced
     * inside the function because the name will be known inside the function.
     * This causes the value of the variable to be preserved across function calls.
     */
    static int i = 0;
    i++;
    return i;
}