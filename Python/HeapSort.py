def swap(i, j):                    
    sq[i], sq[j] = sq[j], sq[i] 

def heapify(end,i):   
    l=2 * i + 1  
    r=2 * (i + 1)   
    max=i   
    if l < end and sq[i] < sq[l]:   
        max = l   
    if r < end and sq[max] < sq[r]:   
        max = r   
    if max != i:   
        swap(i, max)   
        heapify(end, max)   

def heap_sort():     
    end = len(sq)   
    start = end // 2 - 1 # use // instead of /
    for i in range(start, -1, -1):   
        heapify(end, i)   
    for i in range(end-1, 0, -1):   
        swap(i, 0)   
        heapify(i, 0)

sq = input("Enter numbers with spaces: ")
sq = list(map(int, sq.split()))
#Give input in way 21 -7 101 -21 5 51 13

heap_sort()
print(sq)
