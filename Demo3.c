//Write a program to create a pipe and show their read and write pipe descriptors
#include <stdio.h>
#include <unistd.h>
int main() 
{
    int pipefds[2]; 
    if (pipe(pipefds) == -1)
    {
        printf("pipe");
        return 1;
    }
    printf("Read descriptor: %d\n", pipefds[0]);
    printf("Write descriptor: %d\n", pipefds[1]);
    return 0;
}
