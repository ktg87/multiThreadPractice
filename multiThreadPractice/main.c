//
//  main.c
//  multiThreadPractice
//  Using this to help learn about developing
//  programs with multiple threads

// Required Libraries
#include <stdio.h>    // Standard I/O Routines Library
#include <unistd.h>    // Unix Standard Library
#include <pthread.h>    // POSIX Thread Creation Library

/* Develop thread function to make the program multithreaded
 * Thread function must have a return type as a pointer
 */
void *customThreadFunction()
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


int main()
{
    pthread_t thread;   // Thread Descriptor
    int status;         // Status Variable to store the Status of the thread.
    
    status = pthread_create(&thread, NULL, customThreadFunction, NULL);
    /*  status = 0 ==> If thread is created Sucessfully.
     *  status = 1 ==> If thread is unable to create.
     */
    if(!status)
    {
        printf("Custom Created Successfully and starting to run.\n");
    }
    else
    {
        printf("Unable to create the Custom Thread.\n");
        return 0;
    }
    
    // Main Function For loop
    for(int i = 0; i < 15; i++)
    {
        printf("MAINTHREAD%d: I am the process thread created by compiler By default.\n", i);
        sleep(1);
    }
    
    return 0;
    
}
