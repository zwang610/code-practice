#ifndef StaticArray_h
#define StaticArray_h

template <typename V, int CAP>
class StaticArray{
    private: 
    V value[CAP];
    V dummy;
    
    public:
    StaticArray();
    V& operator[](int);
    V operator[](int) const;
    int capacity() const;
};

template <typename V, int CAP>
V& StaticArray<V, CAP>::operator[](int index){
    if (index < 0 || index > CAP) return dummy;
    return value[index];
}

template <typename V, int CAP>
V StaticArray<V, CAP>::operator[](int index) const {
    if (index < 0 || index > CAP) return 0;
    return value[index];
}

template <typename V, int CAP>
int StaticArray<V, CAP>::capacity() const {return CAP;}

template <typename V, int CAP>
StaticArray<V, CAP>::StaticArray(){
    for (int n; n < CAP; n++)
    value[n] = V();
}

#endif