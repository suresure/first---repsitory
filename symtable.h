#ifndef eseses
#define eseses

struct node
{
    char *key;
    void *value;
    struct node *next;
};


typedef struct node* Link_t;

Link_t LinkTable_new(void);


void LinkTable_free(Link_t oLink);


int LinkTable_getLength(const Link_t oLink);


int Link_contains(const Link_t oLink, const char *pcKey);


int Link_put(Link_t oLink, const char *pcKey, const void *pvValue);

void *Link_replace(const Link_t oLink, const char *pcKey, const void *pvValue);


void *Link_get(const Link_t oLink, const char *pcKey);


void *Link_remove(Link_t oLink, const char *pcKey);

void display(const Link_t head);

#endif

