#include "graph.h"

void DisjointSet::makeSet(Vertex x) {
	if (subsets[x].parent == -1)
		subsets[x].parent = x;
}

Vertex DisjointSet::findSet(Vertex x) {
	if (subsets[x].parent != x) {
		subsets[x].parent = findSet(subsets[x].parent);
		return subsets[x].parent;
	}
	return subsets[x].parent;
}

void DisjointSet::unionSets(Vertex x, Vertex y) { 
	x = findSet(x);
	y = findSet(y);
	if (x == y) return;
	subsets[y].parent = x;
}

DisjointSet::DisjointSet(int numVertices) : subsets(numVertices, {-1}){}

bool help_sort(const Edge & e1, const Edge& e2) {
	return e1.weight < e2.weight;
}

Graph Graph::sort_edges() const {
	Graph copy_edgeList = *this;
	sort(copy_edgeList.begin(), copy_edgeList.end(), help_sort);
	return copy_edgeList;
}
// returns a list of vertices that are connected to the given vertex
VertexList Graph::edges_from(Vertex vertex) const {
	VertexList connect_v;
	for (const Edge& e : *this) {
		if (e.u == vertex) connect_v.push_back(e.v);
	}
	return connect_v;
}

EdgeList Kruskals(const Graph& G) {
	DisjointSet ds(G.numVertices);
	for (int v = 0; v < G.numVertices; v++) {
		ds.makeSet(v);
	}
	EdgeList F;
	Graph sorted = G.sort_edges();
	for (const Edge& e : sorted) {
		if (ds.findSet(e.u) != ds.findSet(e.v)) {
			F.push_back(e);
			ds.unionSets(e.u, e.v);
		}
	}
	return F;
}

int sum_weights(EdgeList const& L) {
	int result = 0;
	int v_size = L.size();
	for (int i = 0; i < v_size; i++)
		result += L[i].weight;
	return result;
}

void file_to_graph(string file_name, Graph & G) {
	ifstream in(file_name);
	in >> G;
	in.close();
}

void error(string msg) {
	cout << "ERROR: " << msg << endl;
}

VertexList dfs(const Graph& graph, Vertex startVertex) {
	VertexList result;
	vector<bool> visited(graph.size(), false);
	stack<Vertex> S;

	S.push(startVertex);
	visited[startVertex] = true;

	while (!S.empty()) {
		Vertex v = S.top();
		result.push_back(v);
		S.pop();
		for (const Vertex& w : graph.edges_from(v)) {
			if (visited[w] == false) {
				visited[w] = true;
				S.push(w);
			}
		}
	}
	return result;
}

VertexList bfs(const Graph& graph, Vertex startVertex) {
	queue<Vertex> Q;
	VertexList result;
	vector<bool> visited(graph.size(), false);

	visited[startVertex] = true;
	Q.push(startVertex);

	while(!Q.empty()) {
		Vertex v = Q.front();
		Q.pop();
		result.push_back(v);
		for (const Vertex& w : graph.edges_from(v)) {
			if (visited[w] == false) {
				visited[w] = true;
				Q.push(w);
			}
		}
	}
	return result;
}
// what is this for?
string get_arg(int argc, char *argv[], string def) {
	if (argc > 1) return string(argv[1]);
	return def;
}
