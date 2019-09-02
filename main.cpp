#include "graph.h"
	 int opcao;
	 int vertex;
	 vector<int> R,P,X;
 	 Grafo grafo(62);

int main(int agrc, char * argv[]){


	 grafo.create_graph();
	 initializeP(P);

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
	 		callMaximal(R,P,X);
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

	return 0;
}