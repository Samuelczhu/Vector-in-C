#include <assert.h>
#include <stdlib.h>

#include "vector.h"

void vector_init(vector* v) { //initialize the vector
	v->length = 0;
	v->size = INITIAL_VECTOR_SIZE; //initialize size is 4
	v->items = malloc(v->size * sizeof(double));
}

void vector_resize(vector* v, int size) {
	double* items = realloc(v->items, size * sizeof(double));
	assert(items != NULL); //make sure items is not null
	v->size = size;
	v->items = items;
}

int vector_length(vector* v) {
	return v->length;
}

void vector_push_back(vector* v, double val) {
	if (v->length == v->size) { //make sure the size is greater than the length
		vector_resize(v, v->size * 2);
	}
	v->items[v->length] = val; //append the value
	v->length++;
}

void vector_add(vector* v, int index, double val) {
	assert(index >= 0 && index < v->length); //make sure the index is valid
	if (v->length == v->size) {
		vector_resize(v, v->size * 2); //make sure the size is greater than the length
	}

	for (int i = v->length - 1; i >= index; i--) {
		v->items[i + 1] = v->items[i]; //shift the element to right
	}
	v->items[index] = val;
	v->length++;//increase the length
}

void vector_set(vector* v, int index, double val) {
	assert(index >= 0 && index < v->length); //make sure the index is valid
	v->items[index] = val;
}

void vector_delete(vector* v, int index) {
	assert(index >= 0 && index < v->length); //make sure the index is valid
	for (int i = index; i < v->length-1; i++) {
		v->items[i] = v->items[i + 1]; //shift the item to left
	}
	v->length--; //decrease the length
	if (v->length < v->size / 2) { //resize if neccessary
		vector_resize(v, v->size / 2);
	}
}

double vector_get(vector* v, int index) {
	assert(index >= 0 && index < v->length);//make sure the index is valid
	return v->items[index];
}

void vector_free(vector* v) {
	free(v->items);
}

void vector_print(vector* v) {
	printf("{");
	for (int i = 0; i < v->length; i++) {
		printf("%lf", vector_get(v, i));
		if (i != v->length - 1) { //not the last index
			printf(", ");
		}
	}
	printf("}\n");
}
