#include <iostream>
using namespace std;
class enlaza{
	private:
		int tam;
		int *enlazada;
	public:
		enlaza(int t, int arr[]){
			tam=t;
			enlazada = new int[tam];
			for(int i=0 ; i<tam ; i++){
				enlazada[i]=arr[i];
			}
		}
		void imprimir(){
        for(int i=0;i<tam;i++)
            cout<<enlazada[i]<<" ";
        cout<<"longitud="<<tam;}
		void agregar(int val){
			int *nuevo = new int[tam+1];
			int i=0;
			while(i<=tam){
				if(i==tam){
					nuevo[i]=val;
					break;
				}
				nuevo[i]=enlazada[i];

				i++;
			}
			delete[] enlazada;
			tam++;
			enlazada=new int[tam];
			for(int i=0 ; i<tam ; i++){
				enlazada[i]=nuevo[i];
			}
			delete[] nuevo;

		}
		void eliminar(int pos){
			pos--;
			int *nuevo = new int[tam-1];
			int i=0,j=0;
			while(j<tam){
				if(j!=pos){
					nuevo[i]=enlazada[j];
					i++;
				}
				j++;

			}
			tam--;
			delete[] enlazada;
			enlazada=new int[tam];
			for(int i=0 ; i<tam ; i++){
				enlazada[i]=nuevo[i];
			}
			delete[] nuevo;

		}
		bool buscar(int val){
			bool a=false;
			for(int i = 0 ; i<tam ; i++){
				if (enlazada[i] == val){
					a=true;
					break;
				}
			}
			return a;
		}
		void agregarPosicion(int pos , int val){
			pos--;
			int *nuevo = new int[tam+1];
			for (int i = 0; i < pos; ++i)
			{
				nuevo[i]=enlazada[i];
			}
			nuevo[pos]=val;
			int i=pos+1,j=pos;
			while(i<tam+1 || j<tam){
				nuevo[i]=enlazada[j];
				j++;
				i++;
			}
			tam++;
			delete[] enlazada;
			enlazada=new int[tam];
			for(int i=0 ; i<tam ; i++){
				enlazada[i]=nuevo[i];
			}
			delete[] nuevo;
		}



};

int main(){
    int ar[]={1,2,4,5,6};
    enlaza l(5,ar);
    l.imprimir();/*
    cout<<endl;
    l.agregar(10);
    l.imprimir();
    cout<<endl;
    l.agregar(8);
    l.imprimir();
    cout<<endl;
    l.eliminar(1);
    l.imprimir();

    cout<<endl;
    cout<<l.buscar(3);
    cout<<endl;
    cout<<l.buscar(20);
    cout << endl;
    l.agregarPosicion(1,7);
    l.imprimir();
    cout << endl;
    l.agregarPosicion(3,3);
    l.imprimir();*/
    cout << endl;
    for (int i=0;i<1000000;i++)
        l.agregar(i);
    l.imprimir();

    return 0;

}
