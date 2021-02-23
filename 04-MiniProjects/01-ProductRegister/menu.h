#ifndef MENU_H_
#define MENU_H_

typedef void (*IMENU)(void);

int MENU_getSelection(const char **options, int items_amount);

void MENU_createRegistry(void);
void MENU_updateRegistry(void);
void MENU_searchRegistry(void);
void MENU_deleteRegistry(void);
void MENU_showAllRegistries(void);
void MENU_saveAllRegistriesInFile(void);
void MENU_exit(void);

#endif /* MENU_H_ */
