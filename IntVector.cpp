#include <cmath>
#include "IntVector.h"
#include <iostream>

using namespace std;

// Constructors

IntVector::IntVector() {
    // TODO: Implement
    count = 0;
    capacity = INITIAL_CAPACITY;
    array = new int[INITIAL_CAPACITY];
}

IntVector::IntVector(int size, int value) {
    // TODO: Implement

   /// capacity *= 2;
    ///int* tmpArray = new int[capacity];

    array = new int[INITIAL_CAPACITY]; ///NÝTT
    capacity = INITIAL_CAPACITY; ///NÝTT
    count = size; ///NÝTT

    for(int i = 0; i < size; i++)///setti inn i < size en það var i < 10
    {
        array[i] = value; /// var svona : tmpArray[i] = array[i];
    }
    ///delete [] array;
    ///array = tmpArray;
}

void IntVector::doubleArray()
{
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
    // TODO: Implement
    if(array != NULL)
    {
        delete[] array;
    }
}

// Public member functions

void IntVector::push_back(int elem) {
    // TODO: Implement

    if(count == capacity)
    {
        doubleArray();
    }

    array[count] = elem;
    count++;

}

void IntVector::insert(int index, int elem) {
    // TODO: Implement

    if(index > capacity)
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
    // TODO: Implement

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
    // TODO: Implement

    array[index] = elem;
}

int IntVector::size() const {
    // TODO: Implement

    return count;
}

bool IntVector::empty() const {
    // TODO: Implement

    int count;
    for(int i = 0; i < capacity; i++)
    {
        if(array[i] == 0)
        {
            count++;
        }
    }
    if(count > 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void IntVector::remove_at(int index) {
    // TODO: Implement

    if(index > capacity)
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
    // TODO: Implement
    if(empty()==true)
    {
        throw
        EmptyException();
    }
    else
    {
        ///TODO: GERA POP_BACK!
    }
    return 0;
}

void IntVector::clear() {
    // TODO: Implement

    for(int i = 0; i < count; i++)
    {
         array[i] = NULL;
    }
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
    // TODO: Throw exception if index is out of range.

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
