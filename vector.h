#ifndef VECTOR_H
#define VECTOR_H

#define INITIAL_VECTOR_SIZE 4;

typedef struct {
	double* items;
	int length;
	int size;
} vector;

void vector_init(vector* v);
void vector_resize(vector* v, int size);
int vector_length(vector* v);
void vector_push_back(vector* v, double val);
void vector_add(vector* v, int index, double val);
void vector_set(vector* v, int index, double val);
void vector_delete(vector* v, int index);
double vector_get(vector* v, int index);
void vector_free(vector* v);
void vector_print(vector* v);

#endif