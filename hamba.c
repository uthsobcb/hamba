#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_FILE "assets/cow.txt"

const char *randomMessage[] = {
    "Believe in yourself! You can do it!",
    "Every day is a second chance.",
    "Hardships often prepare ordinary people for extraordinary destiny.",
    "Success is not final, failure is not fatal: It is the courage to continue that counts.",
    "Dream big and dare to fail.",
    "Act as if what you do makes a difference. It does.",
    "The only limit to our realization of tomorrow will be our doubts of today."
    "You have everything within you to achieve greatness. Trust yourself, and keep moving forward.",

    "I see your strength and potential, even when you can’t. Keep believing in yourself.",

    "You’re doing better than you think—don’t let the small setbacks overshadow your progress.",

    "I admire your courage to face life’s challenges. You’re stronger than you realize.",

    "Every step you take, no matter how small, is a step closer to your dreams. Keep going.",

    "You’re capable of incredible things, and I can’t wait to see what you accomplish.",

    "I see the light in you that others sometimes overlook. You’re truly remarkable.",

    "It’s okay to rest; you’re doing so much. You deserve kindness from yourself too.",

    "You inspire others just by being you. Keep shining your light.",

    "I believe in you wholeheartedly, and I know you’re going to overcome this."};

#define MESSAGE_COUNT (sizeof(randomMessage) / sizeof(randomMessage[0]))

void printRandomMessage()
{
    srand(time(NULL));
    int index = rand() % MESSAGE_COUNT;
    printAsciiArtFromFile(randomMessage[index]);
}

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
    printf("  -r      Display a random message\n");
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
    else if (strcmp(argv[1], "-r") == 0)
    {
        printRandomMessage();
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