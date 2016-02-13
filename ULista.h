//---------------------------------------------------------------------------

#ifndef ListaH
#define ListaH

#include <fstream>
//---------------------------------------------------------------------------
using namespace std;


template <class T> class Lista {

private:
        template <class T>
        struct Nodo {
              T info;
              Nodo<T>* sig;
        };
        int numElem;
        Nodo <T>* primero;
        Nodo <T>* ultimo;

public:
       Lista();
       Lista(T elem);
       ~Lista();
       int getNum();
       T getElem(int i);
       void aniadirElem(T info);
       void quitarElem(int i);
       void cargarLista(ifstream &f);
       void guardarLista(ofstream &f);
       bool vacia(){return numElem==0;};
};


// Implementación de funciones


template <class T> Lista<T>::Lista() {
        numElem=0;
        primero=NULL;
        ultimo=NULL;
}

template <class T> Lista<T>::Lista(T elem){
        Nodo* nodo=new Nodo;
        nodo->info=elem;
        nodo->sig=NULL;
        primero=ultimo=nodo;
        numElem=1;
}

template <class T> Lista<T>::~Lista() {

        Nodo<T>* tmp;

        while (numElem>0) {
             tmp=primero->sig;
             liberaMemoria(primero->info);
             delete primero;
             primero=tmp;
             numElem--;
     }
}


template <class T> int Lista<T>::getNum() {
        return numElem;
}


template <class T> T Lista<T>::getElem(int i) {

        if (numElem<i) return NULL;
        else {
            Nodo<T>* tmp=primero;
            for (int x=1; x<i; x++)
               tmp=tmp->sig;
            return tmp->info;
        }
}


template <class T> void Lista<T>::aniadirElem(T info) {

        Nodo<T>* aux=new Nodo<T>;

        if (primero==NULL) {
          primero=aux;
          primero->info=info;
          primero->sig=NULL;
          ultimo=primero;
        }
        else {
            ultimo->sig=aux;
            aux->info=info;
            aux->sig=NULL;
            ultimo=aux;
        }
        numElem++;
}


template <class T> void Lista<T>::quitarElem(int i) {

         if (numElem<i) return;
         else {
               if (numElem==1){
                    delete primero->info;
                    delete primero;
                    primero=NULL;
                    ultimo=NULL;
               }
               else {
                   Nodo<T>* act=primero;
                   Nodo<T>* ant=NULL;
                   for (int x=1; x<i; x++) {
                        ant=act;
                        act=act->sig;
               }
                   if (act==primero) {
                     primero=act->sig;
                     act->sig=NULL;
                     delete act->info;
                     delete act;
                   }
                   else {
                        if (act==ultimo) ultimo=ant;
                        ant->sig=act->sig;
                        act->sig=NULL;
                        delete act->info;
                        delete act;
                   }
               }
             numElem--;
         }

}

/*
template <class T> void Lista<T>::cargarLista(ifstream &f) {

        int n;
        T dato;

        f.read((char*)&n, sizeof(int));

        for (int i=0; i<n; i++) {
           leer(f,dato);
           aniadirElem(dato);
        }
}


template <class T> void Lista<T>::guardarLista(ofstream &f) {

        f.write((char*)&numElem, sizeof(int));

        Nodo<T>* tmp=primero;
        for (int i=0; i<numElem; i++) {
           guardardato(f,tmp->info);
           tmp=tmp->sig;
        }
} */


#endif

