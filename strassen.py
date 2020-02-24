import math

def add(A,B):
    m = len(A)
    C = [[0 for i in range(m)] for i in range(m)]

    for i in range(m):
        for j in range(m):
            C[i][j] = A[i][j] + B[i][j]
    return C

def sub(A,B):
    m = len(A)
    C = [[0 for i in range(m)] for i in range(m)]

    for i in range(m):
        for j in range(m):
            C[i][j] = A[i][j] - B[i][j]
    return C

def submatrix(A,r,c,m):
    C = [[0 for i in range(m)] for i in range(m)]

    f_row = r+m
    f_col = c+m

    for i in range(r,f_row):
        for j in range(c,f_col):
            C[i-r][j-c] = A[i][j]
    return C

def Strassen(A,B):
    l = len(A)

    if l == 1:
        C = [[A[0][0] * B[0][0]]]
        return C

    m = l / 2
    A11 = submatrix(A, 0, 0, m)
    A12 = submatrix(A, 0, m, m)
    A21 = submatrix(A, m, 0, m)
    A22 = submatrix(A, m, m, m)
    B11 = submatrix(B, 0, 0, m)
    B12 = submatrix(B, 0, m, m)
    B21 = submatrix(B, m, 0, m)
    B22 = submatrix(B, m, m, m)

    P1 = Strassen(A11,sub(B12,B22))
    P2 = Strassen(add(A11,A12),B22)
    P3 = Strassen(add(A21,A22),B11)
    P4 = Strassen(A22,sub(B21,B11))
    P5 = Strassen(add(A11,A22),add(B11,B22))
    P6 = Strassen(sub(A12,A22),add(B21,B22))
    P7 = Strassen(sub(A11,A21),add(B11,B12))

    C11 = sub(add(P5,P4),sub(P2,P6))
    C12 = add(P1,P2);
    C21 = add(P3,P4)
    C22 = sub(add(P1,P5),add(P3,P7))

    C = [[0 for i in range(l)] for i in range(l)]
    for i in range(m):
        for j in range(m):
            C[i][j] = C11[i][j]
            C[i][j+m] = C12[i][j]
            C[i+m][j] = C21[i][j]
            C[i+m][j+m] = C22[i][j]
    return C

def printmat(A):
    for i in range(len(A)):
        print(A[i])

m = int(input("Dimension de la matriz: "))

if m <= 0:
    exit()

m2 = int(math.pow(2,math.ceil(math.log(m,2)))) 

A = [[0 for i in range(m2)] for i in range(m2)]
B = [[0 for i in range(m2)] for i in range(m2)]

for i in range(m):
    for j in range(m):
        A[i][j] = int(input("Entrada A(%d,"%(i+1) + "%d): "%(j+1)))

for i in range(m):
    for j in range(m):
        B[i][j] = int(input("Entrada B(%d,"%(i+1) + "%d): "%(j+1)))

print("\nStrassen(A,B)")
C = Strassen(A,B)
printmat(C)
