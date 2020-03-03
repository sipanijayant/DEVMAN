#include<stdio.h>
#include<string.h>

/*
just = 1 for left justified text
just = 2 for centre justified text
just = 3 for right justified text
*/
void title(const char txt[], char s_border, char t_border, int just)
{
	int len = strlen(txt);
	for(int i = 0; i < 80; i++)
		printf("%c", t_border);

	printf("%c", s_border);

	switch(just)
	{
		case 1:
			printf(" %s", txt);
			for(int i = 0; i < 77- len; i++) // 77 as one side border is to be added at the start of the line with one space as well, with one side border at the end
				printf(" ");
		break;

		case 2:
			for(int i = 0; i < 39-(len/2); i++) // 39 as one character is taken up by the side border already printed a line above
				printf(" ");

			printf("%s",txt); //printing out the user text

			for(int i = 0; i < 38-(len/2); i++) // 38 as one side border is to be added at the end of the line and one has already been printed at the start of the line
				printf(" ");
		break;

		case 3:
			for(int i = 0; i < 77 - len; i++) // 78 as one side border is to be added at the end of the line with one space as well, with one side border at the start
				printf(" ");
			printf("%s ", txt);	
		break;
	}

	printf("%c", s_border);
			
	for(int i = 0; i < 80; i++)
		printf("%c", t_border);
}