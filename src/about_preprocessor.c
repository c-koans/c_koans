#include "c_koans.h"
#include <string.h>
#include <stdbool.h>

/*
    The C Preprocessor is a powerful tool. It allows us to do many things before
    compilation; things like macro substitution, doing conditional logic and
    including files are only a few things that we can do, but are the most
    common.

    All preprocessor directives (things we tell it to do) start with the '#'
    symbol.
*/

#define JOKER "JOKER"

#define MAX(a, b) (a)

Test(about_preprocessor, macro_definitions)
{
    /*
        The C Preprocessor allows us to 'define' things called Macros.
        Macros in C operate exactly as you remember them in MIPS. The
        Preprocessor
        will replace anything that matches something that has been 'defined'
        with what is on the right side of the definition.
        This is known as 'Macro Substitution'
    */

    /* Fix the string we are comparing with what JOKER will be replaced with. */

    const char *CHANGE_ME = "MONA";
    cr_assert(strcmp(CHANGE_ME, JOKER) == 0,
        "Macro JOKER not compared with what it was replaced with!");

    /*
        You can even have macros that have arguments. This allows the macro
        replacement to be different on different calls to the macro.

        You have to be careful with these macros: they may look like a function,
        but
        they are just text replacement when they are expanded.
    */

    /*
        Here we will make a simple MAX macro, that will be replaced with the max
        of the two primitive values.
        Tip: The ternary operator '?'
    */
    int i = 1;
    int j = 2;
    cr_assert(MAX(i, j) == 2, "Max incorrect!");

    (void)j; /* ignore this, it's to suppress the 'unused variable' warning. */
}

#ifndef DEFINE_ME
#define FIVE 0
#else
#define FIVE 5
#endif /* DEFINE_ME */

#ifndef MOVE_ME
#define SEVEN 0
#else
#define SEVEN 7
#endif /* MOVE_ME */

#define MOVE_ME

Test(about_preprocessor, conditional_defines)
{
    /*
        Conditional logic can be done with a few different directives.
        These directives include 'if', 'elif', 'ifdef', ifndef' and 'else'
        'if', 'elif', and 'else' work as you would expect them to, so we will
        ignore
        these for now.

        'ifdef' and 'ifndef' check if the input string has been defined as a
        macro.
        All of the preprocessor 'if' directives must be with and 'endif' block.
    */

    /* Define the macro DEFINE_ME */
    cr_assert_eq(5, FIVE, "FIVE incorrectly defined!");

    /*
        The Preprocessor does a linear scan, so things are defined in the order
        they appear in the file.
        For the next test, define MOVE_ME in a place such that it will pass.
    */

    cr_assert_eq(7, SEVEN, "SEVEN incorrectly defined!");
}

#define STRINGIZE(arg) #arg

Test(about_preprocessor, stringizing)
{
    /*
        The Preprocessor has a functionality known as "Stringizing"
        What stringizing does is replace a macro argument with a string literal.
        It is done by appending a '#' before the argument in a macro.
    */

    /*
        To complete this test, replace put the correct argument into STRINGIZE
        such that it will match the string literal.
    */
    cr_assert_eq("my string", STRINGIZE(TODO), "Stringizing not completed.");
}

#define ALWAYS_FALSE false
#define ALWAYS_TRUE true

#define THIS_IS(b) ALWAYS_##b

Test(about_preprocessor, macro_concatination)
{
    /*
        Concatenation is denoted by the use of a '##' inside of a macro.
        When the macro is expanded, it will combine both tokens on each side of
        the '##' into one long token. As can be seen in the macro THIS_IS, it
        will be replaced with one of the macros defined right above it.
    */

    /*
        To complete this test, assert that THIS_IS(TRUE)!
        Be wary of your usage of capital letters.
    */
    cr_assert(THIS_IS(FALSE), "Concatenation not completed.");
}

#define VARIADIC_ARGUMENTS(...) #__VA_ARGS__

Test(about_preprocessor, variadic_macros)
{
    /*
        The Preprocessor has the power to take advantage of variable length
        arguments
        On a simple level, it is not different than regular macro substitution
        since it replaces the input argument list denoted
        by '...' where '__VA_ARGS__' is in the macro.

        It even includes the commas.
    */

    /*
        To pass this test, put the correct argument into the macro call.
        Note that the macro takes advantage of stringizing. Your argument is not
        going to be a string.
    */
    cr_assert_eq("varable,args,with,commas", VARIADIC_ARGUMENTS(TODO),
        "Variadic macros not yet completed");
}
