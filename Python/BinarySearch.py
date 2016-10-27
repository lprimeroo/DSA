# blanyal, hiimbex :)

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
