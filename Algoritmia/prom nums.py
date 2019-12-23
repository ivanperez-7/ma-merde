print("E para salir\n")
numStr = input("Ingresa un número: ")
contnum = 0
suma = 0
while numStr != "E":
    try:
        float(numStr)
    except ValueError:
        print("Cantidad no válida\n")
    else:
        num = float(numStr)
        suma = suma + num
        contnum = contnum + 1
    numStr = input("Ingresa un número: ")
if contnum == 0:
    print("\nNo se ha ingresado ningún número.")
else:
    prom = suma / contnum
    print("\nEl promedio de los números es de",prom)
input()
