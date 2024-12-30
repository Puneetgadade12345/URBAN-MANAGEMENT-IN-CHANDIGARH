BFS(Graph G, Node start):
    Create a queue Q
    Create a set visited
    Enqueue start into Q
    Add start to visited
    
    while Q is not empty:
        u = Dequeue from Q
        Process(u)  // Can be printing or storing the node
        
        for each neighbor v of u:
            if v is not in visited:
                Add v to visited
                Enqueue v into Q
