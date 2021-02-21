#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "type.h"

void Controller_LoadRoutes(void);
EndpointReply *Controller_execute(const char *service, const char *endpoint, const char *vars);
void Controller_Free(EndpointReply *endpointReply);

#endif /* CONTROLLER_H_ */
