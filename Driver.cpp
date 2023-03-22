#include <iostream>

#include "Node.h"
#include "Edge.h"
#include "Graph.h"

using std::cout;
using std::endl;

/*
* Parker Mayer
* CS 260
* 3/21/23
*/


int main(int argc, char** argv){

    // cout << "Test 0.1: Default graph constructor" << endl;
    // Graph g;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 1.1: Non-default node constructor" << endl;
    // Node n("TestNode");
    // cout << "Name of node: " << n.nodeName << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 2.1: Non-default edge constructor" << endl;
    // Node *nS;
    // Node *nD;
    // Edge e(nS, nD, 100);
    // cout << "New edge's cost: " << e.cost << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 3.1: Adding node with a name" << endl;
    // Graph g;
    // cout << "Node addition successful? " << g.addNode("TestNode") << endl;
    // cout << "End of test reached.\n" << endl;
    
    // cout << "Test 3.2: Adding node without a name" << endl;
    // cout << "Node addition successful?\n" << g.addNode("") << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 4.1: Successful edge adding" << endl;
    // Graph g;
    // g.addNode("Corvallis");
    // g.addNode("Albany");
    // cout << "Status of adding an edge from Corvallis to Albany? " << g.addEdge("Corvallis", "Albany", 50) << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 4.2: Unsuccessful edge adding" << endl;
    // cout << "Status of adding an edge from Corvallis to Lebanon? " << g.addEdge("Corvallis", "Lebanon", 70) << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 5.1: Successful node removal" << endl;
    // Graph g;
    // g.addNode("Corvallis");
    // cout << "Status of removing Corvallis node? " << g.removeNode("Corvallis") << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 5.2: Unsuccessful node removal" << endl;
    // cout << "Status of removing Lebanon none? " << g.removeNode("Lebanon") << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 6.1: Successful edge removal" << endl;
    // Graph g;
    // g.addNode("Corvallis");
    // g.addNode("Albany");
    // g.addEdge("Corvallis", "Albany", 50);
    // cout << "Status of removing edge from Corvallis to Albany? " << g.removeEdge("Corvallis", "Albany") << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 6.2: Unsuccessful edge removal" << endl;
    // cout << "Status of removing edge from Corvallis to Lebanon? " << g.removeEdge("Corvallis", "Lebanon") << endl;
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 7.1: toString an empty graph" << endl;
    // Graph g;
    // g.toString();
    // cout << "End of test reached.\n" << endl;
    
    // cout << "Test 7.2: toString a sample graph with some nodes, edges" << endl;
    // g.addNode("A");
    // g.addNode("B");
    // g.addNode("C");

    // g.addEdge("A", "B", 4);
    // g.addEdge("B", "C", 3);
    // g.addEdge("A", "C", 6);
    // g.toString();
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 8.1: Find and print shortest path where the source is the destination" << endl;
    // Graph g;

    // g.addNode("A");
    // g.addNode("B");
    // g.addNode("C");

    // g.addEdge("A", "B", 4);
    // g.addEdge("B", "C", 3);
    // g.addEdge("A", "C", 6);
    // g.shortestPath("A", "A");
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 8.2: Find and print shortest path where the source is not the destination" << endl;
    // g.shortestPath("A", "C");
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 9.1: Find MST of an unconnected graph" << endl;
    // Graph g;

    // g.addNode("A");
    // g.addNode("B");
    // g.addNode("C");

    // g.minimumSpanningTree();
    // cout << "End of test reached.\n" << endl;

    // cout << "Test 9.2: Find MST of a connected graph" << endl;
    // g.addEdge("A", "B", 4);
    // g.addEdge("B", "C", 3);
    // g.addEdge("A", "C", 6);
    // g.minimumSpanningTree();
    // cout << "End of test reached.\n" << endl;

    Graph g;

    cout << "- - - DEMO - - -\n" << endl;
    cout << "- Adding nodes to graph... -\n" << endl;
    cout << "Node addition successful? " << g.addNode("Covell") << endl;
    cout << "Node addition successful? " << g.addNode("Batcheller") << endl;
    cout << "Node addition successful? " << g.addNode("Dearborn") << endl;
    cout << "Node addition successful? " << g.addNode("Graf") << endl;
    cout << "Node addition successful? " << g.addNode("Kelley") << endl;
    cout << "Node addition successful? " << g.addNode("Milam") << endl;
    cout << "Node addition successful? " << g.addNode("Dixon") << endl;
    cout << "Node addition successful? " << g.addNode("Library") << endl;
    cout << "Node addition successful? " << g.addNode("Memorial Union") << "\n" << endl;


    cout << "- Adding edges to nodes... -\n" << endl;
    // Covell
    cout << "Edge addition successful? " << g.addEdge("Covell", "Batcheller", 1) << endl;
    cout << "Edge addition successful? " << g.addEdge("Covell", "Graf", 7) << endl;

    // Batcheller
    cout << "Edge addition successful? " << g.addEdge("Batcheller", "Covell", 2) << endl;
    cout << "Edge addition successful? " << g.addEdge("Batcheller", "Dearborn", 3) << endl; 
    cout << "Edge addition successful? " << g.addEdge("Batcheller", "Graf", 5) << endl;   

    // Dearborn
    cout << "Edge addition successful? " << g.addEdge("Dearborn", "Batcheller", 2) << endl;
    cout << "Edge addition successful? " << g.addEdge("Dearborn", "Graf", 7) << endl;
    cout << "Edge addition successful? " << g.addEdge("Dearborn", "Milam", 11) << endl;
    cout << "Edge addition successful? " << g.addEdge("Dearborn", "Library", 15) << endl;

    // Graf
    cout << "Edge addition successful? " << g.addEdge("Graf", "Kelley", 10) << endl;

    // Kelley
    cout << "Edge addition successful? " << g.addEdge("Kelley", "Dixon", 9) << endl;

    // Milam
    cout << "Edge addition successful? " << g.addEdge("Milam", "Kelley", 14) << endl;
    cout << "Edge addition successful? " << g.addEdge("Milam", "Memorial Union", 5) << endl;

    // Dixon
    cout << "Edge addition successful? " << g.addEdge("Dixon", "Kelley", 11) << endl;

    // Memorial Union
    cout << "Edge addition successful? " << g.addEdge("Memorial Union", "Dixon", 12) << endl;
    cout << "Edge addition successful? " << g.addEdge("Memorial Union", "Dearborn", 18) << endl;
    cout << "Edge addition successful? " << g.addEdge("Memorial Union", "Library", 14) << endl;

    // Library
    cout << "Edge addition successful? " << g.addEdge("Library", "Memorial Union", 14) << endl;

    cout << "\n- Current graph -" << endl;
    g.toString();
    cout << "- - - - - -\n" << endl;

    cout << "The robot is currently at Covell Hall and needs to find the shortest\n"
         << "path to Kelley Engineering Center! Calculating shortest path...\n" << endl;

    g.shortestPath("Covell", "Kelley");
    cout << "- - - - - -\n" << endl;

    cout << "Let's find the campus map's minimum spanning tree: " << endl;
    g.minimumSpanningTree();
    cout << "- - - - - -\n" << endl;

    return 0;
}