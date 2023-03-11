## my_malloc and my_free

- Memory leaks and double free suck, I tried to built "my_malloc" to solve those problems
- my_malloc: function allocate a spaces in the heap (with malloc) and frees them when main exit
- my_free / my_free_all:\
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- for programs that keep running and allocating space continuously\
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- or in case your program could exit somewhere outside the main,\
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;put my_free_all() before exit()

## Usage :

```c
#include "C_garbage_collector/header.h"

void   *ptr0 =   (void*)my_malloc(1000);
int    *ptr1 =    (int*)my_malloc(2000);
char  **ptr2 =  (char**)my_malloc(5000);
char ***ptr3 = (char***)my_malloc(300);
                        my_free(ptr0);
                        my_free((uintptr_t)ptr1);
                        my_free((uintptr_t)ptr2);
```

## Running Tests

```bash
git clone git clone https://github.com/mohammedhrima/C_garbage_collector.git
```
```bash
gcc C_garbage_collector/utils.c your_file.c #don't forget to include C_garbage_collector/header.h
```

## Important : (what you need to know)

- void * , void**, void *** ..., are an addresses (for an allocate space in memory)
- Those addresses are also stored in memory and have the same size
- The number of '*' means only the level of pointer so compiler know many steps will do while navigate in the lowest level
of this data type, example:
``` c
char *str; 
str[2] = 'c'; // move 2*sizeof(char) step or we can say move 2 byte step
              // and change the character stored there to 'c'
char **arr;
arr[2] = "hello wrold"; // move 2*sizeof(char*) step or we can say move 2 * (8 bytes) step 
                        // and change the address stored to the address pointing to string "hello world"
```

```
        !!! size of pointer depends on computer architecture !!!
        In 32-bit computer machine sizeof(pointer) is 4 bytes
        In 64-bit computer machine sizeof(pointer) is 8 bytes
```

\
![001](https://user-images.githubusercontent.com/71414472/212447316-2f09d29c-c43c-4607-964e-178c93f69fc6.png) \
\
![002](https://user-images.githubusercontent.com/71414472/212447477-0bac06ba-71a3-4894-9f8c-652302f84ce7.png) \
\
![003](https://user-images.githubusercontent.com/71414472/212447320-93845755-9044-4ed9-a00b-77b69d27da65.png) \
\
![004](https://user-images.githubusercontent.com/71414472/212447327-d8aed60f-f55c-4ebe-b54e-ec53aefdb312.png)

