#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *  To debug the child code follows the instructions
 *  $ gdb ./exec.out 
 *  (gdb) b main 
 *  (gdb) set follow-fork-mode child 
 *  (gdb) set follow-exec-mode new
 *  (gdb) r 
 * 
 *   when this process calls the new application
 *   it starts to debug spawns program 
 */

int main(int argc, char const *argv[])
{
    char *args[] = {
        "./message.out", "hello world", NULL
    };

    printf("Running other programming.\n");
    if(execvp(args[0], args)){
        printf("Error launch %s.\n", args[0]);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
