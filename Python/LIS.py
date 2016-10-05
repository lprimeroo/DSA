'''
    This check_longest_increasing_subsequence(ar) , checks out the length of longest conitnuous subaaray by using DP(Dynamic Programming)

'''

def check_longest_increasing_subsequence(ar):
    dp=[]

    # Initialising the value for first array element
    dp.append(1)

    for i in range(1,len(ar)):

        if ar[i]>ar[i-1]:
            # As for any indivisual element minimum length can be 1  for itself
            dp.append(1)
            # After checking the previous element increementing the count from the counter variable of the previous value itself(DP)
            dp[i]=dp[i-1]+1


        else:
            dp.append(1)

    pos=dp.index(max(dp))
    print("Longest subsequence array is ")
    #pos+1 because slicing needs +1 for going to the exact position we want to
    print(ar[pos+1-max(dp):pos+1])
    return max(dp)

ar=[1,6,-3,0,3,4,2,1,6,7,8]
print("original array is :",ar)
print("Longest Length of increasing subsequence is "+str(check_longest_increasing_subsequence(ar)))