#include <criterion/criterion.h>
#include <stdio.h>

/*
 * We have used functions from string.h, for more information take a look at man
 * page for string.
 * Open terminal and type 'man string'
 */

Test(about_strings, what_is_string){
    /* Here is a declaration of String "CSE320 is awesome" */
    char* string = "CSE320 is awesome";
    /* It ois automatically allocated memory space to contain it with the
     * terminating \0
     */

    // Change this to: 'cr_assert_not_null'
    cr_assert_null(string, "string contains value which is the address of first\
     character");
    //Change it to 'C'

    cr_assert_eq('c', *string, "Dereferencing will give the first character of \
        the string");

    cr_assert_eq('S', *(string + 1), "Dereferencing with offset will give \
        character at offset");
}

Test(about_strings, reference_characters){
    /* String are just like array of char, all the ways of defreferencing array
     * will work with string
     */
    char* string = "CSE320 is awesome";

    //Change it to 'E', indexing starts with 0
    cr_assert_eq('3', string[2], "String can be used as arrays");

    //Can also add the can use both offset and bracket notation at the same time
    cr_assert_eq('3', (string+1)[2], "Gets character at the sum of both numbers"
        );

    /* *string + 1 will get first character and add 1 to the character, while
     * *(string + 1) adds 1 to the pointer then
     * dereferences it
     */
    cr_assert_eq( *string + 1 , *(string + 1) , "They are not equal");
}

Test(about_strings, assignment){
    /*
     * char* string = "CSE 320", string declared are immutable (read only)
     * trying to change would raise in compiler error but
     * char string[] = "CSE 320", is mutable
     */
    char string[] = "CSE 320";
    string[2] = 'S';
    cr_assert_str_eq("CSE 320", string, "String declared this way are mutable");

    *(string + 4) = '2'; // forgeting () will give compiling error
    cr_assert_str_eq("CSE 320", string, "String declared this way are mutable");

    (string + 4)[2] = '1';
    cr_assert_str_eq("CS3 320", string, "String declared this way are mutable");
}

Test(about_strings, declaration){
    /* DOES NOT automatically add terminating character at the end */
    char string1[] = {'C', 'S', 'E', '3', '2', '0'};
    char string2[] = "CSE320"; //Adds terminating character at the end

    cr_assert_eq(sizeof(string1),sizeof(string2), "Only one of them contains \\\
        0 at the end");
}

Test(about_strings, sizeof_strlen){
    /*
     * strlen : Returns the length of the C string str, Does not inclue '\0'
     * strlen("CSE 320") would return 7
     */

    /* For function calls in strings.h strings end at /0 */
    char string[] = {'C', 'S', 'E', '\0', '3', '2', '0'};
    cr_assert_eq(sizeof(string), strlen(string), "strlen ends counting at \\0");

    char* string2 = "Some String";
    char string3[10] = "CSE 320";

    cr_assert_eq( 11, sizeof(string2), "sizeof string2 only shows size of the \
        char pointer");
    cr_assert_eq(7,  sizeof(string3), "sizeof string3 shows memeory used by \
        string3 array not string size");

}

Test(about_strings, copy){
    char string1[] = "CSE 320";

    /* Only copies pointer, string2 and string1 now reference the same memory */
    char* string2 = string1;

    string1[4] = '2'; //string1 = CSE 220

    cr_assert_str_eq("CSE 320", string2, "Only copied pointer, did not copy the\
     string");

    /* Correct way to copy string */
    char string3[8];
    strcpy(string3, string1); //copy all characters

    /* Replace with cr_assert_str_eq */
    cr_assert_eq("CSE 320", string2, "Only copied pointer, did not copy the \
        string");

}

void test_a_string_length_with_sizeof(char* string) {
    /* Sizeof(string) is 8 becuase the size of pointer is 8 */
    cr_assert_eq(7 , sizeof(string), "That same string gives a different size \
        when passed into this function, always use strlen function");
}

Test(about_strings, function_paramater){
    /* Sizeof can give diffrent result when, string are passed in as parameter,
     * but strlen will give the length work
     */
    char string[] = {'C', 'S', 'E', '\0'};
    cr_assert_eq(4, sizeof(string), "Sizeof give correct output");
    test_a_string_length_with_sizeof(string);
}

Test(about_strings, formating_strings){
    char* string1 = malloc(12);
    sprintf(string1, "%s %s!", "CSE", "220!");

    cr_assert_str_eq("CSE 320!", string1, "Instead of printing to stdout we \
        print it to String1");
    free(string1);
}
