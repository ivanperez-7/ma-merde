while 1 == 1:
    while 1 == 1:
        cant = input("Cantidad de números: ")
        try:
            int(cant)
        except ValueError:
            continue
        else:
            break
    cant = int(cant)
    if cant > 0:
        NUMS = [0 for i in range(cant)]
        print()
        j = 0
        while j < cant:
            index = j + 1
            NUMS[j] = input("Ingresa el número %i: "%index)
            try:
                int(NUMS[j])
            except ValueError:
                continue
            else:
                NUMS[j] = int(NUMS[j])
                j = j + 1
        print()
        print(NUMS)
        if 0 in NUMS:
            print("\nlcm = 0")
            input()
            break
        else:
            lcm = 1
            div = 2
            while cant == cant:
                for j in range(cant):
                    if abs(NUMS[j]) != 1:
                        break
                if abs(NUMS[j]) != 1:
                    while cant == cant:
                        for j in range(cant):
                            if NUMS[j] % div == 0:
                                break
                        if NUMS[j] % div == 0:
                            for j in range(cant):
                                if NUMS[j] % div == 0:
                                    NUMS[j] = int(NUMS[j] / div)
                            lcm = lcm * div
                            print(NUMS,"/ %i"%div)
                            div = 2
                            break
                        else:
                            div = div + 1
                else:
                    break
        print("\nlcm = %i"%lcm)
        input()
        break
    else:
        print("Debe ser un número positivo\n")
