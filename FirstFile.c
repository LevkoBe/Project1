#include <stdio.h>

int main()
{
    char text[100] = "";

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
            scanf_s(" %99[^\n]", additional_text, sizeof(additional_text));
            strcat_s(text, sizeof(text), additional_text);
        }
		else if (command == 2)
		{
			strcat(text, "\n");
			printf("\nNew line was started.\n");
			command = 10;
		}
		else if (command == 3) {

		}
		else if (command == 4) {

		}
		else if (command == 5) {

		}
		else if (command == 6) {

		}
		else if (command == 7) {

		}
		else if (command == 8) {

		}
		else if (command == 9) {

		}
		else {
			printf("\nCommand 0 is for exit;\n");
			printf("Command 1 is for adding some text;\n");
			printf("Command 2 is for adding a new line;\n");
			printf("Command 3 is for ;\n");
			printf("Command 4 is for ;\n");
			printf("Command 5 is for ;\n");
			printf("Command 6 is for ;\n");
			printf("Command 7 is for ;\n");
			printf("Command 8 is for ;\n");
			printf("Command 9 is for ;\n");
			printf("Command 10 is for instructions.\n");
		}
        printf("\nThe text is \"%s\" now.\n", text);
    }

    return 0;
}
