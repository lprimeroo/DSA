import queue

def BFS(start_node):

    dfs_order = []  # to store list of elements in order of DFS 

    q = queue.Queue()   # create a FIFO Queue
    q.put(start_node)   # add start node to Queue
    visited[start_node] = True    # mark the node as visited
    
    while not q.empty():    # while the queue is not empty
        current_node = q.get()  # get first node from the queue
        dfs_order.append(current_node)  # add to the dfs order list
        for adjacent_node in adjacency_list[current_node]:  # for each adjacent node of the current_node
            # print (current_node, adjacent_node, visited[adjacent_node])
            # print ("\n")
            if visited[adjacent_node] is False:     # if this node is not visited
                q.put(adjacent_node)    # put this node in the queue
                visited[adjacent_node] = True    # mark the node as visited

    print ("\nDFS for the graph is : ")
    print (dfs_order)


if __name__=="__main__":
    number_of_vertices = int(input("Enter the number or nodes : "))
    number_of_edges = int(input("Enter the number of edges : "))
    visited = [False for i in range(number_of_vertices)]    # mark all nodes as not visited
    adjacency_list=[[] for i in range(number_of_vertices)]  # create empty adjacency list
    print ("\nEnter the edges int the form u v indexing from 0")
    for i in range(number_of_edges):
        u,v = input().split()   # 3 4
        u = int(u)  # 3
        v = int(v)  # 4
        adjacency_list[u].append(v) # we assume undirected graph by default
        adjacency_list[v].append(u) # so if (u -> v) then (u -> v)
    
    print (adjacency_list)

    BFS(int(input("Enter start node for BFS : ")))

    print ("\nAfter BFS the visited array is : ")
    print (visited)
