#ifndef S_PTR_H
#define S_PTR_H

template <class T>
class s_ptr {

    public:
        s_ptr(T *tptr) {
            ptr = tptr;
        }
        ~s_ptr() {
            delete ptr;
        }
        T* operator->() {
            return ptr;
        }

    private:
    T *ptr;    
};

#endif