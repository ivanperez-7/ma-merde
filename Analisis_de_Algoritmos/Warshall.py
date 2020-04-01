def printmat(A):
    print("   ",end='')
    for i in range(len(A)):
        print("%d "%(i+1),end='')
    print("")

    for i in range(len(A)):
        print("%d ["%(i+1),end='')
        for j in range(len(A[i])):
            print(str(A[i][j])[0] + " ",end='')
        print("\b]")

def Warshall(V,E):
    n = len(V)
    A = [[False for i in range(n)] for i in range(n)]
    
    for i in range(n):
        for j in range(n):
            A[i][j] = (i+1,j+1) in E
        A[i][i] = True
        
    for k in range(n):
        for i in range(n):
            for j in range(n):
                A[i][j] = A[i][j] or (A[i][k] and A[k][j])
    printmat(A)

V = [1,2,3,4,5]        # array de vértices
E = [(1,2),(2,3),(4,3),(4,5),(1,5),(3,5),(1,4)]        # array de aristas

print("V = " + str(V))
print("E = " + str(E) + "\n")
Warshall(V,E)
