#include <stdio.h>
#include <stdlib.h>
char* get_line(FILE* f, int maxchar)
{
	char* string = malloc(maxchar+1);
	int c;
	int i = 0;

	while ((c = fgetc(f)) != EOF && c != '\n' && i < maxchar)
	{
		*(string + i++) = c;
	}
	*(string + i) = '\0';
	return string;
}

int main(void)
{
	FILE* f;
	f = fopen("file.txt", "r");
	printf("%s\n", get_line(f, 3)); 
	printf("%s\n", get_line(f, 5));
	fclose(f);
	return 0;
}
