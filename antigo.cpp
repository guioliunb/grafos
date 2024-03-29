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
	    cout << "Maximal Clique--> ";
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

		void EveryDegreeCalculate(){
		int count = 0;
		for(int i = 1; i<=62 ; i++){
			cout << "VERTICE:" << i << " ";
			for(auto x : graph[i]){
				cout << x  << " ";
				count++;
			}
			
			cout << "tem o respectivo grau => " << count << endl;
			count = 0;
		}
		}

		int DegreeCalculate(int vertex){
		int count = 0;
		cout << "VERTICE:" << vertex << " ";
			for(auto x : graph[vertex])
				count++;
			cout << "tem o respectivo grau => " << count << endl << endl;

			return count;
		}
		int DegreeCalculate2(int vertex){
		int count = 0;
		cout << "VERTICE:" << vertex << " ";
			for(auto x : graph[vertex])
				count++;
			cout << "tem o respectivo grau => " << count << endl << endl;

			return count;
		}
		int linksCalculate(int vertex){
			int count = 0;
			for(int x = 0 ; x< (graph[vertex].size()) ; x++){
				for(int y = x+1; y< graph[vertex].size(); y++)
					{
					std::vector<int>::iterator it= find(graph[(graph[vertex][x])].begin(),graph[(graph[vertex][x])].end(),graph[vertex][y]);
					if (it != (graph[(graph[vertex][x])].end()) )
   				 count++;

					}
				}
				return count;
			}
			void clusteringCoefficient(){
				double sum = 0;
				for(int i=1; i<=62; i++){
				int degree = DegreeCalculate2(i);
				int links = linksCalculate(i);
				double d = (degree)*(degree-1);
				double cc = (2*links);
				if(d!=0)
				cc = cc/d;
				else
				cc=0;

				sum += cc;
				cout << "O Coeficiente de Aglomeração do vértice : " << i << " é " << cc << endl;
				}
				cout << endl;
				printf("O Coeficiente médio de Aglomeração do Grafo %.10lf \n",(sum/62));
			}
		

int main(int agrc, char * argv[]){

	 Grafo grafo(62);
	 grafo.create_graph();
	 vector<int> R,P,X;
	 initializeP(P);

	 int opcao;
	 int vertex;

	 while(1){
	 	cout << endl << "Por favor escolha a operação pra ser realizada no grafo" << endl;
	 	cout << "Digite o número de uma das opções" << endl;
	 	cout << "1 - O grau de um vértice especifico" << endl;
 		cout << "2 - O grau de todos os vértices" << endl;
	 	cout << "3 - Todos os cliques maximais" << endl;
	 	cout << "4 - Coeficiente de Aglomeração dos vértices e geral" << endl;
	 	cout << "5 - Encerrar o programa" << endl;
	 	cin >> opcao ;
		system("clear");
	 	if(opcao == 1){
	 		cout << "Por favor informe o vértice desejado"  << endl;
	 		cin >> vertex ;
	 		DegreeCalculate(vertex);

	 	}
	 	else if(opcao == 2){
	 		EveryDegreeCalculate();
	 	}
	 	else if(opcao == 3){
	 		BronKerbosch(R,P,X, graph);
	 	}
	 	else if(opcao == 4){
	 		clusteringCoefficient();
	 			
	 	}
	 	else if(opcao == 5){
	 		return 0;
	 		
	 	}
	 	else{
	 		cout << "Por favor digite uma opção válida"<<endl;
	 	}

	 }
	 //linksCalculate(1);
	 //clusteringCoefficient();
	 //BronKerbosch(R,P,X, graph);
	 //calcular grau
	 //EveryDegreeCalculate();
	 //maximal cliques

	//int cust = beautiful_code.dijkstra(0,5);

	return 0;
}