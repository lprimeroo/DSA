elements = [55,12,13,99,7]
maxSize = max(elements)
temp = [0 for x in range(maxSize)]
for element in elements:
    temp[element-1] += 1
b = []
count=1
for i in temp:
    if i:
        b.append(count)
    count += 1
b
