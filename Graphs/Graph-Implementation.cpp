#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>  // Thêm thư viện này để sử dụng std::find

using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> adjacentList;
    int numberOfNodes;

public:
    Graph() {
        numberOfNodes = 0;
    }

    // Thêm đỉnh (node)
    void addVertex(string node) {
        adjacentList[node] = vector<string>();
        numberOfNodes++;
    }

    // Thêm cạnh (edge) giữa hai đỉnh
    void addEdge(string node1, string node2) {
        // Đồ thị vô hướng: kết nối cả hai chiều
        if (find(adjacentList[node1].begin(), adjacentList[node1].end(), node2) == adjacentList[node1].end()) {
            adjacentList[node1].push_back(node2);
        }
        if (find(adjacentList[node2].begin(), adjacentList[node2].end(), node1) == adjacentList[node2].end()) {
            adjacentList[node2].push_back(node1);
        }
    }

    // Hiển thị tất cả các kết nối
    void showConnections() {
        for (auto &pair : adjacentList) {
            cout << pair.first << "-->";
            for (auto &neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph myGraph;
    myGraph.addVertex("0");
    myGraph.addVertex("1");
    myGraph.addVertex("2");
    myGraph.addVertex("3");
    myGraph.addVertex("4");
    myGraph.addVertex("5");
    myGraph.addVertex("6");

    myGraph.addEdge("3", "1");
    myGraph.addEdge("3", "4");
    myGraph.addEdge("4", "2");
    myGraph.addEdge("4", "5");
    myGraph.addEdge("1", "2");
    myGraph.addEdge("1", "0");
    myGraph.addEdge("0", "2");
    myGraph.addEdge("6", "5");

    myGraph.showConnections();

    return 0;
}
