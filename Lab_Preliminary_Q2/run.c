#include <stdio.h>
#include "lab2_copy.h"

int main()
{
    char sentence[256] = "This is the lab exam of CENG140 of Ceng department (in english version)!";

    char substr[10] = "eng!";

    int arr[10];

    to_lower(sentence);

    substrings(sentence, substr, arr);

    addSome(sentence, arr, substr);

    print_sentence(sentence);

    return 0;
}