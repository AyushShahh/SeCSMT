# SeCSMT
Secure Cryptographic Seed Modulo and Twirl Hash algorithm.

Takes a string and bucket size as an input and computes an index for a hash table array. The bucket size should atleast be around 2.22 times the number of words you want to index to keep the number of collissions at minimum.

## Usage
Download `csmt.h` and `csmt.c` from [releases](https://github.com/AyushShahh/SeCSMT/releases/tag/v1.0) and keep then in the root folder with respect to your C file.<br>Add this line in the beginning of your file:
```c
#include "csmt.h"
```
For example if your file name is `main.c` then compile it with gcc using this command:
```terminal
$ gcc -o main main.c csmt.c
```

## Performance
There is a file in this repository named `large` with 143091 words.
```terminal
Total words: 143091
Bucket size: 329081
Collisions: 26766
Empty: 212756
```
