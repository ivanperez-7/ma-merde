def costR(r,i,j):
    if i == j:
        return 0 
    
    return min([costR(r,i,k) + costR(r,k+1,j) + r[i-1]*r[k]*r[j] for k in range(i,j)])

def cost(r,n):
    m = [[0 for i in range(n+1)] for i in range(n+1)]

    for d in range(1,n):
        for i in range(1,n-d+1):
            j = i+d
            m[i][j] = min([m[i][k] + m[k+1][j] + r[i-1]*r[k]*r[j] for k in range(i,j)])
    return m[1][n]

r = [1,2,4,4,3,2]
print(r)
print("Recursivo : %d"%costR(r,1,len(r)-1))
print("D.P. : %d"%cost(r,len(r)-1))
