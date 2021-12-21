#ifndef SET_H_
#define SET_H_

extern const void *Set;

void *add (void *_set, const void *_element);
void *find (const void *_set, const void *_element);
void *drop (void *_set, const void *_element);
int contains (const void *_set, const void *_element);

#endif /* SET_H_ */
