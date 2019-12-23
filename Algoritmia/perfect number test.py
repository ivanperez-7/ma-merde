print("E para salir\n")
numStr = 1
while numStr != "E":
   numStr = input("Ingresa un número: ")
   try:
      int(numStr)
   except ValueError:
      continue
   else: 
      if int(numStr) <= 1:
         print("No funciona así >:V\n")
      else:
         num = int(numStr)
         suma = 0
         print("El número tiene los siguientes divisores:")
         for cont in range(1,num):
            res = num % cont
            if res == 0:
               suma = suma + cont
               print(cont)
         if suma == num:
            print("El número es perfecto C:\n")
         else:
            print("El número no es perfecto:'v la suma es de",suma,"\n")
