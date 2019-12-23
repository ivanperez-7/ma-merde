p = int(input("Principio: "))
f = int(input("Fin: "))
print("")
contprim = 0
if p <= 1:
    p = 2
for cont in range(p,f+1):
    res = 1
    for cont2 in range(2,cont):
        res = cont % cont2
        if res == 0:
            break
    if res != 0:
        contprim = contprim + 1
        print(cont)
print("\nSe hallaron",contprim,"números primos en el intervalo.")
input()
