#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
    char userID[50];
    char date[9];
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
    struct residentalSale *next;
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
    struct officeSale *next;
};
struct landSale
{
    char address[100];
    char landType[50];
    char size[50];
    char contactNum[50];
    char price[50];
    char addedByUser[50];
    struct landSale *next;
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
    struct rentalResidental *next;
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
    struct rentalOffice *next;
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
    struct rentalLand *next;
};
struct user *userHead = NULL, *userLast, *userNode;
struct residentalSale *residentalSaleHead = NULL, *residentalSaleLast, *residentalSaleNode;
struct officeSale *officeSaleHead = NULL, *officeSaleLast, *officeSaleNode;
struct landSale *landSaleHead = NULL, *landSaleLast, *landSaleNode;
struct rentalResidential *rentalResidentalHead = NULL, *rentalResidentalLast, *rentalResidentalNode;
struct rentalOffice *rentalOfficeHead = NULL, *rentalOfficeLast, *rentalOfficeNode;
struct rentalLand *rentalLandHead = NULL, *rentalLandLast, *rentalLandNode;

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
    takeInput(newEstate->sizeMainEstate);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter bedrooms:\t");
    takeInput(newEstate->bedrooms);
    printf("\nEnter price:\t");
    takeInput(newEstate->price);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
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
    printf("\nResidential property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main Estate: %s", newEstate->sizeMainEstate);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nBedrooms: %s", newEstate->bedrooms);
    printf("\nPrice: %s", newEstate->price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
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
    takeInput(newEstate->sizeMainEstate);
    printf("\nEnter contact number:\t");
    takeInput(newEstate->contactNum);
    printf("\nEnter office rooms:\t");
    takeInput(newEstate->officeRooms);
    printf("\nEnter price:\t");
    takeInput(newEstate->price);

    // Set the addedByUser field to the username of the user who added the property
    strcpy(newEstate->addedByUser, usr.username);
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
    printf("\nOffice property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main structure: %s", newEstate->sizeMainEstate);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nOffice Rooms: %s", newEstate->officeRooms);
    printf("\nPrice: %s", newEstate->price);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
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
    printf("\nLand property added successfully!");
    printf("\nAddress: %s", newEstate->address);
    printf("\nLand type: %s", newEstate->landType);
    printf("\nArea: %s", newEstate->size);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nPrice: %s", newEstate->price);
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
    takeInput(newEstate->sizeMainEstate);
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
    printf("\nRental Residential property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main structure: %s", newEstate->sizeMainEstate);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nBedrooms: %s", newEstate->bedrooms);
    printf("\nMortgage: %s", newEstate->mortgage);
    printf("\nRent: %s", newEstate->rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
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
    takeInput(newEstate->sizeMainEstate);
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
    printf("\nRental office property added successfully!");
    printf("\nZone: %s", newEstate->zone);
    printf("\nAddress: %s", newEstate->address);
    printf("\nEstate Type: %s", newEstate->estateType);
    printf("\nAge of Estate: %s", newEstate->ageEstate);
    printf("\nArea: %s", newEstate->size);
    printf("\nFloors: %s", newEstate->floors);
    printf("\nArea of Main Estate: %s", newEstate->sizeMainEstate);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nBedrooms: %s", newEstate->bedrooms);
    printf("\nMortgage: %s", newEstate->mortgage);
    printf("\nRent: %s", newEstate->rent);
    printf("\nAdded by User: %s", usr.username);
    printf("\n\n Press any key to continue...");
    getch();
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
    printf("\nLand property added successfully!");
    printf("\nAddress: %s", newEstate->address);
    printf("\nLand type: %s", newEstate->landType);
    printf("\nArea: %s", newEstate->size);
    printf("\nContact Number: %s", newEstate->contactNum);
    printf("\nMortgage: %s", newEstate->mortgage);
    printf("\nRent: %s", newEstate->rent);
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
    // // This part will be used when all the files is existing
    // if (residentialFile == NULL || officeFile == NULL || landFile == NULL ||
    //     rentalResidentialFile == NULL || rentalOfficeFile == NULL || rentalLandFile == NULL)
    // {
    //     printf("Error opening one or more files.\n");
    //     return;
    // }
    residentialNode = malloc(sizeof(struct residentalSale));
    while (fread(residentialNode, sizeof(struct residentalSale), 1, residentialFile))
    {
        residentialCount++;
    }
    fclose(residentialFile);

    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        officeCount++;
    }
    fclose(officeFile);

    landNode = malloc(sizeof(struct landSale));
    while (fread(landNode, sizeof(struct landSale), 1, landFile))
    {
        landCount++;
    }
    fclose(landFile);

    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        rentalResidentialCount++;
    }
    fclose(rentalResidentialFile);

    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        rentalOfficeCount++;
    }
    fclose(rentalOfficeFile);

    rentalLandNode = malloc(sizeof(struct rentalLand));
    while (fread(rentalLandNode, sizeof(struct rentalLand), 1, rentalLandFile))
    {
        rentalLandCount++;
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
        if (strcmp(residentialNode->zone, zoneCode) == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", residentialNode->zone, residentialNode->address, residentialNode->estateType, residentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", residentialNode->size, residentialNode->floors, residentialNode->sizeMainEstate, residentialNode->contactNum);
            printf("\nBedrooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for  RESIDENTAL sales", residentialNode->bedrooms, residentialNode->price, residentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
        fclose(residentialFile);
    officeNode = malloc(sizeof(struct officeSale));
    while (fread(officeNode, sizeof(struct officeSale), 1, officeFile))
    {
        if (strcmp(officeNode->zone, zoneCode) == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", officeNode->zone, officeNode->address, officeNode->estateType, officeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", officeNode->size, officeNode->floors, officeNode->sizeMainEstate, officeNode->contactNum);
            printf("\nOffice rooms: %s\t\tPrice: %s\t\tAdded by user: _%s_ for OFFICE sales", officeNode->officeRooms, officeNode->price, officeNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }

    fclose(officeFile);

    // Process rental residential estates
    rentalResidentialNode = malloc(sizeof(struct rentalResidental));
    while (fread(rentalResidentialNode, sizeof(struct rentalResidental), 1, rentalResidentialFile))
    {
        if (strcmp(rentalResidentialNode->zone, zoneCode) == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", rentalResidentialNode->zone, rentalResidentialNode->address, rentalResidentialNode->estateType, rentalResidentialNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", rentalResidentialNode->size, rentalResidentialNode->floors, rentalResidentialNode->sizeMainEstate, rentalResidentialNode->contactNum);
            printf("\nBedrooms: %s\t\tRent: %s\t\tAdded by user: _%s_ for RENTAL RESIDENTIAL", rentalResidentialNode->bedrooms, rentalResidentialNode->rent, rentalResidentialNode->addedByUser);
            printf("\n-------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(rentalResidentialFile);

    // Process rental office estates
    rentalOfficeNode = malloc(sizeof(struct rentalOffice));
    while (fread(rentalOfficeNode, sizeof(struct rentalOffice), 1, rentalOfficeFile))
    {
        if (strcmp(rentalOfficeNode->zone, zoneCode) == 0)
        {
            printf("\nZone: %s\t\tAddress: %s\t\tType: %s\t\tAge: %s", rentalOfficeNode->zone, rentalOfficeNode->address, rentalOfficeNode->estateType, rentalOfficeNode->ageEstate);
            printf("\nSize: %s\t\tFloors: %s\t\tInfrastructure: %s\t\tNum: %s", rentalOfficeNode->size, rentalOfficeNode->floors, rentalOfficeNode->sizeMainEstate, rentalOfficeNode->contactNum);
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
// Users report
void reports()
{
    int choice;
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
        // Write admin reports in the end!!
        printf("\n8. List of rental estates sorted by mortgage and rent");
        printf("\n9. Back to the main menu");
        printf("\n\nYour choice:\t");
        scanf("%d", &choice);
        getchar(); // for not reading the \n
        switch (choice)
        {
        case 1:
            countEstates();
            break;
        case 2:
            printf("Enter the zone code (1 to 6): ");
            char zoneCode[50];
            scanf("%s", &zoneCode);
            listEstatesByZone(zoneCode);
            break;
        case 3:
            // Add code for List of estates by the age range
            break;
        case 4:
            // Add code for List of estates by the size of infrastructure
            break;
        case 5:
            // Add code for List of estates by the price range
            break;
        case 6:
            // Add code for List of estates by the specific number of rooms
            break;
        case 7:
            // Add code for Total value of the estates in the system
            break;
        case 8:
            // Add code for List of rental estates sorted by mortgage and rent
            break;
        case 9:
            // Return to the main menu
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    } while (choice != 9);
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

    int choice;
    do
    {
        // system("cls");
        printf("\n\t\t\t\t---===== Change Profile =====---");
        printf("\n\n1. Change Password");
        printf("\n2. Change Email");
        printf("\n3. Change Phone Number");
        printf("\n4. Change User ID");
        printf("\n5. Back to Menu");
        printf("\n\nYour choice:\t");
        scanf("%d", &choice);
        getchar(); // for not reading the \n

        switch (choice)
        {
        case 1:
            printf("\nEnter your new password:\t");
            takePassword(currentUser->password);
            printf("\nPassword changed successfully!");
            break;
        case 2:
            printf("\nEnter your new email:\t");
            takeInput(currentUser->email);
            printf("\nEmail changed successfully!");
            break;
        case 3:
            printf("\nEnter your new phone number:\t");
            takeInput(currentUser->phone);
            printf("\nPhone number changed successfully!");
            break;
        case 4:
            printf("\nEnter your new User ID:\t");
            takeInput(currentUser->userID);
            printf("\nUser ID changed successfully!");
            break;
        case 5:
            // Write the updated user data back to the file
            fseek(fp, -sizeof(struct user), SEEK_CUR); // Move the file pointer back by the size of struct user
            fwrite(currentUser, sizeof(struct user), 1, fp);
            fclose(fp); // Close the file
            return;
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    } while (1);

    fclose(fp); // Close the file
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
            reports();
            break;
        case 4:
            changeProfile(&usr);
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
    char password2[50];
    time_t t;
    struct tm *local_time;

    userNode = malloc(sizeof(struct user));
    if (userNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        printf("\n\nEnter your full name:\t");
        takeInput(userNode->fullName);
        printf("\nEnter your email:\t");
        takeInput(userNode->email);
        printf("\nEnter phone number:\t");
        takeInput(userNode->phone);
        printf("\nEnter phone ID:\t");
        takeInput(userNode->userID);

        do // Check if username is different
        {
            printf("\nEnter your username:\t");
            takeInput(userNode->username);
            if (isUsernameTaken(userNode->username) == 0)
            {
                break;
            }

            printf("\nUsername is already taken. Please choose another one.");
            Beep(750, 300);
        } while (1);

        printf("\nEnter your password:\t");
        takePassword(userNode->password);
        printf("\nConfirm your password:\t");
        takePassword(password2);

        // Compare two passwords
        if (strcmp(userNode->password, password2))
        {
            printf("\nYour passwords didn't match. Please try again!");
            Beep(750, 300);
        }
    } while (strcmp(userNode->password, password2));

    printf("\nYour password matched");

    fp = fopen("Users.dat", "ab"); // Use "wb" for the first write
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    t = time(NULL);
    local_time = localtime(&t);
    sprintf(userNode->date, "%0d/%0d/%0d", local_time->tm_year+1900, local_time->tm_mon+1, local_time->tm_mday);
    
    fwrite(userNode, sizeof(struct user), 1, fp);
    fclose(fp);

    printf("\n\nUser registration was successful. Press any key to continue...");
    getch();
}

void login()
{
    FILE *fp;
    char username[50], pword[50];
    int userFound;

    do
    {
        userFound = 0; // Reset the flag for each login attempt

        printf("\nEnter your username:\t");
        takeInput(username);
        printf("\nEnter your password:\t");
        takePassword(pword);
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
                system("cls");
                printf("\n\t\t\t\tWelcome %s", userNode->fullName);
                printf("\n\n|Full name:\t%s", userNode->fullName);
                printf("\n|Email:\t%s", userNode->email);
                printf("\n|Username:\t%s", userNode->username);
                printf("\n|Phone number:\t%s", userNode->phone);
                printf("\n|ID:\t%s", userNode->userID);
                userFound = 1;

                mainMenu(*userNode);
                break; // Exit the loop once the user is found
            }

            userNode = userNode->link;
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
