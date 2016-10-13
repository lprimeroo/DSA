# Give List of number. No need to input number of elements
numlist = input()
numbers = list(map(int,numlist.split()))
count = len(numbers)
for i in range(0,count-1):
	for j in range(0,count-i-1):
		if(numbers[j]>numbers[j+1]):
			temp = numbers[j];
			numbers[j] = numbers[j+1];
			numbers[j+1] = temp;

print(numbers)
