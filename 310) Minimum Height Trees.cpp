#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    // Function to find the nodes that form trees with the minimum height
    vector<int> findMinHeightTrees(int numNodes, vector<vector<int>>& edges) {
        // Base case: if there's only one node, it's the root of a minHeightTree
        if (numNodes == 1) return {0};

        // Each node will be an index in an adjacency list
        vector<vector<int>> adjacencyList(numNodes);
        // The degree count for each node
        vector<int> degrees(numNodes, 0);

        // Construct the graph
        for (const auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
            degrees[nodeA]++;
            degrees[nodeB]++;
        }

        // Initialize a queue for processing leaf nodes (nodes with degree 1)
        queue<int> processingQueue;
        for (int i = 0; i < numNodes; ++i) {
            if (degrees[i] == 1) {
                processingQueue.push(i);
            }
        }

        // Vector to hold the minimum height tree roots
        vector<int> minHeightRoots;

        // Process the graph
        while (!processingQueue.empty()) {
            // Start a new level
            minHeightRoots.clear();
            int levelSize = processingQueue.size(); // Number of nodes in the current level

            // Process all nodes in the current level
            for (int i = 0; i < levelSize; ++i) {
                int currentNode = processingQueue.front();
                processingQueue.pop();

                // Add the current node to this level's results
                minHeightRoots.push_back(currentNode);

                // Decrease the degree of adjacent nodes and enqueue new leaf nodes
                for (int adjacentNode : adjacencyList[currentNode]) {
                    if (--degrees[adjacentNode] == 1) { // If it becomes a leaf node
                        processingQueue.push(adjacentNode);
                    }
                }
            }
        }

        // minHeightRoots now contains the roots of tree who have the minimum height
        return minHeightRoots;
    }
};
