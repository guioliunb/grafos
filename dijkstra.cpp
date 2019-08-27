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

		//adjacency list pointer
		list<pair<int ,int>> * adj ;

	public:
		Grafo(int v){
			this->v = v;

			adj = new list<pair < int , int >>[v];
		}

		void addAresta(int v1, int v2, int custo){
			adj[v1].push_back(make_pair(v2, custo));
		}
	int dijkstra(int src, int dest){
		int dist[v];
		int visits[v];
		int antecedent[v];

		//construtor para definir a queue do menor para o maior(inversao)
		priority_queue < pair<int, int>, vector< pair<int, int>>, greater<pair<int , int > > > pq;

		//vectors initialize
		for(int i=0; i<v; i++){
			dist[i] = infinite;
			visits[i] = false;
			antecedent[i] = -1;
		}

		dist[src] = 0 ;

		pq.push(make_pair(dist[src], src));

		//the magic is here
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			//p. queue <peso, vertice>
			//adj <vertice, peso>
			//prestar atencao nisso!!!
			int u = p.second;

			pq.pop();

			if(visits[u]== false){
				visits[u] = true;

				for(auto it = adj[u].begin(); it!= adj[u].end(); it++){
					int v = it->first;
					int weight = it->second;

					//relaxing step
					if(dist[v] > dist[u] + weight){
						// A* = g(n) + h(n)
						//g(n) = dist[u] + weight
						dist[v] = dist[u] + weight;
						pq.push(make_pair(dist[v], v));
						antecedent[v]= u;
					}
				}

			}
		}

			/*for(int i = 1 ; i< v ; i++)
				cout << antecedent[i] ;
			cout << endl;*/
		int dest1 = dest;
		int aux;
		cout << "Dest ";	
		while(dest1 != 0){
			aux = antecedent[dest1];
			cout << "-" <<antecedent[dest1] << "-";
			dest1 = aux;
		}
		cout << "<-<- THE PATH IS" << endl;
		return dist[dest];
	}
};

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
		cout << str.substr(start, end - start) << " ";
	}
}

int main(int agrc, char * argv[]){

	  string line;
		const char delim = ' ';
		std::vector<std::string> out;
		

		for (auto &s: out) {
			std::cout << s << '\n';
		}
	  ifstream myfile ("golfinho.txt"); // ifstream = padrão ios:in
	  if (myfile.is_open())
	  {
	  	int i = 1;
	    while (! myfile.eof() ) //enquanto end of file for false continua
	    {
	      getline (myfile,line); // como foi aberto em modo texto(padrão)
	                             //e não binário(ios::bin) pega cada linha
	      if(i>36){
		      tokenize(line, delim, out);
				}
					i++;
	      //cout << line << endl;
	    }
	    /*for (auto &s: out) {
						std::cout << s << ' ';
					}*/
	    myfile.close();
	  }

  else cout << "Unable to open file"; 

	Grafo beautiful_code(6);

	beautiful_code.addAresta(0,1,4);
	beautiful_code.addAresta(0,2,2);
	beautiful_code.addAresta(1,3,5);
	beautiful_code.addAresta(2,1,1);
	beautiful_code.addAresta(2,3,8);
	beautiful_code.addAresta(2,4,10);	
	beautiful_code.addAresta(3,5,6);
	beautiful_code.addAresta(3,4,2);
	beautiful_code.addAresta(4,5,3);

	int cust = beautiful_code.dijkstra(0,5);
	cout << "The cust to reach that place is :" << cust << endl;


	return 0;
}