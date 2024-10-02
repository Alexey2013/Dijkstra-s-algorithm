#include "Dijkstra.h"
#include "dheap.h"

int main() {
    int n = 5;  // ���������� ������
    int m = 7;  // ���������� �����
    int d = 2;  // D ��� D-����� ����
    int start = 0;  // ��������� �������

    // ������� ��� �������� �����������
    Vector<int> dist(n + 1);
    Vector<int> up(n + 1);

    // �������� �������� ��������
    Dijkstra(dist, up, n, d, start);

    // ������� ����������
    std::cout << "���������� ���������� �� ������� " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "������� " << i << ": ���������� = " << dist[i];
        if (up[i] != -1) {
            std::cout << ", ���������� ������� = " << up[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
