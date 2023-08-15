#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Counts
    {
    int letters;
    int words;
    int sentences;
    };

struct Counts count_letters(string text, int length);
int Coleman (struct Counts count);
void get_score(int index);

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    struct Counts result = count_letters(text, length);
    int index = Coleman(result);
    get_score(index);
}

struct Counts count_letters(string text, int length)
{
    struct Counts result = {0, 1, 0};

    for (int letter = 0; letter <= length; letter++)
    {
        if (isalpha(text[letter]))
        {
            result.letters++;
        }
        if (isspace(text[letter]))
        {
            result.words++;
        }
        if (text[letter]== '?' || text[letter]== '.' || text[letter]== '!')
        {
            result.sentences++;
        }
    }
    return result;
}

int Coleman(struct Counts count)
{
    float L = ((float) count.letters/count.words)*100;
    float S = ((float) count.sentences/count.words)*100;
    int index = (int)round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

void get_score(int index)
{
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <1){
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n",index);
    }
}