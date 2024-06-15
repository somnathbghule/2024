#include <iostream>
using namespace std;
#include "s_vector.h"
#include "s_ptr.h"
#include "singletone.h"



int main (int argc, char **argv) {

    cout << "running .. " << argv[0] << endl;
    {
        s_ptr <s_vector> ptr (new s_vector(5));
        ptr->insert(1);
        ptr->insert(2);
        ptr->insert(3);
        ptr->insert(4);
        ptr->insert(5);
        ptr->insert(6);
        ptr->insert(7);
        ptr->print();
    }
    /*{
        s_ptr <singletone> ptr (singletone::instance());
    }*/
    return 0;
}