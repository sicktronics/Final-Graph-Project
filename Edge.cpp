#include "Edge.h"

/*
* Parker Mayer
* CS 260
* 3/21/23
*/

// Assigns the source node, destination node, and cost
Edge::Edge(Node *src, Node *dest, int cst){
    sourceNode = src;
    destinationNode = dest;
    cost = cst;
}