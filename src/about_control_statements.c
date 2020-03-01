#include "c_koans.h"
#include <stdbool.h>

/*
    As the language we are most familiar with, Java, has a syntax  heavily
    inspired by C, the following control flow statements should feel very
    familiar to proficient Java programmers like ourselves...
 */

Test(about_control_statements, ifs)
{
    /*
        The if statement is the most familiar: the statement inside of the
        parenthesis is evaluated.
        The only difference from Java is the lack of a boolean type.
        Due to this, the conditional is evaluated for a nonzero or zero value.
        A value of 0 is evaluated as false, a nonzero value as true.
    */
    int var = 1 < 2;

    if (var)
        var = 1;
    else
        var = 2;

    /* To pass this test, determine where the control flow will go. */
    cr_assert_eq(var, TODO, "If statements work just like other languages");

    /* Of course, C also has the familiar else-if */
    if (1 > 2)
        var = 1;
    else if (1 == 2)
        var = 3;
    else
        var = 4;

    cr_assert_eq(var, TODO, "Determine the control flow for this block, too");
}

Test(about_control_statements, switch_block)
{
    /*
        The switch is also familiar, and similar to the else-if.
        The difference is that a switch block will check a value only
        with "constant" integer expressions.

        The switch will 'fall through' without
        the 'break' keyword, meaning that it will do
        the next case in the block if there is no break statement.
    */
    int var = 1;
    switch (var) {
    case 1:
        var = 100;
    case 10:
        var = 200;
        break;
    default:
        break;
    }

    cr_assert_eq(var, TODO, "Determine the control flow for this block.");
}

Test(about_control_statements, loops)
{
    /*
        C possesses three types of loops. The first of which is the 'while'
        The while loop will execute everything inside of its block until the
        condition it checks is 'false', meaning that until it is 0.
        The while loop will not execute once if its condition is initially 0.

        This brings another discussion for the 'break' statement: if the control
        flow reaches that statement inside of a loop,
        than it will stop the execution of that loop.
    */

    int var = 0;
    while (true) {
        var++;
        if (var == 10)
            break;
    }

    cr_assert_eq(
        var, TODO, "Determine the result of the execution of this loop.");

    /*
        The for loop should also feel familiar.
        It possess three statements inside of its parenthesis:
        the first is done before the first iteration, the second is the check to
        stop iteration, and
        the third is done after every iteration.

        We will write a for loop that does
        the same thing as the while loop in the previous example...
    */

    for (var = 0; var < 10; var++) {
        ;
    }

    /*
        For this loop, the {} are optional since the body of the loop does not
        have any statements.
    */
    cr_assert_eq(
        var, TODO, "Determine the result of the for loop's execution.");

    /*
        The final loop, the do-while, executes the same as the while,
        except that it will do at least one iteration.
    */

    var = 0;
    do {
        var++;
    } while (var < 10);

    cr_assert_eq(
        var, TODO, "Determine the result of the do-while loop's execution");
}

Test(about_control_statements, goto_and_labels)
{
    /*
        The goto at the assembly level is an
        unconditional branch, 'j' or 'b' from MIPS.
        It unconditionally jumps to a label within the local scope of a function

        Jumping outside of a function, a long jump, requires other constructs
        that are platform dependent.
    */
    int var = 10;

    goto label;

    var = 50;
    /*
        The label syntax is some name
        (the same as a variable name) followed by a colon.
    */
label:
    cr_assert_eq(
        var, TODO, "Determine the result of the flow of the function.");
}
