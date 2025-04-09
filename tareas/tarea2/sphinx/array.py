import random  # Para generar números aleatorios

# Función para imprimir el array
def print_array(arr):
    """
    Imprime los elementos del array.

    Esta función toma un array de números enteros y los imprime en una sola línea, 
    separados por espacios.

    :param arr: Lista de números enteros a imprimir
    :type arr: list[int]
    """
    print(" ".join(map(str, arr)))  # Convierte cada número a string y los une con espacios

# Función de ordenamiento por burbuja (Bubble Sort)
def bubble_sort(arr):
    """
    Ordena el array usando el algoritmo de ordenamiento por burbuja (Bubble Sort).

    Esta función toma un array y lo ordena en orden ascendente utilizando el método
    de ordenamiento por burbuja. El algoritmo compara elementos adyacentes y los 
    intercambia si están en el orden incorrecto.

    :param arr: Lista de números enteros a ordenar
    :type arr: list[int]
    """
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Intercambio de valores

# Función principal
def main():
    """
    Función principal que solicita al usuario el tamaño de un array, 
    genera un array de números aleatorios y lo ordena.

    Esta función coordina el proceso de pedir el tamaño del array, generar los 
    números aleatorios, imprimir el array desordenado, ordenar el array y 
    luego imprimir el array ordenado.
    """
    N = int(input("Ingrese el tamaño del array: "))  # Leer tamaño del array
    arr = [random.randint(0, 99) for _ in range(N)]  # Generar array con números aleatorios

    print("Array desordenado: ", end="")
    print_array(arr)  # Imprimir array desordenado

    bubble_sort(arr)  # Ordenar array con Bubble Sort

    print("Array ordenado: ", end="")
    print_array(arr)  # Imprimir array ordenado

# Ejecutar la función principal
if __name__ == "__main__":
    main()
