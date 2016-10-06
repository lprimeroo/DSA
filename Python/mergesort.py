## Mergesort implementation in Python
## Runtime: O(n log(n))
## Space: O(n)
## Advantages: guaranteed good complexity (no need to worry about choice of pivot as in quicksort)
## Disadvantages: more temporary data storage needed than quicksort

def mergesort(arr):
    if len(arr) <= 1:
        return arr
    midpoint = len(arr) // 2
    return merger(mergesort(arr[:mid]), mergesort(arr[mid:]))
def merger(arrLeft, arrRight):
    if not arrLeft:
        return arrRight
    if not arrRight:
        return arrLeft
    if arrLeft[0] < arrRight[0]:
        return arrLeft[0] + merger(arrLeft[1:], arrRight)
    return arrRight[0] + merger(arrLeft, arrRight[1:])
