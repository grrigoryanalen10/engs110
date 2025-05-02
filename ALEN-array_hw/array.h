typedef int element_type;
typedef unsigned int size_type;

struct array
{
	element_type* start;
	size_type size;
	size_type capacity;
};

extern struct array* array_create();
extern void array_push_back(struct array* a, element_type e);
extern void array_pop_back(struct array* a);
extern void array_insert(struct array* a, size_type index, element_type e);
extern int array_empty(struct array* a);
extern size_type array_size(struct array* a);
extern size_type array_capacity(struct array* a);
extern void array_print(struct array* a);
