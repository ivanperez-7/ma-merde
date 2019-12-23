print("Mostrar múltiplos\nE para salir\n")
numStr = "E"
numStr = input("Ingresa un número: ")
while numStr != "E":
    try:
        int(numStr)
    except ValueError:
        print("Acaso eres idiota >:v\n")
    else:
        num = int(numStr)
        if num <= 1:
            print("Nel\n")
        else:
            YN = input("¿Mostrar sólo primos? (Y/N) ")
            if YN == "Y" or YN == "y":
                print("\nDivisible entre:")
                for cont in range(2,num+1):
                    res = num % cont
                    if res == 0:
                        res2 = 1
                        for cont2 in range(2,cont):
                            res2 = cont % cont2
                            if res2 == 0:
                                break
                        if res2 != 0:
                            print(cont)
                print("")
            elif YN == "N" or YN == "n":
                print("\nEl número tiene los divisores:")
                for cont in range(1,num+1):
                    res = num % cont
                    if res == 0:
                        print(cont)
                print("")
            else:
                print("")
    numStr = input("Ingresa un número: ")
