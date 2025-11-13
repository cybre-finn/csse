/*
 * FILE: hash_table.c
 *
 *       Implementation of the hash table functionality.
 *
 */

/*
 * Include the declaration of the hash table data structures
 * and the function prototypes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash_table.h"

#include "memcheck.h"
#include "sys/types.h"



/*** Hash function. ***/

int hash(char *s)
{
  int hash_val;
  hash_val = 0;
  for(; *s != '\0'; s++) { /* interesting way to iterate throguh string. An LLM taught me that */
    hash_val += (u_int8_t)(*s);
  }
  return hash_val % HASH_MOD;
}


/*** Linked list utilities. ***/

/* Create a single node. */
node *create_node(char *key, int value)
{ 
  node *mynode;
  mynode = (node *)malloc(sizeof(node));
  mynode->key = malloc(strlen(key) + 1);
  strcpy(mynode->key, key);
  mynode->value = value;
  mynode->next = NULL;
  return mynode;
}


/* Free all the nodes of a linked list. */
void free_list(node *list)
{
    node *n;     /* a single node of the list */

    while (list != NULL)
    {
        n = list;
        list = list->next;
        free(n->key);
        free(n);
    }
}


/*** Hash table utilities. ***/

/* Create a new hash table. */
hash_table *create_hash_table()
{
  int i;
  hash_table *ht;
  ht = malloc(sizeof(hash_table));
  ht->slot = malloc(sizeof(node *) * NSLOTS);
  /* init to NULL */
  for(i = 0; i < NSLOTS; i++) {
    ht->slot[i] = NULL;
  }

  return ht;
}


/* Free a hash table. */
void free_hash_table(hash_table *ht)
{
  int i;
  for(i = 0; i < NSLOTS; i++) {
    free_list(ht->slot[i]);
  }
  free(ht->slot);
  free(ht);
}


/*
 * Look for a key in the hash table.  Return 0 if not found.
 * If it is found return the associated value.
 */
int get_value(hash_table *ht, char *key)
{
  int index = hash(key);
  node *pos;
  /* Index is defined through hash function, now traverses the linked list at that index */
  for (pos = ht->slot[index]; pos != NULL; pos = pos->next) {
    if (strcmp(pos->key, key) == 0) {
      return pos->value;
    }
  }
  return 0;
}


/*
 * Set the value stored at a key.  If the key is not in the table,
 * create a new node and set the value to 'value'.  Note that this
 * function alters the hash table that was passed to it.
 */
void set_value(hash_table *ht, char *key, int value)
{
  int index;
  node *new_node;
  node *pos;

  index = hash(key);
  /* First check if key already exists, if so update value */
  for (pos = ht->slot[index]; pos != NULL; pos = pos->next) {
    if (strcmp(pos->key, key) == 0) {
      pos->value = value;
      return;
    }
  }
  /* key not found, create new node, insert at front of lnkd list */
  new_node = create_node(key, value);
  new_node->next = ht->slot[index];
  ht->slot[index] = new_node;
}


/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht)
{
  node *pos;
  int i = 0;
    
  for(; i < NSLOTS ; i++) {
    for (pos = ht->slot[i]; pos != NULL; pos = pos->next) {
      printf("%s %d\n", pos->key, pos->value);
    }
    
  }

}

