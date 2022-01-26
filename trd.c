/*Test program for the tracing system call. It forks a child and waits for the child to complete.
The child opens and closes a file to demonstrate the open and close system calls.
In the test program, we show the three different modes in which the system call can be used.
1. Only the process being traced
2. The process and its children being traced
3. Process not being traced*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "trace.h"

void forkrun() {
        int fr = fork();
        if(fr == -1) {
                printf(1, "Fork error!\n");
                return;
        }
        else if(fr == 0) {
                close(open("README", 0));
                exit();
        }
        else {
                wait();
        }
}

int main() {
        printf(1, "Process is being traced\n");
        trace(T_TRACE);
        forkrun();
        trace(T_UNTRACE);
        printf(1, "Process and children being traced\n");
        trace(T_TRACE | T_ONFORK);
        forkrun();
        trace(T_UNTRACE);
        printf(1, "Process not being traced\n");
        forkrun();
        exit();
}