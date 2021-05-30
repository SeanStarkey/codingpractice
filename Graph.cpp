//
// Graph data structure
//
// Creates a random graph (directed or undirected)
//
// Perforces DFS and BFS on this graph
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

const int NUMBER_OF_VERTICES = 10;
const bool DIRECTED_GRAPH = true;
const int MIN_NUM_OF_EDGES = 1;
const int MAX_NUM_OF_EDGES = 3;


struct Vertex {
    int value;
    bool visited;
    std::vector<Vertex*> edges;
    Vertex(int in_value);

    void DFS();
};

class Graph {
public:
    void addVertex(int value);
    void addEdge(int vertex1, int vertex2);
    Vertex* getVertex(int value);

    void DFS(int vertex);
    void BFS(int vertex);

private:
    std::map<int, Vertex*> vertices;
};

void Graph::addVertex(int value) {
    Vertex* newVertex = new Vertex(value);
    vertices[value] = newVertex;
}

void Graph::addEdge(int vertex1, int vertex2) {
    std::cout << "Adding edge: " << vertex1 << " -> " << vertex2 << std::endl;
    Vertex* vertex = vertices[vertex1];
    vertex->edges.push_back(vertices[vertex2]);
}


Vertex* Graph::getVertex(int value) {
    return vertices[value];
}


Vertex::Vertex(int in_value) : value(in_value) {
}


void Graph::DFS(int vertex) {
    for (int v=0; v<NUMBER_OF_VERTICES; v++) {
        vertices[v]->visited = false;
    }

    vertices[vertex]->DFS();
}

void Vertex::DFS() {
    if (!visited) {
        std::cout << value << std::endl;
        visited = true;
    }
    for (int e=0; e<edges.size(); e++) {
        if (!edges[e]->visited)
            edges[e]->DFS();
    }
}


void Graph::BFS(int vertex) {
    for (int v=0; v<NUMBER_OF_VERTICES; v++) {
        vertices[v]->visited = false;
    }

    std::queue<Vertex*> queueBFS;
    queueBFS.push(vertices[vertex]);

    while (!queueBFS.empty()) {
        Vertex* nextVertex = queueBFS.front();
        queueBFS.pop();
        if (!nextVertex->visited) {
            nextVertex->visited = true;
            std::cout << nextVertex->value << std::endl;
            for (int e=0; e<nextVertex->edges.size(); e++) {
                queueBFS.push(nextVertex->edges[e]);
            }
        }
    }
}

Graph createRandomGraph() {
    Graph graph;
    for (int v=0; v<NUMBER_OF_VERTICES; v++) {
        graph.addVertex(v);
    }

    for (int v=0; v<NUMBER_OF_VERTICES; v++) {
        std::vector<bool> used(NUMBER_OF_VERTICES, false);
        int numOfEdges = rand() % (MAX_NUM_OF_EDGES - MIN_NUM_OF_EDGES + 1) + MIN_NUM_OF_EDGES;
        used[v] = true;
        Vertex* vertex = graph.getVertex(v);
        for (int e=0; e<vertex->edges.size(); e++)
        {
            used[vertex->edges[e]->value] = true;
            numOfEdges--;
        }
        for (int e=0; e<numOfEdges; e++) {
            while (true)  {
                int vertex = rand() % NUMBER_OF_VERTICES;
                if (!used[vertex]) {
                    graph.addEdge(v, vertex);
                    if (!DIRECTED_GRAPH)
                        graph.addEdge(vertex, v);
                    used[vertex] = true;
                    break;
                }
            }
        }
    }

    return graph;
}

int main() {
    srand(time(NULL));

    Graph graph = createRandomGraph();

    std::cout << std::endl;

    std::cout << "DFS: " << std::endl;
    graph.DFS(0);

    std::cout << std::endl;

    std::cout << "BFS: " << std::endl;
    graph.BFS(0);

    return 0;
}
