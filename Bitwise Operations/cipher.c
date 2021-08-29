/* X-Platform OS import solution */
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>

void print_bin(char n)
{
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf(" ");
}

void print_text_bin(char *n)
{
    while (*n != '\0')
    {
        print_bin(*(n++));
    }
    printf("\n");
}

char* get_text(char *text, unsigned long int *len)
{
    char ch, *cur;
    int i = 1;
    text = (char *) malloc(sizeof(char));
    cur = text;
    while ((ch = getchar()) != EOF)
    {
        text = realloc(text, i*sizeof(char));

        *(cur++) = ch;

        i++;
    }
    *cur = '\0';
    *len = i-2;
    return text;
}


void encode_by(char* text, char key)
{
    char *cur = text;

    while (*cur)
    {
        *(cur++) = ((((*cur ^ key) ^ 0x5) ^ 0x7) ^ 0x3) ^ 0x1 ;  
    }

}


void decode_by(char* text, char key)
{
    char *cur = text;

    while (*cur)
    {
        *(cur++) = ((((*cur ^ 0x1) ^ 0x3) ^ 0x7) ^ 0x5) ^ key;  
    }
}

int main(void)
{
    char *text; unsigned long int *len = malloc(sizeof(unsigned long int)); unsigned long int i = 0;

    printf("input your text:\n");
    
    text = get_text(text, len);

    printf("size: %ld\nstring: \"%s\"\nText is being encoded with cryptographic bit manupilation, bit key: 'x' \n", *len, text);
    
    usleep(750000);

    print_text_bin(text);

    encode_by(text, 0xd);

    printf("encoded string: \"%s\"\nencoded binary: ", text);
    
    print_text_bin(text);

    decode_by(text, 0xd);

    printf("decoded string: \"%s\"\n", text);


    return 0;
}