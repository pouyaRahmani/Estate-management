#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
    char userID[50];
};

void takeInput(char ch[50])
{
    gets(ch);
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

int isUsernameTaken(char username[50])
{
    FILE *fp;

    struct user usr;

    fp = fopen("Users.dat", "r");

    while (fread(&usr, sizeof(struct user), 1, fp))
    {
        if (!strcmp(usr.username, username))
        {
            fclose(fp);
            return 1; // Username is already taken
        }
    }

    fclose(fp);
    return 0; // Username is not taken
}

void signUp()
{
    FILE *fp;
    system("cls");
    struct user users;
    char password2[50];

    do
    {
        printf("\nEnter your full name:\t");
        takeInput(users.fullName);
        printf("\nEnter your email:\t");
        takeInput(users.email);
        printf("\nEnter phone number:\t");
        takeInput(users.phone);
        printf("\nEnter phone ID:\t");
        takeInput(users.userID);

        do
        {
            printf("\nEnter your username:\t");
            takeInput(users.username);
            if (isUsernameTaken(users.username))
            {
                printf("\nUsername is already taken. Please choose another one.");
                Beep(750, 300);
            }
        } while (isUsernameTaken(users.username));

        printf("\nEnter your password:\t");
        takePassword(users.password);
        printf("\nConfirm your password:\t");
        takePassword(password2);

        // Compare two passwords
        if (strcmp(users.password, password2))
        {
            printf("\nYour passwords didn't match. Please try again!");
            Beep(750, 300);
        }
    } while (strcmp(users.password, password2));

    printf("\nYour password matched");

    fp = fopen("Users.dat", "a+");
    fwrite(&users, sizeof(struct user), 1, fp);
    if (fwrite != 0)
    {
        printf("\n\nUser registration was successful. press any key to contiue...");
        getch();
    }
    else
        printf("Oops! Something went wrong :( ");

    fclose(fp);
}

void mainMenu(struct user usr)
{
    // system("cls");
    printf("\n\t\t\t\t---===== Welcome to Estate Management System =====---");
    printf("\n\t\t\t\t\t\t   Main Menu");
    printf("\n\n1. View Profile");
    printf("\n2. Edit Profile");
    printf("\n3. Logout");
    printf("\n\nYour choice:\t");
}

void login()
{
    FILE *fp;
    struct user usr;
    char username[50], pword[50];
    int userFound;

    do
    {
        userFound = 0; // Reset the flag for each login attempt

        printf("\nEnter your username:\t");
        takeInput(username);
        printf("\nEnter your password:\t");
        takePassword(pword);

        fp = fopen("Users.dat", "r");

        while (fread(&usr, sizeof(struct user), 1, fp))
        {
            if (!strcmp(usr.username, username) && !strcmp(usr.password, pword))
            {
                system("cls");
                printf("\n\t\t\t\tWelcome %s", usr.fullName);
                printf("\n\n|Full name:\t%s", usr.fullName);
                printf("\n|Email:\t%s", usr.email);
                printf("\n|Username:\t%s", usr.username);
                printf("\n|Phone number:\t%s", usr.phone);
                printf("\n|ID:\t%s", usr.userID);
                userFound = 1;

                mainMenu(usr);
                int choice;
                scanf("%d", &choice);
                // Adding choices after login
                switch (choice)
                {
                case 1:
                    // View Profile
                    // Add code here
                    break;
                case 2:
                    // Edit Profile
                    // Add code here
                    break;
                case 3:
                    // Logout
                    // Add code here
                    break;
                default:
                    break;
                }
                break; // Exit the loop once the user is found
            }
        }

        if (!userFound)
        {
            printf("\n\nInvalid username or password!! Please try again.");
            Beep(800, 300);
        }

        fclose(fp);
    } while (!userFound);
}

void main()
{
    system("color 0b");

    int role;

    while (1)
    {
        system("cls");
        printf("\n\t\t\t\t---=====Welcome to estate management system=====---");
        printf("\nPlease choose an action");
        printf("\n1.Signup");
        printf("\n2.Login");
        printf("\n3.Exit");
        printf("\n\nYour choice:\t");
        scanf("%d", &role);
        fgetc(stdin);

        switch (role)
        {
        case 1:
            signUp();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("Goodbye, have nice day :)");
            exit(0);
        default:
            break;
        }
    }
}
