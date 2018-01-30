# c_koans

[![Build Status](https://travis-ci.org/c-koans/c_koans.svg?branch=develop)](https://travis-ci.org/c-koans/c_koans)

A kōan 公案 (pinyin: gōng'àn) is a story, question, or statement, which is used in Zen practice to provoke the "great doubt" and test a student's progress in Zen practice.

Inspired by [ruby koans](http://rubykoans.com/) you may learn the syntax and practices of C through a series of lessons in the form of [Unit tests](https://en.wikipedia.org/wiki/Unit_testing). These preprepared tests are all failing, by going through each one and repairing them to make them pass you will learn a small component of the C programming language.

The test are written in the [Criterion](https://github.com/Snaipe/Criterion) unit testing library.

## How to run

### On Linux/OSX:

1. Install [Criterion](https://github.com/Snaipe/Criterion)
2. run `make clean all`
3. run `bin/c_koans`
4. Start fixing!

### On Windows:

1. Get a Linux command line ([Cygwin](http://www.cygwin.com/), [Windows Linux Subsystem](https://docs.microsoft.com/en-us/windows/wsl/install-win10), or whichever you prefer)
2. Follow the Linux/OSX instructions!

## Sections

Inside `src/` you will find a file for each of the following topics in C:

- Basics
- Pointers
- Functions
- Arrays
- Strings
- The Preprocessor
- Control Statements
- Structs
- Dataclasses
- I/O
- Malloc
- Linked List Project

The recommended order for fixing the tests is:
- about_basics.c
- about_control_statements.c
- about_functions.c
- about_pointers.c
- about_malloc.c
- about_arrays.c
- about_strings.c
- about_structs.c
- about_dataclasses.c
- about_printing.c
- about_io.c
- about_linked_lists.c
- about_preprocessor.c
