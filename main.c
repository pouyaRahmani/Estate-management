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
struct residentalSale
{
    char zone[50];
    char address[100];
    char estateType[50];
    char ageEstate[50];
    char size[50];
    char floors[50];
    char sizeMainEstate[50];
    char contactNum[50];
    char bedrooms[50];
    char price[50];
};
struct officeSale
{
    char zone[50];
    char address[100];
    char estateType[50];
    char ageEstate[50];
    char size[50];
    char floors[50];
    char sizeMainEstate[50];
    char contactNum[50];
    char officeRooms[50];
    char price[50];
};
struct landSale
{
    char address[100];
    char landType[50];
    char size[50];
    char contactNum[50];
    char price[50];
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

        do // Check if username is diff
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
    printf("\n\n1. Add new estate");
    printf("\n2. Delete estate");
    printf("\n3. Reports");
    printf("\n4. Account setting");
    printf("\n5. Log out");
    printf("\n6. Exite the program");
    printf("\n\nYour choice:\t");
    int choice;
    scanf("%d", &choice);
    // Adding choices after login
    switch (choice)
    {
    case 1:
        addEstate();
        break;
    case 2:
        // Add function here
        break;
    case 3:
        // Add function here
        break;
    case 4:
        // Add function here
        break;
    case 5:
        // Add function here
        break;
    case 6:
        // Add function here
        break;
    default:
        break;
    }
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

void addEstate()
{
    printf("\n\t\t\t\tAdding new estate");
    printf("\n\n1. Add for sale");
    printf("\n2. Add for rent");
    printf("\n3. Back to menu");
    printf("\n\nYour choice:\t");
    int choice;
    scanf("%d", choice);
    switch (choice)
    {
    case 1:
        printf("Enter kind of your property");
        printf("\n\n1. Residental property");
        printf("\n2. Office property");
        printf("\n3. Add land");
        printf("\n4. Back to menu");
        printf("\n\nYour choice:\t");
        int ch1;
        scanf("%d", ch1);
        switch (ch1)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("ERROR, Invalid inpute");
            break;
        }
        break;

    default:
        break;
    }
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
