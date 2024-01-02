#include <stdio.h>
#include <conio.h>
#include <windows.h>

void takeInput(char ch[50])
{
    gets(ch);
    ch[strlen(ch) - 1] = 0; // Remove \n and add 0 to end of string
}

char generateUsername(char email[50], char username[50])
{
    int i;
    for (i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            break;
        else
            username[i] = email[i];
    };
    username[i] = '\0';
}
// Replace password with *
void takePassword(char pwd[50])
{
#define Enter 13
#define Tab 9
#define BKSPC 8
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == Enter || ch == Tab)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BKSPC)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

void main()
{
    system("color 0b");
    struct user
    {
        char fullName[50];
        char email[50];
        char password[50];
        char username[50];
        char phone[50];
    };
    struct user users;
    char password2[50];
    int role;
    printf("\n\t\t\t\t---=====Welcome to estate management system=====---");
    printf("\nPlease choose your role");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");
    printf("\n\nYour choice:\t");
    scanf("%d", &role);
    fgetc(stdin);

    switch (role)
    {
    case 1:
        printf("\nEnter your full name:\t");
        takeInput(users.fullName);
        printf("\nEnter your email:\t");
        takeInput(users.email);
        printf("\nEnter phone number:\t");
        takeInput(users.phone);
        printf("\nEnter your password:\t");
        takePassword(users.password);
        printf("\nConfirm your password:\t");
        takePassword(password2);

        // Compare two passwords then generate username by email
        if (!strcmp(users.password, password2))
        {
            printf("\nYour password matched");
            generateUsername(users.email, users.username);
            printf("\nYour username is %s", users.username);
        }
        else
        {
            printf("\nYour password didn't match!!");
        }
        break;
    default:
        break;
    }
}