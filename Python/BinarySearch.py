# blanyal, hiimbex :)

'''
    The goal of binary ssearch is to divide the search space in half every iteration
    Binary search also assumes you have a sorted list of integers and goes through every
    time and determines if the item you are searching for is greater than or less than your 
    mid point and jumps to the respective side from there. If your item is found it returns
    true, otherwise your item is either not in the list or the list was not sorted, etc.
'''

def binarysearch (list, item):
    first = 0
    last = len(list) - 1
    found = False
    while not found and first <= last:
        mid = (first+last)//2
        if list[mid] == item:
            found = True
        else:
            if item < list[mid]:
                last = mid - 1
            else:
                first = mid + 1
    return found

if __name__ == "__main__":
    inputList = [int(x) for x in input("Enter the input list: ").split()]
    item =  int(input("Enter the item to be found: "))
    print (binarySearch(inputList, item))
