BFS(graph, start):
    # graph is an adjacency list
    visited = set()  # A set to track visited nodes
    queue = []       # A queue for BFS
    result = []      # A list to store the traversal order
    
    # Mark the starting node as visited and enqueue it
    visited.add(start)
    queue.append(start)
    
    while queue:
        # Dequeue a node from the queue
        node = queue.pop(0)
        result.append(node)  # Process the node (e.g., print or add to result)
        
        # Enqueue all unvisited neighbors
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    
    return result
