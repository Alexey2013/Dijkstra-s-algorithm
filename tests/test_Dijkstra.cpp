#include <gtest.h>
#include "dijkstra.h"

TEST(DijkstraTest, empty_graph_test) {
    int n = 0;
    int d = 2; 
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    Dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist.size(), 1);
    EXPECT_EQ(dist[0], 0); 
}

TEST(DijkstraTest, one_node_graph_test) {
    int n = 1;
    int d = 2;
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    Dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(up[0], 0);
}

TEST(DijkstraTest, SimpleGraph) {
    int n = 4;
    int d = 3;
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    graph[0].push_back(Pair<int, int>(1, 3));
    graph[0].push_back(Pair<int, int>(2, 13));
    graph[0].push_back(Pair<int, int>(3, 21));

    graph[1].push_back(Pair<int, int>(2, 1));
    graph[1].push_back(Pair<int, int>(3, 31));


    graph[3].push_back(Pair<int, int>(0, 2));
    graph[3].push_back(Pair<int, int>(1, 11));


    Dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);  
    EXPECT_EQ(dist[1], 3); 
    EXPECT_EQ(dist[2], 4);   
    EXPECT_EQ(dist[3], 21);  

    EXPECT_EQ(up[1], 0);    
    EXPECT_EQ(up[2], 1);   
    EXPECT_EQ(up[3], 0);  
}


TEST(DijkstraTest, disconnected_graph_test) {
    int n = 4;
    int d = 2;
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    graph[0].push_back(Pair<int, int>(1, 5));

    Dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 5);
    EXPECT_EQ(dist[2], std::numeric_limits<int>::max());
    EXPECT_EQ(dist[3], std::numeric_limits<int>::max());

    EXPECT_EQ(up[1], 0);
    EXPECT_EQ(up[2], -1);
    EXPECT_EQ(up[3], -1);
}

TEST(DijkstraTest, negative_weight_graph_test) {
    int n = 3;
    int d = 2;
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    graph[0].push_back(Pair<int, int>(1, -2)); // Negative weight
    graph[1].push_back(Pair<int, int>(2, 4));

    Dijkstra(dist, up, graph, n, d, start);

    // This test should fail as Dijkstra's algorithm does not support negative weights.
    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], -2);
    EXPECT_EQ(dist[2], -2 + 4);
}

TEST(DijkstraTest, single_edge_test) {
    int n = 2;
    int d = 2;
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    graph[0].push_back(Pair<int, int>(1, 7));

    Dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 7);

    EXPECT_EQ(up[1], 0);
}

TEST(DijkstraTest, fully_connected_graph_test) {
    int n = 3;
    int d = 2;
    int start = 0;

    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);
    Vector<Vector<Pair<int, int>>> graph(n + 1);

    graph[0].push_back(Pair<int, int>(1, 6));
    graph[0].push_back(Pair<int, int>(2, 1));

    graph[1].push_back(Pair<int, int>(0, 6));
    graph[1].push_back(Pair<int, int>(2, 5));

    graph[2].push_back(Pair<int, int>(0, 1));
    graph[2].push_back(Pair<int, int>(1, 5));

    Dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 6);
    EXPECT_EQ(dist[2], 1);

    EXPECT_EQ(up[1], 0);
    EXPECT_EQ(up[2], 0);
}