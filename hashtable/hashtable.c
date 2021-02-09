/*
    this file implements a type of hash table which stores [name: age] 
    when a overlap is happened, linkedlist is used
*/

#include "hashtable.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct hashtable
{
    List **array;
    int size;
};

int hashFunction(char *key)
{
    if (strlen(key) == 0)
        return -1;

    return *key % HASH_ARRAY_SIZE;
}

HashTable *newHashTable()
{
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->array = calloc(HASH_ARRAY_SIZE, sizeof(hashTable->array[0]));

    for (int i = 0; i < HASH_ARRAY_SIZE; i++)
        hashTable->array[i] = newList();

    hashTable->size = 0;

    return hashTable;
}

int getSize(HashTable *hashTable)
{
    return hashTable->size;
}

void addItem(HashTable *hashTable, char *key, int value)
{
    int index = hashFunction(key);
    addNode(hashTable->array[index], key, value);
    hashTable->size++;
}

int deleteItem(HashTable *hashTabe, char *key)
{
    int index = hashFunction(key);
    int status = deleteNode(hashTabe->array[index], key);
    hashTabe->size--;

    return status;
}

int getValue(HashTable *hashTable, char *key)
{
    int index = hashFunction(key);

    List *list = hashTable->array[index];
    if (isEmpty(list))
        return -1;

    return getListValue(list, key);
}

void printHashTable(HashTable *hashTable)
{
    printf("Hash Table:\n");
    for (int i = 0; i < HASH_ARRAY_SIZE; i++)
    {
        printf("\t");
        printList(hashTable->array[i]);
    }
}

void deleteHashTable(HashTable *hashTable)
{
    for (int i = 0; i < HASH_ARRAY_SIZE; i++)
        deleteList(hashTable->array[i]);

    free(hashTable);
}