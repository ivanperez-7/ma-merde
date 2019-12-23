LLUVIAS = [[0 for e in range(6)] for m in range (12)]
MES = [0 for m in range(12)]
MES[0] = "enero"
MES[1] = "febrero"
MES[2] = "marzo"
MES[3] = "abril"
MES[4] = "mayo"
MES[5] = "junio"
MES[6] = "julio"
MES[7] = "agosto"
MES[8] = "septiembre"
MES[9] = "octubre"
MES[10] = "noviembre"
MES[11] = "diciembre"
suma2 = 0
for m in range(12): 
    suma = 0
    e = 0
    while e < 5:
        es = e +1
        print("Ingresa la cantidad de lluvia el mes de",MES[m],"en la estación %i:"%es)
        LLUVIAS[m][e] = input()
        try:
            float(LLUVIAS[m][e])
        except ValueError:
            print("Cantidad inválida\n")
        else:
            LLUVIAS[m][e] = float(LLUVIAS[m][e])
            suma = suma + LLUVIAS[m][e]
            suma2 = suma2 + LLUVIAS[m][e]
            print("")
            e = e + 1
    LLUVIAS[m][5] = suma / 5
promanual = suma2 / 60
contmay = 0
contmen = 0
m = 0
mayor = LLUVIAS[m][5]
mesmay = MES[m]
menor = LLUVIAS[m][5]
mesmen = MES[m]
if LLUVIAS[m][5] > promanual:
    contmay = contmay + 1
elif LLUVIAS[m][5] < promanual:
    contmen = contmen + 1
for m in range(1,12):
    if LLUVIAS[m][5] > mayor:
        mayor = LLUVIAS[m][5]
        mesmay = MES[m]
    elif LLUVIAS[m][5] < menor:
        menor = LLUVIAS[m][5]
        mesmen = MES[m]
    if LLUVIAS[m][5] > promanual:
        contmay = contmay + 1
    elif LLUVIAS[m][5] < promanual:
        contmen = contmen + 1
print("La lluvia promedio anual es de",promanual,"\nEl mes con mayor lluvia fue el mes de",mesmay,"\nEl mes con menor lluvia fue el mes de",mesmen)
print(contmay,"meses tuvieron una lluvia arriba del promedio\n%i"%contmen,"meses tuvieron una lluvia debajo del promedio")
input()
