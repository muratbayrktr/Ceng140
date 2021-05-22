#include <stdio.h>
#include "lab2_copy.h"

int main()
{
    char sentence[256] = "This is the lab exam of CENG140 of Ceng department (in english version)!";

    char substr[10] = "eng!";

    int arr[10], i;

    to_lower(sentence);

    substrings(sentence, substr, arr);

    /* Content of arr is {25,36,55} */

    for (i = 0; i < 10; i++) {
        printf("%d\n",arr[i]);
    }

    removeX(sentence, arr, 3);

    print_sentence(sentence);


    return 0;
}