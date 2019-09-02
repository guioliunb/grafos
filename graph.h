#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define infinite 5000000

class Grafo{
	private:
		int v = 0;


	public:
		Grafo(int v);

		vector<vector<int>> *getGraph();

		int program_error();

		void addEdge(int v1, int v2);

		void insertNodes(std::vector<std::string> &out);

		void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out);

		void create_graph();

		void BronKerbosch(vector<int> R, vector<int> P, vector<int> X, vector<vector<int>>& graph);
	};
		void callMaximal(vector<int> R, vector<int> P, vector<int> X);
		
		void initializeP(vector<int>& P);

		vector<int> intersection(vector<int> v1, vector<int> v2);

		void EveryDegreeCalculate();

		int DegreeCalculate(int vertex);

		int DegreeCalculate2(int vertex);

		int linksCalculate(int vertex);

		void clusteringCoefficient();
		
#endif