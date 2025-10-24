import math

def dist(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def main():
    x1, y1 = map(float, input("Ingrese dos puntos: ").split())
    x2, y2 = map(float, input("Ingrese dos puntos: ").split())
    print(f"{dist(x1, y1, x2, y2):.4f}")

if __name__ == "__main__":
    main()
# d = sqrt((x2 - x1)^2 + (y2 - y1)^2) -> Raíz cuadrada de la suma de las diferencias al cuadrado.