#include "c_koans.h"
#include <stdlib.h>

void func(int *array)
{
    cr_assert_eq(sizeof(array), 0,
        "That same array gives a different size "
        "when passed into this function");
}

Test(about_arrays, what_is_an_array)
{
    /* Here is a declaration of 5 integers */
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    /*
        An array is a sequential declaration of memory with each item being the
        size of the type (in this case, int)
    */
    /* Change this to: 'cr_assert_not_null' */
    cr_assert_null(array,
        "An array declared in this way is a label meaning "
        "it has an address %p",
        array);

    /*
     * An array variable's name is merely a label for the address of the first
     * element in the array.
    */
    cr_assert_eq(*array, 0,
        "Dereferencing this label's address gives us the "
        "value at that point");

    cr_assert_eq(*(array + 2), array[0],
        "Dereferencing with an offset is the same as using the bracket notation"
        " to access");

    /*
        An important operator in C is sizeof:
        The unary operator sizeof generates the size of a variable or datatype,
        measured in the number of char size storage units required for the type.
        As such, the construct sizeof (char) is guaranteed to be 1. The actual
        number of bits of type char is specified by the preprocessor macro
        CHAR_BIT, defined in the header file limits.h. On most modern systems
        this is eight bits. The result has an unsigned integral type that is
        usually denoted by size_t. The operator is written preceding its
        operand, and may be applied either to a variable or any data type
        specification, including primitive types such as integer and
        floating-point types, pointer types, or compound datatypes (unions,
        structs). When applied to a data type the type must be enclosed in
        parenthesis.
    */

    cr_assert_eq(sizeof(array), 0,
        "sizeof an array can be tricky is it size "
        "of a pointer or sum of all memory the "
        "array takes up?");
    func(array); /* Goto line 3 */

    /*
        You do not always have to take up so much lines to create an array whose
        contents you already know. You can use {...} syntax to create such an
        array elegantly.
    */
    int another_array[5] = { 1, 2, 3, 4, 5 };
    cr_assert_eq(another_array[3], TODO,
        "We should be seeing the some element's value.");

    /*
        You will not always know how many items an array might hold at runtime.
        In these kinds of scenarios, you can't use the syntax we've been using.
        Instead, you'll have to think about the array as a pointer first, and
        then you can start using it as an array again.
    */
    const size_t INIT_ARR_SIZE = 5;
    int *yet_another_array = calloc(INIT_ARR_SIZE, sizeof(int));

    /* Thankfully, the syntax is just like it was before. */
    unsigned i;
    for (i = 0; i < INIT_ARR_SIZE; i++) {
        /*
            You can loop on arrays, as long as you handle the indexing logic
            correctly.
     */
        yet_another_array[i] = i + 1;
    }

    /*
        When we need to, we can make an array bigger to accommodate via realloc.
    */
    if (!realloc(yet_another_array, INIT_ARR_SIZE * sizeof(int))) {
        exit(1);
    }

    yet_another_array[INIT_ARR_SIZE] = 6;
    unsigned where = 0;
    for (i = 0; i < INIT_ARR_SIZE + 1; i++) {
        if (yet_another_array[i] == INIT_ARR_SIZE + 1) {
            where = i;
        }

        cr_assert_eq(yet_another_array[i], TODO,
            "Although we started with an "
            "array of 5 elements, we "
            "should be able to find a "
            "sixth element as well.");
    }
    cr_assert_eq(where, TODO,
        "We should be seeing a certain value, given the "
        "way we set these elements' values.");

    /*
        Often, we find ourselves in need of representing strings in a program,
        and usually, we are able to use something like a String class or type.
        Unfortunately, C does not have any such notion of a string baked into
        the language like in some other languages (e.g. Java).
    */
    const char a_string[13] = "hello world!"; /* This is a 'string' in C. */

    /* In C, a string is simply an array of characters. */
    cr_assert_eq(a_string[3], TODO,
        "We may be interested in a particular "
        "character of strings.");

    /*
        In C, memory is just memory. It is just a bunch of bytes. Therefore, we
        need to be able to know when a string ends. We use something called a
        'null byte' or 'null terminator', which is really just a zero-byte, to
        do this. This byte is always found at the end of a string, and if it is
        missing, can lead to very dangerous and unpredictable bugs.
    */
    cr_assert_eq(a_string[12], TODO_NZ, "Null terminators are essential!");
}
