#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256
#define WORD_LEN 50

typedef struct _WORD
{
	int start;
	int end;
	char word[WORD_LEN];
} WORD;

int main()
{
	WORD w[MAX_LEN] = {0, 0, ""};
	char text[MAX_LEN] = "";

	// read a text from the user
	printf("input a text: ");
	fgets(text, MAX_LEN, stdin);
	text[strlen(text) - 1] = 0;

	// fill space with blanks
	printf("              ");

	// display mark to check start and end
	int pre_char = 0; // previous character(0: whitespace, 1: not whitespace)
	int word_count = 0;
	int text_count = 0;
	int i = 0;
	for (i = 0; i < strlen(text); i++)
	{
		// case 1: current text is whitespace
		if (isspace(text[i]))
		{
			// case 1-1: previous character is whitespace
			if (pre_char == 0)
			{ // previous character is whitespace
				printf(" ");
			}

			// case 1-2: previous character is not whitespace (end point)
			else if (pre_char == 1)
			{
				printf("]");
				w[word_count].end = i;
				word_count++;
				text_count = 0;
			}
			pre_char = 0;
		}
		// case 2: current text is not whitespace
		else
		{
			// case 2-1: previous character is whitespace (strat point)
			if (pre_char == 0)
			{
				printf("[");
				w[word_count].start = i;
				w[word_count].word[text_count] = text[i];
				text_count++;
			}
			// case 2-2: previous character is not whitespace
			else if (pre_char == 1)
			{
				printf(" ");
				w[word_count].word[text_count] = text[i];
				text_count++;
			}
			pre_char = 1;
		}
	}
	if (pre_char == 1)
	{
		printf("]");
		w[word_count].end = i;
		word_count++;
	}
	printf("\n\n");

	// display the word[i]
	for (int i = 0; i < word_count; i++)
	{
		printf("words[%d] = (%d,%d,%s)\n", i, w[i].start, w[i].end, w[i].word);
	}

	return 0;
}
