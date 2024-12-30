Bellman-Ford(Graph, source):
    Initialize distances[] = { ∞ } for all nodes except the source, which is 0.
    for i = 1 to V-1:  // V-1 times for relaxation
        for each edge (u, v) with weight w:
            if distances[u] + w < distances[v]:
                distances[v] = distances[u] + w

    // Check for negative-weight cycles
    for each edge (u, v) with weight w:
        if distances[u] + w < distances[v]:
            print("Graph contains negative weight cycle")
            return

    return distances[]
