#include "vector.h"
#include <stdint.h>
# include <memory.h>
#include <malloc.h>
# include <stdbool.h>
#include <assert.h>

void RemoveValues(int *a, size_t *n, int value) {
    int j = 0;
    for (int i = 0; i < *n; i++) {
        if (a[i] != value) {
            a[j++] = a[i];
        }
    }
    *n = j;
}


vector createVector(size_t n) {
    return (vector) {malloc(sizeof(int) * n),
                     0,
                     n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->capacity = newCapacity;
    } else if (newCapacity < v->size) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int *) realloc(v->data, sizeof(int) * v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}


void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
        v->size++;
        v->data[v->size - 1] = x;
    } else if (v->size == v->capacity) {
        reserve(v, v->capacity * 2);
        v->size++;
        v->data[v->size - 1] = x;
    } else
        v->size++;
        v->data[v->size - 1] = x;
}

void popBack(vector *v) {
    if (v->size > 0)
        RemoveValues(v->data, &v->size, v->data[v->size - 1]);
    else
        printf("%d", 1);
}


