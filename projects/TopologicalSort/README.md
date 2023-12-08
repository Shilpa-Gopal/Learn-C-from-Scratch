# Topological Sorting 

In-Depth First Traversal (DFS), we print a vertex and then recursively call DFS for its adjacent vertices. 
In topological sorting, the requirement is to print a vertex before its adjacent vertices. For instance, in the given graph, the vertex ‘5’ should be printed before vertex ‘0’. 
However, unlike DFS, the vertex ‘4’ should also be printed before vertex ‘0’. 
Thus, Topological sorting differs from DFS. An example DFS of the shown graph is “5 2 3 1 0 4”, but it is not a topological sorting.

![Graph](TopologicalSort/topoimagegit.png)

## Algorithm for Topological Sorting

### Prerequisite: DFS

We can modify DFS to find the Topological Sorting of a graph. In DFS:

1. Start from a vertex, print it, and then
2. Recursively call DFS for its adjacent vertices.

In topological sorting:

1. Use a temporary stack.
2. Don't print the vertex immediately.
3. Recursively call topological sorting for all its adjacent vertices, then push it to the stack.
4. Finally, print the contents of the stack.

**Note:** A vertex is pushed to the stack only when all its adjacent vertices (and their adjacent vertices and so on) are already in the stack.

### Approach:

1. Create a stack to store the nodes.
2. Initialize a visited array of size N to keep the record of visited nodes.
3. Run a loop from 0 till N:
4. If the node is not marked True in the visited array, then call the recursive function for topological sort and perform the following steps:
        - Mark the current node as True in the visited array.
        - Run a loop on all the nodes which have a directed edge to the current node.
        - If the node is not marked True in the visited array:
            - Recursively call the topological sort function on the node.
        - Push the current node into the stack.
5. Print all the elements in the stack.
