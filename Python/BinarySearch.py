# blanyal

def binarySearch(inputList, item):
    lower = 0
    upper = len(inputList) - 1
    isFound = False

    while (lower <= upper and not isFound):
        mid = (lower + upper) // 2
        if inputList[mid] == item:
            isFound = True
        elif item < inputList[mid]:
            upper = mid - 1
        else:
            lower = mid + 1

    return isFound
        
if __name__ == "__main__":
    inputList = [int(x) for x in input("Enter the input list: ").split()]
    item =  int(input("Enter the item to be found: "))
    print (binarySearch(inputList, item))
