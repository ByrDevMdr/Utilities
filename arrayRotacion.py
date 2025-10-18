def rotarArray(arr, k):
    """
    Rota un array 'k' posiciones a la derecha en O(n) tiempo
    y O(1) espacio usando el método de las tres inversiones.
    """
    n = len(arr)
    if n == 0:
        return # No hay nada que rotar
    # 0. Normalizar k
    # Si k > n, rotar 7 veces es lo mismo que rotar 0.
    # Rotar 8 veces es lo mismo que rotar 1.
    k = k % n
    if k == 0:
        return # No se necesita rotación
    # --- Inicio del Algoritmo ---
    # Paso 1: Invertir el array completo (0 hasta n-1)
    invertir(arr, 0, n - 1)
    # Paso 2: Invertir los primeros 'k' elementos (0 hasta k-1)
    invertir(arr, 0, k - 1)
    # Paso 3: Invertir los 'n-k' elementos restantes (k hasta n-1)
    invertir(arr, k, n - 1)
def invertir(arr, inicio, fin):
    """
    Función auxiliar para invertir una porción del array
    'in-place' (sin crear un array nuevo).
    """
    while inicio < fin:
        # Intercambio de variables
        arr[inicio], arr[fin] = arr[fin], arr[inicio]
        inicio += 1
        fin -= 1
# def recorrerArray(arr1,arr2):
#     """
#     Función para imprimir los elementos del array.
#     """
#     for elemento in arr1:
#         print(elemento, end=' ')
#     print()
#     for elemento in arr2:
#         print(elemento, end=' ')
#     print()
# --- Ejecución del Programa ---
array = [1, 2, 3, 4, 5, 6, 7]
array2 = [10, 20, 30, 40]
print("Seleccione el array que desea rotar:")
print("1. Array 1:", array)
print("2. Array 2:", array2)

opcion = int(input(" Ingrese el numero del array que desea rotar: "))
k = int(input("Ingrese el número de posiciones que desea rotar del arrelgo: "))
if opcion == 1:
    print(f"Array Original: {array}")
    rotarArray(array, k)
    print(f"Array Rotado {k} veces: {array}")
elif opcion == 2:
    print(f"\nArray Original: {array2}")
    rotarArray(array2, k)
    print(f"Array Rotado {k} veces: {array2}")
    
# print(f"Array Original: {array}")
# rotarArray(array, k)
# print(f"Array Rotado {k} veces: {array}")

# k_2 = 1
# print(f"\nArray Original: {array2}")
# rotarArray(array2, k_2)