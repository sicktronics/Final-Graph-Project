#pragma once
struct Edge;

#include <string>
#include <vector>
#include "Edge.h"

using std::string;
using std::vector;

struct Node {
    // Node();
    Node(string name);

    string nodeName;    // name of city
    vector<Edge *> neighbors;   // complex edge object so can ask for things such as distance 
    int nodeID;                 // Tells us where the node is in the vector of nodes.
};

