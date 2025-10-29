/*
 * CSC-301
 * project3.cpp
 * Fall 2025
 *
 * Partner 1: Do, Khanh
 * Partner 2: Bohrer-Purnell, Myles
 * Date: Oct 31, 2025
 */

#include "project3.hpp"
#include <unordered_set>

using namespace std;

/*
 * createAdjacencyMatrix: given the exchange rates and currency labels,
 *                        creates the corresponding adjacency matrix for the
 *                        graph representation.
 * 
 * Graph description:
 *     Each currency in the exchange is a vertex in the graph.
 *     Directed edges will reflect the exchange rates between pairs of currencies.
 * 
 * Notes:
 *     Use log values as the edge weights.
 * 
 * Args:
 *     vector<double> &rates: the 1D array representing the exchange rates matrix.
 *     vector<string> &currencies: the array of currency label strings.
 * 
 * Returns:
 *     vector<double> adjMatrix: the adjacency matrix representation of the graph.
 */
vector<double> createAdjacencyMatrix(vector<double> &rates, vector<string> &currencies) {
    vector<double> adjMatrix(rates);
    int n = currencies.size();

    // Convert the exchange rates to log values for the adj matrix 
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int pos = r * n + c;
            // Diagonal position: rates of the same currency
            if (r == c) adjMatrix[pos] = 0.0;
            else {
                // Otherwise, save as log value
                adjMatrix[pos] = -log(rates[pos]);
            }
        }
    }

    return adjMatrix;
}

/*
 * detectArbitrage: Detect 
 *
 * Tasks description:
 *     1. Perform the |V| - 1 iterations of Bellman-Ford with tol 
 *     2. Perform the extra iteration and track changes in the distance value
 *     3. Choose a single vertex that had a change and follow its path backwards
 *          using the previous value until you find a cycle
 *     4. Once have this path, remove any vertices not part of the cycle, reverse the path
 * 
 * Notes:
 *     Do not need to find the best arbitrage opportunity.
 *
 * Args:
 *     vector<double> &adjMatrix: the 1D array representing the log exchange rates matrix
 *     vector<string> &currencies: the vector of currency labels.
 *     double tol: a tolerance for truncation, should not be altered.
 * 
 * Returns:
 *     vector<int> cycle: a vector of vertex labels (ints corresponding to their index in adjMatrix)
 */
vector<int> detectArbitrage(vector<double> &adjMatrix, 
                            vector<string> &currencies, 
                            double tol) {

    // Get the number of vertices and initialize the dist and prev values.
    int n = currencies.size();
    vector<double> distances( n, numeric_limits<double>::infinity() );
    vector<int> previous( n, -1 );

    vector<int> cycle;

    // Run the Bellman-Ford algorithm to find negative cost cycles.

    return cycle;
}