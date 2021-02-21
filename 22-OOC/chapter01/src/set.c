#include <set.h>
#include <assert.h>
#include <new.h>

#if ! defined MANY || MANY < 1
#define MANY        10
#endif 

static int heap[MANY];

void *new(const void *type, ...)
{
    int *p;
    for(p = heap + 1; p < heap + MANY; ++p)
        if(!*p)
            break;
    
    assert(p < heap + MANY);
    *p = MANY;
    return p;
}

void delete(void *_item)
{
    int *item = _item;

    if(item)
    {
        assert(item > heap && item < heap + MANY);
        *item = 0;
    }
}

void *add(void *set, const void *element)
{
    int *_set = set;
    const int *_element = element;

    assert(_set > heap && _set < heap + MANY);
    assert(*_set == MANY);
    assert(_element > heap && _element < heap + MANY);

    if(*_element == MANY)
        *(int *)_element = _set - heap;
    else
        assert(*_element == _set - heap);
    return (void *)_element;
}

void *find(const void *_set, const void *_element)
{
    const int *set = _set;
    const int *element = _element;

    assert(set > heap && set < heap + MANY);
    assert(*set == MANY);
    assert(element > heap && element < heap + MANY);
    assert(*element);

    return *element == set - heap ? (void *)element : 0;

}

void *drop(void *_set, const void *_element)
{
    int *element = find(_set, _element);
    if(element)
        *element = MANY;
    return element;
}

int contains(const void *_set, const void *_element)
{
    return find(_set, _element) != 0;
}

int differ (const void *a, const void *b)
{

}