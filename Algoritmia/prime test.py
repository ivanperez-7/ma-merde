print("E para salir\n")
numStr = input("Ingresa un número: ")
while numStr != "E":
    if numStr == "un numero" or numStr == "Un numero" or numStr == "Un número" or numStr== "un número":
            print("No seas wey V:\n")
    else:
        try:
            int(numStr)
        except ValueError:
            print("Que ingreses un número we >:V\n")
        else:
            if int(numStr) <= 1:
                print("Así no sirve >:V\n")
            else:
                res = 1
                num = int(numStr)
                for cont in range(2,num):
                    res = num % cont
                    if res == 0:
                        break
                if res != 0:
                    print("Simón, es primo :'v\n")
                else:
                    div = num / cont
                    print("Nel, no es primo ya que %i"%div,"x",cont,"=",num,"\n")
    numStr = input("Ingresa un número: ")
