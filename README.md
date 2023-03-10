## my_malloc_free

- memory leaks sucks

- So I built "my_malloc" to solve this problems

- my_malloc: function allocate a spaces in the heap and frees them when main exit automatically (you don't have to free them)

## Usage :

```javascript
#include "my_malloc_free/my_malloc_free.h"

void   *ptr0 =   (void*)my_malloc(1000);
int    *ptr1 =    (int*)my_malloc(2000);
char  **ptr2 =  (char**)my_malloc(5000);
char ***ptr3 = (char***)my_malloc(300);
```

- in case you faced memory over flow problem use:
```bash
    my_free(void *ptr); // to free specific address
    or 
    my_free_all(void); // to free all allocated spaces with my_malloc
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

