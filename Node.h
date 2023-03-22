#pragma once
struct Edge;

#include <string>
#include <vector>
#include "Edge.h"

using std::string;
using std::vector;

/*
* Parker Mayer
* CS 260
* 3/21/23
*/

// The Node struct has one constructor that takes that node's name
// and member variables to store its name, neighbors, and ID number
struct Node {

    Node(string name);

    string nodeName;            // name of node
    vector<Edge *> neighbors;   // Vector of associated edges
    int nodeID;                 // Tells us where the node is in the vector of nodes
};

