# COUNTING SORT

# Counting sort is a sorting technique based on keys 
# between a specific range. It works by counting the 
# number of objects having distinct key values 
# (kind of hashing). Then doing some arithmetic to 
# calculate the position of each object in the output sequence.
#
# Example 
# IN data: 1 4 1 2 7 5 2
#
# index     : 0 1 2 3 4 5 6 7 
# count     : 0 2 2 0 1 1 0 1
# count add : 0 2 4 4 5 6 6 7
# OUT array : 1 1 2 2 4 5 7



def countSort(array):
    """
    Counting sort
    """

    #find max
    max_value = max(array)

    #creat emoty box of size Max
    occur_count=[0]*(max_value+1)

    #count the occurences 
    for element in array:
        occur_count[element] += 1
    
    #sort
    z = 0
    for i in range(max_value+1):
        for j in range(occur_count[i]):
            array[z] = i
            z+= 1

    return array

def test_counting_sory():
    """
    Running internal test
    """
    number_of_test_cases = 4
    test_array = [[0, 0, 0, 0, 0, 0], [1440, 1440, 1440, 1440, 1440, 1440], [0, 1234, 234, 34, 4, 5343], [24210, 42120, 54210, 53410, 43540, 4350]]
    expected_out = [[0, 0, 0, 0, 0, 0], [1440, 1440, 1440, 1440, 1440, 1440], [0, 4, 34, 234, 1234, 5343], [4350, 4350, 53410, 54210, 24210, 42120]]

    for test_no in range(number_of_test_cases):
        out_array = countSort(test_array[test_no])
        if out_array != expected_out[3-test_no]:
            print ('{}{}'.format("FAILED TEST: ", test_no))
        else:
            print ('{}{}'.format("PASSED TEST: ", test_no))

def main():
    print ("Enter the numbers with spaces:")
    array = [int(x) for x in input().split()]
    print (array)
    out_array = countSort(array)
    print ("Sorted numbers:")
    print (out_array)


if __name__ == "__main__":
    main()
    #runn internal test
    #est_counting_sory()