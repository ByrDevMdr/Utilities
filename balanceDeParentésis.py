
def balanceParent(cadena):
    """
    Verifica si una cadena de paréntesis (), [], {} está balanceada
    usando una Pila.
    """
    # La Pila (usamos una lista de Python)
    pila = []
    # El mapa de correspondencias
    # (Relaciona CIERRE con APERTURA)
    arrayAssocParent = {
        ')': '(',
        ']': '[',
        '}': '{'
    }
    # Recorrer la cadena
    for caracter in cadena:   
        # Si es un paréntesis de APERTURA ('(', '[', '{')
        # (Forma rápida de checar si es un valor en el mapa)
        if caracter in arrayAssocParent.values():
            pila.append(caracter) # Lo metemos a la pila
            # print(f"Pila después de agregar '{caracter}': {pila}")
        # Si es un paréntesis de cierre (')', ']', '}')
        elif caracter in arrayAssocParent.keys():
            
            # Se verifica si hay un cierre sin apertura
            if not pila: # 'not pila' es True si la pila está vacía
                return False # Inválido
                
            # Se saca el último de la pila
            ultimo_abierto = pila.pop()
            
            # Se compara si coinciden
            if ultimo_abierto != arrayAssocParent[caracter]:
                return False # Inválido (no coinciden)
        
        # (Si el caracter no es un paréntesis, simplemente lo ignoramos)

    # 7. Al final, la pila debe estar vacía para ser válida
    return not pila # Retorna True si la pila está vacía, False si no

# --- Ejemplos de Uso ---

s1 = "({[]})"
s2 = "{([]"
s3 = "{"
s4 = "())"
s5 = "un [ejemplo] (valido)"

print(f"'{s1}': {balanceParent(s1)}") # Válido
print(f"'{s2}': {balanceParent(s2)}") # Inválido
print(f"'{s3}': {balanceParent(s3)}") # Inválido
print(f"'{s4}': {balanceParent(s4)}") # Inválido
