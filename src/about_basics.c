#include <criterion/criterion.h>
#include <stdbool.h>
#include <limits.h>

Test(c_koans, intro) {
    /*
     * Welcome to the C language
     * To begin let's understand the framework in which you will be fixing each unit test
     * This is Criterion a Testing framework. More can be read on it here: http://criterion.readthedocs.io/en/stable/
     *
     * Tests are built on assertions, simple evaluations of truth in order to assess the correctness of code
     */
    cr_assert(false, "This should be true, assertion - a confident and forceful statement of fact");
    /*
     * There is no true and false in C by default. As you can see on line 2. We've included the
     * standard bool header which adds in true and false literals we are used to.
     * In C, true and false are nonzero and zero values respectively
     * The %d allows us to do string interpolation, the 'd' specifies to interpret the input as an int
     */
    cr_assert(false == 1, "In C there is no false, there is only zero. false is in fact: %d", false);
    cr_assert(true == 0, "In C there is no true, there is only not zero. true is in fact: %d", true);
    /*
     * Criterion has more descriptive tests that can evaluate the same thing
     * eq is short for equals
     */
    cr_assert_eq(false, 1, "Nothing is not something");
    cr_assert_eq(true, 0, "Something is not nothing");
}

Test(c_koans, variables) {
    /*
     * If you've had some experience with Java then C won't seem too foreign in terms of syntax
     */
    char c = 'C';
    short s = 320;
    int i = 0xC0DE;
    unsigned int ui = 0x80000000;
    long l = 0b1010;
    long int li = 033;
    double d = 3.20;
    double ld = 320e-2;

    cr_assert_eq(c, 0x0, "All characters in C are interpreted from the ascii table, go to your terminal and enter 'man ascii' to find this solution");
    cr_assert_eq(s, 0, "A short is 2 bytes");
    cr_assert_eq(i, 0, "A int is 4 bytes");

    /* This unsigned int should exceed the maximum capacity of an INT (hint INT_MAX is declared in limits.h) */
    cr_assert_gt(ui, 0x88888888, "An unsigned number can be used to increase the capacity of a value by only storing positive values");

    cr_assert_eq(l, 0xF, "A long is both a modifier and type");
    cr_assert_eq(li, 33, "Numbers that start with zero are interpreted as octal");

    cr_assert_float_eq(d, (16 / 5), 0.000001, "Just like in Java division is by default done as integer division");
    cr_assert_float_eq(ld, 3 + (1 / 5), 0.000001, "Addition also effects whether a number literal is interpreted as IEEE or 2's Comp");
}
