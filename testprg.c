/*test program to show the interrupt number 78 occurring when we try to access an out-of-bounds index in an array.
The user program testprg calls the “int” instruction to run the exception handler in the kernel*/

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int n, ch, index=0, i;
    char c, junk;
    printf(1, "Enter the number of elements in the array\n");
    n = read(0, &c, 1);
    n = read(0, &junk, 1);
    n = c - '0';
    int arr[n];
    while(1) {
        printf(1, "Enter 1 to insert an element, 2 to display and 3 to exit\n");
        ch = read(0, &c, 1);
        ch = read(0, &junk, 1);
        ch = c - '0';
        switch(ch) {
            case 1:
                if(index==n)
                    asm("int $78");
                printf(1, "Enter the element to be entered\n");
                arr[index] = read(0, &c, 1);
                arr[index] = read(0, &junk, 1);
                arr[index] = c - '0';
                index = index + 1;
                break;
            case 2:
                for(i=0;i<index;i++)
                    printf(1, "%d\t", arr[i]);
                printf(1, "\n");
                break;
            case 3:
                exit();
            default:
                printf(1, "Invalid choice\n");
                break;
        }
    }
    exit();
}