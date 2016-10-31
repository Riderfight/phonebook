#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], hashTable *tb)
{
    /* TODO: implement */
    entry *e;
    unsigned int index = hash(lastName);
    for(e = tb->list[index];e != NULL; e = e->pNext){
       if(strcasecmp(lastName,e->lastName) == 0)
         return e;
    }

    return NULL;
}

void append(char lastName[], hashTable *tb)
{
    unsigned int index = hash(lastName);
    entry *e;
    e = (entry*)malloc(sizeof(entry));
    strcpy(e->lastName,lastName);
    e->pNext = tb->list[index];
    tb->list[index] = e;    
}

unsigned int hash(char *str){
    unsigned int seed = 131;
    unsigned int hash_value = 0;
    while (*str){
        hash_value = hash_value * seed + (*str++);
        // hash = hash << 7 + hash << 1 + hash + (*str++);
    } 
    return (hash_value % TABLE_SIZE);
}

hashTable *createHashTable(int tablesize){
    int i;
    hashTable *tb;
    tb = (hashTable*)malloc(sizeof(hashTable));
    tb->list = (entry**)malloc(sizeof(entry*)*TABLE_SIZE);
    for(i=0;i<TABLE_SIZE;i++)
      tb->list[i] = NULL;
    return tb;
}
