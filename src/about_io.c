#include "c_koans.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

Test(about_io, intro)
{
    /*
        This koan will teach you about input and output in C. Let's go over the
        basics of printing out text to the terminal with a format. This is
        one of the most common ways of printing information out in C.
    */
    printf("Hello World!\n"); // NOTE: Don't forget the newline character (\n)!

    /*
        To print variables you must use a % modifier in the format string passed
        to printf. For example:
    */
    char *string = "World!";
    printf("Hello %s\n", string);

/*
    There are many modifiers present in C. You can access a list of them at:
    http://www.cplusplus.com/reference/cstdio/printf/
    Complete the following:
*/

/*
    Use the references to determine which format specifier will give the
    proper output. When you complete this koan, change the literal on line
    37 to a nonzero value. This is to avoid compilation errors.
*/

#if 0
    char c = 'J';
    int i = -1;
    double d = 3.14;
    long l = 0xDEADBEEF;
    void* p = (void*)0x400;

    printf("char: TODO\n", c);
    printf("int: TODO\n", i);
    printf("unsinged int: TODO\n", i);
    printf("hexadecimal unsigned int: TODO\n", i);
    printf("float: TODO\n", d);
    printf("long: TODO\n", l);
    printf("pointer: TODO\n", p);
#endif
    cr_assert_file_contents_eq_str(stdout, "char: J\nint: -1\nunsigned int:    \
    4294967295\nhexadecimal unsigned int: ffffffff\nfloat: 3.140000\nlong:     \
    3735928559\npointer: 0x400\n");
}

Test(about_io, file_stream)
{
    /*
        The standard io library, <stdio.h>, provides a FILE type for standard io
        usages. Most functions that use standard in or out have a stream counter
        -part, making use of FILE*.
    */

    FILE *f;
    char buf[1024];
    /*
        fopen takes a path to a file and a mode, in this case we are opening in
        read only mode.
    */
    f = fopen("rsrc/file.txt", "r");

    /*
        fgets will read at most the number of bytes specified into the given
        buffer from the stream. fgets will read until it reads the number of
        bytes, it hits a new line character or until it gets EOF.
    */
    fgets(buf, 1024, f);

    cr_assert_str_eq(buf, TODO_S, "rsrc/file.txt to see what buf should be");
}
