#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_FILE "assets/cow.txt"

void printAsciiArtFromFile(const char *message)
{
    FILE *file = fopen(ASCII_FILE, "r");
    if (!file)
    {
        perror("Error opening ASCII art file");
        return;
    }

    printf("\n");

    printf("       << %s >>\n", message);
    printf("          ||\n");
    printf("          ||\n");

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    printf("\n");
    printf("\n");
    fclose(file);
}

void showHelp()
{
    printf("Usage: cowsay [OPTION] [MESSAGE]\n");
    printf("Options:\n");
    printf("  -say    Display the ASCII art with your message\n");
    printf("  -help     Show this help message\n");
    printf("Arguments:\n");
    printf("  MESSAGE     The message to display\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error: No arguments provided. Use -help for usage information.\n");
        return 1;
    }

    if (strcmp(argv[1], "-say") == 0)
    {
        if (argc < 3)
        {
            printf("Error: Please provide a message to Say by Hamba.\n");
            return 1;
        }

        char message[256] = "";
        for (int i = 2; i < argc; i++)
        {
            strcat(message, argv[i]);
            if (i < argc - 1)
                strcat(message, " ");
        }

        printAsciiArtFromFile(message);
    }
    else if (strcmp(argv[1], "-help") == 0)
    {
        showHelp();
    }
    else
    {
        printf("Error: Unknown option '%s'. Use -help for usage information.\n", argv[1]);
        return 1;
    }

    return 0;
}