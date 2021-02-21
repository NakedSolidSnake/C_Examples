#ifndef HANDLE_PARTIALS_H_
#define HANDLE_PARTIALS_H_

#include "type.h"

Head *Partials_getHead(const char *path, const char *filename);
Menu *Partials_getMenu(const char *path, const char *filename);
Page *Partials_getPage(const char *path, const char *filename);
Footer *Partials_getFooter(const char *path, const char *filename);

void Partials_freeHead(Head *head);
void Partials_freeMenu(Menu *menu);
void Partials_freePage(Page *page);
void Partials_freeFooter(Footer *footer);

#endif /* HANDLE_PARTIALS_H_ */
