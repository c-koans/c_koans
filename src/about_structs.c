#include "c_koans.h"

/*
    A structure is simply a collection of multiple variables all within the
    same memory space. It is comparable to a Class in Java, except it does not
    have member functions (methods), and does not have visibility qualifiers
    like 'public'
*/

/* Here is a simple struct to represent a point, with an x and y coordinate. */
struct point2d {
    int x;
    int y;
}; /* note this semi-colon */

Test(about_structs, struct_basics)
{
    /* Structs are initialized very simply. */
    /* We have to specify that the 'point2d' type is a struct */
    struct point2d p1;

    /* Their members are accessed very familiarly, with a '.' */
    p1.x = 10;
    p1.y = 2;

    cr_assert_eq(p1.x, TODO, "What has the x value been initialized to?");

    /*
        The sizeof operator will operate as expected, even with a struct
        Since we are using sizeof on p1, we do not have to enclose it in
        parenthesis
    */
    cr_assert_eq(sizeof p1, TODO, "What is the size of our two ints?");

    /*
        We can initialzed our structs statically, with similar syntax to array
        initialization
        The members are initialized in the order that they have been declared in
        the struct
    */
    struct point2d p2 = { 10, 20 };

    cr_assert_eq(p2.y, TODO, "What has the y value been initialized to?");

    /*
        You can even have structs that contain structs
        Note that it is probably a bad idea to declare a struct inside of the
        scope of a function...
    */

    /*
        When you declare a struct, you can declare a new variable after the
        closing '}'
        This is equivalent to doing 'int x;'
    */
    struct point3d {
        struct point2d two_d;
        int z;
    } p3;

    p3.two_d.x = 10;
    p3.two_d.y = 20;
    p3.z = 40;

    cr_assert_eq(p3.two_d.y, TODO, "Member access is no different than usual");

    /*
        You can use 'typedef' to declare a struct type that can be used without
        having to use 'struct'
    */
    typedef struct {
        struct point3d three_d;
        int w;
    } point4d;

    point4d p4;
    p4.three_d.z = 2;
    p4.three_d.two_d.x = 1;

    cr_assert_eq(p4.three_d.two_d.x, TODO,
        "What is the value of x, after all the struct access?");
}

Test(about_structs, structs_and_functions_and_pointers)
{
    /*
        A struct can be passed as a variable to a function, just like any other
        type
    */
    struct person person1;

    /* Examine this function in c_koans_helpers.c */
    person1 = make_person("Brian", 5, 14, 1996);

    cr_assert_str_eq(person1.name, TODO_S, "What is the name of this person?");

    /*
        Since functions are call by value in C, this means that a function
        argument becomes a local variables on the call stack of that function.
        Can you see a problem with using a struct as an argument? What would
        happen if that struct is larger than a word? For this reason, most
        function arguments and returns use pointers to structs.
    */
    struct person person2;

    /* Examine this function in c_koans_helpers.c */
    int success = make_person_better(&person2, "Bob", 10, 23, 1994);

    cr_assert_eq(success, TODO_NZ,
        "If the operation succeeded, what is the return value?");
    cr_assert_eq(
        person2.bday.month, TODO, "What is the month for this person?");
}

Test(about_structs, arrays_of_structs)
{
    /*
        Arrays of structures operate as would expect, when declaring the size,
        it accounts for the size of the struct.
    */

    struct s1 {
        int i;
        int j;
    };

    struct s1 a1[5];

    cr_assert_eq(sizeof a1, TODO, "What is the size of this array in bytes?");

    /*
        For arrays of structs, the size of the struct must be conscious of the
        size of the data in the struct for the alignment in memory.
        For this reason, the compiler will increase the size of the struct to
        account for this. This is known as 'padding'

        struct s2 has an int and a char, a single byte. The largest type here is
        the int, so to account for the alignment of the next possible int in
        memory, it will pad 3 extra bytes after the char c.
    */

    struct s2 {
        int i;
        char c;
    };

    cr_assert_eq(
        sizeof(struct s2), TODO, "What is the size of the padded struct?");

    /*
        Compilers will have special extensions to allow for the packing of
        structs.
        For the GNU compiler, GCC, this is the __attribute__(()) tag.
        The __attribute__((packed)) at the end of the definition will allow
        cause the struct to be 'packed'.
    */
    struct s3 {
        int i;
        char c;
    } __attribute__((packed));

    cr_assert_eq(
        sizeof(struct s3), TODO, "What is the size of the packed struct?");
}

Test(about_structs, self_referential_structs)
{
    /*
        Structs can be self referential, and have pointers to structs of the
        same struct that it is as members of the struct.
    */

    struct s1 {
        int i;
        int j;
        struct s1 *s;
    };

    struct s1 sv1;
    struct s1 sv2;

    sv1.s = &sv2;

    sv1.s->i = 10;
    sv1.s->j = 20;

    cr_assert_eq(
        sv1.s->i, TODO, "What is the value of the nested struct's value i?");
}
