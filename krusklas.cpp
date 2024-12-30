ALGORITHM Kruskal(Graph G, int n)
Input: A graph G with n vertices and edges, where edges have weights
Output: A Minimum Spanning Tree (MST) of G

1. Initialize MST ← ∅ // Empty set to store MST edges
2. Sort all edges of G in non-decreasing order of weights
3. Create a Disjoint Set (Union-Find) for all vertices
4. for each edge (u, v) in sorted edges do
5.     if Find(u) ≠ Find(v) then // Check if u and v belong to different sets
6.         Add edge (u, v) to MST
7.         Union(u, v) // Merge the sets containing u and v
8.         if size of MST = n - 1 then // MST has n-1 edges
9.             break
10. return MST
