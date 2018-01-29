#include "c_koans.h"
#include <string.h>

Test(about_pointers, pointers_and_addresses)
{
    /*
     * Pointers are the trademark of the C language, and the largest mental
     * block of programmers of languages where they do not explicitly exist.
    */
    int i = 10;
    int j = 20;

    /* This is the syntax of the pointer declaration. It is a type name
     * followed by a '*' somewhere between the type name and the variable name.
     *
     * The '&' operator gives the address of a variable.
    */
    int *iptr = &i;
    int *jptr = &j;

    cr_assert_eq(
        sizeof(i), TODO, "What is the size of an int on a 64 bit machine?");
    cr_assert_eq(sizeof(iptr), TODO,
        "What is the size of an address on a 64 bit machine?");

    /* The '*' operator has another meaning when used not in a declaration to
     * 'dereference' a pointer, and give the value at that address.
    */

    cr_assert_eq(*jptr, TODO, "What is the value that jptr 'points' to?");

    /*
     * Multi-variable declarations mixing pointers and the type it points to
     * can be hard to interpret depending on your choice of position for the
     * '*'.
    */

    /* DON'T DELETE THE CLANG-FORMAT LINES */
    /* clang-format off */
    int k, *l;
    int* m, n;
    /* clang-format on */

    cr_assert_eq(sizeof(k), TODO, "What type is k?");
    cr_assert_eq(sizeof(l), TODO, "What type is l?");
    cr_assert_eq(sizeof(m), TODO, "What type is m?");
    cr_assert_eq(sizeof(n), TODO, "What type is n?");
}

Test(about_pointers, pointers_as_function_arguments)
{
    /*
     * Since functions in C are call-by-value, there is seemingly no way to
     * change a value of an argument inside of the function. This is where
     * pointers come in to play.
    */
    int i = 10;

    double_an_int(&i);

    cr_assert_eq(i, TODO, "What is the new value of i?");
}

Test(about_pointers, pointers_arrays_and_arithmetic)
{
    /*
     * In C, pointers and arrays are intertwined.
     * Since we have already learned a little bit about arrays, we will focus
     * on the pointer aspect.
    */

    int a[5] = { 1, 2, 3, 4, 5 };
    int *p1 = &a[0];
    int *p2 = &a[1];

    cr_assert_eq(*a, TODO, "Remember what the ");
    cr_assert_eq(*p1, TODO, "What does p1 point to?");
    cr_assert_eq(*p2, TODO, "What does p2 point to?");

    /*
     * Since p1 now points to the array, we can treat p1 as being the array
     * and do arithmetic to mirror that.
     * Pointer arithmetic is 'smart', it will do the arithmetic based on the
     * size of the type that is being pointed to.
    */

    cr_assert_eq(*(p1 + 1), TODO, "What is the value at this address?");

    cr_assert_eq(p1[1], TODO,
        "Bracket notation is just syntactic sugar for pointer arithmetic.");

    /*
     * Think about this example, if p1 points to the first int and p2 points to
     * the second int, what is the number of bytes between the two addresses?
    */
    cr_assert_eq((long)((long)p2 - (long)p1), TODO,
        "What is the number of bytes diffence?");

    cr_assert_eq(
        (int)(p2 - p1), TODO, "What is the number of ints difference?");
}

Test(about_pointers, function_pointers)
{
    /* Declaration of an array of strings and the sorted equivalent */

    const size_t array_size = 5;
    char *names[] = { "Spike", "Ein", "Jet", "Ed", "Faye" };
    char *sorted_names[] = { "Ed", "Ein", "Faye", "Jet", "Spike" };
    (void)array_size; /* to avoid a compiler error */

    /*
        Function pointers are a tricky notion to handle for beginner C
        programmers, but with a little practice you should be able to understand
        how they work.

        To display function pointers, we will examine the usage of the C stdlib
        function qsort, quicksort.

        To start, we will examine the function prototype for qsort:

        void qsort(void *base, size_t nmemb, size_t size,
                    int (*compar)(const void *, const void *));

        base: This is your array.
        nmemb: This is the number of elements in your array.
        size: This is the size of each element in your array.
        compar: This is the function pointer for the comparison function

        Now, compar itself has a very tricky declaration, and we will dissect
       it.

        int (*compar)(const void *, const void *)

        In plain English, this declaration means: "A pointer to a function that
        takes two const void pointers as arguments, and returns an int"

        The key to the declaration is (*compar). This signifies that this is a
        function pointer. If *compar was not in parens, compar would be read by
        the compiler as a pointer to an int. With them, it is read as a function
        that returns an int.

        The next key is the (const void *, const void *). This signifies the
        arguments of the function being pointed to.

        To test your knowledge, you will now write the line of code to call
       qsort to sort the array declared earlier. We have provided a comparison
        function for strings that can be used by qsort.
    */

    /*
        Write the line of code to sort names here.
        the comparison function to use can be found found in c_koans_helpers.c,
        named string_compare
    */

    /* qsort(); */

    cr_assert_arr_eq_cmp(sorted_names, names, array_size, string_compare,
        "The names are not sorted.");
}
