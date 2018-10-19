#include "stdafx.h"
#include "vector.h"
#include <stdio.h>

int main() {
	vector v;
	vector_init(&v);
	vector_push_back(&v, 1);
	vector_push_back(&v, 2);
	vector_push_back(&v, 3);
	vector_push_back(&v, 4);
	vector_push_back(&v, 6);
	vector_print(&v);
	vector_add(&v, 0, -10);
	vector_print(&v);
	vector_set(&v, 1, -5);
	vector_print(&v);
	vector_delete(&v, 1);
	vector_print(&v);
	printf("The element on index 3 is: lf", vector_get(&v, 3));
	vector_free(&v);
	return 0;
}