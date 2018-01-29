#include "c_koans.h"

Test(about_dataclasses, unions)
{

    /*
        Unions are a data type that offers one variable to be able to
        accomidate different data types all at once. They allow for different
        types of different sizes and alignment to be handled all at once place
        in storage.
        Alignment and size of a union is determined by the compiler. The size of
        a union will be the size of the largest data type within.
    */

    /* A union declaration is the same as a struct's */
    union first_union {
        double d;
        int i;
        short s;
        char c;
    } u; /* Here we initialize a union variable, just like a struct. */

    u.d = 1.01;

    cr_assert_eq(u.d, TODO, "What is the value of d that we assigned?");
    cr_assert_eq(sizeof u, TODO,
        "What is the size of the largest data type in "
        "the union?");

    /*
        Since a union holds its data in one place, it could be interpreted
        differently depending on how it is accessed.
    */

    u.i = 0xDEADCAFE;

    cr_assert_eq(u.s, TODO,
        "What is the value stored inside the union, "
        "interpreted as a short?");
}

Test(about_dataclasses, enums)
{
    /*
        enums offer a list of constant integer values with an optional
        identifer. The list of the enums may be assigned values, assigned no
        value, or only the first be assigned a value: the rest of the values
        will increase by 1 beginning from the first value.
    */

    /* TRUE will be assigned 0, FALSE will be the next value, 1 */
    enum boolean { TRUE, FALSE };

    cr_assert_eq(FALSE, TODO, "What will the enum FALSE be?");

    /* enum declarations follow a similar format as structs */
    enum month {
        JAN = 1,
        FEB,
        MAR,
        AP,
        MAY,
        JUN,
        JUL,
        AUG,
        SEP,
        OCT,
        NOV,
        DEC
    };

    /* enums can be assigned variables in the same fashion as structs */
    enum month current = AUG;

    cr_assert_eq(current, TODO,
        "What is the current month? (This was written "
        "in August)");

    /* enums may even be typedef'd */

    typedef enum {
        ONE = 0x1,
        TWO = 0x2,
        THREE = 0x4,
        FOUR = 0x8,
        FIVE = 0x10,
        SIX = 0x20,
        SEVEN = 0x40,
        EIGHT = 0X80
    } bit_mask;

    bit_mask mask_four = FOUR;

    cr_assert_eq(mask_four, TODO, "What is the value of FOUR in this enum?");
}

Test(about_dataclasses, bit_fields)
{
    /*
        Sometimes it is necessary to pack multiple fields into a single word,
        half, or byte. This is where bit fields come in. A bit field is denoted
        in a struct member declaration, with a ':' following a member name that
        is followed by a number - this number is the number of bits.
    */

    /*
        Here is a struct to represent a course number: since a course number is
        only 3 digits, the options are 0 to 999. This can be represented by 10
        bits.
    */
    struct course_number {
        unsigned int n : 10;
    } cnum;

    cnum.n = 101;

    /*
        The size of a bit field is represented by the type that it assigned to.
        In this case, this is an int, which is 32 bits long. Prior to C99, the
        only valid type a bit field could be was 'int', a single word.
    */
    cr_assert_eq(sizeof cnum, TODO, "What is the size of the struct?");

    struct course {
        unsigned int n : 10;
        unsigned int c3 : 7;
        unsigned int c2 : 7;
        unsigned int c1 : 7;
        unsigned int is_offered : 1;
    };

    struct course cse101 = { 101, 'E', 'S', 'C', 1 };

    cr_assert_eq(*(unsigned int *)(&cse101), TODO,
        "Determine the hex value of "
        "the bit vector for cse101!");

    cr_assert_eq(sizeof cse101, TODO, "What is the size of our variable?");

    /*
        In more modern C (C99+), bit fields may be of any type, and the size of
        the resultant struct will be based on the type used for the field(s).
    */

    /* Here's a struct of 16 bits */
    struct mmio_cell {
        unsigned char background_color : 4;
        unsigned char background_char : 4;
        unsigned char foreground_color : 4;
        unsigned char foreground_char : 4;
    };
    cr_assert_eq(sizeof(struct mmio_cell), TODO,
        "What would the size of this "
        "struct?");
}

Test(about_dataclasses, about_const)
{
    /*
        The const qualifier is a very useful tool for avoiding runtime errors
        by defining things that should not be modified.
        The compiler will catch all const transgressions.
    */

    /* A const primitive is unchangable */
    const int i = 10;
    /* i = 4; ERROR! */
    cr_assert_eq(i, TODO,
        "Attempting to reassign i will result in a compiler "
        "error.");

    /* A const pointer points to an unchangable space of memory */
    int j = 100;
    const int *jp = &j;

    /* *jp = 10; ERROR! */
    cr_assert_eq(*jp, TODO,
        "Attemping to change the value jp pointer to will "
        "result in a compiler error.");

    /*
        A const after the '*' in a pointer declaration defines a pointer that
       can not point anywhere else.
    */
    int *const kp = &j;

    /* jp2 = &i; ERROR! */

    cr_assert_eq(kp, TODO,
        "Attempting to point kp elsewhere will result in a "
        "compiler error.");

    /* Using both instances of const will result in a const pointer to const! */
    const int l = 400;
    const int *const lp = &l;

    cr_assert_eq(*lp, TODO,
        "Attempting to do any of the previous options to "
        "lp will result in a compiler error.");
}
