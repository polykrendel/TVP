#include <iostream>
using namespace std;

class Graph {
private:
    int n;
    int g[10][10];
public:
    Graph(int x) {
        n = x;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                g[i][j] = 0;
            }
        }
    }

    void displayAdjacencyMatrix() {
        cout << "\n Матрица смежности:";
        for (int i = 0; i < n; ++i){
            cout << "\n";
            for (int j = 0; j < n; ++j){
                cout << " " << g[i][j];
            }
        }
        cout << "\n";
    }

    void addEdge(int x, int y) {
        if ((x >= n) || (y >= n)) {
            cout << "Vertex does not exists!\n";
        }
        if (x == y) {
            cout << "Same Vertex!\n";
        }
        else {
            g[y][x] = 1;
            g[x][y] = 1;
        }
    }

    void addVertex() {
        n++;
        int i;
        for (i = 0; i < n; ++i){
            g[i][n - 1] = 0;
            g[n - 1][i] = 0;
        }
    }

    void removeVertex(int x) {
        if (x >= n){
            cout << "\nVertex not present!";
            return;
        }
        else{
            int i;
            while (x < n){
                for (i = 0; i < n; ++i){
                    g[i][x] = g[i][x + 1];
                }
                for (i = 0; i < n; ++i){
                    g[x][i] = g[x + 1][i];
                }
                x++;
            }
            n--;
        }
    }

    void removeEdge(int x, int y) {
        if ((x >= n) || (y >= n) || (g[x][y]==0)) {
            cout << "Vertex or edge does not exists!\n";
        }
        if (x == y) {
            cout << "Same Vertex!\n";
        }
        else {
            g[x][y] = 0;
            g[y][x] = 0;
        }
    }

    Graph unite(Graph &g1, Graph &g2) {
        Graph g3 = Graph(max(g1.n, g2.n));
        for (int i = 0; i < g3.n; ++i) {
            for (int j = 0; j < g3.n; ++j) {
                if (g1.g[i][j] == 1 || g2.g[i][j] == 1) {
                    g3.g[i][j] = 1;
                }
            }
        }
        return (g3);
    }

    Graph intersect(Graph &g1, Graph &g2) {
        Graph g3 = Graph(max(g1.n, g2.n));
        for (int i = 0; i < g3.n; ++i) {
            for (int j = 0; j < g3.n; ++j) {
                if (g1.g[i][j] == 1 && g2.g[i][j] == 1) {
                    g3.g[i][j] = 1;
                }
            }
        }
        return (g3);
    }
};

void checkAddEdge(Graph &g1,Graph &g2) {
    cout << "Введите номера смежных вершин для 1 графа (для окончания ввода введите -1,любое число): " << "\n";
    int x = 0, y;
    while (x != -1) {
        cin >> x >> y;
        if (x == -1) {
            break;
        }
        else {
           g1.addEdge(x, y);
        }
    }
    cout << "Введите номера смежных вершин для 2 графа (для окончания ввода введите -1,любое число): " << "\n";
    x = 0;
    while (x != -1) {
        cin >> x >> y;
        if (x == -1) {
            break;
        }
        else {
            g2.addEdge(x, y);
        }
    }
    g1.displayAdjacencyMatrix();
    g2.displayAdjacencyMatrix();
}

void checkAddVertex(Graph &g1, Graph &g2) {
    int kol;
    cout << "Введите количество вершин которое хотите добавить к 1 графу: \n";
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        g1.addVertex();
    }
    cout << "Введите количество вершин которое хотите добавить ко 2 графу: \n";
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        g2.addVertex();
    }
    g1.displayAdjacencyMatrix();
    g2.displayAdjacencyMatrix();
}

void checkRemoveVertex(Graph &g1, Graph &g2) {
    cout << "Введите номера вершин, которые хотите удалить в 1 графе (если не хотите, введите -1): \n";
    int num=0;
    while (num != -1) {
        cin >> num;
        if (num == -1) {
            break;
        }
        else {
            g1.removeVertex(num);
        }
    }
    cout << "Введите номера вершин, которые хотите удалить во 2 графе (если не хотите, введите -1): \n";
    num = 0;
    while (num != -1) {
        cin >> num;
        if (num == -1) {
            break;
        }
        else {
            g2.removeVertex(num);
        }
    }
    g1.displayAdjacencyMatrix();
    g2.displayAdjacencyMatrix();
}

void checkRemoveEdge(Graph &g1, Graph &g2) {
    cout << "Введите номера вершин, между которыми хотите удалить ребро в 1 графе (если не хотите, введите -1, любое число): \n";
    int x=0, y;
    while (x != -1) {
        cin >> x >> y;
        if (x == -1) {
            break;
        }
        else {
            g1.removeEdge(x, y);
        }
    }
    cout << "Введите номера вершин, между которыми хотите удалить ребро во 2 графе (если не хотите, введите -1, любое число): \n";
    x = 0;
    while (x != -1) {
        cin >> x >> y;
        if (x == -1) {
            break;
        }
        else {
            g2.removeEdge(x, y);
        }
    }
    g1.displayAdjacencyMatrix();
    g2.displayAdjacencyMatrix();
}

int main() {
    setlocale(LC_ALL,"Russian");
    int size_1,size_2;
    cout << "Введите количество вершин в 1 графе: ";
    cin >> size_1;
    cout << "\n";
    Graph g1 = Graph(size_1);
    cout << "Введите количество вершин в 2 графе: ";
    cin >> size_2;
    cout << "\n";
    Graph g2 = Graph(size_2);
    int x = 1;
    while (x >= 1 && x <= 6) {
        cout << "Выбирете что нужно сделать (1-добавить ребро, 2-добавить вершину, 3-удалить вершину, 4-удалить ребро, 5-выполнить объединение 2-х графов, 6-выполнить пересечение 2-х графов, иначе завершить программу): \n";
        cin >> x;
        switch (x) {
        case 1:
            checkAddEdge(g1, g2);
            break;
        case 2:
            checkAddVertex(g1, g2);
            break;
        case 3:
            checkRemoveVertex(g1, g2);
            break;
        case 4:
            checkRemoveEdge(g1, g2);
            break;
        case 5:
            g1=g1.unite(g1, g2);
            g1.displayAdjacencyMatrix();
            break;
        case 6:
            g1=g1.intersect(g1, g2);
            g1.displayAdjacencyMatrix();
            break;
        default:
            break;
        }
    }
}