array = [['1' if i == 0 or i == 49 or j == 0 or j == 49 else '0' for j in range(50)] for i in range(50)]
for row in array:
    print("".join(row))