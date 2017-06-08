#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is a function prototype. A function prototype is a way for our program 
 * to know about the function without it actually being implemented. 
 */
static int string_compare(const void *, const void *);

Test(c_koans, function_pointers) {
    /* Declaration of an array of strings and the sorted equivalent */
    size_t array_size = 5;
    char *names[] = {"Spike", "Ein", "Jet", "Ed", "Faye"};
    char *ordered_names[] = {"Ed", "Ein", "Faye", "Jet", "Spike"};

    /*
     * Function pointers are a tricky notion to handle for beginner C 
     * programmers, but with a little practice you should be able to understand      * how they work.
     * 
     * To display function pointers, we will examine the usage of the C stdlib
     * function qsort, quicksort.
     * 
     * To start, we will examine the function prototype for qsort:
     *
     * void qsort(void *base, size_t nmemb, size_t size,
     *             int (*compar)(const void *, const void *));
     * 
     * base: This is your array.
     * nmemb: This is the number of elements in your array.
     * size: This is the size of each element in your array.
     * compar: This is the function pointer for the comparison function 
     *
     * Now, compar itself has a very tricky declaration, and we will dissect it.
     * 
     * int (*compar)(const void *, const void *)
     *
     * In plain English, this declaration means: "A pointer to a function that 
     * takes two const void pointers as arguments, and returns an int"
     * 
     * The key to the declaration is (*compar). This signifies that this is a 
     * function pointer. If *compar was not in parens, compar would be read by 
     * the compiler as a pointer to an int. With them, it is read as a function
     * that returns an int.
     *
     * The next key is the (const void *, const void *). This signifies the 
     * arguments of the function being pointed to.
     *
     * To test your knowledge, you will now write the line of code to call qsort
     * to sort the array declared earlier. We have provided a comparison 
     * function for strings that can be used by qsort.
     */

    // write the line of code to sort names here!   
    
    cr_assert(strcmp(names[0], ordered_names[0]) == 0,
	      "Names are not sorted. Try again!");
}

static int string_compare(const void *s1, const void *s2) {
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
