// Jonathan Rivera
// CS 561
// Domletters
//
// Sources:
// https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
// https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/

#include "domletters.h"

int countDomletters(string input);
int maxValue(int array[]);

int main()
{
    string input;
    int count = 0;

    while (getline(cin, input))
    {
        count += countDomletters(input);
    }

    cout << count << endl;

    return 0;
}

// This function counts the dominant letters in the input text.
// It returns an integer.
int countDomletters(string input)
{
    int count = 0;
    int length = input.length();
    string word = "";
    int i;
    bool alpha_flag = true;
    int ascii[128];

    for (i = 0; i < 128; ++i)
    {
        ascii[i] = 0;
    }

    // iterate through the string
    for (i = 0; i <= length; ++i)
    {
        char ch = input[i];
        int max_index = 0;
        int max_val = 0;

        if (isalpha(ch))
        {
            ascii[int(ch)] += 1;
            word = word + ch;
        }
        else if (ch != ' ' && ch != '\0')
        {
            word = "";
            alpha_flag = false;

            // reset array to zeroes
            for (int j = 0; j < 128; ++j)
            {
                ascii[j] = 0;
            }
        }
        else
        {
            max_val = maxValue(ascii);
            max_index = distance(ascii, max_element(ascii, ascii + 128));

            // Need to account for capital and lowercase
            // versions of the same letter
            if (max_index < 97)
            {
                max_val += ascii[max_index + 32];
            }
            else
            {
                max_val += ascii[max_index - 32];
            }

            // If the word has a non-alphabetic character,
            // reset max_val.
            if (alpha_flag == false)
            {
                max_val = 0;
            }

            count += max_val;
            word = "";

            // reset array to zeroes
            for (int j = 0; j < 128; ++j)
            {
                ascii[j] = 0;
            }

            alpha_flag = true;
        }
    }

    return count;
}

// This functions finds the max value in an integer array.
// It returns an integer.
int maxValue(int array[])
{
    int max = array[0];
    int i;

    for (i = 1; i < 128; ++i)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}