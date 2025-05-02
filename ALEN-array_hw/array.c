#include "array.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct array* array_create()
{
	struct array* a = (struct array*)malloc(sizeof(struct array));
        assert(0 != a);
        memset(a, 0, sizeof(struct array));
	a->size = 0;
	a->capacity = 2;
	a->start = (element_type*)malloc(a->capacity * sizeof(element_type));
	return a;
}

void array_push_back(struct array* a, element_type e)
{
        assert(0 != a);
        
        // Check if there is a need to resize the array
        if (a->size >= a->capacity) {
                // Double the capacity
                a->capacity *= 2;
                a->start = (element_type*)realloc(a->start, a->capacity * sizeof(element_type));
                assert(0 != a->start);
        }
        
        // Add the element to the end
        a->start[a->size] = e;

        // Increase size
        a->size++;
}

void array_pop_back(struct array* a)
{
        assert(0 != a);
        assert(a->size > 0); // Make sure array is not empty
        
        // Decrease the size (no need to actually remove the element)
        a->size--;
}

void array_insert(struct array* a, size_type index, element_type e)
{
        assert(0 != a);
        assert(index <= a->size); // Index must be valid
        
        // Check if we need to resize the array
        if (a->size >= a->capacity) {
                // Double the capacity
                a->capacity *= 2;
                a->start = (element_type*)realloc(a->start, a->capacity * sizeof(element_type));
                assert(0 != a->start);
        }
        
        // Shift elements to make space for the new element
        for (size_type i = a->size; i > index; i--) {
                a->start[i] = a->start[i-1];
        }
        
        // Insert the new element and increase size
        a->start[index] = e;
        a->size++;
}

size_type array_size(struct array* a)
{
	assert(0 != a);
	return a->size;
}

size_type array_capacity(struct array* a)
{
	assert(0 != a);
	return a->capacity;
}

void array_print(struct array* a)
{
	assert(0 != a);
	for (size_type i = 0; i < a->size; ++i) {
		printf("%d ", a->start[i]);
	}
	printf("\nsize = %d", a->size);
	printf("\ncapacity = %d\n\n", a->capacity);
}

int array_empty(struct array* a)
{
	assert(0 != a);
	return a->size == 0;
}
