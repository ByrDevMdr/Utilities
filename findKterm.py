def encontrarTermino(A, B, k):
    # Aseguramos que A sea el arreglo más corto
    if len(A) > len(B):
        return encontrarTermino(B, A, k)

    m, n = len(A), len(B)
    
    # Si A está vacío
    if m == 0:
        return B[k - 1]
    
    # Si k = 1, el más pequeño de ambos primeros
    if k == 1:
        return min(A[0], B[0])
    
    # Dividimos k en dos partes
    i = min(m, k // 2)
    j = k - i

    if A[i - 1] < B[j - 1]:
        # Descartamos la parte izquierda de A
        return encontrarTermino(A[i:], B, k - i)
    else:
        # Descartamos la parte izquierda de B
        return encontrarTermino(A, B[j:], k - j)


# Ejemplo de uso:
A = [2, 3, 4, 10, 15]
B = [1, 5, 8, 12, 14, 18]

k = int(input("Ingrese el valor de k para encontrar el k-ésimo elemento: "))
