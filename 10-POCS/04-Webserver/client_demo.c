#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

int menu(void);

typedef void (*option)(void);

typedef struct 
{
    int opt;
    option operation;
}Option_t;

void get_method(void);
void post_method(void);
void quit(void);

static Option_t options[] = 
{
    {1, get_method},
    {2, post_method},
    {9, quit}
};


int main(int argc, char const *argv[])
{
    int choosed;
    int execute = 0;
    while(1)
    {
        choosed = menu();

        for(int i = 0; i < sizeof(options)/sizeof(options[0]); i++)
        {
            if(options[i].opt == choosed)
            {
                options[i].operation();
                execute = 1;
                break;
            }
        }

        if(!execute)
        {
            printf("Command does not exist.\n");            
        }

        execute = 0;
    }

    return 0;
}

int menu(void)
{
    int choose = 0;
    char b[3] = {0};    

    printf("\n\n++++++ Test Webserver 1.0 ++++++\n");
    printf("[1] - Receives page from Webserver.\n");
    printf("[2] - Sends data to the server.\n");
    printf("[9] - Quit.\n");

    do
    {    
        printf("\nOption: ");
        fgets(b, sizeof(b), stdin);        
    }while(!isdigit(b[0]));

    choose = atoi(b);
    return choose;
}

void get_method(void)
{
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost");
    curl_easy_setopt(curl, CURLOPT_PORT,3404);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    curl_easy_cleanup(curl);
  }    
}

void post_method(void)
{
  
  CURL *curl;
  CURLcode res;

  struct curl_slist *hs=NULL;  
 
  curl = curl_easy_init();
  
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost");
    curl_easy_setopt(curl, CURLOPT_PORT,3404);

    hs = curl_slist_append(hs, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);

    /* Now specify the POST data */ 
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"name\":\"Cristiano\"}");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen("{\"name\":\"Cristiano\"}"));
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
}

void quit(void)
{
    printf("call quit\n");
    exit(0);
}