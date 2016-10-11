#github username = Lakshya1605

def DFS(node_number):
    visited[node_number]=1
    p = len(adjacency_list[node_number])
    i=0
    while(i!=p):
        x = adjacency_list[node_number][i]
        if not visited[x]:
            DFS(x)
        i+=1

if __name__=="__main__":
    number_of_vertices = input("Please enter the number or node")
    number_of_edges = input("Please enter the number of edges")
    visited = [0 for i in xrange(number_of_vertices)]
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

DFS(0)
print "After DFS the visited array is"
print visited

        
