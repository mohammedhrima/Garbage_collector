
I built "my_malloc" to solve leaks problems using linked list\
"my_malloc" function allocate a space in the heap and frees it at the end of the program\
so you don't have to worry about memory leaks,\
buuuut !!! if you want to 😒😒, you can use "my_free" or "my_free_all" (I built them for programs that run continuously to avoid memory overflow)
and they are protected from the double free

==================================================================

Prototype: \
&emsp;&emsp;my_malloc(size_t size_to_allocate) \
&emsp;&emsp;my_free(void *ptr) \
&emsp;&emsp;my_free_all(void)

==================================================================

I created a struct named "t_mal": \
    &emsp;&emsp;typedef struct s_mal\
    &emsp;&emsp;{\
	    &emsp;&emsp;&emsp;unsigned long address;\
	    &emsp;&emsp;&emsp;struct s_mal *next;\
	    &emsp;&emsp;&emsp;int is_free;\
    &emsp;&emsp;} t_mal;

- unsigned long address : keep the address of allocate space
- next: is a pointer to the next node in the linked list
- is_free: everytime you call "my_free" function, it free the allocated space and set "is_free" to true to avoid double free

==================================================================

- my_malloc: is built using malloc, you give it the size you want to allocate, \
&emsp;&emsp;&emsp;&emsp;&emsp;it allocate it, add it to the linked list and returns its address.

- my_free:   is build using free, it frees the allocated space by "my_malloc" and set it as NULL, takes pointer as parameter

- my_free_all: function that free all previous allocated spaces by "my_malloc", if they aren't freed by "my_free"

==================================================================
- how my_malloc works: \
I created a linked list , its head is declared as static variable, that means it's stored in the data segment of the memory,
when the program exit it automatically free the values pointed by it

==================================================================
- how to use my_malloc: #include "my_malloc_free/my_malloc_free.h" \
use it like malloc: \
&emsp;&emsp;char *ptr0 = my_malloc(1000); \
&emsp;&emsp;char **ptr1 = my_malloc(1000); \
&emsp;&emsp;char ***ptr2 = my_malloc(1000); \
&emsp;&emsp;int *ptr3 = my_malloc(1000); \
&emsp;&emsp;...
- compile it like this: gcc my_malloce_free/my_malloc_free.c your_file.c

==================================================================
- I added main.c , it includes a main in case you want to test the functions before using them \
\
\
![001](https://user-images.githubusercontent.com/71414472/212447316-2f09d29c-c43c-4607-964e-178c93f69fc6.png) \
\
![002](https://user-images.githubusercontent.com/71414472/212447477-0bac06ba-71a3-4894-9f8c-652302f84ce7.png) \
\
![003](https://user-images.githubusercontent.com/71414472/212447320-93845755-9044-4ed9-a00b-77b69d27da65.png) \
\
![004](https://user-images.githubusercontent.com/71414472/212447327-d8aed60f-f55c-4ebe-b54e-ec53aefdb312.png)

