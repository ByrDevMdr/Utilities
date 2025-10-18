def findNum(limite):   
    # 1. Crear la criba: una lista de booleanos hasta el límite.
    # Asumimos que todos son primos al inicio (True).
    primo = [True] * limite
    primo[0] = primo[1] = False  # 0 y 1 no son primos
    # 2. Aplicar la Criba de Eratóstenes
    for p in range(2, int(limite**0.5) + 1):
        if primo[p]:
            # Si 'p' es primo, marcar todos sus múltiplos como no primos
            for i in range(p * p, limite, p):
                primo[i] = False
    # 3. Recolectar todos los números primos encontrados
    primos = [] # Se inicializa la lista de primos
    for p in range(limite):
        if primo[p]:
            primos.append(p)
    # 4. Encontrar los pares gemelos
    gemelos = [] # Se inicializa la lista de pares gemelos
    # Recorremos la lista de primos y comparamos cada uno con el siguiente
    for i in range(len(primos) - 1):
        if primos[i+1] - primos[i] == 2:
            gemelos.append((primos[i], primos[i+1]))
    return gemelos
limite_superior = 1000
pares_gemelos = findNum(limite_superior)
print(f"--- Pares de primos gemelos menores que {limite_superior} ---")
print(pares_gemelos)
