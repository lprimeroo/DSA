#This is python implementation for Huffman encoding of input string.
# The input is the string to be encoded.
# THe outputs:-
# 1. The number of distinct letters for the code
# 2. The frequency of each distinct letter.
# 3. The code for each distinct letter.
# 4. The encoding of the input string
import Queue

code = [""]*128

# The data to be in the tree
class data:
    def __init__(self,data1,freq1):
        self.left = None
        self.right = None
        self.data = data1
        self.freq = freq1
    def __cmp__(self,other):
        return cmp(self.freq,other.freq)
q = Queue.PriorityQueue()

# The function that recursively generates the hash for the characters  
def encodeIt(root,ch):
    if root is None:
        return
    if root.data != "@#$":
        print root.data+" : "+ch
        code[ord(root.data)] = ch
    encodeIt(root.left,ch+"0")
    encodeIt(root.right,ch+"1")

# The function that builds the tree
def executeTree(dataHe,freqHe,n):
    for i in range(n):
        q.put(data(dataHe[i],freqHe[i]))
    while(q.qsize() !=1):
        lefty = q.get()
        righty = q.get()
        top = data("@#$",lefty.freq+righty.freq)
        top.left = lefty
        top.right = righty
        q.put(top)
    temp = q.get()
    q.put(temp)

    # Call the function that generates the hash for the code
    encodeIt(temp,"")
    
if __name__ == '__main__':
    a = raw_input("Enter a string\n")
    p = len(a)
    t=[0]*128
    count = 0
    for i in range(p):
        t[ord(a[i])]+=1
    for i in range(128):
        if t[i]!=0:
            count+=1
    print "The number of distinct characters used is "+str(count)+"\n"
    letter = []
    freq=[]
    n = count
    for i in range(128):
        if t[i]!=0:
            letter.append(chr(i))
            freq.append(t[i])
    for i in range(n):
        print "Frequency of "+str(letter[i])+" : "+str(freq[i])
    
    print "The codes are \n"
    executeTree(letter,freq,n)
    final = ""
    print "The encoded string for "+a+" is "
    for i in range(p):
        final+=code[ord(a[i])]
    print final
        
    
