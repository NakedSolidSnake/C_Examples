#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char aszXmlData[] = "<body><name>amlendra</name><age>25</age></body>";
    char aszXmlRequest[250] = {0};
    char aszServiceMethod[] = "applicationform.svc/getdetail";
    char aszRequest[150] = {0};
    char aszHostIp[30] = "74.125.28.121";
    char aszPort[] = "80";
    sprintf(aszRequest, "http://%s:%s/%s/%s HTTP/1.1", aszHostIp, aszPort, aszServiceMethod);
    printf("Method and Resource path is below:\n\n\n");
    printf("%s", aszRequest);
    strcat(aszHostIp, ":");
    strcat(aszHostIp, aszPort);
    printf("\n\nHOST header is below:\n\n\n");
    printf("%s", aszHostIp);
    sprintf(aszXmlRequest, "POST %s\r\nHost: %s\r\nContent-Type: application/xml\r\nContent-Length: %d\r\n\r\n%s\r\n", aszRequest, aszHostIp, strlen(aszXmlData), aszXmlData);
    printf("\n\n\nPOST Request which send to the server:\n\n");
    printf("%s", aszXmlRequest);
    return 0;
}