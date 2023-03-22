## 1. "Create a design before you start coding that describes or shows how a graph structure could be used to store some kinds of data and solve some kind of problem (yes, this can be a game that needs a graph to represent a map!)"

- add note about directed graph, mst conflict

## 2. "Create some tests (at least two for each piece of functionality) before you start coding..."

Note: More testing of functionality takes place in the "Demo" section of the project below.

### Test 0: Graph constructor

- Test 0.1 Default constructor (only one test makes sense here).

![image](Test01.png)

### Test 1: Node constructor

- Test 1.1: Non-default constructor (no default)

![image](Test11.png)

### Test 2: Edge constructor

- Test 2.1: Non-default constructor (no default)

![image](Test21.png)


### Test 3: addNode method

- Test 3.1: Adding node with a name

- Test 3.2: Adding node without a name

![image](Test3.png)

### Test 4: addEdge method

- Test 4.1: Successful edge adding

- Test 4.2: Unsuccessful edge adding

![image](Test4.png)

### Test 5: removeNode method

- Test 5.1: Successful node removal

- Test 5.2: Unsuccessful node removal

![image](Test5.png)

### Test 6: removeEdge method

- Test 6.1: Successful edge removal

- Test 6.2: Unsuccessful edge removal

![image](Test6.png)

### Test 7: toString method

- Test 7.1: toString an empty graph

- Test 7.2: toString a sample graph with some nodes, edges

![image](Test7.png)

### Test 8: shortestPath and printShortestPath methods

- Test 8.1: Find and print shortest path where the source is the destination

- Test 8.2: Find and print shortest path where the source is not the destination

![image](Test8.png)


### Test 9: minimumSpanningTree method (and by association, compareEdgeCost, find, and setUnion methods)

- Test 9.1: Find MST of an unconnected graph

- Test 9.2: Find MST of a connected graph

![image](Test8.png)






