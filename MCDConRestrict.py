def MCD(a, b):
    """
    Calcula el Máximo Común Divisor (MCD) de a y b
    """
    while b:
        a, b = b, a % b
    return a
# Esta función cuenta cuántos números k en el rango de 1 a n cumplen MCD(k, n) = 1
def countPr(n):
    contador = 0
    # Iteramos k desde 1 hasta n
    for k in range(1, n + 1):
        if MCD(k, n) == 1:
            contador += 1
            
    return contador
# --- Ejecución ---
num = int(input("Ingrese un número n: "))
resultado = countPr(num)

print(f"\nMétodo 1 (Fuerza Bruta):")
print(f"Hay {resultado} números 'k' (entre 1 y {num}) que cumplen MCD(k, {num}) = 1.")