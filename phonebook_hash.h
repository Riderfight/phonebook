#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
 #define HASH 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} phonebook_detail;

typedef struct __LAST_NAME_ENTRY{
    char lastName[MAX_LAST_NAME_SIZE];
    int hashtable;
    phonebook_detail *detail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;

typedef struct phonebook_hash{
    entry **list;
} hashTable;

unsigned int hash(char *str);
entry *findName(char lastName[], hashTable *tb);
void append(char lastName[], hashTable *tb);
hashTable *createHashTable(int tablesize);

#endif
