#ifndef S_VECTOR_H
#define S_VECTOR_H

#include <iostream>
using namespace std;

class s_vector {

    public:
        s_vector(int size = 0);
        ~s_vector();
        void insert(int val);
        void print();
    private:
        int size;
        int *buffer;
        int idx;

};

#endif