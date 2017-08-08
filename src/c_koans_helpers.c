#include "c_koans.h"
#include <string.h>

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