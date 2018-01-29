#include "c_koans.h"
#include <limits.h>
#include <stdbool.h>

Test(about_basics, intro)
{
    /*
        Welcome to the C language
        To begin let's understand the framework in which you will be fixing each
        unit test
        This is Criterion a Testing framework. More can be read on it here:
        http://criterion.readthedocs.io/en/stable/

        Tests are built on assertions, simple evaluations of truth in order to
        assess the correctness of code
    */
    cr_assert(false,
        "This should be true, assertion - a confident and forceful "
        "statement of fact");
    /*
        There is no true and false in C by default. As you can see on line 2.
        We've included the standard bool header which adds in true and false
        literals we are used to.
        In C, true and false are nonzero and zero values respectively
        The %d allows us to do string interpolation, the 'd' specifies to
        interpret
        the input as an int
    */
    cr_assert(false == 1,
        "In C there is no false, there is only zero. false is in fact: %d",
        false);
    cr_assert(true == 0,
        "In C there is no true, there is only not zero. true is in fact: %d",
        true);
    /*
        Criterion has more descriptive tests that can evaluate the same thing
        eq is short for equals
    */
    cr_assert_eq(false, 1, "Nothing is not something");
    cr_assert_eq(true, 0, "Something is not nothing");
}

Test(about_basics, variables)
{
    /*
        If you've had some experience with Java then C won't seem too foreign in
        terms of syntax
    */
    char c = TODO;
    cr_assert_eq(c, 'C',
        "All characters in C are interpreted from the ASCII "
        "table, go to your terminal and enter 'man ascii' to "
        "find this solution");

    short s = TODO;
    cr_assert_eq(s, 0xBEE, "A short is 2 bytes");

    int i = TODO;
    cr_assert_eq(i, 0xBADBEEF, "A int is 4 bytes");

    long l = TODO;
    cr_assert_eq(l, 0xDEBA7AB1E,
        "A long is a larger integer type than int (supports unsigned).");

    unsigned int ui = TODO;
    /*
        This unsigned int should exceed the maximum capacity of an INT (hint
        INT_MAX is declared in limits.h)
    */
    cr_assert_gt(ui, 0xDEADBEEF,
        "The unsigned modifier can be used on a "
        "primitive data type to increase the upper "
        "limit by only storing positive values");

    long long ll = TODO;

    cr_expect_eq(ll, 0xFF,
        "A number literal starting with 0x will be interpreted as hexadecimal");
    cr_expect_eq(ll, 0b11111111,
        "A number literal starting with 0b will be interpreted as binary");
    cr_assert_eq(ll, 0777,
        "A number literal starting with 0 will be interpreted as octal");

    double d = 3.50;
    cr_assert_float_eq(d, (7 / 2), 0.000001,
        "Just like Java, C does integer division for 7/2");

    double d2 = 350e-2;
    cr_assert_float_eq(d2, 3 + (1 / 2), 0.000001,
        "Addition also effects whether a number literal is "
        "interpreted as IEEE or 2's Comp");
}
