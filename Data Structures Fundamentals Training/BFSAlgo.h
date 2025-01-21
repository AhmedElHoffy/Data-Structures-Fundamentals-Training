#ifndef BFSALGO_H
#define BFSALGO_H

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<class DataType>

void AddEdge_Vector(vector<vector<DataType>>& AdjacentVertices, DataType Vertex_1, DataType Vertex_2) {
	if (Vertex_1 >= AdjacentVertices.size() || Vertex_2 >= AdjacentVertices.size()) {
		cout << "Error: Vertex index out of bounds!\n";
		return;
	}
	AdjacentVertices[Vertex_1].push_back(Vertex_2);
	AdjacentVertices[Vertex_2].push_back(Vertex_1); // Un_Directed Graph
}

template<class DataType>
void BFS_Vector(vector<vector<DataType>>& AdjacentVertices, DataType StartVertex) {
	if (StartVertex >= AdjacentVertices.size()) {
		cout << "Error: Start vertex out of bounds!\n";
		return;
	}
	queue<DataType> QueueBFS;
	vector<bool> Visited_Vertices(AdjacentVertices.size(), false);

	//initially push start vertex;
	Visited_Vertices[StartVertex] = true;
	QueueBFS.push(StartVertex);

	while (!QueueBFS.empty()) {

		// Dequeue vurr vertex at the front of the queue and print it
		DataType Curr_Vertex = QueueBFS.front();
		QueueBFS.pop();
		cout << Curr_Vertex << " ";
		for (int i = 0; i < AdjacentVertices[Curr_Vertex].size(); i++) {
			DataType temp = AdjacentVertices[Curr_Vertex][i];
			if (!Visited_Vertices[temp]) {
				Visited_Vertices[temp] = true;
				QueueBFS.push(temp);
			}
		}
	}
	cout << endl;

}



// function overloading for using characters instead of integers as the Chat2Index & Index2Char Functions are needed for using the ASCII code
template<class DataType>
void BFS_Vector(vector<vector<DataType>>& AdjacentVertices, DataType StartVertex, map<int, char>& indexToChar) {
	queue<DataType> QueueBFS;
	vector<bool> Visited_Vertices(AdjacentVertices.size(), false);

	// Initially push the start vertex
	Visited_Vertices[StartVertex] = true;
	QueueBFS.push(StartVertex);

	while (!QueueBFS.empty()) {
		// Dequeue the current vertex
		DataType Curr_Vertex = QueueBFS.front();
		QueueBFS.pop();

		// Print the character corresponding to the index
		cout << indexToChar[Curr_Vertex] << " ";

		// Explore all adjacent vertices
		for (int i = 0; i < AdjacentVertices[Curr_Vertex].size(); i++) {
			int temp = AdjacentVertices[Curr_Vertex][i];
			if (!Visited_Vertices[temp]) {
				Visited_Vertices[temp] = true;
				QueueBFS.push(temp);
			}
		}
	}
	cout << endl;
}

#endif  //BFSALGO_H
