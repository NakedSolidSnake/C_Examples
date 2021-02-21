#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"

void log(int tag, const char *msg)
{
  char tag_info[10] = {0};  
  int msg_len = strlen(msg);

  switch(tag)
  {
    case 0:  //INFO
       strncpy(tag_info, "INFO: ", strlen("INFO:"));
       break;

    case 1: //WARNING
       strncpy(tag_info, "WARNING: ", strlen("WARNING:"));
       break;

   case 2: //ERROR
       strncpy(tag_info, "ERROR: ", strlen("ERROR:"));
       break;

   case 3: //FATAL
       strncpy(tag_info, "FATAL: ", strlen("FATAL:"));
       break;

   default:
       return;
  }


  char *msg_complete =(char *) malloc(sizeof(char) * ( msg_len + strlen(tag_info)));
  
  strncpy(msg_complete, tag_info, strlen(tag_info));   
  strncat(msg_complete, msg, msg_len);

  printf("%s\n", msg_complete);

  free(msg_complete);
  return;
}

