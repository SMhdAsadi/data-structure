#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"

#define HASH_ARRAY_SIZE 5

struct hashtable;
typedef struct hashtable HashTable;

// creates and returns a new empty hash table
HashTable *newHashTable();

// adds a new node to hash table
void addItem(HashTable *hashTable, char *key, int value);

// returns size of the hash table
int getSize(HashTable *hashTable);

/*
    deletes item with this key
    returns -1 if hash table is empty or key not found
*/
int deleteItem(HashTable *hashTabe, char *key);

/*
    finds and returns value of specified key
    returns -1 if hash table is empty or key not found
*/
int getValue(HashTable *hashTable, char *key);

// prints hash table on the stdout
void printHashTable(HashTable *hashTable);

// deletes entire hash table and frees memory
void deleteHashTable(HashTable *hashTable);

#endif