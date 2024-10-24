#include <gtest.h>
#include "dijkstra.h"

TEST(DijkstraTest, empty_graph_test) {
    int n = 0;
    int d = 2; 
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist.size(), 1);
    EXPECT_EQ(dist[0], 0); 
}

TEST(DijkstraTest, one_node_graph_test) {
    int n = 1;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(up[0], 0);
}

TEST(DijkstraTest, SimpleGraph) {
    int n = 4;
    int d = 3;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 3));
    graph[0].push_back(pair<int, int>(2, 13));
    graph[0].push_back(pair<int, int>(3, 21));

    graph[1].push_back(pair<int, int>(2, 1));
    graph[1].push_back(pair<int, int>(3, 31));


    graph[3].push_back(pair<int, int>(0, 2));
    graph[3].push_back(pair<int, int>(1, 11));


    dijkstra(dist, up, graph, n, d, start);

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

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 5));

    dijkstra(dist, up, graph, n, d, start);

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

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, -2));
    graph[1].push_back(pair<int, int>(2, 4));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], -2);
    EXPECT_EQ(dist[2], -2 + 4);
}

TEST(DijkstraTest, single_edge_test) {
    int n = 2;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 7));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 7);

    EXPECT_EQ(up[1], 0);
}

TEST(DijkstraTest, fully_connected_graph_test) {
    int n = 3;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 6));
    graph[0].push_back(pair<int, int>(2, 1));

    graph[1].push_back(pair<int, int>(0, 6));
    graph[1].push_back(pair<int, int>(2, 5));

    graph[2].push_back(pair<int, int>(0, 1));
    graph[2].push_back(pair<int, int>(1, 5));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 6);
    EXPECT_EQ(dist[2], 1);

    EXPECT_EQ(up[1], 0);
    EXPECT_EQ(up[2], 0);
}

TEST(DijkstraTest, two_node_graph_test) {
    int n = 2;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 10));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 10);
    EXPECT_EQ(up[1], 0);
}

TEST(DijkstraTest, three_node_cycle_graph_test) {
    int n = 3;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 2));
    graph[1].push_back(pair<int, int>(2, 3));
    graph[2].push_back(pair<int, int>(0, 4));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 2);
    EXPECT_EQ(dist[2], 5);
    EXPECT_EQ(up[1], 0);
    EXPECT_EQ(up[2], 1);
}

TEST(DijkstraTest, multiple_edges_test) {
    int n = 4;
    int d = 3;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 5));
    graph[0].push_back(pair<int, int>(1, 2));
    graph[1].push_back(pair<int, int>(2, 1));
    graph[1].push_back(pair<int, int>(3, 1));
    graph[2].push_back(pair<int, int>(3, 3));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 2);
    EXPECT_EQ(dist[2], 3);
    EXPECT_EQ(dist[3], 3);
    EXPECT_EQ(up[1], 0);
    EXPECT_EQ(up[2], 1);
    EXPECT_EQ(up[3], 1);
}

TEST(DijkstraTest, large_graph_test) {
    int n = 100;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        graph[i].push_back(pair<int, int>(i + 1, 1));
    }

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    for (int i = 1; i < n; ++i) {
        EXPECT_EQ(dist[i], i);
        EXPECT_EQ(up[i], i - 1);
    }
}

TEST(DijkstraTest, zero_weight_edge_test) {
    int n = 3;
    int d = 2;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 0));
    graph[1].push_back(pair<int, int>(2, 5));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 0);
    EXPECT_EQ(dist[2], 5);
    EXPECT_EQ(up[1], 0);
    EXPECT_EQ(up[2], 1);
}

TEST(DijkstraTest, graph_with_multiple_paths_test) {
    int n = 5;
    int d = 3;
    int start = 0;

    vector<int> dist(n + 1);
    vector<int> up(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    graph[0].push_back(pair<int, int>(1, 10));
    graph[0].push_back(pair<int, int>(2, 5));
    graph[1].push_back(pair<int, int>(3, 1));
    graph[2].push_back(pair<int, int>(1, 2));
    graph[2].push_back(pair<int, int>(3, 10));
    graph[3].push_back(pair<int, int>(4, 3));

    dijkstra(dist, up, graph, n, d, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 7);
    EXPECT_EQ(dist[2], 5);
    EXPECT_EQ(dist[3], 8);
    EXPECT_EQ(dist[4], 11);
    EXPECT_EQ(up[1], 2);
    EXPECT_EQ(up[2], 0);
    EXPECT_EQ(up[3], 1);
    EXPECT_EQ(up[4], 3);
}
