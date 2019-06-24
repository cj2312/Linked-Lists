#include<iostream>
#include "Punto.hh"
using namespace std;
template <class T>

class ListaEnlazadaSimple{
    class Nodo;
public:
    ListaEnlazadaSimple(){
        primero=ultimo=NULL;
    }
   
    bool vacio(){
        return (primero==NULL);
    }
    void insertarAlInicio(T elemento)
    {
        Nodo *temp=new Nodo(elemento);
        if (vacio()){
            primero=ultimo=temp;
        }
        else{
            temp->sig=primero;
            primero=temp;
        }
    }
    void insertarAlFinal(T elemento)
    {
        Nodo *temp=new Nodo(elemento);
        if (vacio()){
            primero=ultimo=temp;
        }
        else{
            ultimo->sig=temp;
            ultimo=temp;
        }
    }
    void ordenarLista()
    {
         Nodo *actual , *siguiente;
         T temp;

         actual = primero;
         while(actual->sig != NULL)
         {
              siguiente = actual->sig;

              while(siguiente!=NULL)
              {
                   if(actual->elemento > siguiente->elemento)
                   {
                        temp = siguiente->elemento;
                        siguiente->elemento = actual->elemento;
                        actual->elemento = temp;
                   }
                   siguiente = siguiente->sig;
              }
              actual = actual->sig;
              siguiente = actual->sig;

         }

         cout<<"\n\n\tLista ordenada..."<<endl;
    }

    void borrarPrimerNodo()
    {
        if (vacio()){
            cout<<"Lista vacia!\n";
        }
        else{
            if (primero==ultimo){
                primero=ultimo=NULL;
                cout<<"elemento eliminado!\n";
            }
            else{
                Nodo *temp=primero;
                primero=primero->sig;
                delete temp;
                cout<<"elemento eliminado!\n";
            }
        }
    }
    void borrarUltimoNodo()
    {
        if (vacio()){
            cout<<"Lista vacia!\n";
        }
        else{
            if (primero==ultimo){
                primero=ultimo=NULL;
                cout<<"elemento eliminado\n";
            }
            else{
                Nodo *aux=primero;
                while(aux!=NULL){
                    if(aux->sig==ultimo){
                        Nodo *temp=ultimo;
                        ultimo=aux;
                        ultimo->sig=NULL;
                        delete temp;
                        cout<<"elemento eliminado\n";
                    }
                    aux=aux->sig;
                }
            }

        }
    }
    void mostrarLista(){
        if(vacio()){
            cout<<"No hay elementos en la lista\n";
        }
        else{
            Nodo *aux=primero;
            int i=0;
            cout<<"Los datos de la lista son los siguientes:\n";
            while(aux!=NULL){
                cout<<" "<<aux->elemento;
                aux=aux->sig;
                i++;
            }
            cout<<endl;
        }
    }
    private:
        class Nodo{
            T elemento;
            Nodo *sig;
            friend class ListaEnlazadaSimple;
        public:
            Nodo(T elemento){
                this->elemento=elemento;
                sig=NULL;
             }
        };
        Nodo *primero;
        Nodo *ultimo;
};


int main(){
    int a[6]={1,7,4,3,6,5};
    Punto<int> p[5]={Punto<int>(2,1),Punto<int>(4,1),Punto<int>(5,-1),Punto<int>(6,2),Punto<int>(-1,2)};
    ListaEnlazadaSimple<Punto<int> > lp;
    for(int i=0;i<5;i++){
        lp.insertarAlFinal(p[i]);
    }
    lp.mostrarLista();
    lp.ordenarLista();
    lp.mostrarLista();
   
    ListaEnlazadaSimple<int> le;
    for(int i=0;i<6;i++){
        le.insertarAlFinal(a[i]);
    }
    le.mostrarLista();
    le.ordenarLista();
    le.mostrarLista();
    le.borrarPrimerNodo();
    le.borrarUltimoNodo();
   
}
