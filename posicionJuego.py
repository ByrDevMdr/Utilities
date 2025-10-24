def main():
    commands = input("Ingrese los comandos: ").strip()
    x = y = 0
    for c in commands:
        if c == 'U': y += 1
        elif c == 'D': y -= 1
        elif c == 'L': x -= 1
        elif c == 'R': x += 1
    print(x, y)

if __name__ == "__main__":
    main()
