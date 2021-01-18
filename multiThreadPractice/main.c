//
//  main.c
//  multiThreadPractice
//  Using this to help learn about developing
//  programs with multiple threads
#include "multithreadFunctions.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pthread_t thread;   // Thread Descriptor
    int status;         // Status Variable to store the Status of the thread.
    
    status = pthread_create(&thread, NULL, customThreadFunctionExit, NULL);
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
    
    // Section to test out the pthread_equal
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, customThreadFunctionEqual, NULL);
    pthread_create(&thread2, NULL, customThreadFunctionEqual, NULL);
    
    if(pthread_equal(thread1, thread2))
    {
        printf("MAINTHREAD: Two theads are Equal..!\n");
    }
    else
    {
        printf("Two threads are not equal\n");
    }
    
    // Section to test out single argument thread
    char color[50];
    printf("What is your favorite color: \n");
    fgets(color, 50, stdin);
    
    pthread_t threadArgument;
    pthread_create(&threadArgument, NULL, singleArgumentThreadFunction, color);
    pthread_join(threadArgument, NULL);
    
    // Section to test out multiple argument thread
    struct arguments *person = (struct arguments *)malloc(sizeof(struct arguments));
    printf("This is a Simple Collection of Contact Information.\n");
    char name[50], email[50], phone[11];
    printf("Enter the name of the person: ");
    fgets(name, 50, stdin);
    printf("Enter the email of the person: ");
    //TODO: program is not reading the email address correctly.
    scanf("%s", &email);
    printf("Enter the phone of the person: ");
    scanf("%s", &phone);
    
    person->name = name;
    person->email = email;
    person->phone = phone;
    
    pthread_t threadMultiple;
    pthread_create(&threadMultiple, NULL, multipleArgumentsThreadFunction, (void *)person);
    pthread_join(threadMultiple, NULL);
    
    return 0;
    
}
