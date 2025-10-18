def sumaFact(number):
    suma = 0
    for i in range(1,number):
        if number % i == 0: # Si 'i' es un factor propio de 'number' entonces: la suma aumentará.
                suma += i
    return suma
"""" Los Factores Propios de un número son 
    aquellos números que lo dividen exactamente, excluyendo al mismo número.
"""""
# --- Ejecución ---
num = int(input("Ingrese un número para calcular la suma de sus factores propios: "))
resultado = sumaFact(num)
print(f"La suma de los factores propios de {num} es: {resultado}")
# import math
# def sumaFact(number):
#     suma = 0
#     for i in range(1, number):
#         if number % i == 0:
#             suma += i
#     return suma
