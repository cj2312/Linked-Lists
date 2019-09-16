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
		int getTam(){
			return tam;
		}
		void imprimir(){
        for(int i=0;i<tam;i++)
            cout<<enlazada[i]<<" ";
        cout<<"longitud="<<tam;
        cout << endl;}
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

		void Insertsortt(){
             for(int i=1;i<tam;++i){
                int j=i-1;
                int key=enlazada[i];
                while(j>=0 && enlazada[j]>key){
                    enlazada[j+1]=enlazada[j];
                    --j;
                }
                enlazada[j+1]=key;
             }

		}
		void bubbleSort(){
            int i,j,temp;
            for(i=0;i<tam-1;i++){
                for (j=tam-1;j>=i+1;j--){
                    if(enlazada[j]<enlazada[j-1]){
                        temp=enlazada[j];
                        enlazada[j]=enlazada[j-1];
                        enlazada[j-1]=temp;
                    }
                }
            }
        }
        void merge(int arr[], int l, int m, int r)
		{
		    int i, j, k;
		    int n1 = m - l + 1;
		    int n2 =  r - m;

		    /* creamos arrays temporales */
		    int L[n1], R[n2];

		    /* copiamos los datos a los arreglos temporales L y R */
		    for (i = 0; i < n1; i++)
		        L[i] = arr[l + i];
		    for (j = 0; j < n2; j++)
		        R[j] = arr[m + 1+ j];

		    /* combina los arreglos temporales de nuevo en arr[l..r]*/
		    i = 0; // incdice inicial del primer subarreglo
		    j = 0; // indice inicial del segundo subarreglo
		    k = l; // indice inicial del subarreglo combinado
		    while (i < n1 && j < n2)
		    {
		        if (L[i] <= R[j])
		        {
		            arr[k] = L[i];
		            i++;
		        }
		        else
		        {
		            arr[k] = R[j];
		            j++;
		        }
		        k++;
		    }

		    /* copia los elementos restantes de L[] si hay alguno */
		    while (i < n1)
		    {
		        arr[k] = L[i];
		        i++;
		        k++;
		    }

		    /*Copia los elementos restantes de R[] si hay alguno*/
		    while (j < n2)
		    {
		        arr[k] = R[j];
		        j++;
		        k++;
		    }
		}

/*
l es para el índice izquierdo y r es el índice derecho del subarreglo de arr que se ordenará */
		void mergeSort(int l, int r)
		{
		    if (l < r)
		    {
		        // Igual que (l + r) / 2, pero evita el desbordamiento de
		        // grandes l y h
		        int m = l+(r-l)/2;

		        // ordenar primera y segunda mitad
		        mergeSort(l, m);
		        mergeSort(m+1, r);

		        merge(enlazada, l, m, r);
		    }
		}

		void swap(int* a, int* b)
		{
		    int t = *a;
		    *a = *b;
		    *b = t;
		}

		/*
		Esta función toma el último elemento como pivote,
		 coloca el elemento de pivote en su posición correcta
		 en la matriz ordenada y coloca todos los más pequeños
		 (más pequeños que el pivote) a la izquierda del pivote y
		  todos los elementos mayores a la derecha del pivote */
		int partition (int arr[], int low, int high)
		{
		    int pivot = arr[high];    // pivote
		    int i = (low - 1);  // Indice del elemento mas pequeño

		    for (int j = low; j <= high- 1; j++)
		    {
		        // si el eelemento actual es menor o
		        // igua al pivote
		        if (arr[j] <= pivot)
		        {
		            i++;    // índice de incremento del elemento más pequeño
		            swap(&arr[i], &arr[j]);
		        }
		    }
		    swap(&arr[i + 1], &arr[high]);
		    return (i + 1);
		}

		/*
		 arr[] --> Array a ordenar,
		  low  --> Indice de inicio,
		  high  --> indice final */
		void quickSort(int low, int high)
		{
		    if (low < high)
		    {
		        /* p está dividiendo el índice, arr [p] ahora está en el lugar correcto */
		        int p = partition(enlazada, low, high);

		        // Ordenar por separado los elementos antes
		        // particion y despues particion
		        quickSort(low, p - 1);
		        quickSort(p + 1, high);
		    }
		}
		int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


// Una función para hacer el conteo de arr [] de acuerdo con
// el dígito representado por exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // arreglo de salida
    int i, count[10] = {0};

    // almacenar la cuenta de ocureencias en count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;


// Cambiar count [i] para que count[i] ahora contenga la real
    // posición de este dígito en la salida []
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // constrir el arreglo de salida
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }


// Copie el arreglo de salida a arr [], para que arr [] ahora
    // contenga números ordenados según el dígito actual
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


// La función principal para eso ordena arr [] de tamaño n usando
// Radix Sort
void radixsort(int n)
{

// Encuentra el número máximo para saber el número de dígitos

    int m = getMax(enlazada, n);

   // Contar ordenando para cada dígito. Tenga en cuenta que en su lugar
    // de pasar el número de dígitos, se pasa la exp. exp es 10 ^ i
    // donde i es el número de dígito actual
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(enlazada, n, exp);
}


		int posicion(int val){
            int pos=0,i=0;
            while(enlazada[i]<val){
                ++pos;
                ++i;
            }
            return pos;

            //agregarPosicion(pos+1,val);

		}
		int buscar(int val){

			for(int i = 0 ; i<tam ; i++){
				if (enlazada[i] == val){
					return i;
					break;
				}
			}
			return -1;
		}
		int binarySearch( int l, int r, int x)
        {
            while (l <= r) {
                int m = l + (r - l) / 2;

                // Check if x is present at mid
                if (enlazada[m] == x)
                    return m;

                // If x greater, ignore left half
                if (enlazada[m] < x)
                    l = m + 1;

                // If x is smaller, ignore right half
                else
                    r = m - 1;
            }

            // if we reach here, then element was
            // not present
            return -1;
        }

};

int main(){
    int ar[]={1,2,4,5,6};
    enlaza l(5,ar);
    l.imprimir();
    l.agregar(10);
    l.imprimir();
    l.agregar(8);
    l.imprimir();
    l.eliminar(1);
    l.imprimir();

    cout<<l.binarySearch(0,l.getTam(),6);
    cout<<endl;
    cout<<l.buscar(10);
    cout << endl;
    l.agregarPosicion(1,7);
    l.imprimir();
    l.agregarPosicion(3,3);
    l.imprimir();
    /*/for (int i=0;i<=100000;i++){
    	l.agregar(i);
    }*/
    l.radixsort(l.getTam());
    //l.quickSort(0,l.getTam());
    //l.Insertsortt();
    //l.mergeSort(0,l.getTam()-1);
    l.imprimir();



    //l.Insertsortt();
    //l.bubbleSort();
    /*l.imprimir();
    l.posicion(3);
    l.imprimir();
    enlaza m(4,ar);
    m.imprimir();
    cout<<m.posicion(6);
*/


    return 0;

}
