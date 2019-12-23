# E.D.F. que lea una matriz de 5 X 5 elementos y que calcule e imprima la suma de sus elementos que se encuentran en la diagonal principal.
MATRIZ = [[0 for i in range(5)] for j in range(5)]
suma = 0
for m in range(5):
    for n in range(5):
        MATRIZ[m][n] = float(input("Ingresa un número: "))
m = 0
n = 0
while m <= 4 and n <= 4:
    suma = suma + MATRIZ[m][n]
    m = m + 1
    n = n + 1
print("\nLa suma es",suma)
