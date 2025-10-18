def calcular_termino_secuencia(n_objetivo):
    
    # Definimos el módulo (10^9 + 7)
    M = 1000000007
    
    # 1. Definimos la condición inicial
    # 'a' guardará el valor del término actual
    a = 1  # Este es a_0
    
    # 2. Iteramos 'n' desde 1 hasta el número objetivo
    # (Usamos n_objetivo + 1 para que el rango incluya a n_objetivo)
    for n in range(1, n_objetivo + 1):
        
        # 3. Aplicamos la fórmula de recurrencia
        # a_n = 2 * a_{n-1} + 3 * n^2
        
        # El valor 'a' actual es a_{n-1}
        termino_anterior = (2 * a) % M
        termino_cuadratico = (3 * n * n) % M
        
        # Calculamos el nuevo 'a' (que es a_n)
        a = (termino_anterior + termino_cuadratico) % M
        
    # 4. Al final del bucle, 'a' contiene el valor de a_n_objetivo
    return a

# --- Ejecución del Programa ---

# Pedimos al usuario el número 'n'
try:
    numero = int(input("Ingrese el término 'n' que desea calcular: "))
    
    if numero < 0:
        print("Error: Por favor ingrese un número no negativo (0 o más).")
    else:
        # Calculamos el resultado
        resultado = calcular_termino_secuencia(numero)
        
        # Imprimimos la respuesta
        print(f"\nEl valor de a_{numero} (módulo {10**9 + 7}) es:")
        print(resultado)

except ValueError:
    print("Error: Entrada no válida. Debe ingresar un número entero.")