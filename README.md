# CSE320 Homework 1 - Fall 2017
## Dr. Jennifer Wong-Ma

A kōan 公案 (pinyin: gōng'àn) is a story, dialogue, question, or statement, which is used in Zen practice to provoke the "great doubt" and test a student's progress in Zen practice.

Here you may learn the syntax and practices of C through a series of lessons in the form of [Unit tests](https://en.wikipedia.org/wiki/Unit_testing). These preprepared tests are all failing, by going through each one and repairing them to make them pass you will learn a small component of the C programming language.

# Sections

Inside `src/` you will find a file for each of the following topics in C:

- Basics: variables, assignment, addresses, intro pointers
- Pointers: arithmetic, pass by reference/value, address of, NULL
- Functions: function pointers, prototypes
- Arrays & Strings: label + offset vs pointer + offset, sizeof and its pitfalls
- Preprocessor: defines, conditional defines, code pitfalls (semicolon in define, use in for loop)
- Control Statements: If, While, For, Switch, Do While, Goto, Break, (pitfalls: If only takes next line if no {})
- Structs: more sizeof, typedef, pointer dereference, access `->` vs `.`, (One test with Union)
- Dataclasses (There's a better name for this): Enum, Extern, Static (Make a function that persists data in static var), Void
- I/O: Open (read, write, append), Read, Write, Close, Dup2
- Signals: sigaction, segfault, sigint (your OS's version of exceptions) (Use the unit test's acceptance of signal to test for success)
- Malloc: Dynamic memory allocation vs Stack, calloc, realloc, free
- Linked List Project: This one will be left for you to implement we have given all the unit tests for it, its a small culminating project that uses all you've learned from these tests.

# Contributors
- Neal Beeken
- Brian Gavin
- May Hoque
- Jaykumar Patel