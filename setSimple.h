//
// Created by sony on 02.03.2020.
//


#include <form.h>

using namespace std;
#define SIZE  300000000
template <class T>
class SetSimple{

public:
    T* array = new T[SIZE];
    int countElements = 0;
    SetSimple(){
        for(auto i = 0; i< SIZE ; i++)
        {
            array[i] = false;
        }
    }
    void insert(T x){
        if (countElements >= SIZE){
            cout << "List is FULL " << endl;
            return;
        } else if(array[x] == true){
            cout <<"This element: " << x << " already exist in this set" << endl;
            return;
        }else{
            array[x] = true;
            countElements++;
            return;
        }

    }
    T remove(T x){
        T temporary;
        if(countElements == 0){
            cout<< "Size set is empty" << endl;
            return temporary;
        } else if(array[x] == false){
            cout<< "This element does not exist in this set!" << endl;
            return temporary;
        }
        else{
       //     cout << "Removing: " << x << " from our set..." << endl;
            temporary = array[x];
            array[x]= false;
            countElements--;
            return temporary;
        }
    }
    static SetSimple mergeTwoSets(const SetSimple& a, const SetSimple& b){
        SetSimple<T> c;
        for (int j = 0; j < SIZE; ++j) {
            c.array[j] = a.array[j];
        }
        c.countElements = a.countElements;
        for (int i = 0; i < SIZE; ++i) {
            if (b.array[i] == true && c.array[i] == false){
                c.array[i] = true;
                c.countElements++;
            }
        }
        return c;
    }
    static SetSimple productOfSets(const SetSimple& a, const SetSimple& b){
        SetSimple<T> c;
        for (int j = 0; j < SIZE; ++j) {
            c.array[j] = a.array[j];
        }
        c.countElements = a.countElements;
        for (int i = 0; i < SIZE; ++i) {
            if (c.array[i] == true && b.array[i] == false){
                c.array[i]=false;
                c.countElements--;
            }
        }
        return c;
    }
    static SetSimple differenceOfTwoSets(const SetSimple& a, const SetSimple& b){
        SetSimple<T> c;
        for (int j = 0; j < SIZE; ++j) {
            c.array[j] = a.array[j];
        }
        c.countElements = a.countElements;
        for (int i = 0; i < SIZE ; ++i) {
            if(c.array[i] == true && b.array[i] == true){
                c.array[i] =false;
                c.countElements--;
            }
        }
        return c;
    }
    bool areSetsThesame(const SetSimple& a, const SetSimple& b){
        for (int i = 0; i < SIZE ; ++i) {
            if(a.array[i] != b.array[i]){
                return false;
            }
        }
        return true;
    }
    bool isExist(T x){
        return array[x];
    }
    void clearSet(){
        for (int i = 0; i < SIZE ; ++i) {
            array[i] = false;
        }
    }
    void size(){
        cout<< "Size of set is equal to: " << countElements << endl;
    }
    void printSet(){
        cout<<"Our set looks like this: " << endl;
        for (int i = 0; i < SIZE; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    
};



