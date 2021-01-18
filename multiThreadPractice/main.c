//
//  main.c
//  multiThreadPractice
//  Using this to help learn about developing
//  programs with multiple threads
#include "multithreadFunctions.h"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

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
