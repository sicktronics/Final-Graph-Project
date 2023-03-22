#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include "Node.h"
#include "Edge.h"
#include "Graph.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::unordered_map;


// Add a node using name, returns true if node was successfully added, false otherwise
bool Graph::addNode(string nodeName){

    // Adding a new node to the nodes vector
    nodes.push_back(new Node(nodeName));

    // Checking to see if the node at that new location has a name
    if(nodes.at(nodes.size()-1)->nodeName != ""){
        return true;
    }
    cout << "Warning! Node has no name...Status: ";
    return false;
}

// Add an edge using source and destinations as names of nodes to connect, 
// returns true to indicate edge was successfully added, false otherwise
bool Graph::addEdge(string sourceNode, string destinationNode, int cost){

    // We need some node pointers to ultimately point to src and dest
    Node *tempSrc = nullptr;
    Node *tempDest = nullptr;

    // Searching the nodes vector for source and destination nodes
    for(int i = 0; i < nodes.size(); i++){
        if (nodes.at(i)->nodeName == sourceNode){
            tempSrc = nodes.at(i);
        }
        if (nodes.at(i)->nodeName == destinationNode){
            tempDest = nodes.at(i);
        }
    }

    // Add the edge to the source's neighbors vector and return true (if the source/dest exist)
    if (tempSrc != nullptr && tempDest != nullptr){
        tempSrc->neighbors.push_back(new Edge(tempSrc, tempDest, cost));
        return true;
    }
    // Otherwise return false
    return false;
} 

// Remove a node if it exists, returns true if a node is removed, false otherwise
bool Graph::removeNode(string nodeName){

    // Iterate over nodes vector
    for(int i = 0; i < nodes.size(); i++){

        // If we find a match based on name, remove the node at that location, return true
        if(nodes.at(i)->nodeName == nodeName){
            nodes.erase(nodes.begin()+i);
            return true;
        }
    }
    // Return false if couldn't find the node
    return false;    
} 

// Remove an edge if it exists, returns true if an edge is removed, false otherwise
bool Graph::removeEdge(string sourceNode, string destinationNode){

    // Iterate over nodes vector to find source node
    for(int i = 0; i < nodes.size(); i++){
        // If source node found...
        if(nodes.at(i)->nodeName == sourceNode){

            // Temporarily store it and check its edges to see if one leads to the destination node
            Node *tempNode = nodes.at(i);
            for(int j = 0; j < tempNode->neighbors.size(); j++){

                // If we did find a match for the destination's name, erase it from neighbors vector
                if(tempNode->neighbors.at(j)->destinationNode->nodeName == destinationNode){
                    tempNode->neighbors.erase(tempNode->neighbors.begin()+j);
                    return true;
                }
            }
        }
    }
    // Return false if couldn't find edge
    return false;
}

/* Print out all nodes and edges, in the form:
    a -> b, c, e
    b -> d, q
    c -> a, b, e
    ...
*/
// The toString method iterates over all nodes in the graph and,
// for a given node, prints out its neighbors and associated edge cost.
void Graph::toString(){ 

    // For each node in the graph, print it out...
    for(int i = 0; i < nodes.size(); i++){
        cout << nodes.at(i)->nodeName << " -> " ;

        // Then iterate over its neighbors, printing the name of the destination node and the cost
        for(int j = 0; j < nodes.at(i)->neighbors.size(); j++){
            cout << nodes.at(i)->neighbors.at(j)->destinationNode->nodeName << " (" << nodes.at(i)->neighbors.at(j)->cost << "), ";
        }
        cout << endl;
    }
}

// The printShortestPath method is used by the shortest path method.
// Takes the path vector and the destination node initially,
// Then back tracks back to the source node, recursively printing
// Out the path
void printShortestPath(vector<Node *>parent, Node *node){
    // Base case: node is source
    if(parent[node->nodeID] == nullptr){
        return;
    }
    // Otherwise recursively call, passing the path and
    // The new node (the "parent" in the tree)
    printShortestPath(parent, parent[node->nodeID]);
    // Print it out
    cout << node->nodeName << " -> " ;
}

// Given the names of the source and destination nodes, find the shortest
// path from the source to the destination by Dijkstra's Algorithm. 
// Then, prints out the cost of the path as well as the path to get there
void Graph::shortestPath(string sourceNode, string destinationNode){

    Node *tempSrc = nullptr;
    Node *tempDest = nullptr;

    // Find and store the source and destination nodes
    for(int i = 0; i < nodes.size(); i++){
        if (nodes.at(i)->nodeName == sourceNode){
            tempSrc = nodes.at(i);
        }
        if (nodes.at(i)->nodeName == destinationNode){
            tempDest = nodes.at(i);
        }
    }

    vector<int> dist(nodes.size());     // Int vector that stores all distances from source node
    vector<Node *> path(nodes.size());  // Node pointer vector that stores path from source to dest
    bool visited[nodes.size()];         // Bool array that stores whether each node has been visited or not

    Node *current;                        // To track the current node
    vector<Node *> unvisited;             // Set of unvisited nodes

    // Setting visited nodes array to empty, path to empty strings, and distances to "infinity"
    for(int i = 0; i < nodes.size(); i++){
        visited[i] = false;
        path[i] = nullptr;
        dist[i] = INT_MAX;
        // Also assigning ID numbers to each node in the graph
        nodes[i]->nodeID = i;
    }
    // Setting up our first "current" node, which is always the source node
    dist[tempSrc->nodeID] = 0;      // Distance starts at 0
    path[tempSrc->nodeID] = nullptr;     // Path starts as empty string
    current = tempSrc;              // Set the current to be source node

    while(true){
        // Mark the "current" node as visited
        visited[current->nodeID] = true;

        // Check all neighbors to see if visited
        for(int i = 0; i < current->neighbors.size(); i++){
            // If a given destination node is visited, move on to next for loop iteration
            Node *v = current->neighbors[i]->destinationNode;
            if(visited[v->nodeID]){
                continue;
            }
            // Otherwise add it to the vector of unvisited nodes
            unvisited.push_back(v);

            // Calculating hypothetical updated cost (current distance + cost to get to a given neighbor)
            int alt = dist[current->nodeID] + current->neighbors[i]->cost;

            // Update path cost if the alt cost is better than the current cost
            if (alt < dist[v->nodeID]){
                dist[v->nodeID] = alt;              // Updating cost
                path[v->nodeID] = current;  // Adding the node to the path
            }
        }
        // Next, we need to erase the "current" node from the set of unvisited nodes
        for(int i = 0; i < unvisited.size(); i++){
            if (unvisited[i]->nodeName == current->nodeName){
                unvisited.erase(unvisited.begin()+i);
                break;
            }
        }
        // If the unvisited set becomes empty, we exit the while loop
        if(unvisited.empty()){
            break;
        }

        int minDist = INT_MAX;
        int index = 0;

        // Deciding on the next current node by updating the minimum distance value
        // and then setting the index based on the next lowest value
        for(int i = 0; i < unvisited.size(); i++){
            if(dist[i] < minDist){
                minDist = dist[i];
                index = i;
            }
        }
        // Updating the "current" node
        current = unvisited[index];
    } // End of while loop

    // Print out the distance from source to destination
    cout << "Shortest distance from " << sourceNode << " to "
    << destinationNode << " is: " << dist[tempDest->nodeID] << endl;

    // Print out the path from source to destination
    printShortestPath(path, tempDest);
    cout << "Arrived!!" << endl;
} 

// ----

bool compareEdgeCost(Edge *e1, Edge *e2){
    return e1->cost < e2->cost;
}

Node *Graph::find(Node *n){

    if(PARENT[n] == n){
        return n;
    } else {
        return find(PARENT[n]);
    }
}

void Graph::setUnion(Node *root1, Node *root2){

    if(RANK[root1] > RANK[root2]){
        PARENT[root2] = root1;
    } else if(RANK[root2] > RANK[root1]){
        PARENT[root1] = root2;
    } else {
        PARENT[root1] = root2;
        RANK[root2]++;
    }

}

// Find a minimum spanning tree and return it... *more details later*
string Graph::minimumSpanningTree(){

    // Need array to store MST
    vector<Edge *> mst;

    // Vector to store the edges in our graph
    vector<Edge *> edges;


    // Take all vertices of the graph and make them a single-vertex disjoint set
    for(int i = 0; i < nodes.size(); i++){
        PARENT[nodes[i]] = nodes[i];
        RANK[nodes[i]] = 0;

        // Create edges vector
        for(int j = 0; j < nodes[i]->neighbors.size(); j++){
            edges.push_back(nodes[i]->neighbors[j]);
        }
    }

    sort(edges.begin(), edges.end(), compareEdgeCost);

    for(int i = 0; i < edges.size(); i++){

        Node *root1 = find(edges[i]->sourceNode);
        Node *root2 = find(edges[i]->destinationNode);

        if(root1 != root2){
            mst.push_back(edges[i]);
            setUnion(root1, root2);
        }
    }

    for(int i = 0; i < mst.size(); i++){
        cout << mst[i]->sourceNode->nodeName << "  " << mst[i]->destinationNode->nodeName << "  " << mst[i]->cost << endl;
    }


return "";
}

// Start of private methods

// Finds the node with name, return pointer to that node with that name
// Node *Graph::findNodeHelper(string nodeName){
// return nullptr;
// }

// // Finds the edge with given source and destination, return pointer to that edges
// Edge *Graph::findEdgeHelper(string sourceNode, string destinationNode){
// return nullptr;
// }