#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char *argv[]){
	if(argc<4){
		cout << "Please provide the all input files through command line argument\n";
		return 0;
	}
	while(true){
		cout << "Find Shortest-pair in\n";
		cout << "1. g1.txt\n";
		cout << "2. g2.txt\n";
		cout << "3. g3.txt\n";
		cout << "4. Press 4 to exit\n";
		int choice;
		cin >> choice;
		string str;
		switch(choice){
			case 1:
				str = argv[1];
				break;
			case 2:
				str = argv[2];
				break;
			case 3:
				str = argv[3];
				break;
			default:
				exit(0);
		}
		ifstream file(str);
		int nodes, edges;
		file >> nodes >> edges;
		ll graph[nodes+1][nodes+1];
		for(int i=0; i<=nodes; i++){
			for(int j=0; j<=nodes; j++){
				graph[i][j]=INT_MAX;
			}
		}
		int u, v, wt;
		while(!file.eof()){
			file >> u >> v >> wt;
			graph[u][v]=wt;
		}
		ll result=INT_MAX;
		for(int k=1; k<=nodes; k++){
			for(int i=1; i<=nodes; i++){
				for(int j=1; j<=nodes; j++){
					if(graph[i][j]>graph[i][k]+graph[k][j]){
						graph[i][j]=graph[i][k]+graph[k][j];
						result = min(result, graph[i][j]);
					}
				}
			}
		}
		if(graph[1][1]<0){
			cout << "Graph Contains Negative Cycle\n";
		}
		cout << result << "\n";
	}
	return 0;
}
