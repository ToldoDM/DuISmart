#include "cvector.h"

template<class T>
CVector<T>::CVector(){
    arr = new T[1];
    capacity = 1;
    current = 0;
}

template<class T>
CVector<T>::CVector(const CVector<T>& vec){
    delete[] arr;
    arr = new T[static_cast<unsigned long>(vec.capacity)];
    for (int i = 0; i < capacity; i++) { arr[i] = vec[i]; }
}

template<class T>
CVector<T>::~CVector(){
    delete[] arr;
}

template<class T>
const T& CVector<T>::operator[](int i) const{ return arr[i]; }

template<class T>
T& CVector<T>::operator[](int i) { return arr[i]; }

template<class T>
const T& CVector<T>::operator*() const { return arr[0]; }

template<class T>
T& CVector<T>::operator*() { return arr[0]; }

template<class T>
void CVector<T>::push(const T& data){
    // se il numero di elementi e' uguale a capacity
    // significa che non c'e piu spazio.
    // dobbiamo raddoppiare la capacita'
    if (current == capacity) {
        T* temp = new T[static_cast<unsigned long>(2*capacity)];

        // copio il vecchio array in un nuovo array
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }

        // deleting previous array
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    // inserisco il nuovo elemento
    arr[current] = data;
    current++;
}

template<class T>
void CVector<T>::push(const T& data, int index){
    // se l'index e' uguale a capacity allora
    // la funzione e' la sessa di quella definita sopra
    if (index == capacity) push(data);
    else arr[index] = data;
}

template<class T>
T CVector<T>::get(int index) const{
    // se l'index e' nel range
    if (index < current) return arr[index];
    else return nullptr;
}

template<class T>
void CVector<T>::erase(const T& item){
    bool transpose = false;
    for (int i=0; i<current-1; i++) {
        if(item == arr[i]) transpose = true;
        if(transpose) arr[i] = arr[i+1];
    }
    arr[current] = nullptr;
    delete item;
    current--;
}

template<class T>
int CVector<T>::size() const{ return current;}

//Inizializzato per questioni di errori run-time
template class CVector<const SmartDevice*>;
