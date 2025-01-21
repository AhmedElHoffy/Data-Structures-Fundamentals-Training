#ifndef DFSALGO_H
#define DFSALGO_H

#include<iostream>
using namespace std;
#include<stack>
#include<vector>


template<class DataType>
void AddEdge_VectorDFS(vector<vector<DataType>>& AdjacentVertices, DataType Vertex_1, DataType Vertex_2) {
	if (Vertex_1 >= AdjacentVertices.size() || Vertex_2 >= AdjacentVertices.size()) {
		cout << "Error: Vertex index out of bounds!\n";
		return;
	}
	AdjacentVertices[Vertex_1].push_back(Vertex_2);
	AdjacentVertices[Vertex_2].push_back(Vertex_1); // Un_Directed Graph
}


template<class DataType>
void DFS_Recursive(vector<vector<int>>& Adjacent_vertices, vector<bool> &Visited_Vertices, DataType Curr_Vertex) {
	Visited_Vertices[Curr_Vertex] = true;

	//Print the current Vertex
	cout << Curr_Vertex << " ";


	//Recursively visit all the adjacent vertices that are not yet visited
	for (int i = 0; i < Adjacent_vertices[Curr_Vertex].size(); i++) {
		DataType temp = Adjacent_vertices[Curr_Vertex][i];
		if (Visited_Vertices[temp] == false) {
			DFS_Recursive(Adjacent_vertices, Visited_Vertices, temp);
		}
	}
}
template<class DataType>

void DFS_Vector(vector<vector<DataType>> &Adjacent_vertices, DataType StartVertex) {
	
	if (StartVertex >= Adjacent_vertices.size()) {
		cout << "Error: Start vertex out of bounds!\n";
		return;
	}

	vector<bool> Visited_Vertices(Adjacent_vertices.size(), false);

	DFS_Recursive(Adjacent_vertices, Visited_Vertices, StartVertex);

}



#endif //DFSALGO_H