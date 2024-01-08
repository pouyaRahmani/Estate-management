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
    struct user *link;
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
    char addedByUser[50];
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
    char addedByUser[50];
};

struct landSale
{
    char address[100];
    char landType[50];
    char size[50];
    char contactNum[50];
    char price[50];
    char addedByUser[50];
};
struct rentalResidental
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
    char mortgage[50];
    char rent[50];
    char addedByUser[50];
};
struct rentalOffice
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
    char mortgage[50];
    char rent[50];
    char addedByUser[50];
};
struct rentalLand
{
    char address[100];
    char landType[50];
    char size[50];
    char contactNum[50];
    char mortgage[50];
    char rent[50];
    char addedByUser[50];
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

void addResidentalSale(struct user usr)
{
    struct residentalSale estate;
    printf("\nEnter zone:\t");
    takeInput(estate.zone);
    printf("%c", estate.zone);
    printf("\nEnter address:\t");
    takeInput(estate.address);
    printf("\nEnter estate type:\t");
    takeInput(estate.estateType);
    printf("\nEnter age of estate:\t");
    takeInput(estate.ageEstate);
    printf("\nEnter area in meter:\t");
    takeInput(estate.size);
    printf("\nEnter floors:\t");
    takeInput(estate.floors);
    printf("\nEnter area of main structure in meter:\t");
    takeInput(estate.sizeMainEstate);
    printf("\nEnter contact number:\t");
    takeInput(estate.contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(estate.bedrooms);
    printf("\nEnter price:\t");
    takeInput(estate.price);
    system("cls");
    // Set the addedByUser field to the username of the user who added the property
    strcpy(estate.addedByUser, usr.username);
    FILE *fp;
    fp = fopen("ResidentalSales.dat", "a");
    fwrite(&estate, sizeof(struct residentalSale), 1, fp);
    fclose(fp);
    // Display property features
    printf("\nResidential property added successfully!");
    printf("\nZone: %s", estate.zone);
    printf("\nAddress: %s", estate.address);
    printf("\nEstate Type: %s", estate.estateType);
    printf("\nAge of Estate: %s", estate.ageEstate);
    printf("\nArea: %s", estate.size);
    printf("\nFloors: %s", estate.floors);
    printf("\nArea of Main Estate: %s", estate.sizeMainEstate);
    printf("\nContact Number: %s", estate.contactNum);
    printf("\nBedrooms: %s", estate.bedrooms);
    printf("\nPrice: %s", estate.price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
}

void addOfficeSale(struct user usr)
{
    struct officeSale estate;
    printf("\nEnter zone:\t");
    takeInput(estate.zone);
    printf("\nEnter address:\t");
    takeInput(estate.address);
    printf("\nEnter estate type:\t");
    takeInput(estate.estateType);
    printf("\nEnter age of estate:\t");
    takeInput(estate.ageEstate);
    printf("\nEnter area in meter:\t");
    takeInput(estate.size);
    printf("\nEnter floors:\t");
    takeInput(estate.floors);
    printf("\nEnter area of main structure in meter:\t");
    takeInput(estate.sizeMainEstate);
    printf("\nEnter contact number:\t");
    takeInput(estate.contactNum);
    printf("\nEnter office rooms:\t");
    takeInput(estate.officeRooms);
    printf("\nEnter price:\t");
    takeInput(estate.price);
    // Set the addedByUser field to the username of the user who added the property
    strcpy(estate.addedByUser, usr.username);
    FILE *fp;
    fp = fopen("OfficeSales.dat", "a");
    fwrite(&estate, sizeof(struct officeSale), 1, fp);
    fclose(fp);
    printf("\nOffice property added successfully!\n");
    // Display property features
    printf("\nResidential property added successfully!");
    printf("\nZone: %s", estate.zone);
    printf("\nAddress: %s", estate.address);
    printf("\nEstate Type: %s", estate.estateType);
    printf("\nAge of Estate: %s", estate.ageEstate);
    printf("\nArea: %s", estate.size);
    printf("\nFloors: %s", estate.floors);
    printf("\nArea of Main structure: %s", estate.sizeMainEstate);
    printf("\nContact Number: %s", estate.contactNum);
    printf("\nBedrooms: %s", estate.officeRooms);
    printf("\nPrice: %s", estate.price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
}

void addLandSale(struct user usr)
{
    struct landSale estate;
    printf("\nEnter address:\t");
    takeInput(estate.address);
    printf("\nEnter land type:\t");
    takeInput(estate.landType);
    printf("\nEnter area in meter:\t");
    takeInput(estate.size);
    printf("\nEnter contact number:\t");
    takeInput(estate.contactNum);
    printf("\nEnter price:\t");
    takeInput(estate.price);
    // Set the addedByUser field to the username of the user who added the property
    strcpy(estate.addedByUser, usr.username);
    FILE *fp;
    fp = fopen("LandSales.dat", "a");
    fwrite(&estate, sizeof(struct landSale), 1, fp);
    fclose(fp);
    printf("\nLand property added successfully!\n");
    printf("\nAddress: %s", estate.address);
    printf("\nLand type: %s", estate.landType);
    printf("\nArea: %s", estate.size);
    printf("\nContact Number: %s", estate.contactNum);
    printf("\nPrice: %s", estate.price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
}

void addSaleEstate(struct user usr)
{
    int choice;
    printf("\n\t\t\t\tAdding new estate for sale");
    printf("\n\n1. Add residental property");
    printf("\n2. Add office property");
    printf("\n3. Add land property");
    printf("\n4. Back to menu");
    printf("\n\nYour choice:\t");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        addResidentalSale(usr);
        break;
    case 2:
        addOfficeSale(usr);
        break;
    case 3:
        addLandSale(usr);
        break;
    case 4:
        // Return to the main menu
        break;
    default:
        printf("\nInvalid choice! Please try again.\n");
        break;
    }
}
void addRentalResidental(struct user usr)
{
    struct rentalResidental rentalEstate;
    printf("\nEnter zone:\t");
    takeInput(rentalEstate.zone);
    printf("\nEnter address:\t");
    takeInput(rentalEstate.address);
    printf("\nEnter estate type:\t");
    takeInput(rentalEstate.estateType);
    printf("\nEnter age of estate:\t");
    takeInput(rentalEstate.ageEstate);
    printf("\nEnter area in meter:\t");
    takeInput(rentalEstate.size);
    printf("\nEnter floors:\t");
    takeInput(rentalEstate.floors);
    printf("\nEnter area of main structure in meter:\t");
    takeInput(rentalEstate.sizeMainEstate);
    printf("\nEnter contact number:\t");
    takeInput(rentalEstate.contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(rentalEstate.bedrooms);
    printf("\nEnter mortgage:\t");
    takeInput(rentalEstate.mortgage);
    printf("\nEnter rent:\t");
    takeInput(rentalEstate.rent);
    // Set the addedByUser field to the username of the user who added the property
    strcpy(rentalEstate.addedByUser, usr.username);
    FILE *fp;
    fp = fopen("RentalResidental.dat", "a");
    fwrite(&rentalEstate, sizeof(struct rentalResidental), 1, fp);
    fclose(fp);

    // Display property features
    printf("\nRental Residential property added successfully!");
    printf("\nZone: %s", rentalEstate.zone);
    printf("\nAddress: %s", rentalEstate.address);
    printf("\nEstate Type: %s", rentalEstate.estateType);
    printf("\nAge of Estate: %s", rentalEstate.ageEstate);
    printf("\nArea: %s", rentalEstate.size);
    printf("\nFloors: %s", rentalEstate.floors);
    printf("\nArea of Main structure: %s", rentalEstate.sizeMainEstate);
    printf("\nContact Number: %s", rentalEstate.contactNum);
    printf("\nBedrooms: %s", rentalEstate.bedrooms);
    printf("\nMortgage: %s", rentalEstate.mortgage);
    printf("\nRent: %s", rentalEstate.rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
}
void addRentalOffice(struct user usr)
{
    struct rentalOffice rentalOffice;
    printf("\nEnter zone:\t");
    takeInput(rentalOffice.zone);
    printf("\nEnter address:\t");
    takeInput(rentalOffice.address);
    printf("\nEnter estate type:\t");
    takeInput(rentalOffice.estateType);
    printf("\nEnter age of estate:\t");
    takeInput(rentalOffice.ageEstate);
    printf("\nEnter Area in meter:\t");
    takeInput(rentalOffice.size);
    printf("\nEnter floors:\t");
    takeInput(rentalOffice.floors);
    printf("\nEnter Area of main structure in meter:\t");
    takeInput(rentalOffice.sizeMainEstate);
    printf("\nEnter contact number:\t");
    takeInput(rentalOffice.contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(rentalOffice.bedrooms);
    printf("\nEnter mortgage:\t");
    takeInput(rentalOffice.mortgage);
    printf("\nEnter rent:\t");
    takeInput(rentalOffice.rent);
    // Set the addedByUser field to the username of the user who added the property
    strcpy(rentalOffice.addedByUser, usr.username);
    FILE *fp;
    fp = fopen("RentalOffice.dat", "a");
    fwrite(&rentalOffice, sizeof(struct rentalOffice), 1, fp);
    fclose(fp);

    // Display property features
    printf("\nRental office property added successfully!");
    printf("\nZone: %s", rentalOffice.zone);
    printf("\nAddress: %s", rentalOffice.address);
    printf("\nEstate Type: %s", rentalOffice.estateType);
    printf("\nAge of Estate: %s", rentalOffice.ageEstate);
    printf("\nArea: %s", rentalOffice.size);
    printf("\nFloors: %s", rentalOffice.floors);
    printf("\nArea of Main Estate: %s", rentalOffice.sizeMainEstate);
    printf("\nContact Number: %s", rentalOffice.contactNum);
    printf("\nBedrooms: %s", rentalOffice.bedrooms);
    printf("\nMortgage: %s", rentalOffice.mortgage);
    printf("\nRent: %s", rentalOffice.rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
}
void addRentalLand(struct user usr)
{
    struct rentalLand rentalLand;
    printf("\nEnter address:\t");
    takeInput(rentalLand.address);
    printf("\nEnter land type:\t");
    takeInput(rentalLand.landType);
    printf("\nEnter area in meter:\t");
    takeInput(rentalLand.size);
    printf("\nEnter contact number:\t");
    takeInput(rentalLand.contactNum);
    printf("\nEnter mortgage:\t");
    takeInput(rentalLand.mortgage);
    printf("\nEnter rent:\t");
    takeInput(rentalLand.rent);
    // Set the addedByUser field to the username of the user who added the property
    strcpy(rentalLand.addedByUser, usr.username);
    FILE *fp;
    fp = fopen("RentalLands.dat", "a");
    fwrite(&rentalLand, sizeof(struct rentalLand), 1, fp);
    fclose(fp);
    printf("\nLand property added successfully!\n");
    printf("\nAddress: %s", rentalLand.address);
    printf("\nLand type: %s", rentalLand.landType);
    printf("\nArea: %s", rentalLand.size);
    printf("\nContact Number: %s", rentalLand.contactNum);
    printf("\nMortgage: %s", rentalLand.mortgage);
    printf("\nRent: %s", rentalLand.rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
}
void addRentalEstate(struct user usr)
{
    int choice;
    printf("\n\t\t\t\tAdding new rental estate");
    printf("\n\n1. Add residental property");
    printf("\n2. Add office property");
    printf("\n3. Add land property");
    printf("\n4. Back to menu");
    printf("\n\nYour choice:\t");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        addRentalResidental(usr);
        break;
    case 2:
        addRentalOffice(usr);
        break;
    case 3:
        addRentalLand(usr);
        break;
    case 4:
        // Return to the main menu
        break;
    default:
        printf("\nInvalid choice! Please try again.\n");
        break;
    }
}
void addEstate(struct user usr)
{
    printf("\nChoose action do you want to take");
    printf("\n1. Add estates for sale");
    printf("\n2. Add estates for rent");
    printf("\n3. Back to menu");
    printf("\nYour choice:\t");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        addSaleEstate(usr);
        break;
    case 2:
        addRentalEstate(usr);
        break;

    default:
        break;
    }
}

void mainMenu(struct user usr)
{
    int choice;

    do
    {
        // system("cls");
        printf("\n\t\t\t\t---===== Welcome to Estate Management System =====---");
        printf("\n\t\t\t\t\t\t   Main Menu");
        printf("\n\n1. Add new estate");
        printf("\n2. Delete estate");
        printf("\n3. Reports");
        printf("\n4. Account setting");
        printf("\n5. Log out");
        printf("\n6. Exit the program");
        printf("\n\nYour choice:\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEstate(usr);
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
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    } while (choice != 6);
}

void signUp()
{
    FILE *fp;
    struct user users;
    char password2[50];

    do
    {
        printf("\n\nEnter your full name:\t");
        takeInput(users.fullName);
        printf("\nEnter your email:\t");
        takeInput(users.email);
        printf("\nEnter phone number:\t");
        takeInput(users.phone);
        printf("\nEnter phone ID:\t");
        takeInput(users.userID);

        do // Check if username is different
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
        printf("\n\nUser registration was successful. Press any key to continue...");
        getch();
    }
    else
        printf("Oops! Something went wrong :( ");

    fclose(fp);
}

void login()
{
    FILE *fp;
    struct user *start = NULL, *end, *usr, ur;
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

        while (!feof(fp))
        {
            usr = malloc(sizeof(struct user));
            fread(usr, sizeof(struct user), 1, fp);

            if (start == NULL)
            {
                start = usr;
                end = usr;
                end->link = NULL;
            }
            else
            {
                end->link = usr;
                end = usr;
                end->link = NULL;
            }
        }

        usr = start;
        while (usr)
        {
            if (!strcmp(usr->username, username) && !strcmp(usr->password, pword))
            {
                system("cls");
                printf("\n\t\t\t\tWelcome %s", usr->fullName);
                printf("\n\n|Full name:\t%s", usr->fullName);
                printf("\n|Email:\t%s", usr->email);
                printf("\n|Username:\t%s", usr->username);
                printf("\n|Phone number:\t%s", usr->phone);
                printf("\n|ID:\t%s", usr->userID);
                userFound = 1;

                mainMenu(*usr);
                break; // Exit the loop once the user is found
            }

            usr= usr->link;
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
        // system("cls");
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
            printf("Goodbye, have a nice day :)");
            exit(0);
        default:
        printf("Error, Invalid input! try again");

            break;
        }
    }
}
