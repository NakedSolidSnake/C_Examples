#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define QUIT 0
#define CREATE 1
#define INSERT 2
#define REMOVE 3
#define CHANGE 4
#define PRINT 5
#define EXCLUDE 6

#define SELLER_CODE_LEN 20
#define SELLER_NAME_LEN 80

#define WORKDIRECTORY   120

#define WORKFILE        50

typedef struct
{
    char sellerCode[SELLER_CODE_LEN];
    char sellerName[SELLER_NAME_LEN];
    double value;
    int month;
} Data;

typedef struct 
{
    char workDirectory[WORKDIRECTORY];
    char workFile[WORKFILE];
}Workspace;

static int menu(void);
static int createFile(void);
static int insertDataInFile(void);
static int removeDataFromFile(void);
static int changeDataFromFile(void);
static int printRegistries(void);
static int excludeFile(void);

static int printFilesDir(void);
static int printData(const char *filename, Data *data);
static int getFileSize(FILE *file);


static Workspace workspace;

int main(int argc, char *argv[])
{
    int option ;
    memset(&workspace, 0, sizeof(Workspace));

    while(1)
    {
        option = menu();

        switch (option)
        {
        case QUIT:
            printf("Quiting...\n");
            exit(EXIT_SUCCESS);
            break;

        case CREATE:
            createFile();
            break;

        case INSERT:
            insertDataInFile();
            break;

        case REMOVE:
            removeDataFromFile();
            break;

        case CHANGE:
            changeDataFromFile();
            break;

        case PRINT:
            printRegistries();
            break;
        
        case EXCLUDE:
            excludeFile();
            break;

        default:
            break;
        }        
    }
    
    return EXIT_SUCCESS;
}

static int menu(void)
{
    int option;
    printf("[1] - Create a data file.\n");
    printf("[2] - Include data in a file.\n");
    printf("[3] - Remove seller from file.\n");
    printf("[4] - Change value's sale from file.\n");
    printf("[5] - Print registries.\n");
    printf("[6] - Exclude file.\n");
    printf("[0] - End program.\n");

    printf("Select an option.: ");
    scanf("%d", &option);
    getchar();
    return option;
}

static int createFile(void)
{
    int ret = -1;
    char yes = 'n';
    char filename[WORKFILE];

    printFilesDir();

    printf("Type a file name to create a file.: ");
    fgets(filename, WORKFILE - 1, stdin);

    filename[strlen(filename) - 1] = 0;

    printf("Is the filename correct?\n%s\nType y for yes or n for no.\n", filename);

    yes = getchar();

    if (yes == 'y')
    {
        FILE *fd = fopen(filename, "w");
        if (fd == NULL)
        {
            fprintf(stderr, "Error to create %s file.\n", filename);
            return -1;
        }

        fclose(fd);

        printf("The file %s was created.\n", filename);

        ret = 0;

        strncpy(workspace.workFile, filename, WORKFILE);
    }

    return ret;
}

static int insertDataInFile(void)
{
    Data data;

    printf("Type the seller's name.:");
    fgets(data.sellerName, SELLER_NAME_LEN - 1, stdin);
    data.sellerName[strlen(data.sellerName) - 1] = 0;

    printf("Type the seller's code.:");
    fgets(data.sellerCode, SELLER_CODE_LEN - 1, stdin);
    data.sellerCode[strlen(data.sellerCode) - 1] = 0;

    printf("Type the value of sale.:");
    scanf("%lf", &data.value);
    getchar();

    printf("Type the month of sale.:");
    scanf("%d", &data.month);
    getchar();
    

    printData(workspace.workFile, &data);

    return 0;
}

static int removeDataFromFile(void)
{
    char *fileContent;
    char *pCharacter;
    int size = 0;
    // FILE *file = fopen(workspace.workFile, "r");
    FILE *file = fopen("test", "r");
    if(file == NULL)
    {
        fprintf(stderr, "File not exist.\n");
        return -1;
    }

    
    fseek(file, SEEK_SET, 0);

    size = getFileSize(file);

    fileContent = (char *)malloc(sizeof(char) * size + 1);
    if(fileContent == NULL)
    {
        fprintf(stderr, "Error to allocate memory.\n");
        fclose(file);
    }

    fread(fileContent, size, 1, file);
    fclose(file);

    pCharacter = fileContent;

    // while(*pCharacter != '\0')
    // {
    //     printf("%c", *pCharacter);
    //     pCharacter++;
    // }

    free(fileContent);

    return 0;
}

static int changeDataFromFile(void)
{
    return 0;
}

static int printRegistries(void)
{
    size_t len = 0;
    ssize_t read;
    char * line = NULL;
    FILE *file = fopen(workspace.workFile, "r");
    if(file == NULL)
    {
        fprintf(stderr, "File not exist.\n");
        return -1;
    }

    
    fseek(file, 0, SEEK_SET);

    while((read = getline(&line, &len, file)) != -1)
    {
        printf("%s", line);
    }

    if (line)
        free(line);
    return EXIT_SUCCESS;
}

static int excludeFile(void)
{

    int ret = -1;
    char yes = 'n';
    char filename[WORKFILE];

    printFilesDir();

    printf("Type a file name to remove a file.: ");
    fgets(filename, WORKFILE - 1, stdin);

    filename[strlen(filename) - 1] = 0;

    printf("Would you like to remove this file?\n%s\nType y for yes or n for no.\n", filename);

    yes = getchar();

    if (yes == 'y')
    {
        remove(filename);
        printf("The file %s was created.\n", filename);

        ret = 0;
    }

    return ret;
}

static int printFilesDir(void)
{
    DIR *folder;
    struct dirent *entry;

    folder = opendir(".");
    if(folder == NULL)
    {
        fprintf(stderr, "Unable to read directory.\n");
        return -1;
    }

    while((entry = readdir(folder)))
    {
        printf("%s\n", entry->d_name);
    }

    closedir(folder);
    return 0;
}

static int printData(const char *filename, Data *data)
{
    FILE *file;
    if(filename == NULL)
        file = stdout;
    else{
        file = fopen(filename, "a");
    }

    fprintf(file, "Seller : %s, ", data->sellerName);
    fprintf(file, "Code : %s, ", data->sellerCode);
    fprintf(file, "Sale : %.2lf, ", data->value);
    fprintf(file, "Month : %d\n", data->month);

    fclose(file);
    return 0;
}

static int getFileSize(FILE *file)
{
    int size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}