def factorial(number):
    # Calcula el factorial de un número dado en caso de que sea 0 o 1, retorna 1
    if number == 0 or number == 1:
        return 1    
    result = 1
    # Calcula el factorial multiplicando todos los enteros desde 2 hasta 'number'
    for i in range(2, number + 1):
        result *= i
    return result
# --- Ejecución ---
number = int(input("Ingrese un número para calcular su factorial: "))
print(f"El factorial de {number} es {factorial(number)}")