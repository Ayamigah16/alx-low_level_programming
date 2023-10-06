#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht = malloc(sizeof(shash_table_t));
if (!ht)
return NULL;

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (!ht->array)
{
free(ht);
return NULL;
}

memset(ht->array, 0, sizeof(shash_node_t *) * size);
ht->shead = NULL;
ht->stail = NULL;

return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *new_node, *tmp, *prev;

if (!ht || !key || !value)
return 0;

index = hash_djb2((unsigned char *)key) % ht->size;

new_node = malloc(sizeof(shash_node_t));
if (!new_node)
return 0;

new_node->key = strdup(key);
new_node->value = strdup(value);
new_node->next = NULL;

if (!new_node->key || !new_node->value)
{
free(new_node->key);
free(new_node->value);
free(new_node);
return 0;
}

if (ht->array[index] == NULL)
{
ht->array[index] = new_node;
}
else
{
tmp = ht->array[index];
prev = NULL;

while (tmp && strcmp(tmp->key, key) <= 0)
{
prev = tmp;
tmp = tmp->next;
}

if (!prev)
{
new_node->next = ht->array[index];
ht->array[index] = new_node;
}
else
{
prev->next = new_node;
new_node->next = tmp;
}
}

/* Update sorted linked list */
if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
ht->shead = new_node;

if (ht->stail == NULL || strcmp(key, ht->stail->key) > 0)
ht->stail = new_node;

return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *node;

if (!ht || !key)
return NULL;

index = hash_djb2((unsigned char *)key) % ht->size;

node = ht->array[index];
while (node)
{
if (strcmp(node->key, key) == 0)
return node->value;
node = node->next;
}

return NULL;
}

void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;

if (!ht)
return;

node = ht->shead;
printf("{");
while (node)
{
printf("'%s': '%s'", node->key, node->value);
if (node->snext)
printf(", ");
node = node->snext;
}
printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;

if (!ht)
return;

node = ht->stail;
printf("{");
while (node)
{
printf("'%s': '%s'", node->key, node->value);
if (node->sprev)
printf(", ");
node = node->sprev;
}
printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
unsigned long int i;
shash_node_t *node, *temp;

if (!ht)
return;

for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node)
{
temp = node->next;
free(node->key);
free(node->value);
free(node);
node = temp;
}
}

free(ht->array);
free(ht);
}
