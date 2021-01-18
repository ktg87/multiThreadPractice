//
//  multithreadFunctions.c
//  multiThreadPractice
//
//

#include "multithreadFunctions.h"

// Required Libraries
#include <stdio.h>    // Standard I/O Routines Library
#include <unistd.h>    // Unix Standard Library
#include <pthread.h>    // POSIX Thread Creation Library

/* Develop thread function to make the program multithreaded
 * Thread function must have a return type as a pointer
 */
void* customThreadFunctionExit(void* s)
{
    for (int i = 0; i < 15; i++)
    {
        printf("CUSTOMTHREAD%d: I am a Custom Thread Function Created By Programmer.\n", i);
        sleep(1);
        if (i == 5)
        {
            // By using pthread_exit, this function will stop running before the
            // for loop iterates through all of its iterations.
            // Not, the main thread created by the compiler continues to run until
            // the program completes.
            printf("I have finished my task.  Time to terminate using pthread_exit.\n");
            pthread_exit(NULL);
        }
    }

    return NULL;
}

void* customThreadFunctionEqual(void* s)
{
    printf("This is a custom function to test out pthread_equal.\n");
    return NULL;
}

void *singleArgumentThreadFunction(void *input)
{
    printf("Another Thread: Hey, here is your input --> %s\n", (char *)input);
    pthread_exit(NULL);
}

void *multipleArgumentsThreadFunction(void *contactInfo)
{
    printf("Name: %s", ((struct arguments*)contactInfo)->name);
    printf("Email: %s", ((struct arguments*)contactInfo)->email);
    printf("Phone: %s", ((struct arguments*)contactInfo)->phone);
    return NULL;
}
