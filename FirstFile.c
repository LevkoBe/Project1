#include <stdio.h>

char text[100] = "";

void insert_line(int line, int column, int text_length, int inserting, const char* additional_text) {
    int lines = 0;
    int position = 0;
    char result[100] = "";
    for (int i = 0; i < text_length; i++)
    {
        if (lines == line)
        {
            position = i + column;
            break;
        }
        else if (text[i] == '\n')
        {
            lines++;
        }
    }
    for (int i = 0; i < position; i++)
    {
        result[i] = text[i];
    }
    for (int i = 0; i < inserting; i++)
    {
        result[position + i] = additional_text[i];
    }
    for (int i = 0; i < text_length - position; i++)
    {
        result[position + inserting + i] = text[position + i];
    }
    strcpy_s(text, sizeof(text), result);
}

int main() {

    char additional_text[100];
    int command = 0;

    while (1) {
        printf("\nChoose the command:\n");
        command = 10;
        printf("(from 0 to 10, where 10 is instructions): ");
        scanf_s("%d", &command);

        if (command == 0) {
            break;
        }
        else if (command == -1) {
            printf("The text is cleared.");
            strcpy(text, "");
        }
        else if (command == 1) {
            printf("\nEnter the text you want to add: \n");
            scanf_s(" %99[^\n]", additional_text, sizeof(additional_text));
            strcat_s(text, sizeof(text), additional_text);
        }
        else if (command == 2) {
            strcat(text, "\n");
            printf("\nNew line was started.\n");
        }
        else if (command == 3) {
            printf("Enter a name of the file you want to use for saving the text: ");
            char filename[20];
            scanf_s(" %19[^\n]", filename, sizeof(filename));

            FILE* file;
            if (fopen_s(&file, filename, "w") != 0) {
                printf("Error opening file");
            }
            else {
                fputs(text, file);
                fclose(file);
            }
        }
        else if (command == 4) {
            printf("Enter a name of the file you want to use for loading the text: ");
            char filename[20];
            scanf_s(" %19[^\n]", filename, sizeof(filename));

            FILE* file;
            char mystring[100];
            if (fopen_s(&file, filename, "r") != 0) {
                printf("Error opening file");
            }
            else {
                strcpy(text, "");
                while (fgets(mystring, sizeof(mystring), file) != NULL) {
                    strcat(text, mystring);
                }
                fclose(file);
            }
        }

        else if (command == 5) {
            printf("\nThe text is \"%s\" now.\n", text);
        }
        else if (command == 6) {
            //printf("Choose line and index: ");
            int line;
            int column;
            printf_s("Line: ");
            scanf_s("%d", &line);
            printf_s("Column: ");
            scanf_s("%d", &column);
            printf("Enter text to insert: ");
            scanf_s(" %99[^\n]", additional_text, sizeof(additional_text));
            int text_length = strlen(text);
            int inserting = strlen(additional_text);
            insert_line(line, column, text_length, inserting, additional_text);
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
            printf("Command 3 is for saving the text in a file;\n");
            printf("Command 4 is for loading some text from a file;\n");
            printf("Command 5 is for printing the text;\n");
            printf("Command 6 is for ;\n");
            printf("Command 7 is for ;\n");
            printf("Command 8 is for ;\n");
            printf("Command 9 is for ;\n");
            printf("Command 10 is for instructions.\n");
        }
    }

    return 0;
}
