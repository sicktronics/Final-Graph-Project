#include <unordered_map>

#include "Node.h"
#include "Edge.h"

/*
* Parker Mayer
* CS 260
* 3/21/23
*/

// The Graph class has methods for adding and removing nodes or edges,
// printing the graph, finding the shortest path between two nodes,
// and finding the minimum spanning tree.

class Graph {

    public:
        // Detailed comments can be found in "Graph.cpp"
        bool addNode(string nodeName);
        bool addEdge(string sourceNode, string destinationNode, int cost);

        bool removeNode(string nodeName);
        bool removeEdge(string sourceNode, string destinationNode);

        void toString();

        void shortestPath(string sourceNode, string destinationNode);

        Node *find(Node *n);
        void setUnion(Node *root1, Node *root2);
        void minimumSpanningTree();

    private:
        vector<Node *> nodes;   // All the nodes in our graph
        std::unordered_map<Node *, Node *> PARENT; // These are used in the disjointed unions for
        std::unordered_map<Node *, int> RANK;      // Kruskal's algorithm
};