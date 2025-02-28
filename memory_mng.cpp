/*
- Memory Types:
               - RAM, ROM
               - Cache (L1,L2,L3)
               - Registers
               - virtual memory
               - Hard disks, usb drives

- Virtual memory: The basic idea of virtual memory is to separate the addresses
                  a program may use from the addresses in physical computer memory.
                  by using a mapping function an access to virtual program memory
                  can be redirected to a real address which is guaranteed to be protected
                  from other programs.

                  Assigns a contigous and well ordered block of memory to each program.

- Problems of physical memory: Programs writing over each other if several programs are allowed
                            to access the same memory address and holes in address space.
                            
- Heap: also called " Free store"    
      > it is shared among multiple threads in a program
      > contrary to the stack, the heap is not managed automatically by the system
       but by the programmer
      > If memory is allocated on the heap, it is the programmer's responsibility to free it
      > unlike the stack, the heap is shared among multiple threads which means that memory
      managment for the heap needs to take concurrency into account as several threads might
      compete for the same memory resource.
      > Heap memory grows upward while the stack grows in the opposite direction
      
- Types of memory allocation
    > Static memory allocation: for static global vars which are stored in data and bss.
    > Automatoc memory allocation: for function parameters and local vars which are stored in the stack.
    > Dynamic memory allocation: is a possibility for programs to request memory from the OS at runtime
                                and it is not performed on the limited stack but on the heap and almost
                                only limited by the size of the address space.
                                allocation request using > "malloc" (memory allocation) or "new" or
                                                          "calloc" (cleared memory allocation)
                                deallocation using > "Free" or "delete"
NB: stack should be the default choice for memory allocation as it has faster access as it is done by OS
    but the stack  size is limited so we use heap.                                    
      
- Properties of dynamic allocation:
        > memory allocated inside a function without it being deleted when the scope is left.  
        > local variables on the stack allocated at compile time, thus the size of a string var
          might not be appropirate as the length of the string will not be known until the program
          is executed and the user inputs it but with dynamically allocated heap memory, vars are allocated
          at runtime. this means that the size of the above mentioned string can be tailored to the actual
          length of the user input.  

- Malloc: ptr_name = ( cast_type *) malloc (size)   
         is used to dynamically allocate a single large block of memory with specified size
         it returns a pointer of type void which can be cast into a pointer of any form.

- Calloc: ptr_name = ( cast_type *) calloc (num_elements, size_elements)      
          is used to dynamically allocated specified number of blocks of memory
          of specified type, it initialize each block with a default value '0'  

- Realloc: to change the size of the dynamically allocated memory block during runtime   

- Freeing up memory: if memory has been reserved, it should be released as soon as it is no longer needed
                     to do this, the pointer pointing to the memory area to be freed is specified
                     as a parameter for the Free 
                     free(p);

- New and delete: with introduction of classes and oop in c++, memory allocation & de allocation has 
                 become more complex, when an object is created it's constructor needs to be called
                 to allow for member initialization and on object deletion, the destructor is called
                 to free resources
                 for this reason, c++ introduces the operators new/delete which represent the object oriented 
                 counter part to memory managment malloc/free.

NB: malloc & free > are functions
    new & delete > are operators
                  
- NB: don't use delete twice to avoid code crashing

- Overloading new and delete: one of the major advantages of new/delete over free/malloc
                              is the possibility of overloading.

- Memory Management problems:
              1- Memory leaks: occur when data is allocated on the heap at runtime
                              but not properly deallocated.
                              
              2- Buffer overruns: occur when memory outside the allocated limits
                                  is overwritten and thus corrupted.
                                  
              3- Unintialized memory: when allocating a memory on the heap without
                                      proper initialization, it might sometimes contain
                                      garbage that can cause problems.
                                      
                                      
- Smart pointers: Resource acquisition is initialization (RAII)     
                 when a smart pointer is no longer needed (which is the case as soon as it goes out of scope) 
                 the memory to which it points is automatically deallocated.  
                 
- Smart pointer overview: 3 types of smart pointers
                      > unique pointer std::unique_ptr
                      is a smart pointer which exclusively owns a dynamically allocated resource
                      on the heap, there must not be a second unique ptr to the same resource.
                      as soon as the unique pointer goes out of scope, the memory resource
                      is deallocated again.
                      std::unique_ptr <Type> P (new Type);
                      
                      > shared pointer std::shared_ptr
                      points to a heap resource but does not explicitly own it.
                      there may even be several shared pointers to the same resource,
                      each of which will increase an internal reference counter
                      as soon as this counter reaches zero, the resource will automatically
                      be deallocated.

                      is useful for cases where you require access to a memory location on the heap
                      in multiple parts of your program and you want to make sure that whoever
                      owns a shared pointer to the memory can rely on the fact that it will
                      be accessible through the lifetime of that Ptr.

                      > weak pointer std::weak_ptr
                       behaves similar to the shared pointer but does not increase 
                       the reference counter.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>

//or 
//#include<malloc.h>

using std::cout;

struct myStruct
{
    int i;
    double d;
    char a[5];
};

class Myclass
{
    private:
    int* ptr;

    public:

    // class constructor
    Myclass()
    {
        cout << "Allocate memory" << std::endl;
        ptr = (int *) malloc (sizeof(int));
    }

    // class destructor
    ~Myclass()
    {
        cout << "Delete memory" << std::endl;
        free(ptr);

    }

    void SetNumber(int num)
    {
        *ptr = num;
        cout << "Number:" << *ptr << "\n";
    }

};

                     /* new/delete overloading example */
// void* operator new (size_t size)    
// {
//     cout << "new:allocating" << size << "bytes of memory" << "\n";
//     void* p = malloc(size);

//     return p;

// }  
 
// void operator delete (void* p)
// {
//     cout << "delete:memory is free" << "\n";

//     free (p);
// }
//                         /* new[] / delete[] overloading example */
// use the following code to create an array of objects

// void* operator new[] (size_t size);

// void operator delete (void*);

/* let us use the principles of RAII to create a management class that calls
   delete automatically */
class MyInit
{
    // pointer to heap data
    int* _p;

    public:
    // constructor to initialize the pointer with null
    MyInit(int* p = NULL)
    {
        _p = p;

    }

    // destructor 
    ~MyInit()
    {
        cout << " resource" << *_p << " deallocated" << std::endl;
        delete _p;
    }

    //overload derefernece operator
    int& operator* ()
    {
        return *_p;
    }

};

                            /* Smart pointer Examples */
void RawPointer ()        
{
    // raw Ptr on the heap
    int* raw = new int;

    //assign a value
    *raw = 1;

    // delete resource again
    delete raw;
}    

void UniquePointer ()
{
    // create a unique Ptr on the stack
    std::unique_ptr <int> unique (new int);

    //assign a value
    *unique = 2;
}

int main ()
{
    int *p = (int*) malloc (sizeof(int));

    int *p2 = (int*) malloc ( 2* sizeof(int));
    p2[0] = 1;
    p2[1] = 2;

    // resize memory to hold 4 integers, p2 is the address of pointer which have the old memory block
    p2 = (int*) realloc (p2,4 * sizeof(int));

    p2[2] = 3;
    p2[3] = 4;

    // resize memory again to hold 2 integers, p2 is the address of pointer which have the old memory block
    p2 = (int*) realloc (p2,2 * sizeof(int));
    // p2[3] = 6;
    // p2[4] = 6;

    myStruct *p3 = (myStruct*) calloc(4, sizeof(myStruct));

    // cout << "address: " << " " << p << std::endl;
    // cout << "address: " << " " << p2 << std::endl;

    //cout << p2[0] << p2[1] << p2[2] << p2[3] << p2[4] << std::endl;

                          /* malloc and free example */
    // Allocate memory using malloc function
    Myclass *PtrClass = (Myclass*) malloc (sizeof(Myclass));
    // *. = ->
    PtrClass -> SetNumber(42);
    // Free it using free function
    free(PtrClass);

    /* NB: using malloc and free, we should call the construcor and the destructor
    to avoid code crashing while calling SetNumber function in the main
    but using new and delete, we don't have to call the constructor and destructor explicitly
    as they are called implicitly */

                       /* new and delete example */
    // Allocate memory using new operator  
    Myclass *PtrClasss = new Myclass();
    PtrClasss -> SetNumber(43);
    delete PtrClasss;

                        /* RAII examples */
    double den[] = {1.0, 2.0, 3.0, 4.0,5.0};
    
    // for (size_t i=0; i < 5; i++)
    // {
    //     //allocate the resource on the heap
    //     double* en = new double(i);

    //     cout<< *en << "/" << den[i] << "=" << *en/den[i] << std::endl;

    //     /* deallocate the resource, and note that we may forgot to delete the resource
    //        so let us use the principles of RAII to create a management class that calls
    //        delete automatically */
    //     delete en;
    // }

                  /* shared pointer example */
    std::shared_ptr <int> shared1 (new int);
    cout << " shared pointer count = " << shared1.use_count()  << std::endl;

    {
        std::shared_ptr <int> shared2 = shared1;
        cout << " shared pointer count = " << shared1.use_count() << std::endl;
    }   
    cout << " shared pointer count = " << shared1.use_count() << std::endl;         

    return 0;
}
