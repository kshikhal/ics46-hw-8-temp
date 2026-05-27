#include <gtest/gtest.h>

#include "graph.h"

TEST(sum_weights, correct) {
	EdgeList L;
	L.push_back({0, 1, 2});
	L.push_back({1, 2, 2});
	int result = sum_weights(L);
	EXPECT_EQ(result, 4);
}

TEST(sum_weights, empty) {
	EdgeList L;
	int result = sum_weights(L);
	EXPECT_EQ(result, 0);
}

TEST(sort_edges, correct) {
	Graph G;
	G.push_back({0, 1, 3});
	G.push_back({0, 1, 1});
	Graph sorted = G.sort_edges();
	EXPECT_EQ(sorted[0].weight, 1);
}

TEST(Kruskals, correct) {
	Graph G;
	G.push_back({0, 1, 1});
	G.push_back({1, 2, 2});
	G.push_back({0, 1, 3});
	G.numVertices = 3;
	EdgeList kruskal = Kruskals(G);

	EXPECT_EQ(kruskal.size(), 2);
	int kruskal_weight = sum_weights(kruskal);
	EXPECT_EQ(kruskal_weight, 3);
}

TEST(makeSet, correct) {
	DisjointSet ds(3);
	ds.makeSet(0);
	EXPECT_EQ(ds.findSet(0), 0);
}

TEST(unionSets, correct) {
	DisjointSet ds(3);
	ds.makeSet(0);
	ds.makeSet(1);
	ds.unionSets(0, 1);
	EXPECT_EQ(ds.findSet(0), ds.findSet(1));
}

TEST(dfs, correct) {
	Graph G;
	G.push_back({0, 1, 1});
	G.push_back({1, 2, 2});
	G.numVertices = 3;
	VertexList result = dfs(G, 0);
	EXPECT_EQ(result[0], 0);
	EXPECT_EQ(result.size(), 3);
}

TEST(bfs, correct) {
	Graph G;
	G.push_back({0, 1, 1});
	G.push_back({1, 2, 2});
	G.numVertices = 3;
	VertexList result = bfs(G, 0);
	EXPECT_EQ(result[1], 1);
	EXPECT_EQ(result.size(), 3);
}
