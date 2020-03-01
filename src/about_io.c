#include "c_koans.h"
#include <stdio.h>

/*
    This series of koans will go over topics not entirely specific to the C
    language itself, but is an essential topic for writing more-than-trivial
    C programs: IO. It is recommended to do the about_printing koan prior to
    this one.

    As IO is fairly environment specific, this koan will only go over the
    standard IO library that is supported by all platforms.

    It will be referred to as stdio, after the header file <stdio.h>
 */

Test(about_io, streams)
{
    /*
        Before we can go into detail about stdio we must discuss the
	foundation of the library, the three streams that are provided:
	stdin, stdout, and stderr

	Don't worry if you cannot fully understand these concepts, we will go
	into more detail about them as we go along.
    */

    /*
        stdin provides input, typically keyboard input from your terminal.

	The functions that interact with stdin will typically block the program
	waiting	until input is entered into the program.
    */

    cr_assert_str_eq("stdio", TODO_S, "The standard input stream is...");

    /*
        stdout provides output, which is typically your terminal screen.
    */

    cr_assert_str_eq("stdout", TODO_S, "The standard output stream is...");

    /*
        stderr is slightly different than stdin and stdout. This stream provides
	a stream to write error messages to. Under normal execution, it usually
	prints to the same place as stdout.

	Since it is a different stream entirely, tricks can be done such that
	it will instead write to a different place entirely, or its output is
	ignored and will not interfere with the regular output of a program.

	The aforementioned "tricks" are not related to the C language, so they
	will not be discussed in this koan, but it is an important topic for
	more advanced C programming.
    */

    cr_assert_str_eq("stderr", TODO_S,
		     "The output stream for error messages is...");
}

Test(about_io, using_streams)
{
    /*
        Now that we are familiar with the three streams given to us, we can go
	over the functions that utilize streams.

	Most of the functions that we have seen before that use stdout by
	default have stream-using counterparts.

	For simplicity, we will use fputs, the stream counterpart of puts.
    */

    /*
        For this koan, output "Hello World" to both stdout and stderr.
	<stdio.h> provides variables for accessing the streams, which are just
	the names that we have been referring to them until now
	(stdin, stdout, and stderr)
    */

    fputs("Hello World", TODO_FP);
    fputs("Hello World", TODO_FP);

    cr_assert_file_contents_eq_str(stdout, "Hello World");
    cr_assert_file_contents_eq_str(stderr, "Hello World");

    /*
        "But what exactly is a stream?" you may ask. This question will be
	answered in the next koan.
    */
}

Test(about_io, file_io)
{
    /*
        The standard io library, <stdio.h> provides a FILE type for standard io
        usages. Any pointer of type FILE* is referred to as a "stream." So, this
	means that the variables we have been using thus far have been type
	FILE*.

	Streams can be used for our own file input and output. This koan will
	go over opening from and reading from a file.
    */

    FILE *f;
    char buf[1024];
    /*
        fopen takes a path to a file and a mode, in this case we are opening in
        read only mode.
    */
    f = fopen("rsrc/file.txt", "r");

    /*
        fgets will read at most the number of bytes specified into the given
        buffer from the stream. fgets will read until it reads the number of
        bytes, it hits a new line character or until it gets EOF.
    */
    fgets(buf, 1024, f);

    cr_assert_str_eq(buf, TODO_S, "view rsrc/file.txt to see what buf should be");
}

Test(about_io, buffered_io)
{
    /*
        One of the most important aspects of the standard io library is that
	it is buffered. What does this mean? It means that every write is not
	immediately written to the stream, for efficiency purposes.

	Every write is first written to a buffer in memory before it is written
	to the stream, and is instead all written together in one big write at
	a later time. Since IO is expensive, reducing the number of times these
	operations are done saves quite a bit of time.

	Reads on the other hand are done in large chunks, so reading from a
	stream will be reading from a buffer in memory.

	To send what's in the buffer to the stream without waiting, stdio has
	a function fflush that will "flush" a stream's buffer.
    */

    /*
        For this koan, output "foo" to stdout. This may seem trivial, but the
	added "fflush" changes this operation quite a bit under the hood.
    */
    fputs(TODO_S, TODO_FP);
    fflush(stdout);
    cr_assert_file_contents_eq_str(stdout, "foo");
}
