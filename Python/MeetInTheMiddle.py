# robin-0 ( Nabil Ibtehaz)

'''
  This code implements the Meet in the Middle paradigm.
  
  In this code we'll determine whether or not it is possible 
  to obtain a certain sum from some numbers and also in how many 
  ways are there to achieve that sum.

'''

def checkBit(number,position):
  
  '''
    This function simply checks whether or not the bit at position
    of number is set or not.

    If the bit is set , this returns True.
    If the bit is reset , this returns False.
  '''

  return ( ( number & (1<<position) ) !=0 )


def binarySearch(number):

  ''' 
    This function simply searches whether or not the number is
    in the array
  '''

  global leftArray

  low=0
  high=len(leftArray)-1

  while(low<=high):

    mid=(low+high)//2
 

    if(leftArray[mid]==number):
      
      return True

    elif(leftArray[mid]>number):

      high = mid - 1
    
    else:

      low = mid + 1


  return False

def upperBound(number):

  ''' 
    This function will return the highest index of an sorted 
    array where the array element is less than the number
  '''

  global leftArray

  low=0
  high=len(leftArray)-1

  # early bypassings

  if(leftArray[high]<number):
    return high

  if(leftArray[low]>=number):
    return -1

  while(low<high):

    mid=(low+high+1)//2

    if(leftArray[mid]>=number):
    
      high = mid - 1
    
    else:

      low = mid 


  return low



if __name__ == "__main__":

  '''
    This is the main function.
    A simple UI is provided.


    In this implementation we are avoiding python dictionary 
    and rather using binary search for efficiency.
  '''

  N = int(input('How many numbers: '))

  inputArray = [int(x) for x in input('Enter the input list: ').split()]

  # meet in the middle : dividing the array into two partitions and storing the sum

  global leftArray   # using a global array to avoid passing it

  leftArray = []     # number of elements 2^floor(N/2)
  rightArray = []     # number of elements 2^ceiling(N/2)

  leftN = N // 2;   # left half of array
  rightN = N - leftN  # right half of array

  leftArrayCombinations = (1<<leftN) - 1  # how many combinations are possible for the left partitioned array 
  rightArrayCombinations = (1<<rightN) - 1  # how many combinations are possible for the right partitioned array 


  for i in range(leftArrayCombinations+1):   # can we omit the + 1 here ? :p
    bitmask=i
    tempSum=0

    for position in range(leftN):

      if(checkBit(bitmask,position)):
        tempSum+=inputArray[position]

    leftArray.append(tempSum)

  leftArray.sort()        # sorting the left array


  for i in range(rightArrayCombinations+1):   # can we omit the + 1 here ? :p
    bitmask=i
    tempSum=0

    for position in range(rightN):

      if(checkBit(bitmask,position)):
        tempSum+=inputArray[position+leftN]

    rightArray.append(tempSum)


  # no need to sort rightArray for our implementation


  Q = int(input('How many queries: '))
  queryNo=1

  while(Q>0):

    neededSum = int(input('Query ' + str(queryNo) + ' : '))
    queryNo+=1
    Q-=1

    numberOfWays=0

    for i in rightArray:

      need = neededSum - i 

      if(binarySearch(need)):
        
        L = upperBound(need)
        R = upperBound(need+1)

        numberOfWays+=R-L

    if(numberOfWays==0):
      print('Not possible\n')
    else:
      print('Possible')
      print('Number of ways : '+str(numberOfWays))


