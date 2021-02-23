#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Music {    
    int amountFound;
    int *indexes;
}Music_t;

void musicListAll(void);
void musicSearch(const char *musicName);
Music_t musicSearchPart(const char *partName);

const char *musicList[] = 
    {
        "November Rain",
        "Careless Whisper",
        "Billie Jean",
        "I Want to break free",
        "Forever Young",
        "I wanna rock",
        "Another brick in the wall"
    };

const unsigned char musicAmount = sizeof(musicList)/sizeof(musicList[0]);

int main(int argc, char const *argv[])
{
    // char musicName[80];

    // printf("Type your music: ");
    // fgets(musicName, 80, stdin);

    // musicSearch(musicName);

    char musicPart[10];
    printf("Enter the part music's name.: ");
    fgets(musicPart, 10, stdin);

    musicPart[strlen(musicPart) - 1] = 0;

    Music_t music = musicSearchPart(musicPart);
    if(music.amountFound > 0){
        for(int i = 0; i < music.amountFound; i++)
        {
            printf("%s\n", musicList[music.indexes[i]]);
        }
    }

    free(music.indexes);

    return 0;
}


void musicListAll(void)
{
    for(int i = 0; i < musicAmount; i++)
    {
        printf("%s\n", musicList[i]);
    }
}

void musicSearch(const char *musicName)
{
    for(int i = 0; i < musicAmount; i++)
    {
        if(strncmp(musicName, musicList[i], strlen(musicName) - 1) == 0)
        {
            printf("Music found: %s\n", musicName);
            return ;
        }        
    }

    printf("Music not found.\n");
}

Music_t musicSearchPart(const char *partName)
{
    Music_t music;
    memset(&music, 0, sizeof(music));
    int pos = 0;    

    music.indexes = (int *)malloc(sizeof(int) * musicAmount);

    for(int i = 0; i < musicAmount; i++)
    {
        char *ptr = strstr(musicList[i], partName);
        if(ptr != NULL){
            music.indexes[pos++] = i;
            music.amountFound++;            
        }
    }

    return music;
}