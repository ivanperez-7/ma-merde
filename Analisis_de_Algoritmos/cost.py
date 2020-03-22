def costR(r,i,j):
    if i == j:
        return 0
    
    min = 10**20
    for k in range(i,j):
        count = costR(r,i,k) + costR(r,k+1,j) + r[i-1]*r[k]*r[j]
        if count < min:
            min = count
    return min

def cost(r,n):
    m = [[0 for i in range(n+1)] for i in range(n+1)]

    for i in range(1,n+1):
        m[i][i] = 0
    for d in range(1,n):
        for i in range(1,n-d+1):
            j = i+d
            min = 10**20

            for k in range(i,j):
                count = m[i][k] + m[k+1][j] + r[i-1]*r[k]*r[j]
                if count < min:
                    min = count
            m[i][j] = min
    return m[1][n]

r = [1,2,4,4,3,2]
print(r)
print("Recursivo : %d"%costR(r,1,len(r)-1))
print("D.P. : %d"%cost(r,len(r)-1))
