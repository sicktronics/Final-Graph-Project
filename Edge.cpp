#include "Edge.h"

Edge::Edge(Node *src, Node *dest, int cst){
    sourceNode = src;
    destinationNode = dest;
    cost = cst;
}