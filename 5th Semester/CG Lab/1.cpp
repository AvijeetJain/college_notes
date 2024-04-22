#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

pair<vector<float>, vector<int>> sphereToMesh(int numVertices, int numFaces, float radius) {
    float angleBetweenVertices = 2 * M_PI / numVertices;
    vector<float> vertices;
    vector<int> faces;

    for (int i = 0; i < numVertices; i++) {
        float x = radius * sin(angleBetweenVertices * i);
        float y = radius * cos(angleBetweenVertices * i);
        float z = 0;
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
    }

    for (int i = 0; i < numFaces; i++) {
        int vertexIndex1 = i % numVertices;
        int vertexIndex2 = (i + 1) % numVertices;
        int vertexIndex3 = (i + numVertices / 2) % numVertices;
        faces.push_back(vertexIndex1);
        faces.push_back(vertexIndex2);
        faces.push_back(vertexIndex3);
    }

    return make_pair(vertices, faces);
}

