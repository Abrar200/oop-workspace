#include "Person.h"

Person* createPersonArray(int n) {
    Person* array = new Person[n];
    for (int i = 0; i < n; ++i) {
        array[i].name = "Jack Ryan";
        array[i].age = 21;
    }
    return array;
}