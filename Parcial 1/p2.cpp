#include <vector>
#include <iostream>
using namespace std;

void print_vector(vector<int> vec) {
    for (unsigned i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

//El mejor caso posible es donde el arreglo esté ya ordenado de menor
// a mayor. Sin embargo, el algoritmo no tiene forma de saber que ya
// está ordenado, por lo que realizará de igual manera los dos ciclos
// for. De esta manera sigue siendo Tbest(N) = O(N²)

// El peor caso viene siendo cuando el arreglo está en orden descendente
// (completamente desordenado). Nuevamente, el algoritmo hará los dos ciclos
// for que dependen de N. Así, es Tworst(N) = O(N²)

void selection_sort(vector<int> & vec) {
  int size = vec.size();
  int med = size/2;
  for(int i = 0; i <= med; i++){
    int minIndex = i;
    int maxIndex = i;
    for(int j = i+1; j < size - i; j++){
      if(vec[j] <= vec[minIndex]){
        minIndex = j;
      }
      if(vec[j] >= vec[maxIndex]){
        maxIndex = j;
      }
    }
    swap(vec[i], vec[minIndex]);  //Note que el número de comparaciones e intercambios no cambia de double selection sort a
    if(i == maxIndex){            // selection sort, porque selection sort hace 1 swap y 1 comparacion n veces, mientras que double
      maxIndex = minIndex;        // selection sort hace 2 swaps y 2 comparaciones n/2 veces. Por lo que a la larga hacen el mismo numero.
    }
    swap(vec[size-i-1], vec[maxIndex]);
    if(size-i-1 == minIndex){
      minIndex = maxIndex;
    }
  }
}


int main()
{
    vector<int> v1 = {9,6,3,2,6,7,8,5,4};
    print_vector(v1);
    selection_sort(v1);
    print_vector(v1);

    cout << endl;

    vector<int> v2 = {1,2,3,4,5,6,7,8,9};
    print_vector(v2);
    selection_sort(v2);
    print_vector(v2);

    cout << endl;

    vector<int> v3 = {9,8,7,6,5,4,3,2,1};
    print_vector(v3);
    selection_sort(v3);
    print_vector(v3);

    return 0;
}
