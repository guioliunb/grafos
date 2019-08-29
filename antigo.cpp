#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define infinite 5000000

vector<vector<int>> graph(63);
list<vector<int>> result_cliques;

class Grafo{
	private:
		int v = 0;


	public:
		Grafo(int v){
			this->v = v;
			}

		int program_error()
		{
			exit(1);
		}
		void addEdge(int v1, int v2){
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		void insertNodes(std::vector<std::string> &out){
			int aux = 1; 
			int num1, num2 = num1 = 0;
		  std::string::size_type sz;
			for(auto w : out)
			{
				//num2 = vertice num1 = adjacencia
				if(aux % 2 == 0){
					num2 = std::stoi (w,&sz);
					addEdge(num2, num1);
					addEdge(num1, num2);
				}
				else{
					num1 = std::stoi (w,&sz);
				}
			 aux++;
			}
		}

		void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out)
		{
			size_t start;
			size_t end = 0;

			while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
			{
				end = str.find(delim, start);
				// .substr(posicao, tamanho)
				out.push_back(str.substr(start, end - start));
			}
		}
		void create_graph(){
			string line;
			const char delim = ' ';
			std::vector<std::string> out;
			
			ifstream myfile ("golfinho.txt"); // ifstream = padrão ios:in
			if (myfile.is_open())
			{
			while (! myfile.eof() ) //enquanto end of file for false continua
			{
				getline (myfile,line); // como foi aberto em modo texto(padrão)
			                         //e não binário(ios::bin) pega cada linha
			  tokenize(line, delim, out);
			}
			insertNodes(out);
			myfile.close();
			}

			else{ 
				cout << "Unable to open file"; 
				program_error();
			}
		}
	};

		void initializeP(vector<int>& P){
			for(int i=1;i<=62;i++)
				P.push_back(i);
		}

		vector<int> intersection(vector<int> v1, vector<int> v2){
    vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}


		void BronKerbosch(vector<int> R, vector<int> P, vector<int> X, vector<vector<int>>& graph){
	  if (P.empty() && X.empty()){
	    result_cliques.insert(result_cliques.begin(), R);
	    for(auto x: R)
	    	cout << x << " ";
	    cout << endl;
	  }

	  for (auto node = P.begin(); node != P.end();){
	    auto R_with_node = R;

	    R_with_node.push_back(*node);
	    BronKerbosch(R_with_node, intersection(P, graph[*node]), intersection(X, graph[*node]), graph);
	    X.push_back(*node);
	    node = P.erase(node);
	  }
	}


int main(int agrc, char * argv[]){

	 Grafo grafo(62);
	 grafo.create_graph();
	 vector<int> R,P,X;
	 initializeP(P);
	 BronKerbosch(R,P,X, graph);

	//int cust = beautiful_code.dijkstra(0,5);

	return 0;
}