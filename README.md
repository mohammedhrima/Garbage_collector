
I built "my_malloc" to solve leaks problems using linked list\
my_malloc function allocate a space in the heap and frees it at the end of the program
so you don't have to worry about memory leak,
buuuut !!! if you want to 😒😒, you can use "my_free" or "my_free_all" (I built them for program that runs continuously)

\
to check the program:
	run make

Prototype: \
&emsp;&emsp;my_malloc(size_t size_to_allocate) \
&emsp;&emsp;my_free(void *ptr) \
&emsp;&emsp;my_free_all(void)

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


my_malloc: is built using malloc, you give it the size you want to allocate, \
&emsp;&emsp;&emsp;&emsp;&emsp;it allocate it, add it to the linked list and returns its address.

my_free:   is build using free, it frees the allocated space by "my_malloc", takes pointer as parameter (you don't have to use it, it's opional)

my_free_all: function that free all previous allocated spaces by "my_malloc", if they aren't freed (you don't have to use it, it's opional)

the head of the node is declared as static variable, that means it's stored in the data segment of the memory,
when the program exit it automatically free the values pointed by the head

example:    
    char ***ptr = my_malloc(1000);


to use it: \
&emsp;&emsp;&emsp;&emsp;include the header -> #include "my_malloc_free/my_malloc_free.h" \
&emsp;&emsp;&emsp;&emsp;and compile it like this: \
&emsp;&emsp;&emsp;&emsp;gcc my_malloce_free/my_malloc_free.c your_file.c
