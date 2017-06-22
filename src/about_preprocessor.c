#include <criterion/criterion.h>
#include <string.h>

/* 
 * The C Preprocessor is a powerful tool. It allows us to do many things before 
 * compilation; things like macro substitution, doing conditional logic and 
 * including files are only a few things that we can do, but are the most common.
 *
 * All preprocessor directives (things we tell it to do) start with the '#' symbol.
 */

#define JOKER "JOKER"

#define MAX(a,b) (a)

Test(c_koans, macro_definitions) {
    
    /* 
     * The C Preprocessor allows us to 'define' things called Macros.
     * Macros in C operate exactly as you remember them in MIPS. The Preprocessor
     * will replace anything that matches something that has been 'defined' with 
     * what is on the right side of the definition. 
     * This is known as 'Macro Substitution'
     */

    /* Fix the string we are comparing with what JOKER will be replaced with. */

    const char *CHANGE_ME = "MONA";
    
    cr_assert(strcmp(CHANGE_ME, JOKER) == 0,
		 "Macro JOKER not compared with what it was replaced with!");

    /*
     * You can even have macros that have arguments. This allows the macro 
     * replacemnt to be different on different calls to the macro.
     *
     * You have to be careful with these macros: they may look like a function, but
     * they are just text replacement when they are expanded. 
     */

    /* 
     * Here we will make a simple MAX macro, that will be replaced with the max
     * of the two primitive values. 
     * Tip: The ternary operator '?'
     */
    int i = 1;
    int j = 2;
    cr_assert(MAX(i, j) == 2, "Max incorrect!");

    (void)j; // ignore this, it's to suppress the 'unused variable' warning!
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

Test(c_koans, conditional_defines) {
    /*
     * Conditional logic can be done with a few different directives. 
     * These directives include 'if', 'elif', 'ifdef', ifndef' and 'else'
     * 'if', 'elif', and 'else' work as you would expect them to, so we will ignore
     * these for now.
     *
     * 'ifdef' and 'ifndef' check if the input string has been defined as a macro.
     * All of the preprocessor 'if' directives must be with and 'endif' block.
     */

    
    /* Define the macro DEFINE_ME */
    cr_assert_eq(5, FIVE, "FIVE incorrectly defined!");

    
    /* The Preprocessor does a linear scan, so things are defined in the order they 
     * are in the file. For the next test, define MOVE_ME in a place such that it
     * will pass.
     */

    cr_assert_eq(7, SEVEN, "SEVEN incorrectly defined!");
}
