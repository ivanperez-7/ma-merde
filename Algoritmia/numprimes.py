low = int(input("Principio: "))
if low <= 1:
    low = 2
num = int(input("Número de primos: "))
if num > 0:
    print()
    c = 0
    res = 1
    while c < num:
        for d in range(2,low):
            res = low % d
            if res == 0:
                break
        if res != 0:
            print(low)
            c = c + 1
        low = low + 1
print("\nDone ! ")
input()
