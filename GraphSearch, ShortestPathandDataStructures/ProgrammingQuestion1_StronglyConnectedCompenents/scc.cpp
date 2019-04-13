#include<bits/stdc++.h>
using namespace std;
vector < int > visited;
stack < int > finished;
int ct;
void dfs(vector < vector < int > > &graph, int u, int state){
	visited[u]=1;
	ct++;
	for(int i=0; i<graph[u].size(); i++){
		int v = graph[u][i];
		if(!visited[v]){
			dfs(graph, v, state);
		}
	}
	if(!state){
		finished.push(u);
	}
}

int main(){
	int nodes=875715;
	vector < vector < int > > graph;
	vector < vector < int > > reverseGraph;
	ifstream input;
	input.open("scc.txt");

	graph.resize(nodes);
	reverseGraph.resize(nodes);
	visited.resize(nodes);
	int u, v;
	while(!input.eof()){
		input >> u >> v;
		graph[u].push_back(v);
		reverseGraph[v].push_back(u);
	}
	input.close();
	for(int i=0; i<nodes; i++){
		visited[i]=0;
	}
	for(int i=0; i<nodes; i++){
		if(!visited[i]){
			dfs(reverseGraph, i, 0);
		}
	}
	for(int i=0; i<nodes; i++){
		visited[i]=0;
	}
	vector < int > result;
	while(!finished.empty()){
		int u=finished.top();
		finished.pop();
		if(!visited[u]){
			ct=0;
			dfs(graph, u, 1);
			result.push_back(ct);
		}
	}
	sort(result.begin(), result.end(), greater<int>());
	ofstream output;
	output.open("outputSCC.txt");
	for(int i=0; i<result.size(); i++){
		cout << result[i] << " ";
		output << result[i] << " ";
	}
	output.close();
	cout << "\n";
	return 0;
}
