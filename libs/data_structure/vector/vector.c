#include "vector.h"
#include <stdint.h>
# include <memory.h>
#include <malloc.h>
# include <stdbool.h>
#include <assert.h>

void RazeBadIndex(const size_t index) {
    fprintf(stderr, "IndexError: a[%d] is not exists");
    exit(1);
}

void RazeBadVector() {
    fprintf(stderr, "vector let");
    exit(1);
}

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
        RazeBadVector();

}

int *atVector(vector *v, size_t index) {
    if (index > v->size)
        RazeBadIndex(index);
    else
        return &v->data[index];

}

int *back(vector *v) {
    return &v->data[v->size - 1];
}

int *front(vector *v) {
    return &v->data[0];
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    assert(v.size == 1);
}

void test_pushBack_fullVector() {
    vector v = (vector) {(int[]) {1}, 1, 5};
    pushBack(&v, 2);
    assert(v.size == 2 && v.capacity == 5);
    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = (vector) {(int[]) {1, 2}, 2, 5};
    size_t index = 1;
    atVector(&v, index);
    deleteVector(&v);

}

void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]) {1, 2}, 2, 5};
    atVector(&v, v.size - 1);
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = (vector) {(int[]) {1}, 1, 5};
    back(&v);
    deleteVector(&v);

}


void test_front_oneElementInVector() {
    vector v = (vector) {(int[]) {1}, 1, 5};
    front(&v);
    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();

}
