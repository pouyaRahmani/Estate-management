#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
    char userID[50];
    char date[21];
    int totalAdded;
    struct user *link;
};

struct residentalSale
{
    char zone[50];
    char address[200];
    char estateType[50];
    char ageEstate[50];
    char size[50];
    char floors[50];
    char infrastructure[50];
    char contactNum[50];
    char bedrooms[50];
    char price[50];
    char addedByUser[50];
    char deleteDate[21];
    struct residentalSale *next;
};

struct officeSale
{
    char zone[50];
    char address[200];
    char estateType[50];
    char ageEstate[50];
    char size[50];
    char floors[50];
    char infrastructure[50];
    char contactNum[50];
    char officeRooms[50];
    char price[50];
    char addedByUser[50];
    char deleteDate[21];
    struct officeSale *next;
};

struct landSale
{
    char address[200];
    char landType[50];
    char size[50];
    char contactNum[50];
    char price[50];
    char addedByUser[50];
    char deleteDate[21];
    struct landSale *next;
};

struct rentalResidental
{
    char zone[50];
    char address[200];
    char estateType[50];
    char ageEstate[50];
    char size[50];
    char floors[50];
    char infrastructure[50];
    char contactNum[50];
    char bedrooms[50];
    char mortgage[50];
    char rent[50];
    char addedByUser[50];
    char deleteDate[21];
    struct rentalResidental *next;
};
struct rentalOffice
{
    char zone[50];
    char address[200];
    char estateType[50];
    char ageEstate[50];
    char size[50];
    char floors[50];
    char infrastructure[50];
    char contactNum[50];
    char bedrooms[50];
    char mortgage[50];
    char rent[50];
    char addedByUser[50];
    char deleteDate[21];
    struct rentalOffice *next;
};

struct rentalLand
{
    char address[200];
    char landType[50];
    char size[50];
    char contactNum[50];
    char mortgage[50];
    char rent[50];
    char addedByUser[50];
    char deleteDate[21];
    struct rentalLand *next;
};

struct user *userHead = NULL, *userLast, *userNode;
struct residentalSale *residentalSaleHead = NULL, *residentalSaleLast, *residentalSaleNode;
struct officeSale *officeSaleHead = NULL, *officeSaleLast, *officeSaleNode;
struct landSale *landSaleHead = NULL, *landSaleLast, *landSaleNode;
struct rentalResidental *rentalResidentalHead = NULL, *rentalResidentalLast, *rentalResidentalNode;
struct rentalOffice *rentalOfficeHead = NULL, *rentalOfficeLast, *rentalOfficeNode;
struct rentalLand *rentalLandHead = NULL, *rentalLandLast, *rentalLandNode;

void takeInput(char ch[50]);
void takePassword(char pwd[50]);
int isUsernameTaken(char username[50]);
void ExitProject();
void addResidentalSale(struct user usr);
void addOfficeSale(struct user usr);
void addLandSale(struct user usr);
void addSaleEstate(struct user usr);
void addRentalResidental(struct user usr);
void addRentalOffice(struct user usr);
void addRentalLand(struct user usr);
void addRentalEstate(struct user usr);
void addEstate(struct user usr);
void countEstates();
void listEstatesByZone(const char *zoneCode);
void listEstatesByAge(int minAge, int maxAge);
void listEstatesBySize(int minSize, int maxSize);
void listEstatesByPrice(int minPrice, int maxPrice);
void listEstatesByRooms(char *rooms);
void totalEstatesValue();
void listByRentAndMortgage(int minMortgage, int maxMortgage, int minRent, int maxRent);
void listEstatesByFloor(const char *floorNum);
void lastActive();
void modifyPassword(char password[50]);

struct user *swap(struct user *usr1, struct user *usr2)
{
    struct user *temp = usr2->link;
    usr2->link = usr1;
    usr1->link = temp;

    return usr2;
}

// Declare functions prototypes
void bubbleSort(struct user **start, int num);
void insertNode(struct user **head, struct user *newNode);
void printList(struct user *head);
int countUsers();
void userRegistrations();
int date(char *deleteDate);
void deleteReports();
void registrationReport();
void reports(struct user usr);
void deleteResidentalSale();
void deleteOfficeSale();
void deleteLandSale();
void deleteRentalResidental();
void deleteRentalOffice();
void deleteRentalLand();
void deleteEstate();
void changeProfile(struct user *currentUser);
void mainMenu(struct user usr);
int isValidName(char *name);
int isValidEmail(char *email);
int isValidPhoneNumber(char *phoneNumber);
int isValidID(char *nationalCode);
int isStrongPassword(char *password);
void signUp();
void login();

// Make colorfull error and success message
#define es "\x1b[1;31m"
#define ee "\x1b[0m"
#define ss "\x1b[1;32m"
#define se "\x1b[0m"

void main()
{
    system("color 0b");
    int role;

    while (role != 3)
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
            ExitProject();
        default:
            printf(es "Error, Invalid input! Press any key to continue" ee);
            Beep(800, 300);
            getch();
            system("color 0b");
            break;
        }
    }
}

void takeInput(char ch[50])
{
    gets(ch);
}

int isUsernameTaken(char username[50])
{
    FILE *fp;
    struct user *node;

    fp = fopen("Users.dat", "rb");

    node = malloc(sizeof(struct user));
    while (fread(node, sizeof(struct user), 1, fp))
    {
        if (strcmp(node->username, username) == 0 && node->username != "admin")
        {
            fclose(fp);
            return 1; // Username is already taken
        }
    }

    fclose(fp);
    return 0; // Username is not taken
}

void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100] = " ========= Thank You =========\n";
    char HaveNiceDay[100] = " ======= Have Nice Day =======\n";
    for (i = 0; i < strlen(ThankYou); i++)
    {
        printf("%c", ThankYou[i]);
        Sleep(40);
    }
    for (i = 0; i < strlen(HaveNiceDay); i++)
    {
        printf("%c", HaveNiceDay[i]);
        Sleep(40);
    }
    exit(0);
}

void addResidentalSale(struct user usr)
{
    struct residentalSale *newEstate = malloc(sizeof(struct residentalSale));
    if (newEstate == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter zone:\t");
    takeInput(newEstate->zone);
    printf("\nEnter address:\t");
    takeInput(newEstate->address);
    printf("\nEnter estate type:\t");
    takeInput(newEstate->estateType);
    printf("\nEnter age of estate:\t");
    takeInput(newEstate->ageEstate);
    printf("\nEnter area in meter:\t");
    takeInput(newEstate->size);
    printf("\nEnter floors:\t");
    takeInput(newEstate->floors);
    printf("\nEnter area of main structure in meter:\t");
    takeInput(newEstate->infrastructure);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(newEstate->bedrooms);
    printf("\nEnter price:\t");
    takeInput(newEstate->price);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
    strcpy(newEstate->deleteDate, "0"); // 0 means the estate is active
    newEstate->next = residentalSaleHead;
    residentalSaleHead = newEstate;

    FILE *fp;
    fp = fopen("ResidentialSales.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(newEstate, sizeof(struct residentalSale), 1, fp);
    fclose(fp);

    // Display property features
    printf(ss "\nResidential property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main Estate: %s", newEstate->infrastructure);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nBedrooms: %s", newEstate->bedrooms);
    printf("\nPrice: %s", newEstate->price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue..." se);
    getch();
    system("cls");
    system("color 0b");
}

void addOfficeSale(struct user usr)
{
    struct officeSale *newEstate = malloc(sizeof(struct officeSale));
    if (newEstate == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter zone:\t");
    takeInput(newEstate->zone);
    printf("\nEnter address:\t");
    takeInput(newEstate->address);
    printf("\nEnter estate type:\t");
    takeInput(newEstate->estateType);
    printf("\nEnter age of estate:\t");
    takeInput(newEstate->ageEstate);
    printf("\nEnter area in meter:\t");
    takeInput(newEstate->size);
    printf("\nEnter floors:\t");
    takeInput(newEstate->floors);
    printf("\nEnter area of main structure in meter:\t");
    takeInput(newEstate->infrastructure);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter office rooms:\t");
    takeInput(newEstate->officeRooms);
    printf("\nEnter price:\t");
    takeInput(newEstate->price);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
    strcpy(newEstate->deleteDate, "0"); // 0 means the estate is active
    newEstate->next = officeSaleHead;
    officeSaleHead = newEstate;

    FILE *fp;
    fp = fopen("OfficeSales.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(newEstate, sizeof(struct officeSale), 1, fp);
    fclose(fp);

    // Display property features
    printf(ss "\nOffice property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main structure: %s", newEstate->infrastructure);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nOffice Rooms: %s", newEstate->officeRooms);
    printf("\nPrice: %s", newEstate->price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue..." se);
    getch();
    system("cls");
    system("color 0b");
}

void addLandSale(struct user usr)
{
    struct landSale *newEstate = malloc(sizeof(struct landSale));
    if (newEstate == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter address:\t");
    takeInput(newEstate->address);
    printf("\nEnter land type:\t");
    takeInput(newEstate->landType);
    printf("\nEnter area in meter:\t");
    takeInput(newEstate->size);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter price:\t");
    takeInput(newEstate->price);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
    strcpy(newEstate->deleteDate, "0"); // 0 means the estate is active
    newEstate->next = landSaleHead;
    landSaleHead = newEstate;
    FILE *fp;
    fp = fopen("LandSales.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(newEstate, sizeof(struct landSale), 1, fp);
    fclose(fp);
    // Display property features
    printf(ss "\nLand property added successfully!");
    printf("\nAddress: %s", newEstate->address);
    printf("\nLand type: %s", newEstate->landType);
    printf("\nArea: %s", newEstate->size);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nPrice: %s", newEstate->price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue..." se);
    getch();
    system("cls");
    system("color 0b");
}

void addSaleEstate(struct user usr)
{
    int choice;
    system("cls");

    do
    {
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
            system("cls");
            addResidentalSale(usr);
            break;
        case 2:
            system("cls");
            addOfficeSale(usr);
            break;
        case 3:
            system("cls");
            addLandSale(usr);
            break;
        case 4:
            system("cls");
            // Return to the main menu
            break;
        default:
            system("cls");
            printf(es "\nInvalid choice! press any key and try again.\n" ee);
            getch();
            system("color 0b");
            break;
        }
    } while (choice != 4);
}

void addRentalResidental(struct user usr)
{
    struct rentalResidental *newEstate = malloc(sizeof(struct rentalResidental));
    if (newEstate == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter zone:\t");
    takeInput(newEstate->zone);
    printf("\nEnter address:\t");
    takeInput(newEstate->address);
    printf("\nEnter estate type:\t");
    takeInput(newEstate->estateType);
    printf("\nEnter age of estate:\t");
    takeInput(newEstate->ageEstate);
    printf("\nEnter area in meter:\t");
    takeInput(newEstate->size);
    printf("\nEnter floors:\t");
    takeInput(newEstate->floors);
    printf("\nEnter area of main structure in meter:\t");
    takeInput(newEstate->infrastructure);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(newEstate->bedrooms);
    printf("\nEnter mortgage:\t");
    takeInput(newEstate->mortgage);
    printf("\nEnter rent:\t");
    takeInput(newEstate->rent);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
    strcpy(newEstate->deleteDate, "0"); // 0 means the estate is active
    newEstate->next = rentalResidentalHead;
    rentalResidentalHead = newEstate;

    FILE *fp;
    fp = fopen("RentalResidental.dat", "ab"); // Use "wb" for the first write
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(newEstate, sizeof(struct rentalResidental), 1, fp);
    fclose(fp);

    // Display property features
    printf(ss "\nRental Residential property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main structure: %s", newEstate->infrastructure);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nBedrooms: %s", newEstate->bedrooms);
    printf("\nMortgage: %s", newEstate->mortgage);
    printf("\nRent: %s", newEstate->rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue..." se);
    getch();
    system("cls");
    system("color 0b");
}

void addRentalOffice(struct user usr)
{
    struct rentalOffice *newEstate = malloc(sizeof(struct rentalOffice));
    if (newEstate == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter zone:\t");
    takeInput(newEstate->zone);
    printf("\nEnter address:\t");
    takeInput(newEstate->address);
    printf("\nEnter estate type:\t");
    takeInput(newEstate->estateType);
    printf("\nEnter age of estate:\t");
    takeInput(newEstate->ageEstate);
    printf("\nEnter Area in meter:\t");
    takeInput(newEstate->size);
    printf("\nEnter floors:\t");
    takeInput(newEstate->floors);
    printf("\nEnter Area of main structure in meter:\t");
    takeInput(newEstate->infrastructure);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(newEstate->bedrooms);
    printf("\nEnter mortgage:\t");
    takeInput(newEstate->mortgage);
    printf("\nEnter rent:\t");
    takeInput(newEstate->rent);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
    strcpy(newEstate->deleteDate, "0"); // 0 means the estate is active
    newEstate->next = rentalOfficeHead;
    rentalOfficeHead = newEstate;

    FILE *fp;
    fp = fopen("RentalOffice.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(newEstate, sizeof(struct rentalOffice), 1, fp);
    fclose(fp);

    // Display property features
    printf(ss "\nRental office property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main Estate: %s", newEstate->infrastructure);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nBedrooms: %s", newEstate->bedrooms);
    printf("\nMortgage: %s", newEstate->mortgage);
    printf("\nRent: %s", newEstate->rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue..." se);
    getch();
    system("cls");
    system("color 0b");
}

void addRentalLand(struct user usr)
{
    struct rentalLand *newEstate = malloc(sizeof(struct rentalLand));
    if (newEstate == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter address:\t");
    takeInput(newEstate->address);
    printf("\nEnter land type:\t");
    takeInput(newEstate->landType);
    printf("\nEnter area in meter:\t");
    takeInput(newEstate->size);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter mortgage:\t");
    takeInput(newEstate->mortgage);
    printf("\nEnter rent:\t");
    takeInput(newEstate->rent);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
    strcpy(newEstate->deleteDate, "0"); // 0 means the estate is active
    newEstate->next = rentalLandHead;
    rentalLandHead = newEstate;

    FILE *fp;
    fp = fopen("RentalLands.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(newEstate, sizeof(struct rentalLand), 1, fp);
    fclose(fp);

    // Display property features
    printf(ss "\nLand property added successfully!");
    printf("\nAddress: %s", newEstate->address);
    printf("\nLand type: %s", newEstate->landType);
    printf("\nArea: %s", newEstate->size);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nMortgage: %s", newEstate->mortgage);
    printf("\nRent: %s", newEstate->rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue..." se);
    getch();
    system("cls");
    system("color 0b");
}

void addRentalEstate(struct user usr)
{
    int choice;
    system("cls");

    do
    {
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
            system("cls");
            addRentalResidental(usr);
            break;
        case 2:
            system("cls");
            addRentalOffice(usr);
            break;
        case 3:
            system("cls");
            addRentalLand(usr);
            break;
        case 4:
            system("cls");
            // Return to the main menu
            break;
        default:
            system("cls");
            printf(es "\nInvalid choice! Press any key and try again.\n" ee);
            Beep(800, 300);
            getch();
            system("color 0b");
            break;
        }
    } while (choice != 4);
}

void addEstate(struct user usr)
{
    int choice;

    do
    {
        printf("\nChoose action do you want to take");
        printf("\n1. Add estates for sale");
        printf("\n2. Add estates for rent");
        printf("\n3. Back to menu");
        printf("\nYour choice:\t");
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
        case 3:
            system("cls");
            break;
        default:
            system("cls");
            printf(es "\n\nInvalid choice! Press any key and try again\n" ee);
            Beep(800, 300);
            getch();
            system("color 0b");
            break;
        }
    } while (choice != 3);
}

void countEstates()
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;
    int residentialCount = 0, officeCount = 0, landCount = 0, rentalResidentialCount = 0, rentalOfficeCount = 0, rentalLandCount = 0;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->deleteDate, "0") == 0)
        {
            residentialCount++;
        }
    }
    fclose(residentialFile);

    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->deleteDate, "0") == 0)
        {
            officeCount++;
        }
    }
    fclose(officeFile);

    landNode = malloc(sizeof(struct landSale));
    while (fread(landNode, sizeof(struct landSale), 1, landFile))
    {
        if (strcmp(landNode->deleteDate, "0") == 0)
        {
            landCount++;
        }
    }
    fclose(landFile);

    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            rentalResidentialCount++;
        }
    }
    fclose(rentalResidentialFile);

    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            rentalOfficeCount++;
        }
    }
    fclose(rentalOfficeFile);

    rentalLandNode = malloc(sizeof(struct rentalLand));
    while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
    {
        if (strcmp(rentalLandNode->deleteDate, "0") == 0)
        {
            rentalLandCount++;
        }
    }
    fclose(rentalLandFile);

    printf("\nNumber of existing residential sales estates: %d", residentialCount);
    printf("\nNumber of existing office sales estates: %d", officeCount);
    printf("\nNumber of existing land sales estates: %d", landCount);
    printf("\nNumber of existing rental residential estates: %d", rentalResidentialCount);
    printf("\nNumber of existing rental office estates: %d", rentalOfficeCount);
    printf("\nNumber of existing rental land estates: %d\n", rentalLandCount);
}

void listEstatesByZone(const char *zoneCode)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->zone, zoneCode) == 0 && strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }

    fclose(residentialFile);
    officeNode = malloc(sizeof(struct officeSale));

    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->zone, zoneCode) == 0 && strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }

    fclose(officeFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->zone, zoneCode) == 0 && strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->zone, zoneCode) == 0 && strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);

    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void listEstatesByAge(int minAge, int maxAge)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        int age = atoi(residentialNode->ageEstate);
        if (age >= minAge && age <= maxAge && strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(residentialFile);

    // Process office sales estates
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        int age = atoi(officeNode->ageEstate);
        if (age >= minAge && age <= maxAge && strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(officeFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        int age = atoi(rentalResidentialNode->ageEstate);
        if (age >= minAge && age <= maxAge && strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        int age = atoi(rentalOfficeNode->ageEstate);
        if (age >= minAge && age <= maxAge && strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);

    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void listEstatesBySize(int minSize, int maxSize)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        int size = atoi(residentialNode->infrastructure);
        if (size >= minSize && size <= maxSize && strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(residentialFile);

    // Process office sales estates
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        int size = atoi(officeNode->infrastructure);
        if (size >= minSize && size <= maxSize && strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(officeFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        int size = atoi(rentalResidentialNode->infrastructure);
        if (size >= minSize && size <= maxSize && strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);
    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        int size = atoi(rentalOfficeNode->infrastructure);
        if (size >= minSize && size <= maxSize && strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);

    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void listEstatesByPrice(int minPrice, int maxPrice)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        int price = atoi(residentialNode->price);
        if (price >= minPrice && price <= maxPrice && strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(residentialFile);

    // Process office sales estates
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        int price = atoi(officeNode->price);
        if (price >= minPrice && price <= maxPrice && strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(officeFile);
    // Process land sales
    landNode = malloc(sizeof(struct landSale));
    while (fread(landNode, sizeof(struct landSale), 1, landFile))
    {
        int price = atoi(landNode->price);
        if (price >= minPrice && price <= maxPrice && strcmp(landNode->deleteDate, "0") == 0)
        {
            printf("\nAddress: %s\t\tLand Type: %s\t\tSize: %s", landNode->address, landNode->landType, landNode->size);
            printf("\nNum: %s\t\tPrice: %s", landNode->contactNum, landNode->price);
            printf("\nAdded by user: _%s_ for LAND SALE", landNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(landFile);

    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(landNode);
    return;
}

void listEstatesByRooms(char *rooms)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->bedrooms, rooms) == 0 && strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(residentialFile);
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->officeRooms, rooms) == 0 && strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }

    fclose(officeFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->bedrooms, rooms) == 0 && strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->bedrooms, rooms) == 0 && strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);

    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void totalEstatesValue()
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;
    int toatal = 0;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->deleteDate, "0") == 0)
        {
            int price = atoi(residentialNode->price);
            toatal += price;
        }
    }
    fclose(residentialFile);

    // Process office sales estates
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->deleteDate, "0") == 0)
        {
            int price = atoi(officeNode->price);
            toatal += price;
        }
    }
    fclose(officeFile);
    // Process land sales
    landNode = malloc(sizeof(struct landSale));
    while (fread(landNode, sizeof(struct landSale), 1, landFile))
    {
        if (strcmp(landNode->deleteDate, "0") == 0)
        {
            int price = atoi(landNode->price);
            toatal += price;
        }
    }
    fclose(landFile);
    printf("The total value of the estates for sale in system is: %d$", toatal);
    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(rentalResidentialNode);
    free(landNode);
    return;
}

void listByRentAndMortgage(int minMortgage, int maxMortgage, int minRent, int maxRent)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        int mortgage = atoi(rentalResidentialNode->mortgage);
        int rent = atoi(rentalResidentialNode->rent);
        if (mortgage >= minMortgage && mortgage <= maxMortgage && rent >= minRent && rent <= maxRent && strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        int mortgage = atoi(rentalOfficeNode->mortgage);
        int rent = atoi(rentalOfficeNode->rent);
        if (mortgage >= minMortgage && mortgage <= maxMortgage && rent >= minRent && rent <= maxRent && strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);
    // Process rental lands
    rentalLandNode = malloc(sizeof(struct rentalLand));
    while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
    {
        int mortgage = atoi(rentalLandNode->mortgage);
        int rent = atoi(rentalLandNode->rent);
        if (mortgage >= minMortgage && mortgage <= maxMortgage && rent >= minRent && rent <= maxRent && strcmp(rentalLandNode->deleteDate, "0") == 0)
        {
            printf("\nAddress: %s\t\tLand Type: %s\t\tSize: %s", rentalLandNode->address, rentalLandNode->landType, rentalLandNode->size);
            printf("\nNum: %s\t\tmortgage: %s\t\tRent: %s", rentalLandNode->contactNum, rentalLandNode->mortgage, rentalLandNode->rent);
            printf("\nAdded by user: _%s_ for RENTAL LAND", rentalLandNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalLandFile);
    //  Free allocated memory
    free(rentalLandNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void listEstatesByFloor(const char *floorNum)
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    // Process residential sales estates
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->floors, floorNum) == 0 && strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(residentialFile);

    // Process rental office estates
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->floors, floorNum) == 0 && strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(officeFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->floors, floorNum) == 0 && strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->floors, floorNum) == 0 && strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);

    // Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void lastActive()
{
    FILE *usersFile;
    struct user *userNode;
    usersFile = fopen("Users.dat", "rb");
    userNode = malloc(sizeof(struct user));
    while (fread(userNode, sizeof(struct user), 1, usersFile))
    {
        printf("\nUsername: %s\t\tName: %s\t\tuserID: %s", userNode->username, userNode->fullName, userNode->userID);
        printf("\nLast activity in %s", userNode->date);
        printf("\n---------------------------------------------------------------------------------------------\n");
    }
    fclose(usersFile);
}

void bubbleSort(struct user **start, int num)
{
    struct user **h;
    int i, j;
    bool swapped;
    for (i = 0; i < num - 1; i++)
    {
        swapped = false;
        h = start;

        for (j = 0; j < num - i - 1; j++)
        {
            struct user *user1 = *h;
            struct user *user2 = user1->link;

            if (user1->totalAdded < user2->totalAdded)
            { // update the link after swapping
                *h = swap(user1, user2);
                swapped = true;
            }

            h = &((*h)->link);
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void insertNode(struct user **head, struct user *newNode)
{
    if (*head == NULL || (*head)->totalAdded <= newNode->totalAdded)
    {
        newNode->link = *head;
        *head = newNode;
    }
    else
    {
        struct user *current = *head;
        while (current->link != NULL && current->link->totalAdded > newNode->totalAdded)
        {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

void printList(struct user *head)
{
    struct user *temp = head;
    while (temp != NULL)
    {
        printf("User: %s\t\tTotal added:%d\n", temp->username, temp->totalAdded);
        printf("\n---------------------------------------------------------\n");
        temp = temp->link;
    }
}

int countUsers()
{
    struct user userNode;
    int numberOfUsers = 0;
    FILE *usersFile;

    usersFile = fopen("Users.dat", "rb");
    if (usersFile == NULL)
    {
        // Handle file opening error
        printf("Error opening Users.dat file.\n");
        exit(EXIT_FAILURE);
    }

    // Count the number of users in the file
    while (fread(&userNode, sizeof(struct user), 1, usersFile))
    {
        numberOfUsers++;
    }

    // Reset the file position indicator
    fseek(usersFile, 0, SEEK_SET);

    // Close the file
    fclose(usersFile);

    return numberOfUsers;
}

void userRegistrations()
{
    FILE *usersFile, *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct user *userNode;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;
    int numberOfUsers = countUsers();

    usersFile = fopen("Users.dat", "rb");
    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");

    residentialNode = malloc(sizeof(struct residentalSale));
    officeNode = malloc(sizeof(struct officeSale));
    landNode = malloc(sizeof(struct landSale));
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    rentalLandNode = malloc(sizeof(struct rentalLand));
    userNode = malloc(sizeof(struct user));
    struct user *head = NULL; // Linked list head

    while (fread(userNode, sizeof(struct user), 1, usersFile))
    {
        int totalCount = 0;

        // Reset the file position indicators for each estate type
        fseek(residentialFile, 0, SEEK_SET);
        fseek(officeFile, 0, SEEK_SET);
        fseek(landFile, 0, SEEK_SET);
        fseek(rentalResidentialFile, 0, SEEK_SET);
        fseek(rentalOfficeFile, 0, SEEK_SET);
        fseek(rentalLandFile, 0, SEEK_SET);

        while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
        {
            if (strcmp(userNode->username, residentialNode->addedByUser) == 0)
            {
                totalCount++;
            }
        }

        while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
        {
            if (strcmp(userNode->username, officeNode->addedByUser) == 0)
            {
                totalCount++;
            }
        }

        while (fread(landNode, sizeof(struct landSale), 1, landFile))
        {
            if (strcmp(userNode->username, landNode->addedByUser) == 0)
            {
                totalCount++;
            }
        }

        while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
        {
            if (strcmp(userNode->username, rentalResidentialNode->addedByUser) == 0)
            {
                totalCount++;
            }
        }

        while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
        {
            if (strcmp(userNode->username, rentalOfficeNode->addedByUser) == 0)
            {
                totalCount++;
            }
        }

        while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
        {
            if (strcmp(userNode->username, rentalLandNode->addedByUser) == 0)
            {
                totalCount++;
            }
        }

        userNode->totalAdded = totalCount;

        // Create a new node
        struct user *newNode = malloc(sizeof(struct user));
        if (newNode == NULL)
        {
            // Handle memory allocation error
            exit(EXIT_FAILURE);
        }

        // Copy data to the new node
        strcpy(newNode->username, userNode->username);
        newNode->totalAdded = userNode->totalAdded;
        newNode->link = NULL;

        // Insert the new node into the sorted linked list
        insertNode(&head, newNode);
    }
    bubbleSort(&head, numberOfUsers);

    // Print the sorted report
    printList(head);

    // Close all files
    fclose(usersFile);
    fclose(residentialFile);
    fclose(officeFile);
    fclose(landFile);
    fclose(rentalResidentialFile);
    fclose(rentalOfficeFile);
    fclose(rentalLandFile);

    // Free allocated memory
    free(userNode);
    free(residentialNode);
    free(officeNode);
    free(landNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    free(rentalLandNode);
}

int date(char *deleteDate)
{
    int year, month, day;
    sscanf(deleteDate, "%d/%d/%d", &year, &month, &day);
    int date;
    date = (year * 12 + month) * 30 + day;
    return date;
}

void deleteReports()
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;
    char startDate[11], endDate[11];
    int deleteStart, deleteEnd;

    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");
    residentialNode = malloc(sizeof(struct residentalSale));

    printf("Enter start date (YYYY/MM/DD): ");
    scanf("%s", startDate);
    printf("Enter end date (YYYY/MM/DD): ");
    scanf("%s", endDate);
    getchar();
    deleteStart = date(startDate);
    deleteEnd = date(endDate);
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->deleteDate, "0") != 0)
        {
            int deletedNumericDate = date(residentialNode->deleteDate);
            if (deletedNumericDate >= deleteStart && deletedNumericDate <= deleteEnd)
            {
                printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
                printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
                printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales\t Delete date: %s", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser, residentialNode->deleteDate);
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    fclose(residentialFile);

    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->deleteDate, "0") != 0)
        {
            int deletedNumericDate = date(officeNode->deleteDate);
            if (deletedNumericDate >= deleteStart && deletedNumericDate <= deleteEnd)
            {
                printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
                printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
                printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales\t Delete date: %s", officeNode->officeRooms, officeNode->price, officeNode->addedByUser, officeNode->deleteDate);
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    fclose(officeFile);

    // Process land sales
    landNode = malloc(sizeof(struct landSale));
    while (fread(landNode, sizeof(struct landSale), 1, landFile))
    {
        if (strcmp(landNode->deleteDate, "0") != 0)
        {
            int deletedNumericDate = date(landNode->deleteDate);
            if (deletedNumericDate >= deleteStart && deletedNumericDate <= deleteEnd)
            {
                printf("\nAddress: %s\t\tLand Type: %s\t\tSize: %s", landNode->address, landNode->landType, landNode->size);
                printf("\nNum: %s\t\tPrice: %s", landNode->contactNum, landNode->price);
                printf("\nAdded by user: _%s_ for LAND SALE\t Delete date: %s", landNode->addedByUser, landNode->deleteDate);
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    fclose(landFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->deleteDate, "0") != 0)
        {
            int deletedNumericDate = date(rentalResidentialNode->deleteDate);
            if (deletedNumericDate >= deleteStart && deletedNumericDate <= deleteEnd)
            {
                printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
                printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
                printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL\t Delete date: %s", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser, rentalResidentialNode->deleteDate);
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->deleteDate, "0") != 0)
        {
            int deletedNumericDate = date(rentalResidentialNode->deleteDate);
            if (deletedNumericDate >= deleteStart && deletedNumericDate <= deleteEnd)
            {
                printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
                printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
                printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE\t Delete date: %s", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser, rentalOfficeNode->deleteDate);
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    fclose(rentalOfficeFile);

    // Process rental lands
    rentalLandNode = malloc(sizeof(struct rentalLand));
    while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
    {
        if (strcmp(rentalLandNode->deleteDate, "0") != 0)
        {
            int deletedNumericDate = date(rentalLandNode->deleteDate);
            if (deletedNumericDate >= deleteStart && deletedNumericDate <= deleteEnd)
            {
                printf("\nAddress: %s\t\tLand Type: %s\t\tSize: %s", rentalLandNode->address, rentalLandNode->landType, rentalLandNode->size);
                printf("\nNum: %s\t\tmortgage: %s\t\tRent: %s", rentalLandNode->contactNum, rentalLandNode->mortgage, rentalLandNode->rent);
                printf("\nAdded by user: _%s_ for RENTAL LAND\t Delete date: %s", rentalLandNode->addedByUser, rentalLandNode->deleteDate);
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    fclose(rentalLandFile);
    //  Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(landNode);
    free(rentalLandNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void registrationReport()
{
    FILE *residentialFile, *officeFile, *landFile, *rentalResidentialFile, *rentalOfficeFile, *rentalLandFile;
    struct residentalSale *residentialNode;
    struct officeSale *officeNode;
    struct landSale *landNode;
    struct rentalResidental *rentalResidentialNode;
    struct rentalOffice *rentalOfficeNode;
    struct rentalLand *rentalLandNode;
    char startDate[11], endDate[11];
    int start, end;
    printf("\n\t\t\t\t---===== Registered estates Reports =====---\n");
    residentialFile = fopen("ResidentialSales.dat", "rb");
    officeFile = fopen("OfficeSales.dat", "rb");
    landFile = fopen("LandSales.dat", "rb");
    rentalResidentialFile = fopen("RentalResidental.dat", "rb");
    rentalOfficeFile = fopen("RentalOffice.dat", "rb");
    rentalLandFile = fopen("RentalLands.dat", "rb");
    residentialNode = malloc(sizeof(struct residentalSale));

    printf("Enter start date (YYYY/MM/DD): ");
    scanf("%s", startDate);
    printf("Enter end date (YYYY/MM/DD): ");
    scanf("%s", endDate);
    getchar();
    start = date(startDate);
    end = date(endDate);
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->infrastructure, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(residentialFile);

    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->infrastructure, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(officeFile);

    // Process land sales
    landNode = malloc(sizeof(struct landSale));
    while (fread(landNode, sizeof(struct landSale), 1, landFile))
    {
        if (strcmp(landNode->deleteDate, "0") == 0)
        {
            printf("\nAddress: %s\t\tLand Type: %s\t\tSize: %s", landNode->address, landNode->landType, landNode->size);
            printf("\nNum: %s\t\tPrice: %s", landNode->contactNum, landNode->price);
            printf("\nAdded by user: _%s_ for LAND SALE", landNode->addedByUser, landNode->deleteDate);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(landFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate, rentalResidentialNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalResidentialNode->floors, rentalResidentialNode->infrastructure, rentalResidentialNode->contactNum, rentalResidentialNode->mortgage);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->deleteDate, "0") == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s\t\tSize: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate, rentalOfficeNode->size);
            printf("\nFloors: %s\t\tInfrastructure: %s\t\tNum: %s\t\tMortgage: %s", rentalOfficeNode->floors, rentalOfficeNode->infrastructure, rentalOfficeNode->contactNum, rentalOfficeNode->mortgage);
            printf("\nOffice rooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL OFFICE", rentalOfficeNode->bedrooms, rentalOfficeNode->rent, rentalOfficeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalOfficeFile);

    // Process rental lands
    rentalLandNode = malloc(sizeof(struct rentalLand));
    while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
    {
        if (strcmp(rentalLandNode->deleteDate, "0") == 0)
        {
            printf("\nAddress: %s\t\tLand Type: %s\t\tSize: %s", rentalLandNode->address, rentalLandNode->landType, rentalLandNode->size);
            printf("\nNum: %s\t\tmortgage: %s\t\tRent: %s", rentalLandNode->contactNum, rentalLandNode->mortgage, rentalLandNode->rent);
            printf("\nAdded by user: _%s_ for RENTAL LAND", rentalLandNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalLandFile);
    //  Free allocated memory
    free(residentialNode);
    free(officeNode);
    free(landNode);
    free(rentalLandNode);
    free(rentalResidentialNode);
    free(rentalOfficeNode);
    return;
}

void reports(struct user usr)
{
    char zoneCode[50], rooms[50], floorNum[50];
    int choice;
    int minAge, maxAge, minSize, maxSize, minPrice, maxPrice;
    int minMortgage, maxMortgage, minRent, maxRent;

    if (strcmp(usr.username, "admin") != 0) // Check if the user is not admin then show the options
    {
        do
        {
            printf("\n\t\t\t\t---===== Reports =====---");
            printf("\n\n1. Number of exiting estates in the system");
            printf("\n2. List of estates by the specific zone(by the zone's code)");
            printf("\n3. List of estates by the age range");
            printf("\n4. List of estates by the size of infrastructure");
            printf("\n5. List of estates by the price range");
            printf("\n6. List of estates by the specific number of rooms");
            printf("\n7. Total value of the estates in the system");
            printf("\n8. List of rental estates sorted by mortgage and rent");
            printf("\n9. List of registered estates in specific period of time");
            printf("\n10. List of estates in specific floor");
            printf("\n11. Back to the main menu");
            printf("\n\nYour choice:\t");
            scanf("%d", &choice);
            getchar(); // for not reading the \n

            switch (choice)
            {
            case 1:
                system("cls");
                countEstates();
                break;
            case 2:
                system("cls");
                printf("Enter the zone code: ");
                scanf("%s", &zoneCode);
                listEstatesByZone(zoneCode);
                break;
            case 3:
                system("cls");
                printf("Enter min age of the estate: ");
                scanf("%d", &minAge);
                printf("Enter max age of the estate: ");
                scanf("%d", &maxAge);
                listEstatesByAge(minAge, maxAge);
                break;
            case 4:
                system("cls");
                printf("Enter min infrastructure size of the estate: ");
                scanf("%d", &minSize);
                printf("Enter max infrastructure size of the estate: ");
                scanf("%d", &maxSize);
                listEstatesBySize(minSize, maxSize);
                break;
            case 5:
                system("cls");
                printf("Enter min price of the estate: ");
                scanf("%d", &minPrice);
                printf("Enter max price of the estate: ");
                scanf("%d", &maxPrice);
                listEstatesByPrice(minPrice, maxPrice);
                break;
            case 6:
                system("cls");
                printf("Enter number of the rooms: ");
                scanf("%s", &rooms);
                listEstatesByRooms(rooms);
                break;
            case 7:
                system("cls");
                totalEstatesValue();
                break;
            case 8:
                system("cls");
                printf("Enter min mortgage: ");
                scanf("%d", &minMortgage);
                printf("Enter max mortgage: ");
                scanf("%d", &maxMortgage);
                printf("Enter min rent: ");
                scanf("%d", &minRent);
                printf("Enter max rent: ");
                scanf("%d", &maxRent);
                listByRentAndMortgage(minMortgage, maxMortgage, minRent, maxRent);
                break;
            case 9:
                system("cls");
                registrationReport();
                break;
            case 10:
                system("cls");
                printf("Enter a floor number");
                scanf("%s", &floorNum);
                listEstatesByFloor(floorNum);
                break;
            case 11:
                system("cls");
                // Return to the main menu
                break;
            default:
                system("cls");
                printf(es "\nInvalid choice! Press any key and try again.\n" ee);
                Beep(800, 300);
                getch();
                system("color 0b");
                break;
            }
        } while (choice != 11);
    }
    else // Admin reports with especial options
    {
        do
        {
            // system("cls");
            printf("\n\t\t\t\t---===== Reports =====---");
            printf("\n\n1. Number of exiting estates in the system");
            printf("\n2. List of estates by the specific zone(by the zone's code)");
            printf("\n3. List of estates by the age range");
            printf("\n4. List of estates by the size of infrastructure");
            printf("\n5. List of estates by the price range");
            printf("\n6. List of estates by the specific number of rooms");
            printf("\n7. Total value of the estates in the system");
            printf("\n8. List of rental estates sorted by mortgage and rent");
            printf("\n9. List of users by the number of registered estates");
            printf("\n10. List of estates in specific floor");
            printf("\n11. List of registered estates in specific period of time");
            printf("\n12. List of deleted estates in specific period of time");
            printf("\n13. List of last users activity");
            printf("\n14. Back to the main menu");
            printf("\n\nYour choice:\t");
            scanf("%d", &choice);
            getchar(); // for not reading the \n

            switch (choice)
            {
            case 1:
                system("cls");
                countEstates();
                break;
            case 2:
                system("cls");
                printf("Enter the zone code: ");
                scanf("%s", &zoneCode);
                listEstatesByZone(zoneCode);
                break;
            case 3:
                system("cls");
                printf("Enter min age of the estate: ");
                scanf("%d", &minAge);
                printf("Enter max age of the estate: ");
                scanf("%d", &maxAge);
                listEstatesByAge(minAge, maxAge);
                break;
            case 4:
                system("cls");
                printf("Enter min infrastructure size of the estate: ");
                scanf("%d", &minSize);
                printf("Enter max infrastructure size of the estate: ");
                scanf("%d", &maxSize);
                listEstatesBySize(minSize, maxSize);
                break;
            case 5:
                system("cls");
                printf("Enter min price of the estate: ");
                scanf("%d", &minPrice);
                printf("Enter max price of the estate: ");
                scanf("%d", &maxPrice);
                listEstatesByPrice(minPrice, maxPrice);
                break;
            case 6:
                system("cls");
                printf("Enter number of the rooms: ");
                scanf("%s", &rooms);
                listEstatesByRooms(rooms);
                break;
            case 7:
                system("cls");
                totalEstatesValue();
                break;
            case 8:
                system("cls");
                printf("Enter min mortgage: ");
                scanf("%d", &minMortgage);
                printf("Enter max mortgage: ");
                scanf("%d", &maxMortgage);
                printf("Enter min rent: ");
                scanf("%d", &minRent);
                printf("Enter max rent: ");
                scanf("%d", &maxRent);
                listByRentAndMortgage(minMortgage, maxMortgage, minRent, maxRent);
                break;
            case 9:
                system("cls");
                userRegistrations();
                break;
            case 10:
                system("cls");
                printf("Enter a floor number");
                scanf("%s", &floorNum);
                listEstatesByFloor(floorNum);
                break;
            case 11:
                system("cls");
                registrationReport();
                break;
            case 12:
                system("cls");
                printf("\n\t\t\t\t---===== Delete Reports =====---\n");
                deleteReports();
                break;
            case 13:
                system("cls");
                lastActive();
                break;
            case 14:
                system("cls");
                // Return to the main menu
                break;
            default:
                system("cls");
                printf(es "\nInvalid choice! Press any key and try again.\n" ee);
                Beep(800, 300);
                getch();
                system("color 0b");
                break;
            }
        } while (choice != 14);
    }
}

void deleteResidentalSale()
{
    FILE *residentialFile;
    struct residentalSale *residentialNode;
    char deleteAddress[200];
    residentialFile = fopen("ResidentialSales.dat", "rb+");
    if (residentialFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Please Enter the exact address of the estate to delete: ");
    gets(deleteAddress);

    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        if (strcmp(residentialNode->address, deleteAddress) == 0)
        {
            // Mark the structure as deleted by setting the deleteDate to the current date
            time_t t = time(NULL);
            struct tm *local_time = localtime(&t);
            sprintf(residentialNode->deleteDate, "%0d/%0d/%0d", local_time->tm_year + 1900,
                    local_time->tm_mon + 1, local_time->tm_mday);

            // Move the file pointer back to overwrite the existing structure with the updated one
            fseek(residentialFile, -sizeof(struct residentalSale), SEEK_CUR);
            fwrite(residentialNode, sizeof(struct residentalSale), 1, residentialFile);

            printf(ss "Estate at address %s deleted successfully. Press any key to continue..." se, deleteAddress);
            getch();
            system("color 0b");
            break; // No need to continue searching
        }
    }
    fclose(residentialFile);
    free(residentialNode);
}

void deleteOfficeSale()
{
    FILE *officeFile;
    struct officeSale *officeSaleNode;
    char deleteAddress[200];
    officeFile = fopen("OfficeSales.dat", "rb+");
    if (officeFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Please Enter the exact address of the estate to delete: ");
    gets(deleteAddress);

    officeSaleNode = malloc(sizeof(struct officeSale));
    while (fread(officeSaleNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeSaleNode->address, deleteAddress) == 0)
        {
            // Mark the structure as deleted by setting the deleteDate to the current date
            time_t t = time(NULL);
            struct tm *local_time = localtime(&t);
            sprintf(officeSaleNode->deleteDate, "%0d/%0d/%0d", local_time->tm_year + 1900,
                    local_time->tm_mon + 1, local_time->tm_mday);

            // Move the file pointer back to overwrite the existing structure with the updated one
            fseek(officeFile, -sizeof(struct officeSale), SEEK_CUR);
            fwrite(officeSaleNode, sizeof(struct officeSale), 1, officeFile);

            printf(ss "Estate at address %s deleted successfully. Press any key to continue..." se, deleteAddress);
            getch();
            system("color 0b");
            break; // No need to continue searching
        }
    }
    fclose(officeFile);
    free(officeSaleNode);
}

void deleteLandSale()
{
    FILE *landFile;
    struct landSale *landSaleNode;
    char deleteAddress[200];
    landFile = fopen("LandSales.dat", "rb+");
    if (landFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Please Enter the exact address of the estate to delete: ");
    gets(deleteAddress);

    landSaleNode = malloc(sizeof(struct landSale));
    while (fread(landSaleNode, sizeof(struct landSale), 1, landFile))
    {
        if (strcmp(landSaleNode->address, deleteAddress) == 0)
        {
            // Mark the structure as deleted by setting the deleteDate to the current date
            time_t t = time(NULL);
            struct tm *local_time = localtime(&t);
            sprintf(landSaleNode->deleteDate, "%0d/%0d/%0d", local_time->tm_year + 1900,
                    local_time->tm_mon + 1, local_time->tm_mday);

            // Move the file pointer back to overwrite the existing structure with the updated one
            fseek(landFile, -sizeof(struct landSale), SEEK_CUR);
            fwrite(landSaleNode, sizeof(struct landSale), 1, landFile);

            printf(ss "Estate at address %s deleted successfully. Press any key to continue..." se, deleteAddress);
            getch();
            system("color 0b");
            break; // No need to continue searching
        }
    }
    fclose(landFile);
    free(landSaleNode);
}

void deleteRentalResidental()
{
    FILE *rentalResidentialFile;
    struct rentalResidental *rentalResidentialNode;
    char deleteAddress[200];
    rentalResidentialFile = fopen("RentalResidental.dat", "rb+");
    if (rentalResidentialFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Please Enter the exact address of the estate to delete: ");
    gets(deleteAddress);

    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->address, deleteAddress) == 0)
        {
            // Mark the structure as deleted by setting the deleteDate to the current date
            time_t t = time(NULL);
            struct tm *local_time = localtime(&t);
            sprintf(rentalResidentialNode->deleteDate, "%0d/%0d/%0d", local_time->tm_year + 1900,
                    local_time->tm_mon + 1, local_time->tm_mday);

            // Move the file pointer back to overwrite the existing structure with the updated one
            fseek(rentalResidentialFile, -sizeof(struct rentalResidental), SEEK_CUR);
            fwrite(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile);

            printf(ss "Estate at address %s deleted successfully. Press any key to continue..." se, deleteAddress);
            getch();
            system("color 0b");
            break; // No need to continue searching
        }
    }
    fclose(rentalResidentialFile);
    free(rentalResidentialNode);
}

void deleteRentalOffice()
{
    FILE *rentalOfficeFile;
    struct rentalOffice *rentalOfficeNode;
    char deleteAddress[200];
    rentalOfficeFile = fopen("RentalOffice.dat", "rb+");
    if (rentalOfficeFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Please Enter the exact address of the estate to delete: ");
    gets(deleteAddress);

    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->address, deleteAddress) == 0)
        {
            // Mark the structure as deleted by setting the deleteDate to the current date
            time_t t = time(NULL);
            struct tm *local_time = localtime(&t);
            sprintf(rentalOfficeNode->deleteDate, "%0d/%0d/%0d", local_time->tm_year + 1900,
                    local_time->tm_mon + 1, local_time->tm_mday);

            // Move the file pointer back to overwrite the existing structure with the updated one
            fseek(rentalOfficeFile, -sizeof(struct rentalOffice), SEEK_CUR);
            fwrite(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile);

            printf(ss "Estate at address %s deleted successfully. Press any key to continue..." se, deleteAddress);
            getch();
            system("color 0b");
            break; // No need to continue searching
        }
    }
    fclose(rentalOfficeFile);
    free(rentalOfficeNode);
}

void deleteRentalLand()
{
    FILE *rentalLandFile;
    struct rentalLand *rentalLandNode;
    char deleteAddress[200];
    rentalLandFile = fopen("RentalLands.dat", "rb+");
    if (rentalLandFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Please Enter the exact address of the estate to delete: ");
    gets(deleteAddress);

    rentalLandNode = malloc(sizeof(struct rentalLand));
    while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
    {
        if (strcmp(rentalLandNode->address, deleteAddress) == 0)
        {
            // Mark the structure as deleted by setting the deleteDate to the current date
            time_t t = time(NULL);
            struct tm *local_time = localtime(&t);
            sprintf(rentalLandNode->deleteDate, "%0d/%0d/%0d", local_time->tm_year + 1900,
                    local_time->tm_mon + 1, local_time->tm_mday);

            // Move the file pointer back to overwrite the existing structure with the updated one
            fseek(rentalLandFile, -sizeof(struct rentalLand), SEEK_CUR);
            fwrite(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile);

            printf(ss "Estate at address %s deleted successfully. Press any key to continue..." se, deleteAddress);
            getch();
            system("color 0b");
            break; // No need to continue searching
        }
    }
    fclose(rentalLandFile);
    free(rentalLandNode);
}

void deleteEstate()
{

    int choice;

    do
    {
        printf("\n\t\t\t\t---===== Estate Delete =====---");
        printf("\nChoose the type of estate you want to delete");
        printf("\n\n1. Delete residental estate sale");
        printf("\n2. Delete office sale");
        printf("\n3. Delete land sale");
        printf("\n4. Delete rental residental estate ");
        printf("\n5. Delete rental office ");
        printf("\n6. Delete rental land ");
        printf("\n7. Back to main menu");
        printf("\n\nYour choice:\t");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            system("cls");
            deleteResidentalSale();
            break;
        case 2:
            system("cls");
            deleteOfficeSale();
            break;
        case 3:
            system("cls");
            deleteLandSale();
            break;
        case 4:
            system("cls");
            deleteRentalResidental();
            break;
        case 5:
            system("cls");
            deleteRentalOffice();
            break;
        case 6:
            system("cls");
            deleteRentalLand();
            break;
        case 7:
            system("cls");
            // Return to the menu
            break;
        default:
            system("cls");
            printf(es "\nInvalid choice! Please try again.\n" ee);
            Beep(800, 300);
            getch();
            system("color 0b");
            break;
        }
    } while (choice != 7);
}

void changeProfile(struct user *currentUser)
{
    FILE *fp;
    fp = fopen("Users.dat", "rb+"); // Open the file in read and write mode
    if (fp == NULL)
    {
        printf("\nError opening the file!");
        return;
    }

    struct user temp;

    // Find the position of the current user in the file
    while (fread(&temp, sizeof(struct user), 1, fp) == 1)
    {
        if (strcmp(temp.userID, currentUser->userID) == 0)
        {
            break; // Found the current user
        }
    }

    if (feof(fp))
    {
        printf("\nUser not found in the file!");
        fclose(fp);
        return;
    }

    int choice;
    int change = 0;

    do
    {
        printf("\n\t\t\t\t---===== Change Profile =====---");
        printf("\n\n1. Change Password");
        printf("\n2. Change Email");
        printf("\n3. Change Phone Number");
        printf("\n4. Change User ID");
        printf("\n5. Change full name");
        printf("\n6. Back to the menu");
        printf("\n\nYour choice:\t");
        scanf("%d", &choice);
        getchar(); // for not reading the \n

        switch (choice)
        {
        case 1:
            printf("\nEnter your new password:\t");
            takePassword(temp.password);
            modifyPassword(temp.password);
            printf(ss "\nPassword changed successfully. Press any key to continue..." se);
            change++;
            getchar();
            system("color 0b");
            break;
        case 2:
            printf("\nEnter your new email:\t");
            takeInput(temp.email);
            printf(ss "\nEmail changed successfully. Press any key to continue..." se);
            change++;
            getchar();
            system("color 0b");
            break;
        case 3:
            printf("\nEnter your new phone number:\t");
            takeInput(temp.phone);
            printf(ss "\nPhone number changed successfully. Press any key to continue..." se);
            change++;
            getchar();
            system("color 0b");
            break;
        case 4:
            printf("\nEnter your new User ID:\t");
            takeInput(temp.userID);
            printf(ss "\nUser ID changed successfully. Press any key to continue..." se);
            change++;
            getchar();
            system("color 0b");
            break;
        case 5:
            printf("\nEnter your new full name:\t");
            takeInput(temp.fullName);
            printf(ss "\nFull name changed successfully. Press any key to continue..." se);
            change++;
            getchar();
            system("color 0b");
            break;
        case 6:
            // Move the file pointer to the beginning of the user record
            fseek(fp, -sizeof(struct user), SEEK_CUR);

            // Write the updated user back to the file
            fwrite(&temp, sizeof(struct user), 1, fp);

            // Close the file
            fclose(fp);
            printf(ss "\nProfile changes saved successfully. Press any key to continue..." se);
            getchar();
            system("color 0b");
            break;
        default:
            printf(es "\nInvalid choice! Press any key and try again." ee);
            getch();
            system("color 0b");
            break;
        }
    } while (choice != 6);
}

void mainMenu(struct user usr)
{
    int choice;

    do
    {
        system("cls");
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
            system("cls");
            addEstate(usr);
            break;
        case 2:
            system("cls");
            deleteEstate();
            break;
        case 3:
            system("cls");
            reports(usr);
            break;
        case 4:
            system("cls");
            changeProfile(&usr);
            break;
        case 5:
            system("cls");
            return;
            break;
        case 6:
            system("cls");
            ExitProject();
            break;
        default:
            system("cls");
            printf(es "\n\nInvalid choice! Please press any key to continue...\n" ee);
            Beep(800, 300);
            getch();
            system("color 0b");
            break;
        }
    } while (choice != 6);
}

int isValidName(char *name)
{
    // Check if the name contains only English alphabet characters
    for (int i = 0; i < strlen(name); i++)
    {
        if (!isalpha(name[i]) && !isspace(name[i]))
        {
            return 1; // Invalid name
        }
    }
    return 0; // Valid name
}

int isValidEmail(char *email)
{
    // Check if '@' and '.' are present in the email
    char *atSymbol = strchr(email, '@');
    char *dotSymbol = strchr(email, '.');
    int valid = 0;
    // Check if '@' and '.' exist, and there is at least one character before and after '@'
    if (atSymbol != NULL && dotSymbol != NULL &&
        atSymbol != email && dotSymbol > atSymbol + 1 &&
        dotSymbol < email + strlen(email) - 1)
    {
        valid = 0; // Valid email address
    }
    else
    {
        valid = 1; // Invalid email address
    }

    FILE *fp;
    struct user *node;
    fp = fopen("Users.dat", "rb");
    node = malloc(sizeof(struct user));

    while (fread(node, sizeof(struct user), 1, fp))
    {
        if (strcmp(node->email, email) == 0)
        {
            valid = 2; // Email is already taken
            break;
        }
    }

    fclose(fp);
    free(node);
    return valid;
}

int isValidPhoneNumber(char *phoneNumber)
{
    FILE *fp;
    struct user *node;
    fp = fopen("Users.dat", "rb");
    node = malloc(sizeof(struct user));
    int valid = 0;

    // Check if the phone number is exactly 11 digits and contains only numeric characters
    if (strlen(phoneNumber) == 11)
    {
        if (phoneNumber[0] == '0' && isdigit(phoneNumber[1]))
        {
            for (int i = 1; i < 11; i++)
            {
                if (!isdigit(phoneNumber[i]))
                {
                    valid = 1; // Invalid phone number
                    break;
                }
            }

            if (valid == 0)
            { // If phone number is still considered valid, check if it's already taken
                while (fread(node, sizeof(struct user), 1, fp))
                {
                    if (strcmp(node->phone, phoneNumber) == 0)
                    {
                        valid = 2; // Phone number is already taken
                        break;
                    }
                }
            }
        }
        else
        {
            valid = 1; // Invalid phone number
        }
    }
    else
    {
        valid = 1; // Invalid phone number
    }

    fclose(fp);
    free(node);
    return valid;
}

int isValidID(char *nationalCode)
{
    FILE *fp;
    struct user *node;

    // Check if the national code is exactly 10 digits and contains only numeric characters
    if (strlen(nationalCode) != 10 || nationalCode[0] != '0')
    {
        return 1; // Invalid national code
    }

    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(nationalCode[i]))
        {
            return 1; // Invalid national code
        }
    }

    fp = fopen("Users.dat", "rb");
    node = malloc(sizeof(struct user));
    int isTaken = 0;

    while (fread(node, sizeof(struct user), 1, fp))
    {
        if (strcmp(node->userID, nationalCode) == 0)
        {
            isTaken = 1;
        }
    }

    fclose(fp);
    free(node);

    if (isTaken)
    {
        return 2; // ID is already taken
    }
    else
    {
        return 0; // Valid national code
    }
}

int isStrongPassword(char *password)
{
    // Check if password length is at least 8 characters
    if (strlen(password) < 8)
    {
        return 1; // Password is less than 8 characters
    }

    // Check if password includes both uppercase and lowercase characters
    int hasUppercase = 0, hasLowercase = 0, i;

    for (i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            hasUppercase = 1;
        }
        else if (islower(password[i]))
        {
            hasLowercase = 1;
        }
    }

    if (!hasUppercase || !hasLowercase)
    {
        return 1; // Password doesn't include both uppercase and lowercase characters
    }

    // Check if password includes at least one special character
    char *specialCharacters = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";
    int hasSpecialCharacter = 0;

    for (i = 0; i < strlen(password); i++)
    {
        if (strchr(specialCharacters, password[i]) != NULL)
        {
            hasSpecialCharacter = 1;
            break;
        }
    }

    if (!hasSpecialCharacter)
    {
        return 2; // Password doesn't include special characters
    }

    // Password meets all criteria
    return 0;
}

void takePassword(char pwd[50])
{
#define Enter 13
#define Tab 9
#define BKSPC 8
    int i = 0;
    char ch;
    // Replace password with * for the security
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

// Function to change password saving in the file
void modifyPassword(char password[50])
{
    int length = strlen(password);
    for (int i = 0; i < length / 2; i++)
    {
        // Swap characters from the beginning and end of the password
        char temp = password[i];
        password[i] = password[length - i - 1];
        password[length - i - 1] = temp;

        // Change ASCII codes with various characters
        password[i] = password[i] + i * 2;
        password[length - i - 1] = password[length - i - 1] + (i * 3 + 2);
    }
}

void signUp()
{
    FILE *fp;
    char password2[50];
    time_t t;
    struct tm *local_time;
    system("cls");

    userNode = malloc(sizeof(struct user));
    if (userNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Check for valid name
    do
    {
        printf("\n\nEnter your full name:\t");
        takeInput(userNode->fullName);
        if (isValidName(userNode->fullName) == 0)
        {
            break;
        }

        printf(es "\nInvalid name!! Press any key and try again" ee);
        Beep(750, 300);
        getch();
        system("color 0b");
    } while (1);

    // Checking the Email address
    do
    {
        printf("\nEnter your email:\t");
        takeInput(userNode->email);
        int validEmail = isValidEmail(userNode->email);

        if (validEmail == 0)
        {
            break;
        }
        else if (validEmail == 1)
        {
            printf(es "Invalid Email!! Try again" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }
        else
        {
            printf(es "\nEmail is already taken. Try again" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }

    } while (1);

    // Checking the phone number
    do
    {
        printf("\nEnter phone number:\t");
        takeInput(userNode->phone);
        int validNum = isValidPhoneNumber(userNode->phone);
        if (validNum == 0)
        {
            break;
        }
        else if (validNum == 1)
        {
            printf(es "Invalid Phone number!! Try again" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }
        else
        {
            printf(es "\nPhone number is already taken. Try again" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }
    } while (1);

    do
    {
        printf("\nEnter your national code:\t");
        takeInput(userNode->userID);
        int validID = isValidID(userNode->userID);
        if (validID == 0)
        {
            break;
        }
        else if (validID == 1)
        {
            printf(es "Invalid national code!! Try again" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }
        else
        {
            printf(es "\nnational code is already taken. Try again" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }
    } while (1);

    userNode->totalAdded = 0;

    do // Check if username is different
    {
        printf("\nEnter your username:\t");
        takeInput(userNode->username);
        if (isUsernameTaken(userNode->username) == 0)
        {
            break;
        }

        printf(es "\nUsername is already taken. Please choose another one." ee);
        Beep(750, 300);
        getch();
        system("color 0b");
    } while (1);

    do
    {
        do
        {
            printf("\nEnter your password:\t");
            takePassword(userNode->password);
            // Modify the password before saving
            modifyPassword(userNode->password);
            int strongPass = isStrongPassword(userNode->password);

            if (strongPass == 0)
            {
                break;
            }
            else if (strongPass == 1)
            {
                printf(es "\nPassword most be at least 8 character and included upper and lower cases!! Try again" ee);
                Beep(750, 300);
                getch();
                system("color 0b");
            }
            else
            {
                printf(es "\nPassword must include special character. Try again" ee);
                Beep(750, 300);
                getch();
                system("color 0b");
            }
        } while (1);

        printf("\nConfirm your password:\t");
        takePassword(password2);

        // Modify the confirmation password before comparing
        modifyPassword(password2);

        // Compare two passwords
        if (strcmp(userNode->password, password2))
        {
            printf(es "\nYour passwords didn't match. Please try again!" ee);
            Beep(750, 300);
            getch();
            system("color 0b");
        }
    } while (strcmp(userNode->password, password2));

    printf(ss "\nYour password matched, Press any key to continue..." se);
    getch();
    system("color 0b");

    fp = fopen("Users.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    t = time(NULL);
    local_time = localtime(&t);
    sprintf(userNode->date, "%0d/%0d/%0d %02d:%02d:%02d", local_time->tm_year + 1900, local_time->tm_mon + 1,
            local_time->tm_mday, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    fwrite(userNode, sizeof(struct user), 1, fp);
    fclose(fp);

    printf(ss "\n\nUser registration was successful. Press any key to continue..." se);
    getch();
    system("color 0b");
}

void forgetPassword()
{
    FILE *usersFile;
    struct user *userNode;
    char username[50], ID[50], newPassword[50], confirmPassword[50];

    printf("\nPlease enter the user details to change your password");
    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("\nEnter your national code: ");
    scanf("%s", ID);

    usersFile = fopen("Users.dat", "rb+");

    if (usersFile == NULL)
    {
        printf("\nError opening the file!");
        return;
    }

    userNode = malloc(sizeof(struct user));
    if (userNode == NULL)
    {
        printf("\nMemory allocation error!");
        fclose(usersFile);
        return;
    }

    int userFound = 0;

    while (fread(userNode, sizeof(struct user), 1, usersFile))
    {
        if (strcmp(userNode->userID, ID) == 0 && strcmp(userNode->username, username) == 0)
        {
            do
            {
                printf("\nEnter new password: ");
                takePassword(newPassword);
                printf("\nEnter the new password again: ");
                takePassword(confirmPassword);

                if (strcmp(newPassword, confirmPassword) != 0)
                {
                    printf("\nPasswords do not match. Please try again.");
                }
            } while (strcmp(newPassword, confirmPassword) != 0);

            // Modify the new password before updating
            modifyPassword(newPassword);

            // Update the password
            strcpy(userNode->password, newPassword);

            // Save the updated user data back to the file
            fseek(usersFile, -sizeof(struct user), SEEK_CUR); // Move the file pointer back by the size of struct user
            fwrite(userNode, sizeof(struct user), 1, usersFile);

            printf(ss "\nPassword changed successfully! Press any key to continue" se);
            getch();
            system("color 0b");

            userFound = 1;
            break; // Exit the loop once the user is found
        }
    }

    if (!userFound)
    {
        printf(es "\nUser not found or incorrect details provided. press any key to continue" ee);
        getch();
        system("color 0b");
    }

    fclose(usersFile);
    free(userNode);
}

void login()
{
    FILE *fp;
    char username[50], pword[50];
    int userFound, count = 0;
    system("cls");

    do
    {
        userFound = 0; // Reset the flag for each login attempt

        printf("\nEnter your username:\t");
        takeInput(username);
        printf("\nEnter your password:\t");
        takePassword(pword);
        // Modify the entered password before comparing
        modifyPassword(pword);
        fp = fopen("Users.dat", "rb");

        while (!feof(fp))
        {
            userNode = malloc(sizeof(struct user));
            fread(userNode, sizeof(struct user), 1, fp);

            if (userHead == NULL)
            {
                userHead = userNode;
                userLast = userNode;
                userLast->link = NULL;
            }
            else
            {
                userLast->link = userNode;
                userLast = userNode;
                userLast->link = NULL;
            }
        }

        userNode = userHead;
        while (userNode)
        {
            if (!strcmp(userNode->username, username) && !strcmp(userNode->password, pword))
            {
                // Update login time
                time_t t = time(NULL);
                struct tm *local_time = localtime(&t);
                sprintf(userNode->date, "%0d/%0d/%0d %02d:%02d:%02d", local_time->tm_year + 1900, local_time->tm_mon + 1,
                        local_time->tm_mday, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

                // Save updated user data back to the file
                fseek(fp, -sizeof(struct user), SEEK_CUR); // Move the file pointer back by the size of struct user
                fwrite(userNode, sizeof(struct user), 1, fp);

                system("cls");
                printf("\n\t\t\t\tWelcome %s", userNode->fullName);
                printf("\n\n|Full name:\t%s", userNode->fullName);
                printf("\n|Email:\t%s", userNode->email);
                printf("\n|Username:\t%s", userNode->username);
                printf("\n|Phone number:\t%s", userNode->phone);
                printf("\n|ID:\t%s", userNode->userID);
                printf("\n|Last login:\t%s", userNode->date);
                printf("\n\nPress any key to continue...");
                userFound = 1;
                getch();
                mainMenu(*userNode);
                break; // Exit the loop once the user is found
            }

            userNode = userNode->link;
        }

        if (!userFound)
        {
            count++;
            printf(es "\n\nInvalid username or password!! Please try again." ee);
            Beep(800, 300);
            getch();
            system("color 0b");
        }

        if (count == 2)
        {
            int choice;
            count = 3;
            do
            {
                system("cls");
                printf("\n\nDid you forget your password?");
                printf("\n1. Yes\n2. No continue\n");
                printf("Your choice : ");
                scanf("%d", &choice);
                getchar();

                switch (choice)
                {
                case 1:
                    forgetPassword();
                    break;
                case 2:
                    continue;
                    break;
                default:
                    printf(es "\n\nInvalid choice, press any key and try again...\n" ee);
                    Beep(800, 300);
                    getch();
                    system("color 0b");
                    break;
                }
            } while (choice != 2);
        }

        // Stop the program while there is to much invalid password or username
        if (count == 5)
        {
            printf("Too many attempts!!! Please try again after 15 minutes.");
            Sleep(900000);
        }
        else if (count == 10)
        {
            printf("Too many attempts!!! Please try again after 30 minutes.");
            Sleep(1800000);
        }
        fclose(fp);
    } while (!userFound);
}