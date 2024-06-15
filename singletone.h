#ifndef SINGLETONE_H
#define SINGLETONE_H
#include <iostream>
using namespace std;

class singletone {


    public:
        static singletone *instance () {
            if (obj == nullptr) {
                obj = new singletone();
            }
            cout << "singletone = " << obj << endl; 
            return obj;
        }
        ~singletone() {
            cout << "singletone DTTR " << endl;
        }
    private:
        singletone() {
            //cout << "singletone CTTR " << endl;
        }

        static singletone *obj;
};

singletone* singletone::obj = nullptr;
#endif