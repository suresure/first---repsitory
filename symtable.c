#include<stdio.h>
#include<stdlib.h>
#include "symtable.h"

Link_t LinkTable_new(void)                               //创造一个新的链表
{
    Link_t head = NULL;
    Link_t tail = NULL;
    Link_t newNode = NULL;
    char *key = NULL;
    char *value = NULL;

    head = (Link_t)malloc(sizeof(struct node));
    if(head == NULL)
    {
	printf("分配内存错误!\n");
        return NULL;
    }
    key = "100";
    value = "abc100";
    head->key = key;
    head->value = value;
    head->next = NULL;
    tail = head;

    Link_put(head, "101", "abc101"); 
    Link_put(head, "102", "abc102");
    Link_put(head, "103", "abc103");
    Link_put(head, "104", "abc104");
    Link_put(head, "105", "abc105");

    return head;
}


void LinkTable_free(Link_t oLink)                      //释放结点
{
    if(oLink == NULL)
    {
        return;
    }
    Link_t p = NULL;
    Link_t q = NULL;
    p = oLink;
    while(p != NULL)
    {
	q = p;
	p = q->next;
        //free(q->key);
        //free(q->value);
 	free(q);
        q = NULL;
    }
}


int LinkTable_getLength(const Link_t oLink)               //返回链表中的结点个数
{
    if(oLink == NULL)
    {
        printf("Empty Linktable!\n");
        return 0;
    }

    int count = 0;
    Link_t p = NULL;
    for(p = oLink; p != NULL; p = p->next)
    {
    	count = count + 1;
    }
    return count;
}


int Link_contains(const Link_t oLink, const char *pcKey)         //查找pckey
{
    if(oLink == NULL)                                             //找不到则返回0
    {
        printf("Empty Linktable!\n");
        return 0;
    }
    if(pcKey == NULL)
    {
        return 0;
    }

    Link_t p = NULL;
    
    if(strcmp(pcKey, oLink->key) == 0)                               //找到则返回1
    {
        return 1;
    }
    for(p = oLink->next; p != NULL; p = p->next)
    {
        if(strcmp(pcKey,p->key) == 0)
        {
            return 1;
        }
    }
    return 0;
}


int Link_put(Link_t oLink, const char *pcKey, const void *pvValue)         //查找pcKey,若不存在则创建节点将pcKey和pvValue插入，否则返回NULL
{ 
    if(oLink == NULL)
    {
        printf("Empty Linktable!\n");
        return 0;
    }
    if(pcKey == NULL || pvValue == NULL)
    {
        return 0;
    }
    Link_t pv = NULL;
    Link_t pTail = NULL;
    for(pv = oLink; pv != NULL; pv = pv->next)
    {  
        //printf("The  value is:===%s\n", pv->value);
        pTail = pv;
        /*if(strcmp(pvValue,pv->value) == 0)
        {
            printf("The value is existed!\n");
            return 0;
        }*/
    }
    if(Link_contains(oLink, pcKey) == 0)
    {
        //printf("The pcKey is:===%s\n", pcKey);
        Link_t newNode = (Link_t)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Alloc memory failed!\n");
            return 0;
        }
        newNode->key = (char*)pcKey;
        newNode->value = (char*)pvValue;
        newNode->next = NULL;
        //printf("pv->key:%s\n", pTail->key);
        pTail->next = newNode;
        return 1;
    }
    return 0;
}


void *Link_replace(const Link_t oLink, const char *pcKey, const void *pvValue)          //查找pcKey,存在则用pvValue替换对应的值，否则返回NULL
{
    if(oLink == NULL)
    {
        printf("Empty Linktable!\n");
        return;
    }
    if(pcKey == NULL || pvValue == NULL)
    {
        return;
    }

    Link_t p = NULL;
    Link_t pRes = NULL;
    for(p = oLink; p != NULL; p = p->next)
    {
        if(strcmp(pcKey, p->key) == 0)
        {
            pRes = p;
            p->value = (char*)pvValue;
            return;
        }
    }
    return pRes;
}

void *Link_get(const Link_t oLink, const char *pcKey)                            //查找pcKey，找到则返回对应值，否则返回NULL
{
    if(oLink == NULL)
    {
        printf("Empty Linktable!\n");
        return NULL;
    }
    if(pcKey == NULL)
    {
        return NULL;
    }

    Link_t p = NULL;
    for(p = oLink; p != NULL; p = p->next)
    {
        if(strcmp(p->key,pcKey) == 0)
        {
            return p->value;
        }
    }
    return NULL;
}


void *Link_remove(Link_t oLink, const char *pcKey)                                     //查找pcKey,找到则删除pcKey及其对应的值，否则返回NULL
{
    if(oLink == NULL)
    {
        printf("Empty Linktable!\n");
        return NULL;
    }
    if(pcKey == NULL)
    {
        return NULL;
    }

    Link_t pre = oLink;
    Link_t p = oLink->next;

    if(strcmp(pre->key,pcKey) == 0)
    {
        oLink = p;
        if(oLink != NULL)
        {
            display(oLink);
        }
        return pre;
    }

    while(p != NULL)
    {
        if(strcmp(p->key, pcKey) == 0)
        {
            pre->next = p->next;
            if(oLink != NULL)
            {
                display(oLink);
            }
            return p;
        }
        pre = p;
        p = p->next;
    }
    return NULL;
}

void display(const Link_t head)
{
    Link_t p = NULL;
    printf("      KEY        VALUE\n");
    for(p = head; p != NULL; p = p->next){
    	printf("      %s        %s\n", p->key, (char*)p->value);
    }
}

