#include "s_vector.h"
s_vector::s_vector(int size) {
    //cout << "s_vector CTTR " << endl;
    this->size = size;
    this->idx = 0;
    if (this->size) {
        buffer = new int [this->size];
    }
}
s_vector::~s_vector() {
    //cout << "s_vector DTTR " << endl;
    delete []buffer;
}
void s_vector::print() {
    //cout << "s_vector print " << endl;
    for (int i = 0 ; i < idx; i++) {
        cout << "buffer [" << i << "] = " << buffer[i] << endl; 
    }
}

void s_vector::insert(int val) {
    if(idx >= size) {
        // reallocate buffer
        int *tempBuffer = new int [size * 2];
        for (int i = 0 ; i < size ; i ++) {
            tempBuffer[i] = buffer[i];
        }
        delete buffer;
        buffer = tempBuffer;
        size = size * 2;
        cout << "reallocated" << " size = " << size << endl;
    }
    buffer[idx] = val;
    idx++;
}