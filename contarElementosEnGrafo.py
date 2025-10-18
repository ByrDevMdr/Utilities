def contar_componentes_conexas(n, aristas):
    """
    Cuenta el número de componentes conexas en un grafo no dirigido.
    :param n: Número total de nodos (etiquetados de 0 a n-1)
    :param aristas: Una lista de tuplas, ej: [(0, 1), (1, 2), (3, 4)]
    """
    # 1. Construir el grafo (lista de adyacencia)
    grafo = {i: [] for i in range(n)}
    for u, v in aristas:
        grafo[u].append(v)
        grafo[v].append(u) # es no dirigido
    # 2. Registro de nodos visitados
    visitados = set()
    # 3. Contador de componentes (islas)
    contador = 0
    def dfs(nodo):
        """
        Función auxiliar para explorar una 'isla' (componente)
        y marcarla como visitada.
        """
        visitados.add(nodo)
        for vecino in grafo[nodo]:
            if vecino not in visitados:
                dfs(vecino)
    # 4. Bucle principal: recorre todos los nodos
    for nodo in range(n):
        # 5. Si encontramos un nodo de una isla nueva...
        if nodo not in visitados:
            contador += 1  # Incrementamos el contador
            dfs(nodo)      # recorremos toda la isla
    return contador

# --- Ejecución ---
# Nodos: 0, 1, 2, 3, 4, 5
n_nodos = 6
# Aristas:
# (0, 1) y (1, 2) forman un componente.
# (3, 4) forman otro componente.
# (5) está aislado y forma su propio componente.
lista_aristas = [
    (0, 1),
    (1, 2),
    (3, 4)
]
resultado = contar_componentes_conexas(n_nodos, lista_aristas)

print(f"Número de nodos: {n_nodos}")
print(f"Aristas: {lista_aristas}")
print(f"Número de componentes conexas: {resultado}")