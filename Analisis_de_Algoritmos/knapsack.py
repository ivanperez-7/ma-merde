def knapsackR(A,V,n,S):
    if S == 0:
        print(V)
        return ;
    if n < 0 or S < 0:
        return ;

    C = V.copy(); C.append(A[n])
    knapsackR(A, C, n-1, S-A[n])
    knapsackR(A, V.copy(), n-1, S)

def knapsack(A,S):
    B = A.copy(); B.insert(0,0)
    n = len(A)  
    t = [[False for i in range(S+1)] for i in range(n+1)]

    t[0][0] = True
    for j in range(1,S+1):
        t[0][j] = False
    for i in range(1,n+1):
        for j in range(S+1):
            t[i][j] = t[i-1][j]
            if j - B[i] >= 0:
                t[i][j] = t[i][j] or t[i-1][j-B[i]]
    return t[n][S]

A = [1,2,2,4,5,2,4]
S = 15

knapsackR(A, list(), len(A)-1, S)
print("\n" + str(knapsack(A,S)))
