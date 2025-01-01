#include <iostream>
#include <string>
using namespace std;

struct Node {
    string Name;     
    int Distance;   
    Node* Link;     
};

struct Graph {
    int vertices;   //so luong dinh trong do thi 
    Node* aList; // mang chua dsach ke 
};

Node* createNode(const string& name, int distance) {
    Node* newNode = new Node;
    newNode->Name = name;
    newNode->Distance = distance;
    newNode->Link = NULL;
    return newNode;
}

// Ham them canh 
void addEdge(Graph& graph, int u, int v, const string& nameU, const string& nameV, int distance) {
    // them canh tu dinh u den dinh v 
    Node* newNode = createNode(nameV, distance);
    newNode->Link = graph.aList[u].Link;
    graph.aList[u].Link = newNode;

}

//ham hien thi do thi 
void displayGraph(Graph& graph) {
    for (int i = 0; i < graph.vertices; ++i) {
        cout << "V" << "(" << graph.aList[i].Name << "): ";
        Node* temp = graph.aList[i].Link;
        while (temp) {
            cout << " -> [" << temp->Name << ", " << temp->Distance << "]";
            temp = temp->Link;
        }
        cout << " -> NULL" << endl;
    }
}

int main() {
    int vertices = 7; 

    //khoi tao do thi 
    Graph graph;
    graph.vertices = vertices;
    graph.aList = new Node[vertices];

    // gan ten cho moi dinh 
    for (int i = 0; i < vertices; ++i) {
        graph.aList[i].Name = string(1, 'a' + i); 
        graph.aList[i].Distance = 0;
        graph.aList[i].Link = NULL;
    }

    // them cac canh vao do thi 
    addEdge(graph, 0, 1, "a", "b", 1);
    addEdge(graph, 0, 2, "a", "c", 1);
    addEdge(graph, 0, 3, "a", "d", 1);
    addEdge(graph, 1, 4, "b", "e", 1);
    addEdge(graph, 3, 4, "d", "e", 1);
    addEdge(graph, 4, 5, "e", "f", 1);
    addEdge(graph, 4, 2, "e", "c", 1);
    addEdge(graph, 4, 5, "e", "f", 1);
    addEdge(graph, 6, 1, "g", "b", 1);
    addEdge(graph, 6, 5, "g", "f", 1);
   

    // Hien thi do thi 
    displayGraph(graph);

    //giai phong bo nho dong 
    for (int i = 0; i < vertices; ++i) {
        Node* current = graph.aList[i].Link;
        while (current) {
            Node* temp = current;
            current = current->Link;
            delete temp;
        }
    }
    delete[] graph.aList;

    return 0;
}

