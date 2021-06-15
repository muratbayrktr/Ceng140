#include <stdio.h>
#define posLen 10


int append(int val, int position, char* ascii_result)
{
    int i;
    int var = val;
    for (i = 100; i >= 1; i = i/10)
    {
        int digit = var/i;
        char c = digit + '0';
        var = var - digit*i;
        
        ascii_result[position++] = c;
        
    }
    return position;
}





void to_ascii (char * sentence, int * positions, int count, char * ascii_result)
{
    int i = 0;
    int k = 0;
    while (positions[i] != 0)
    {
        int j = 0;
        while (j < count)
        {
            char c = *(sentence + *(positions+i) + j);
            if ((c>= 'A' && c<= 'Z') || (c>= 'a' && c<= 'z'))
            {
                int val = (int) c;
                k = append(val, k, ascii_result);
                printf("ascii value of char %c is : %d\n",c,val);
            } else {
                ascii_result[k++] = c;
            }
            j++;
        }
        i++;
    }

    return;
}



int main(){

        int arr[posLen] = {0};

        char sentence[256] = "Lab Exam 2 of the Ceng140 Course!";

        char ascii_result[256] = "";

        int i;

        arr[0] = 4;

        arr[1] = 10;

        arr[2] = 18;

        to_ascii(sentence, arr, 3, ascii_result);

        printf("%s\n",ascii_result);
        
        /* Content of the ascii_result = "069120097 111102067101110" */
        return 0;
    }


/*
This function takes 4 parameters: a character array ('sentence'), a 'positions' array that contains some sorted integer positions and an integer number 'count', result array ('ascii_result') that is supposed to be filled in this function.

Now, your job is to get the 'count' number of characters from each position and add them to the 'ascii_result' array by converting them into their ASCII codes. You may assume there is enough space in the ascii_result array and positions are sorted. Each ASCII code should be in 3 digit form (90 --> 090). If you encounter white space or some punctuations (the encountered character is not a lowercase or uppercase letter) just add them as they are with no change.

Note: You may assume there will be no problematic position (position+count will not exceed the sentence or there will be no nonpositive position).

Hint 1: You should find each digit of the found ASCII code and convert it to character digit by digit.

Hint 2: You can find the ASCII value of a character by converting it to int.
char x = ’A’;
int y = (int) x;

Hint 3: You can convert an integer value to a char by using the following:

int x = 3;

char y = x + '0';

int main(){

        int arr[posLen] = {0};

        char sentence[256] = "Lab Exam 2 of the Ceng140 Course!";

        char ascii_result[256] = "";

        arr[0] = 4;

        arr[1] = 10;

        arr[2] = 18;

        to_ascii(sentence, arr, 3, ascii_result);

        // Content of the ascii_result = "069120097 111102067101110"

    }

Explanation: 
Now we have a sorted integer array of positions. By starting arr[0] (which is 4)we take 3 characters from the sentence which are: ”Exa”
• ASCII value of ’E’ = 69, since it is 2 digit we add 0 at the beginning of it.
• ASCII value of ’x’ = 120.
• ASCII value of ’a’ = 97, we add 0 to the left→097.
Now, we add these values to the ascii_result array.
ascii_result = ”069120097”.

Next, we get the second position which is 10 and read 3 characters from there: ” of”.
• Since ” ” is not in range of our standards (neither uppercase nor lowercase letter) we directly add it.
• ASCII value of ”o” is 111.
• ASCII value of ”f” is 102. 
We add them into the array and continue. 
ascii_result = ”069120097 111102”.

Next, we have pos 18, we take 3 characters again: ”Cen”
•ASCII value of ’C’ is 67, by adding 0 to the left→067.
•ASCII value of ’e’ is 101.
•ASCII value of ’n’ is 110.
ascii_result = ”069120097 111102067101110”.
*/