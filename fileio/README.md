
Instead of using exit(0) and exit(1) for success and error,
use exit(EXIT_SUCCESS) and exit(EXIT_FAILURE)
and these constants EXIT_SUCCESS, EXIT_FAILURE are defined in stdlib.h

stdio (standard io) is buffered interface to stdin, stdout

open, read, write, lseek and close do unbuffered IO.

The file descriptor values for stdin and stdout are
0 and 1, but it is better to use STDIN_FILENO and STDOUT_FILENO
for portability

getc, getchar and friends all who use stdin are buffered and flushed
on newline
```
getc(FILE \*stream);
getchar() is same as getc(stdin);
```

stdin and stdout are FILE\* that are available to all programs

fgets - newline charachter makes fgets stop reading but newline char
is also copied to the buffer.

System calls like read, write etc. return no of bytes stuff done,
and -1 on error, and set corresponding errno.

Use strerror(errno) which returns string that is human readable
description of what errno represents.
AS a result for any handling of syscall, import errno.h and string.h
Here is some good practice
``` C
// most syscalls return -1 on error and set errno
if (somesyscall() == -1) {
    int errsv = errno; // save errno
    printf("somecall() failed due to : %s", strerror(errsv));
}
```

I thought I could implement ls myself in following way:
use open("."), read() contents and output.
But I was wrong.
read() on a fd which represents a dir throws error EISDIR,
means one cannot perform read() on a fd that represents dir,
one has to use opendir() and readdir()


#### Usefule Time structs

    // tm is calendar time broken into its components
    struct tm {
        int tm_sec;
        int tm_min;
        int tm_hour;
        int tm_day;
        int tm_mon;
        int tm_year;
        int tm_wday; // weekday [0,6] (Sunday = 0)
        int tm_yday; // day of the year [0,365]
        int tm_isdst; // daylight savings flag
    }

    // below structures are more useful for duration time etc.
    struct timeval {
        time_t tv_sec;  // whole number seconds
        long int tv_usec; // rest in microseconds
    }

    // same as above but with nanosecond precision
    struct timespec {
        time_t tv_sec; // whole number seconds
        long int tv_nsec; // rest in nanoseconds
    }

