#include "csmt.h"
#include <string.h>


unsigned int hash(char *word, unsigned int bucket)
{
    int seed = 15053;
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash + (seed % (word[i] - 38))) * (word[i] + 19);
        seed -= 10;
    }
    hash %= bucket;
    return hash;
}