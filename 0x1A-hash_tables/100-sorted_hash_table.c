#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * add_node_sorted - Inserts a new node into a sorted linked
 * list in a hash table.
 * @ht: A pointer to the sorted hash table.
 * @new_node: A pointer to the new node to be inserted.
 *
 * Return: 0 if the operation fails (e.g., memory allocation
 * issues), 1 otherwise.
 */
int add_node_sorted(shash_table_t *ht, shash_node_t *new_node);


/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash
 * table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *new_table;
unsigned long int i;

new_table = malloc(sizeof(shash_table_t));
if (!new_table)
return (NULL);

new_table->size = size;
new_table->array = malloc(sizeof(shash_node_t *) * size);
if (!new_table->array)
{
free(new_table);
return (NULL);
}
for (i = 0; i < size; ++i)
new_table->array[i] = NULL;

new_table->shead = NULL;
new_table->stail = NULL;

return (new_table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table to add the element to.
 * @key: The key.
 * @value: The value corresponding to a key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key,
		    const char *value)
{
shash_node_t *new_node, *tmp;
unsigned long int index;

if (!ht || !key || !*key || !value)
return (0);

index = key_index((unsigned char *)key, ht->size);

tmp = ht->array[index];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = strdup(value);
if (!tmp->value)
return (0);
return (1);
}
tmp = tmp->next;
}

new_node = malloc(sizeof(shash_node_t));
if (!new_node)
return (0);

new_node->key = strdup(key);
if (!new_node->key)
{
free(new_node);
return (0);
}

new_node->value = strdup(value);
if (!new_node->value)
{
free(new_node->key);
free(new_node);
return (0);
}

new_node->next = ht->array[index];
ht->array[index] = new_node;

if (add_node_sorted(ht, new_node) == 0)
return (0);

return (1);
}

/**
 * add_node_sorted - Adds a node to the sorted linked list.
 * @ht: The sorted hash table.
 * @new_node: The node to add.
 *
 * Return: 1 if successful, 0 on failure.
 */
int add_node_sorted(shash_table_t *ht, shash_node_t *new_node)
{
shash_node_t *tmp;

if (!ht || !new_node)
return (0);

if (!ht->shead)
{
ht->shead = new_node;
ht->stail = new_node;
new_node->sprev = NULL;
new_node->snext = NULL;
return (1);
}

tmp = ht->shead;
while (tmp)
{
if (strcmp(new_node->key, tmp->key) < 0)
{
new_node->sprev = tmp->sprev;
new_node->snext = tmp;
if (tmp->sprev)
tmp->sprev->snext = new_node;
else
ht->shead = new_node;
tmp->sprev = new_node;
return (1);
}
tmp = tmp->snext;
}

ht->stail->snext = new_node;
new_node->sprev = ht->stail;
new_node->snext = NULL;
ht->stail = new_node;

return (1);
}

/**
 * shash_table_get - Retrieves the value associated
 * with a key in a sorted hash table.
 * @ht: The sorted hash table to search.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or
 * NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *tmp;

if (!ht || !key || !*key)
return (NULL);

index = key_index((unsigned char *)key, ht->size);
tmp = ht->array[index];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
return (tmp->value);
tmp = tmp->next;
}
return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table using
 * the sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *tmp;
int first = 1;

if (!ht)
return;

printf("{");
tmp = ht->shead;
while (tmp)
{
if (!first)
printf(", ");
printf("'%s': '%s'", tmp->key, tmp->value);
first = 0;
tmp = tmp->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse
 * order using the sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *tmp;
int first = 1;

if (!ht)
return;

printf("{");
tmp = ht->stail;
while (tmp)
{
if (!first)
printf(", ");
printf("'%s': '%s'", tmp->key, tmp->value);
first = 0;
tmp = tmp->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *next;
unsigned long int i;

if (!ht)
return;

for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node)
{
next = node->next;
free(node->key);
free(node->value);
free(node);
node = next;
}
}

free(ht->array);
free(ht);
}
