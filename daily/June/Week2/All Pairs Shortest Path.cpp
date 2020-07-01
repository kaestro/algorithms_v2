// https://open.kattis.com/problems/allpairspath

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int num_vertices, num_edges, num_queries;

class Vertex {
public:
    Vertex(int idx):index(idx) {
        min_distances = vector<int>(num_vertices, INT_MAX);
        min_distances[idx] = 0;

        edges = vector<int>(num_vertices, INT_MAX);
    }

    int index;
    vector<int> min_distances;
    vector<int> edges;
};

vector<Vertex> vertices;

void get_edges();
void bellman_ford();
void queries();

int main() {

    while (true) {
        cin >> num_vertices >> num_edges >> num_queries;

        if (num_vertices == 0) break;

        vertices.clear(); vertices.reserve(num_vertices);
        for (int i = 0; i < num_vertices; ++i)
            vertices.push_back(Vertex(i));

        get_edges();

        bellman_ford();

        queries();
    }
    return 0;
}

void get_edges() {
    for (int i = 0; i < num_edges; ++i) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        vertices[src].edges[dst] = cost;
    }
}

void bellman_ford() {
    for (int i = 0; i < num_vertices; ++i) {
        auto& vertex = vertices[i];
        
        for (int rep = 0; rep < num_vertices - 1; ++rep) {
            for (int s_idx = 0; s_idx < num_vertices; ++s_idx) {
                auto& src = vertices[s_idx];
                int mid_dist = vertex.min_distances[s_idx];
                if (mid_dist == INT_MAX) {
                    continue;
                }

                for (int d_idx = 0; d_idx < num_vertices; ++d_idx) {
                    int weight = src.edges[d_idx];
                    if (weight == INT_MAX) {
                        continue;
                    }

                    vertex.min_distances[d_idx] = min(vertex.min_distances[d_idx], mid_dist + weight);
                }
            }
        }
    }
}

void queries() {
    for (int nq = 0; nq < num_queries; ++nq) {
        int src, dst;
        cin >> src >> dst;
        int min_dist = vertices[src].min_distances[dst];

        string output;
        if (min_dist == INT_MAX) {
            output = "Impossible";
        } else if (min_dist < 0) {
            output = "-Infinity";
        } else {
            output = to_string(min_dist);
        }

        cout << output << endl;
    }
    cout << endl;
}