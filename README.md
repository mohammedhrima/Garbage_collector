## Usage :
```c
#include "header.h"

void   *ptr0 = allocate(1000);
int    *ptr1 = allocate(2000);
free_address(ptr1);
char  **ptr2 = allocate(5000);
char ***ptr3 = allocate(300);
free_memory();
```

## Running Tests
```bash
git clone https://github.com/mohammedhrima/Garbage_collector.git
```
```bash
gcc memory.c your_file.c #don't forget to include header.h
```

## Important : (what you need to know)
```
    - void * , char**, int*** ..., are pointers that holds addresses
    - Those pointers have the same size
    - size of pointer depends on computer architecture !!!
        - in 32-bit CPU size of pointer is 4 bytes
        - in 64-bit CPU size of pointer is 8 bytes
        ...
```
