#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;

/**
 * @brief Función para imprimir los elementos de un array.
 * 
 * Esta función recorre el array y imprime cada uno de sus elementos en la consola.
 * 
 * @param arr El array que se va a imprimir.
 * @param size El tamaño del array.
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Función para ordenar un array utilizando el algoritmo de ordenación Bubble Sort.
 * 
 * Este algoritmo compara elementos adyacentes del array y los intercambia si están en el orden incorrecto.
 * El proceso se repite hasta que el array esté completamente ordenado.
 * 
 * @param arr El array que se va a ordenar.
 * @param size El tamaño del array.
 */
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambia los elementos si no están en orden
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Función principal que ejecuta el programa.
 * 
 * En la función principal, se solicita al usuario que ingrese el tamaño de un array, luego se llena con 
 * números aleatorios, se imprime el array desordenado, se ordena usando Bubble Sort y se imprime el array ordenado.
 * 
 * @return int El código de salida del programa.
 */
int main() {
    int N;
    
    // Pedir tamaño del array
    cout << "Ingrese el tamaño del array: ";
    cin >> N;

    int arr[N];  // Definir el array de tamaño N
    
    // Inicializar la semilla del generador de números aleatorios
    srand(time(0));

    // Rellenar el array con números aleatorios
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;  // Números aleatorios entre 0 y 99
    }

    // Imprimir el array desordenado
    cout << "Array desordenado: ";
    printArray(arr, N);

    // Ordenar el array
    bubbleSort(arr, N);

    // Imprimir el array ordenado
    cout << "Array ordenado: ";
    printArray(arr, N);

    return 0;
}

