#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct
{
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

void removePunctuation(char *word)
{
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (ispunct(word[i]))
        {
            for (int j = i; j < length; j++)
            {
                word[j] = word[j + 1];
            }
            i--;
            length--;
        }
    }
}

int compareWords(const void *a, const void *b)
{
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

int compareWordsAlphabetically(const void *a, const void *b)
{
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}

    int caseSensitive = 0;
    int sortByFrequency = 1;
    int wordLengthLimit = -1;


int main(int argc, char *argv[])
{


    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-c") == 0)
        {
            caseSensitive = 1;
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            i++;
            if (i < argc)
            {
                if (strcmp(argv[i], "1") == 0)
                {
                    sortByFrequency = 1;
                }
                else if (strcmp(argv[i], "2") == 0)
                {
                    sortByFrequency = 0;
                }
                else
                {
                    fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
                    return 0;
                }
            }
            else
            {
                fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
                return 0;
            }
        }
        else if (strcmp(argv[i], "-l") == 0)
        {
            i++;
            if (i < argc)
            {
                wordLengthLimit = atoi(argv[i]);
                if (wordLengthLimit < 0)
                {
                    fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
                    return 0;
                }
            }
            else
            {
                fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
                return 0;
            }
        }
    }



    WordCount *wordCounts = malloc(sizeof(WordCount));
    int wordCount = 0;
    char buffer[MAX_WORD_LENGTH + 1];

    while (scanf("%s", buffer) == 1)
    {
        if (caseSensitive == 0) 
        {
            for (int i = 0; buffer[i]; i++)
            {
                buffer[i] = tolower(buffer[i]);
            }
        }

        removePunctuation(buffer);

        if (wordLengthLimit < 0 || (int)strlen(buffer) <= wordLengthLimit)
        {
            int found = 0;

            for (int i = 0; i < wordCount; i++)
            {
                if (strcmp(wordCounts[i].word, buffer) == 0)
                {
                    wordCounts[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                wordCounts = realloc(wordCounts, (wordCount + 1) * sizeof(WordCount));
                strcpy(wordCounts[wordCount].word, buffer);
                wordCounts[wordCount].count = 1;
                wordCount++;
            }
        }
    }
    

    qsort(wordCounts, wordCount, sizeof(WordCount), compareWords);
    char **leastUsedWord = malloc(wordCount*MAX_WORD_LENGTH*sizeof(char));

    int shortestWords = 0;
    int temp = 1; 
    while (shortestWords<1)
    {        
        for (size_t j = 0; j < wordCount; j++)
        {
            if (wordCounts[j].count==temp)
            {
                leastUsedWord[shortestWords] = wordCounts[j].word;
                shortestWords++;
            }
        }
        temp++;            
    }

    char **mostUsedWord = malloc(wordCount*MAX_WORD_LENGTH*sizeof(char));

    temp = 1; 
    mostUsedWord[0]=wordCounts[0].word;
    while (wordCounts[temp].count == wordCounts[0].count)
    {        
        mostUsedWord[temp]=wordCounts[temp].word;
        temp++;
    }
    

    if (sortByFrequency != 1)
    {
        qsort(wordCounts, wordCount, sizeof(WordCount), compareWordsAlphabetically);
    }
    


    printf("Seznam slov:\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%-20s %i\n", wordCounts[i].word, wordCounts[i].count);
    }
    printf("%-20s %i\n", "Pocet slov:", wordCount);
    printf("%-20s ", "Nejcastejsi:");
    for (size_t i = 0; i < temp; i++)
    {
        printf("%s",mostUsedWord[i]);
        if (i+1!=temp)
        {
            printf(" ");
        }
        
    }
    printf("\n%-20s ", "Nejmene caste:");
    for (size_t i = 0; i < shortestWords; i++)
    {
        printf("%s",leastUsedWord[i]);
        if (i+1!=shortestWords)
        {
            printf(" ");
        }
        
    }
    

    printf("\n");
    free(wordCounts);

    return 0;
}
