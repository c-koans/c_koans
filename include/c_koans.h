#ifndef CKOANS_H
#define CKOANS_H

#define TODO 0
#define TODO_NZ 1

extern int global_var;

int string_compare(const void *p1, const void *p2);

void double_an_int(int *i);

int modify_global();
int modify_local();
int modify_local_static();

#endif
