#include "Dijkstra.h"
#include "dheap.h"

int main() {
    int n = 5;  // Количество вершин
    int m = 7;  // Количество ребер
    int d = 2;  // D для D-арной кучи
    int start = 0;  // Стартовая вершина

    // Векторы для хранения результатов
    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);

    // Выполним алгоритм Дейкстры
    Dijkstra(dist, up, n, d, start);

    // Выведем результаты
    std::cout << "Кратчайшие расстояния от вершины " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Вершина " << i << ": расстояние = " << dist[i];
        if (up[i] != -1) {
            std::cout << ", предыдущая вершина = " << up[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
