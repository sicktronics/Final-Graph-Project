#include <unordered_map>

#include "Node.h"
#include "Edge.h"

class Graph {

    public:

        bool addNode(string nodeName);
        bool addEdge(string sourceNode, string destinationNode, int cost);

        bool removeNode(string nodeName); // maybe also have it remove associated edges!
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