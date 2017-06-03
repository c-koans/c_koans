#include <criterion/criterion.h>

Test(c_koans, ifs){
    int var = 0;

    if(var)
        var = 1;
    else
        var = 2;

    cr_assert_eq(var, 3, "If statements work just like other languages");
}
