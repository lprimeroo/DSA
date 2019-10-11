l=list(input().split(" "))
x=input(" enter the number to be searched")
x=float(x)
count=0
for i in l:

  if(float(i)==x):
    print("found at",count)
  count=count+1
    
