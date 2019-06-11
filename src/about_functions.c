#include "c_koans.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int return_5() { return 5; }

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

Test(about_functions, function_basics)
{
    /*
        Functions are pieces of modularized code. They are equivalent in purpose
        to methods in Java. Since there are no Classes in C, C functions can be
        thought of as static methods in Java.
    */
    cr_assert_eq(return_5(), TODO, "What does this function return?");

    /* Of course, functions can be recursive */
    cr_assert_eq(fib(5), TODO, "What is the 5th fibonacci number?");
}

/*
    This is a function prototype: A blueprint of a function that will be
    implemented later. This is how functions can be used and called without
    them being implemented in the order in which they are called.

    Typically, function prototypes are in header files ('.h'), and these are
    #include'd in files that use the functions that are declared.

    Function prototypes do not need to have a name for arguments: only the type.
    They may be included for more clarity of code, but it is up the discretion
    of the programmer.
 */
int function_prototype(int, int);

Test(about_functions, function_prototypes)
{
    /* We will test if our function can be called since it has been declared */
    cr_assert_eq(
        function_prototype(1, 2), TODO, "What does the function return?");
}

/* Here is the implementation for our prototype. */
int function_prototype(int i, int j) { return i + j; }

Test(about_functions, function_scope_and_vars)
{
    /*
        Functions are the main scope of the C language. The location of
        variables are determined by their declaration location in reference to
        the functions.

        We will examine three types of variables: global, local and local static
        through three functions found inside c_koans_helpers.c
    */

    modify_global();
    modify_global();
    cr_assert_eq(modify_global(), TODO,
        "What is the value of global_var after the third call?");

    modify_local();
    modify_local();
    cr_assert_eq(modify_local(), TODO,
        "What is the value of the local variable after the third call?");

    modify_local_static();
    modify_local_static();
    cr_assert_eq(modify_local_static(), TODO,
        "What is the value of the local static variable after the third call?");
}
