#include <stdio.h>
#include <stdbool.h>

char text[100] = "";

void insert_line() {
    int line;
    int column;
    char additional_text[100];
    printf_s("Line: ");
    scanf_s("%d", &line);
    printf_s("Column: ");
    scanf_s("%d", &column);
    printf("Enter text to insert: ");
    scanf_s(" %99[^\n]", additional_text, sizeof(additional_text));
    int text_length = strlen(text);
    int inserting = strlen(additional_text);

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

void search_text(char* needed) {
    int n_length = strlen(needed);
    int indices[100];
    int count = 0;
    for (int i = 0; i <= strlen(text) - n_length; i++)
    {
        bool get_out = false;
        for (int j = 0; j < n_length; j++)
        {
            if (text[i + j] != needed[j])
            {
                get_out = true;
                break;
            }
        }
        if (!get_out)
        {
            indices[count] = i;
            count++;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d, ", indices[i]);
    }
}

void save_to_file() {
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

void load_from_file() {
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

int main() {

    char additional_text[100];
    int command = 0;

    while (1) {
        printf("\nChoose the command:\n");
        command = 10;
        printf("(from -1 to 8, where 8 is instructions): ");
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
            save_to_file();
        }
        else if (command == 4) {
            load_from_file();
        }
        else if (command == 5) {
            printf("\nThe text is \"%s\" now.\n", text);
        }
        else if (command == 6) {
            insert_line();
        }
        else if (command == 7) {
            printf("Enter text to search: ");
            scanf_s(" %99[^\n]", additional_text, sizeof(additional_text));
            search_text(additional_text);
        }
        else {
            printf("\nCommand -1 is for clearing all the text;\n");
            printf("Command 0 is for exit;\n");
            printf("Command 1 is for adding some text;\n");
            printf("Command 2 is for adding a new line;\n");
            printf("Command 3 is for saving the text in a file;\n");
            printf("Command 4 is for loading some text from a file;\n");
            printf("Command 5 is for printing the text;\n");
            printf("Command 6 is for inserting text;\n");
            printf("Command 7 is for searching some text;\n");
            printf("Command 8 is for instructions.\n");
        }
    }

    return 0;
}
