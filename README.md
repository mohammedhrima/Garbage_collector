
to check the program:
	run make
	
my_malloc(site_t size_to_allocate); </br>
my_free(void *ptr, int free_all)

</br>
my_malloc: is like malloc you give it the size you want to allocate</br>
my_free:   is like default free</br>
my_free_all: function that free all not freed allocated spaces</br>

example:</br>
&emsp;&emsp;char ***ptr = my_malloc(1000);</br>
&emsp;&emsp;my_free(ptr)

</br></br>
to use it,
include the header -> #include "my_malloc_free/my_malloc_free.h"
and compile it like this: gcc my_malloce_free/my_malloc_free.c your_file.c
