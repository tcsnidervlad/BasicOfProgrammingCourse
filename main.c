#include <stdio.h>
#include <stdint.h>
# include <memory.h>
#include <malloc.h>
#include "libs/data_structure/vector/vector.h"

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

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}
int main() {
    test();

    return 0;
}
