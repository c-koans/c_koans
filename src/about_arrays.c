#include <criterion/criterion.h>

void func(int* array){
  cr_assert_eq(sizeof(array), 0, "That same array gives a different size "
                                 "when passed into this function");
}

Test(c_koans, what_is_an_array){
    /* Here is a declaration of 5 integers */
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    /*
     * An array is a sequential
     * declaration of memory with each item being the size of the type (int in 
     * this case)
     */
    // Change this to: 'cr_assert_not_null'
    cr_assert_null(array, "An array declared in this way is a label meaning "
                          "it has an address %p", array);

    cr_assert_eq(*array, 0, "Dereferencing this label's address gives us the "
                            "value at that point");

    cr_assert_eq(*(array + 2), array[0], "Dereferencing with an offset is the "
                                         "same as using the bracket notation "
                                         "to access");

    /*
     * An important operator in C is sizeof:
     * The unary operator sizeof generates the size of a variable or datatype, 
     * measured in the number of char size storage units required for the type. 
     * As such, the construct sizeof (char) is guaranteed to be 1. The actual 
     * number of bits of type char is specified by the preprocessor macro 
     * CHAR_BIT, defined in the header file limits.h. On most modern systems 
     * this is eight bits. The result has an unsigned integral type that is 
     * usually denoted by size_t. The operator is written preceding its 
     * operand, and may be applied either to a variable or any data type 
     * specification, including primitive types such as integer and 
     * floating-point types, pointer types, or compound datatypes (unions, 
     * structs). When applied to a data type the type must be enclosed in 
     * parenthesis.
     */

    cr_assert_eq(sizeof(array), 0, "sizeof an array can be tricky is it size "
                                   "of a pointer or sum of all memory the "
                                   "array takes up?");
    func(array); // Goto line 3
}
