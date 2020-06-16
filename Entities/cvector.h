#ifndef CVECTOR_H
#define CVECTOR_H

#include "smartdevice.h"

template <class T>
class CVector {

private:
    /**
     * @brief arr: E' l'array di tipo T che contiene l'indirizzo del vettore
     */
    T* arr;

    /**
     * @brief capacity: Storage totale del vector
     */
    int capacity;

    /**
     * @brief current: Numero corrente di elementi presenti nel vettore
     */
    int current;

public:

    /**
     * @brief CVector: Costruttore di default
     */
    CVector();

    /**
     * @brief CVector: Costruttore di copia
     * @param vec: vettore da copiare
     */
    CVector(const CVector<T>& vec);

    ~CVector();

    const T& operator[](int i) const;

    T& operator[](int i);

    const T& operator*() const;

    T& operator*();

    /**
     * @brief push: Funzione per aggiungere un elemento in coda al vettore
     * @param data: Dato da inserire
     */
    void push(const T& data);

    /**
     * @brief push: Funzione per aggiungere un elemento ad una qualsiasi posizione
     * @param data: Dato da inserire
     * @param index: Indice in cui inserire il dato
     */
    void push(const T& data, int index);

    /**
     * @brief get: Estrae l'elemento ad un dato indice
     * @param index: indice di cui si vuole l'elemento
     * @return
     */
    T get(int index) const;

    /**
     * @brief erase: Funzione per eliminare uno specifico elemento. Viene tolto dal vettore e viene chiamato il distruttore dell'elemento
     * @param item: Elemento da eliminare
     */
    void erase(const T& item);

    /**
     * @brief size: Funzione per avere la dimenzione del vettore
     * @return
     */
    int size() const;
};

#endif // CVECTOR_H
