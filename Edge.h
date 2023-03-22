#pragma once
struct Node;

#include "Node.h"

/*
* Parker Mayer
* CS 260
* 3/21/23
*/

// The Edge struct one non-default constructor and stores
// associated source and destination nodes, as well as edge cost.
struct Edge {

    Edge(Node *src, Node *dest, int cst);

    Node *sourceNode;
    Node *destinationNode;
    int cost;
};