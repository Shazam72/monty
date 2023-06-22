#include "monty.h"
/**
 * _calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		*((char *)(ptr) + i) = 0;
	return (ptr);
}
/**
 * _realloc - reallocate memory and copy the content
 * @ptr: ptr to memory to reallocate
 * @old_size: old size
 * @new_size: new size
 * Return: ptr to new reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < old_size; i++)
			new_ptr[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < new_size; i++)
			new_ptr[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (new_ptr);
}
