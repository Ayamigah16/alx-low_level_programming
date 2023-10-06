#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created
 sorted hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *new_table = malloc(sizeof(shash_table_t));
if (new_table == NULL)
{
return (NULL);
}
new_table->size = size;
new_table->array = calloc(size, sizeof(shash_node_t *));
if (new_table->array == NULL)
{
free(new_table);
return (NULL);
}
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
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *node;
shash_node_t *new_node;
shash_node_t *tmp;
unsigned long int index;
if (ht == NULL || key == NULL || value == NULL)
{
return (0);
}
index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];
while (node != NULL)
{
if (strcmp(node->key, key) == 0)
{
free(node->value);
node->value = strdup(value);
if (node->value == NULL)
{
return (0);
}
return (1);
}
node = node->next;
}
new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL)
{
return (0);
}
new_node->key = strdup(key);
if (new_node->key == NULL)
{
free(new_node);
return (0);
}
new_node->value = strdup(value);
if (new_node->value == NULL)
{
free(new_node->key);
free(new_node);
return (0);
}
new_node->next = ht->array[index];
ht->array[index] = new_node;
if (ht->shead == NULL)
{
ht->shead = new_node;
ht->stail = new_node;
}
else if (strcmp(ht->shead->key, key) > 0)
{
new_node->snext = ht->shead;
ht->shead->sprev = new_node;
ht->shead = new_node;
}
else
{
tmp = ht->shead;
while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
{
tmp = tmp->snext;
}
new_node->snext = tmp->snext;
if (tmp->snext == NULL)
{
ht->stail = new_node;
}
else
{
tmp->snext->sprev = new_node;
}
tmp->snext = new_node;
new_node->sprev = tmp;
}
return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in a sorted hash table.
 * @ht: The sorted hash table to search.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *node;
if (ht == NULL || key == NULL)
{
return (NULL);
}
index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];
while (node != NULL)
{
if (strcmp(node->key, key) == 0)
{
return (node->value);
}
node = node->next;
}
return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table using the sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
if (ht == NULL)
{
return;
}
printf("{");
node = ht->shead;
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
if (node->snext != NULL)
{
printf(", ");
}
node = node->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
if (ht == NULL)
{
return;
}
printf("{");
node = ht->stail;
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
if (node->sprev != NULL)
{
printf(", ");
}
node = node->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *tmp;
unsigned long int i;
if (ht == NULL)
{
return;
}
for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
tmp = node;
node = node->next;
free(tmp->key);
free(tmp->value);
free(tmp);
}
}
free(ht->array);
free(ht);
}
