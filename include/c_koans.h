#include <criterion/criterion.h>
#include <criterion/redirect.h>

#ifndef CKOANS_H
#define CKOANS_H

#define TODO 0
#define TODO_NZ 1
#define TODO_S ""
#define TODO_FP (FILE*) NULL

typedef struct {
    int month;
    int day;
    int year;
} birthday;

struct person {
    char *name;
    birthday bday;
};

extern int global_var;

int string_compare(const void *p1, const void *p2);

void double_an_int(int *i);

int modify_global();
int modify_local();
int modify_local_static();

struct person make_person(const char *, int, int, int);
int make_person_better(struct person *, const char *, int, int, int);
#endif
