## my_malloc_free

- memory leaks and double free suck

- So I built "my_malloc" to solve this problems

- my_malloc: function allocate a spaces in the heap (with malloc) and frees them when main exit
- my_free / my_free_all: free allocated spaces (for programs that keep running and allocate space continually)

## Usage :

```javascript
#include "my_malloc_free/my_malloc_free.h"

void   *ptr0 =   (void*)my_malloc(1000);
int    *ptr1 =    (int*)my_malloc(2000);
char  **ptr2 =  (char**)my_malloc(5000);
char ***ptr3 = (char***)my_malloc(300);
                        my_free(ptr0);
                        my_free((void *)ptr1);
                        my_free((void *)ptr2);

void * , void**, void *** ..., are just pointer or an address stored in memory, means they have the same size
the number of '*' means only the level of pointer so compiler know many steps will do while navigate in the lowest level
in this data type, example:
    char *str -> str[2] = 'c'
        move 2*sizeof(char) steps or we can say move 2 * 1byte steps
        and change the value stored there
        
    char **arr -> arr[2] = "hi"
        move 2*sizeof(char*) steps or we can say move 2 * 8bytes steps 
        and change the value stored there
        
        !!! size of pointer depends computer architecture !!!
        In 32-bit computer machine sizeof(pointer) is 4 bytes
        In 64-bit computer machine sizeof(pointer) is 8 bytes
```


## Running Tests

- Clone the repo
```bash
git clone https://github.com/mohammedhrima/my_malloc_free.git
```

- To run tests, run the following command
```bash
gcc my_malloce_free/my_malloc_free.c file.c (don't forget #include "my_malloc_free/my_malloc_free.h")
```

\
\
![001](https://user-images.githubusercontent.com/71414472/212447316-2f09d29c-c43c-4607-964e-178c93f69fc6.png) \
\
![002](https://user-images.githubusercontent.com/71414472/212447477-0bac06ba-71a3-4894-9f8c-652302f84ce7.png) \
\
![003](https://user-images.githubusercontent.com/71414472/212447320-93845755-9044-4ed9-a00b-77b69d27da65.png) \
\
![004](https://user-images.githubusercontent.com/71414472/212447327-d8aed60f-f55c-4ebe-b54e-ec53aefdb312.png)

