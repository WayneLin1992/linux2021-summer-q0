#include <stdio.h>
#include <unistd.h>

int main(void)
{
    for (int i = 0; i < 12; i++) {
        fork();
        printf("-");                         
    }

    fflush(stdout);
    return 0;
}
