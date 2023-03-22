#pragma once
struct Node;

#include "Node.h"

struct Edge {

    Edge(Node *src, Node *dest, int cst);

    Node *sourceNode;
    Node *destinationNode;
    int cost;
};