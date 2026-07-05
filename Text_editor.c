#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>   // for system()

#define MAX 1000

char text[MAX] = "";
char stack[MAX][MAX];
int top = -1;

// Save current state
void push(char str[])
{
    if (top < MAX - 1)
    {
        top++;
        strcpy(stack[top], str);
    }
}

// Undo operation
void undo(int *len)
{
    if (top >= 0)
    {
        strcpy(text, stack[top]);
        *len = strlen(text);
        top--;
    }
}

// Redraw screen (CodeBlocks compatible)
void redraw()
{
    system("cls");   // ✅ instead of \033

    printf("=========================================\n");
    printf("   TEAM BGH TEXT EDITOR\n");
    printf("=========================================\n\n");

    printf("%s", text);
}

int main()
{
    int len = 0;
    char ch;

    // Welcome message
    printf("=========================================\n");
    printf("   WELCOME TO TEAM BGH TEXT EDITOR\n");
    printf("=========================================\n\n");

    printf("Start typing your text below:\n");
    printf("(Ctrl+Z = Undo, ESC = Exit)\n\n");

    while (1)
    {
        ch = getch();

        // ESC to exit
        if (ch == 27)
            break;

        // Undo
        else if (ch == 26)
        {
            undo(&len);
            redraw();
        }

        // Backspace (multi-line supported)
        else if (ch == 8)
        {
            if (len > 0)
            {
                push(text);
                len--;
                text[len] = '\0';

                redraw();
            }
        }

        // Enter key
        else if (ch == 13)
        {
            push(text);
            text[len++] = '\n';
            text[len] = '\0';

            printf("\n");
        }

        // Normal characters
        else
        {
            push(text);
            text[len++] = ch;
            text[len] = '\0';

            printf("%c", ch);
        }
    }

    // Exit message
    printf("\n\n=========================================\n");
    printf(" Thank you for choosing TEAM BGH TEXT EDITOR\n");
    printf("=========================================\n");

    return 0;
}
