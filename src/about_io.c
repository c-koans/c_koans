#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "c_koans.h"

Test(about_io, intro) {
    /*
        This koan will teach you about input and output in C. Let's go over the
        basics of printing out text to the terminal with a format. This is
        one of the most common ways of printing information out in C.
    */
    printf("Hello World!\n");  //NOTE: Don't forget the newline character (\n)!

    /*
        To print variables you must use a % modifier in the format string passed
        to printf. For example:
    */
    char* string = "World!";
    printf("Hello %s\n", string);

    /*
        There are many modifiers present in C. You can access a list of them at:
        http://www.cplusplus.com/reference/cstdio/printf/
        Complete the following:
    */
    char c = 'J';
    int i = -1;
    double d = 3.14;
    long l = 0xDEADBEEF;
    void* p = 0x400;

    printf("char: TODO\n", c);
    printf("int: TODO\n", i);
    printf("unsinged int: TODO\n", i);
    printf("hexadecimal unsigned int: TODO\n", i);
    printf("float: TODO\n", d);
    printf("long: TODO\n", l);
    printf("pointer: TODO\n", p);

    cr_assert_file_contents_eq_str(stdout, "char: J\nint: -1\nunsigned int:    \
    4294967295\nhexadecimal unsigned int: ffffffff\nfloat: 3.140000\nlong:     \
    3735928559\npointer: 0x400\n");
}
