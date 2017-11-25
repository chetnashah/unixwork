
Three primary functions for processcontrol :
1. fork
2. exec
3. waitpid


Threading model in unix is Pthreads which is short for posix threads:

NOTE: On Linux, programs that use Pthreads API should compiled using -pthread
flag and the header file to include is \<pthread.h\>.

A process can have multiple threads.
All threads in a given process share same heap and data segments,
but different stack.

Attributes per process (shared by all threads of the process):
1.  pid, ppid
2.  pgid, sessionid
3.  user and group IDs
4.  open file descriptors
5.  signal dispositions
6.  file mode creation mask (umask)
7.  current directory and root directory
8.  interval timers and posix timers
9.  nice value and resource limits
10.  measurements of consumption of cpu time
11.  heap

Attributes per thread:
1. stack
2. threadId (tid)
3. signal mask
4. errno variable
5. alternate signal stack
6. real-time scheduling policy and priority

Note most pthread functions return 0 or errno (they don't set errno),
unlike system calls which return -1 and set errno.


Thread ids are unique only within a process, and not guaranteed to be globally
unique.







