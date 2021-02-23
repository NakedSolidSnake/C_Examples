#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <submenu.h>


#define MAX_INPUT   3

typedef int (*call_t)(void);

typedef struct 
{
    int idx;
    call_t call;
}table_t;

static table_t table[] = {
    {.idx = 1, .call = insert_student},
    {.idx = 2, .call = update_student},
    {.idx = 3, .call = delete_student},
    {.idx = 4, .call = list_students},
    {.idx = 0, .call = quit_application},
};

static int table_size = sizeof(table) / sizeof(table[0]) ;

int menu(void);
int check_isDigit(char *str, int size);
int check_options(int *options, int size, int selected);
int clear_stdin(char *b, int size);


int main(int argc, char const *argv[])
{
    printf("\nchoosed option %d\n", menu());
    return 0;
}

int menu(void)
{
    int choose;
    char b[MAX_INPUT] = {0};

    const int options[] = {1,2,3,4,0};
    int opt_items = sizeof(options)/sizeof(options[0]);


    while(1)
    {  
        printf("\n\n[1] - Insert a new student.\n");
        printf("[2] - Update student register.\n");
        printf("[3] - Delete a student.\n");
        printf("[4] - List all students.\n");
        printf("[0] - Quit application.\n");  
        printf("\nOption: ");
        fgets(b, sizeof(b), stdin);

        if(check_isDigit(b, sizeof(b)) == 0){
            choose = atoi(b);
            if(check_options((int *)options, opt_items, choose) == 0)
            {
                for(int i = 0; i < table_size; i++){
                    if(choose == table[i].idx)
                    {
                        table[i].call();
                        break;
                    }
                }
                continue;
            }
        }
        
        printf("Invalid option.\n");
        clear_stdin(b, MAX_INPUT); 
        memset(b, 0, sizeof(0));
    }
    
    return choose;

}

int check_isDigit(char *str, int size)
{
    int i;
    int flag = 0;
    if(str == NULL)
        return -1;

    for(i = 0; i < size ; i++){
        if(iscntrl(str[i]))
            break;
        if(isdigit(str[i]) == 0){
            flag = 1;
        }
    }

    return flag;
}

int check_options(int *options, int size, int selected)
{
    if(options == NULL)
        return -1;
    
    for(int i = 0; i < size; i++){
        if(options[i] == selected)
            return 0;
    }

    return 1;
}

int clear_stdin(char *b, int size)
{
    if(!b)
        return -1;

    for(int i = 0; i < MAX_INPUT; i++)
    {
        if(b[i] == '\n')
            return 0;
    }

    while(getchar() != '\n');
    return 1;
}