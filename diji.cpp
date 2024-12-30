Dijkstra(Graph, source):
    Initialize distances[] = { ∞ } for all nodes except the source, which is 0.
    Create a priority queue (or min-heap) Q to store nodes and their tentative distances.
    Add source to Q with distance 0.

    while Q is not empty:
        current_node = extract_min(Q)  // Remove node with smallest tentative distance
        for each neighbor v of current_node:
            tentative_distance = distances[current_node] + weight(current_node, v)
            if tentative_distance < distances[v]:
                distances[v] = tentative_distance
                update Q with the new distance for v

    return distances[]  // This contains the shortest distances from source to all nodes
