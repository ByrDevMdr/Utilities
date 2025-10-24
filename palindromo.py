def main():
    s = input ("Ingrese una palabra: ").strip()
    if s == s[::-1]:
        print("Y")
    else:
        print("N")
if __name__ == "__main__":
    main()