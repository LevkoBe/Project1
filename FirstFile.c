#include<stdio.h>

int main()
{
	char text[] = "";
	char additional_text[100];
	int command = 0;

	while (1)
	{
		printf("\nChoose the command:\n");

		printf("(from 0 to 10, where 10 is instructions): ");
		scanf_s("%d", &command);

		if (command == 0)
		{
			break;
		}
		else if (command == 1)
		{
			printf("\nEnter the text you want to add: \n");
			scanf_s("%99s", &additional_text, sizeof(additional_text));
			strcat(text, additional_text);
		}
		else if (command == 2)
		{
			strcat(text, "\n");
		}
		printf("\nThe text is \"%s\" now.\n", text);
	}


	return 0;
}