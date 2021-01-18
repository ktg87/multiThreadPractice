//
//  multithreadFunctions.h
//  multiThreadPractice
//
//

#ifndef multithreadFunctions_h
#define multithreadFunctions_h

struct arguments{
    char* name;
    char* email;
    char* phone;
};

void* customThreadFunctionExit(void*);
void* customThreadFunctionEqual(void*);
void* singleArgumentThreadFunction(void* input);
void* multipleArgumentsThreadFunction(void* contactInfo);

#endif /* multithreadFunctions_h */
