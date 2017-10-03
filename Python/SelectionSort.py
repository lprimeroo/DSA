# -*- coding: utf-8 -*-
# author: cruxiu ;)

def selectionSort(array):
    for i in range( len( array ) ):
        least = i
        for k in range(i + 1 , len(array)):
            if array[k] < array[least]:
                least = k
        aux = array[least]
        array[least] = array[i]
        array[i] = aux

def main():
    array = list(map(int, input('Enter the elements of the list:\n').split(' ')))
    print ("Now, we will sort the list. Your list now is:")
    print (array)
    selectionSort(array)
    print ("After sort, your list now is:")
    print (array)

if __name__ == "__main__":
    main()
