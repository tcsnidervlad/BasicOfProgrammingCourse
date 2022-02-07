#include <stdio.h>
#include <stdint.h>
# include <memory.h>
#include <malloc.h>


typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;


vector createVector(size_t n) {
    return (vector) {malloc(sizeof(int) * n),
                     0,
                     n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else if (newCapacity < v->size) {
        v->data = malloc(sizeof(int) * newCapacity);
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else {
        v->data = malloc(sizeof(int) * newCapacity);
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int *) realloc(v->data, sizeof(int) * v->size);
}
void deleteVector(vector *v){
    free(v->data);
}


int main() {


    return 0;
}
