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

    // Инициализируем граф (пример: граф из предыдущего примера)
    graph[0].push_back(Pair<int, int>(1, 3));
    graph[0].push_back(Pair<int, int>(2, 13));
    graph[0].push_back(Pair<int, int>(3, 21));

    // Вершина 1
    graph[1].push_back(Pair<int, int>(2, 1));
    graph[1].push_back(Pair<int, int>(3, 31));

    // Вершина 2 (нет соседей)
    // graph[2] остается пустым

    // Вершина 3
    graph[3].push_back(Pair<int, int>(0, 2));
    graph[3].push_back(Pair<int, int>(1, 11));

    // Вызов функции
    Dijkstra(dist, up, graph, n, d, start);

    // Ожидаемые результаты
    EXPECT_EQ(dist[0], 0);   // Расстояние до стартовой вершины 0
    EXPECT_EQ(dist[1], 3);   // Расстояние до вершины 1
    EXPECT_EQ(dist[2], 4);   // Расстояние до вершины 2
    EXPECT_EQ(dist[3], 21);  // Расстояние до вершины 3

    EXPECT_EQ(up[1], 0);     // Предшественник вершины 1
    EXPECT_EQ(up[2], 1);     // Предшественник вершины 2
    EXPECT_EQ(up[3], 0);     // Предшественник вершины 3
}