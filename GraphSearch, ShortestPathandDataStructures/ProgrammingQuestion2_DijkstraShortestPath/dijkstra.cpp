#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector < pair < int, int > > graph[]){
	priority_queue < pair < int, int > > pq;
	pq.push({0, 1});
	int distance[201];
	for(int i=0; i<=200; i++){
		distance[i]=1000000;
	}
	distance[1]=0;
	while(!pq.empty()){
		pair < int, int > src = pq.top();
		pq.pop();
		int currdist = src.first;
		int head = src.second;
		for(int i=0; i<graph[head].size(); i++){
			int node = graph[head][i].first;
			int dist = graph[head][i].second;
			if(distance[node]>currdist+dist){
				pq.push({currdist+dist, node});
				distance[node]=currdist+dist;
			}
		}
	}
	cout << "See the output file for results\n";
	ofstream output("OutputDijkstra.txt");
	output << "Shortest Distance to all nodes from Source Node '1'\n";
	for(int i=1; i<=200; i++){
		output << distance[i] << ", ";
	}
	output << "\n";
	output << "Result of given nodes\n";
	int array[10]={7,37,59,82,99,115,133,165,188,197};
	for(int i=0; i<10; i++){
		output << distance[array[i]] << ", ";
	}
	output << "\n";
	output.close();
}
int main(){
	int src, dest, dist;
	vector < pair < int, int > > graph[201];
	ifstream input("input.txt");
	string str;
	while(getline(input, str)){
		string temp="";
		int i=0;
		while(str[i]!='\t'){
			temp+=str[i++];
		}
		src=stoi(temp);
		for(;i<str.length(); i++){
			if(str[i]=='\t')
				continue;
			temp="";
			while(str[i]!=','){
				temp+=str[i++];
			}
			dest=stoi(temp);
			temp="";
			i++;
			while(str[i]!='\t'){
				temp+=str[i++];
			}
			dist=stoi(temp);
			graph[src].push_back({dest, dist});
		}
	}
	input.close();
	dijkstra(graph);
	/*for(int i=1; i<=200; i++){
		cout << i << ": ";
		for(int j=0; j<graph[i].size(); j++){
			cout << graph[i][j].first << " ";//<< graph[i][j].second << " ";
		}
		cout << "\n";
	}*/
	return 0;
}
