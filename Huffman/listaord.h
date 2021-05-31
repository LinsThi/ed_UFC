#include <iostream>

using namespace std;

template <typename T>
struct nodo  {
    T key;
    nodo<T>* next;

    nodo(){

    }

    nodo(T x) { 
        key = x;
        next = 0; 
    } 
    nodo& operator++() {
        next = next->next;
        return this;
    }
 };

template <typename T>
class listaord {
protected:
   nodo<T>* ptRaiz;
public:
   listaord() {
      ptRaiz = 0;
    }
    listaord<T>& operator<< (T x) {
        nodo<T>* p = new nodo<T>(x);
        if (ptRaiz==0) {
            ptRaiz = p;
            return *this;
         }
         
         if (x <= ptRaiz->key) {
            p->next = ptRaiz;
            ptRaiz = p;
            return *this;
         }

         nodo<T>* a = ptRaiz;

         while (a->next!=0 && 
                x > a->next->key)    
             a = a->next;
         p->next = a->next;          
         a->next = p;

         return *this;
    } 
    nodo<T>* printRaiz() {
        return ptRaiz;
    }
    bool del(T x) {
        if (ptRaiz==0)
            return false;
        else if (ptRaiz->key==x) {
            nodo<T>* p = ptRaiz;
            ptRaiz = ptRaiz->next;
            delete p;
        } else {
            nodo<T>* a = ptRaiz;
            while (a->next != 0 && a->key!=x)
               a = a->next;
            if (a->next == 0)
                return false;
            else {
                 nodo<T>* p = a->next;
                 a->next = p->next;
                 delete p;
                 return true;
            }    
        }
        return false;
    } 
    ~listaord() {
        while (ptRaiz!=0) {
           nodo<T>* q = ptRaiz;
           ptRaiz = ptRaiz->next;
           delete q;   
        }     
    }
};