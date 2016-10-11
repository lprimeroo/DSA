#username = Lakshya1605

def DFSS(source_node):
    stack =[]
    visited[source_node] =True
    j=0
    stack.append(source_node)
    while len(stack)!=0:
        source_node = stack[j]
        y = source_node
        flag =0
        i =0;
        length =len(adjacency_list[y])
        while(i!=length):
            x = adjacency_list[y][i]
            if not visited[x]:
                visited[x] = True
                j+=1
                stack.append(x)
                source_node = stack[j]
                flag =1
                break
            i+=1
        if flag ==0 :
            stack.pop()
            j-=1


if __name__=="__main__":
        number_of_vertices = input("Please enter the number or node")
        number_of_edges = input("Please enter the number of edges")
        visited = [False for i in xrange(number_of_vertices)]
        adjacency_list=[[] for i in xrange(number_of_vertices)]
        print adjacency_list
        print "Please enter the vertices u -->v indexing from 0 and it should be connected"
        i =0
        while(i!=number_of_edges):
                u,v= raw_input().split()
                u = int(u)
                v = int(v)
                adjacency_list[u].append(v)
                i+=1

DFSS(0)
print "After DFS the visited array is"
print visited

