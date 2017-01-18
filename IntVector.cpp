#include <cmath>
#include "IntVector.h"
#include <iostream>

using namespace std;

// Constructors

IntVector::IntVector() {

    count = 0;
    capacity = INITIAL_CAPACITY;
    array = new int[INITIAL_CAPACITY];
}

IntVector::IntVector(int size, int value) {

    if(size> INITIAL_CAPACITY)
    {
        capacity = size;
    }
    else
    {
        capacity = INITIAL_CAPACITY;
    }

    array = new int[capacity];
    count = size;

    for(int i = 0; i < size; i++)
    {
        array[i] = value;
    }

}

void IntVector::doubleArray(){

    capacity *= 2;
    int* tmpArray = new int[capacity];

    for(int i = 0; i < count; i++)
    {
        tmpArray[i] = array[i];
    }
    delete[] array;
    array = tmpArray;
}

IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count) {

    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}


IntVector::~IntVector() {

    if(array != NULL)
    {
        delete[] array;
    }
}

// Public member functions
void IntVector::push_back(int elem) {

    if(count == capacity)
    {
        doubleArray();
    }

    array[count] = elem;
    count++;

}

void IntVector::insert(int index, int elem) {

    if(index < 0||index > capacity)
    {
        throw
        IndexOutOfRangeException();
    }
    else
    {
        for(int i = count-1; i >= index; i--)
        {
            array[i+1] = array[i];
        }
        array[index] = elem;
    }
}

int IntVector::at(int index) const {

if(index > count)
{
    throw IndexOutOfRangeException();
}
else
{
    return array[index];
}
}

void IntVector::set_value_at(int index, int elem) {

    array[index] = elem;
}

int IntVector::size() const {

    return count;
}

bool IntVector::empty() const {

    return count == 0;

}

void IntVector::remove_at(int index) {

    if(index < 0 || index > capacity)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        for(int i = index-1; i < count; i++)
        {
            array[i] = array[i+1];
        }
    }
}

int IntVector::pop_back() {

    if(empty()==true)
    {
        throw
        EmptyException();
    }
    else
    {
        return array[--count];

    }
}

void IntVector::clear() {

    count = 0;
}

// Overloaded operators
void IntVector::operator=(const IntVector& vec) {
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index) {

    if(index < 0 || index > capacity)
    {
        throw IndexOutOfRangeException();
    }
    return array[index];
}

ostream& operator<< (ostream& out, const IntVector& rhs) {

    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs.at(i);
    }
    return out;
}
