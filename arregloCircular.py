def MaxsubLineal(nums):
    # Función Kadane para el máximo subarreglo
    def cirArray(arr):
        max_ending = max_so_far = arr[0]
        for x in arr[1:]:
            max_ending = max(x, max_ending + x)
            max_so_far = max(max_so_far, max_ending)
        return max_so_far
    # Función Kadane para el mínimo subarreglo
    def arrayMin(arr):
        minimoEnd = ultimoMinimo = arr[0]
        for x in arr[1:]:
            minimoEnd = min(x, minimoEnd + x)
            ultimoMinimo = min(ultimoMinimo, minimoEnd)
        return ultimoMinimo
    totalSsuma = sum(nums)
    maxNormal = cirArray(nums)
    min_normal = arrayMin(nums)
    # Si todos son negativos
    if maxNormal < 0:
        return maxNormal
    # Máximo circular
    max_circular = totalSsuma - min_normal
    return max(maxNormal, max_circular)
# Ejemplo de uso
arr = [5, -3, 5, 9]
print("Arreglo:", arr)
print("Máxima suma circular:", MaxsubLineal(arr))
