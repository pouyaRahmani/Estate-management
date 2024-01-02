#include <stdio.h>
#include <conio.h>
#include <windows.h>

void takeInput(char ch[50])
{
    gets(ch);
    ch[strlen(ch) - 1] = 0; // Remove \n and add 0 to end of string
}

void generateUsername(char email[50], char username[50])
{
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            break;
        else
            username[i] = email[i];
    };
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
        printf("\nEnter your phone number:\t");
        takeInput(users.phone);
        printf("\nEnter your password:\t");
        takeInput(users.password);
        break;

    default:
        break;
    }
}