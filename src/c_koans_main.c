#include "c_koans.h"
#include <criterion/criterion.h>

#define FILTER(test_file) { "bin/c_koans", "--filter", "about_"#test_file"/*", NULL}
#define KOAN_COUNT 13
#define FILTER_ARG_COUNT 3

static const char *FILTER_MAP[][4] = {
    FILTER(basics),
    FILTER(control_statements),
    FILTER(functions),
    FILTER(pointers),
    FILTER(malloc),
    FILTER(arrays),
    FILTER(strings),
    FILTER(structs),
    FILTER(dataclasses),
    FILTER(printing),
    FILTER(io),
    FILTER(linked_lists),
    FILTER(preprocessor)
};

int main()
{
    int res = 0;
    int i = 0;
    struct criterion_test_set *tests;
    for(i = 0; i < KOAN_COUNT; i++) {
        tests = criterion_initialize();
        if(criterion_handle_args(FILTER_ARG_COUNT, (char**)FILTER_MAP[i], true))
            res = !criterion_run_all_tests(tests);
        criterion_finalize(tests);
    }
    return res;
}
