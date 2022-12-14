#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char **split_words(char *str)
{
	char **words = NULL; 
	char *word = strtok (str," ");
	int num_words = 0; 
		     
	while (word != NULL)
	{
		words = realloc (words, sizeof (char*) * ++num_words);
		if (words == NULL)
			exit (-1); 
		words[num_words-1] = word;
		word = strtok (NULL, " ");
	}
	words = realloc (words, sizeof (char*) * (num_words+1));
	words[num_words] = 0;
	return words;
}
int main()
{
	char str[] = "the harder they fall. hard things don dey taya me oh";
	char **words;
	int i;
	     
	words = split_words (str);
	for (i = 0; words[i] != NULL; i++)
		printf ("%s\n", words[i]);
	free (words);
	return 0;
}
