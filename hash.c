#include <stdio.h>
#include <stdlib.h>
#include "csmt.h"

const int LENGTH = 45;
const unsigned int bucket = 329081; // 284751, 30620 - 329081, 26766 - 314807, 27954 - 319097, 27741
const unsigned int words = 143091;

int main(void)
{
    FILE *f = fopen("large", "r");
    if (f == NULL)
    {
        printf("cannot open file\n");
        return 1;
    }

    char w[LENGTH + 1];
    int indices[words];
    printf("\n");
    unsigned int c = 0;
    while (fscanf(f, "%s", w) != EOF)
    {
        indices[c] = hash(w, bucket);
        c++;
    }
    printf("Total words: %i\n", words);
    printf("Bucket size: %i\n", bucket);
    int collisions = 0;
    for (int i = 0; i < words; i++)
    {
        if (indices[i] != 0x0)
        {
            for (int j = i + 1; j < words; j++)
            {
                if (indices[j] != 0x0)
                {
                    if (indices[i] == indices[j])
                    {
                        collisions++;
                        indices[j] = 0x0;
                    }
                }
            }
        }
    }
    printf("Collisions: %i\n", collisions);
    printf("Empty: %i\n\n", bucket - words + collisions);
    fclose(f);
    return 0;
}