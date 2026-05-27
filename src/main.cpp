#include "graph.h"

int main(int argc, char *argv[]) {
	// samll.txt
    string filename = get_arg(argc, argv, "src/small.txt");
    Graph G;
    file_to_graph(filename, G);

    cout << "MST: ";
    EdgeList mst = Kruskals(G);
    cout << mst << endl;
    cout << "Total weight = " << sum_weights(mst) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G, 0) << endl;
	// medium.txt
	string filename2 = get_arg(argc, argv, "src/medium.txt");
    Graph G2;
    file_to_graph(filename2, G2);

    cout << "MST: ";
    EdgeList mst2 = Kruskals(G2);
    cout << mst2 << endl;
    cout << "Total weight = " << sum_weights(mst2) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G2, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G2, 0) << endl;
	// large.txt
	string filename3 = get_arg(argc, argv, "src/large.txt");
    Graph G3;
    file_to_graph(filename3, G3);

    cout << "MST: ";
    EdgeList mst3 = Kruskals(G3);
    cout << mst3 << endl;
    cout << "Total weight = " << sum_weights(mst3) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G3, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G3, 0) << endl;
	// largest.txt
	string filename4 = get_arg(argc, argv, "src/largest.txt");
    Graph G4;
    file_to_graph(filename4, G4);

    cout << "MST: ";
    EdgeList mst4 = Kruskals(G4);
    cout << mst4 << endl;
    cout << "Total weight = " << sum_weights(mst4) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G4, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G4, 0) << endl;
}
