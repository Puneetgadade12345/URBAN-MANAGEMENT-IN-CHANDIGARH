Prim(Graph, start):
    Initialize key[] = { ∞ } for all nodes except the start, which is 0.
    Initialize parent[] = { -1 } for all nodes.
    Create a priority queue (or min-heap) Q to store (key, vertex) pairs.
    Add all vertices to Q with their key values.

    while Q is not empty:
        u = ExtractMin(Q)  // Remove node with the smallest key value
        for each neighbor v of u:
            if v is in Q and weight(u, v) < key[v]:
                key[v] = weight(u, v)
                parent[v] = u
                DecreaseKey(Q, v, key[v])

    return parent[]  // This contains the MST edges (u, parent[u])
