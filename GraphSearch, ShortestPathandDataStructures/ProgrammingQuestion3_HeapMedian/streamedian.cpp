#include<bits/stdc++.h>
using namespace std;
int main(){
	FILE *file = freopen("input.txt", "r", stdin);
	//ifstream file("input.txt");
	int n;
	//string str;
	priority_queue < int > lefthalf;
	priority_queue < int, vector < int >,  greater<int> > righthalf;
	long long int result=0, median=0;
	while(scanf("%d", &n)>0){
		//file >> str;
		//n=stoi(str);
		if(lefthalf.size()==righthalf.size()){
			if(n>median){
				righthalf.push(n);
				median=righthalf.top();
			}else{
				lefthalf.push(n);
				median=lefthalf.top();
			}
		}else if(lefthalf.size()>righthalf.size()){
			if(n>median){
				righthalf.push(n);

			}else{
				righthalf.push(lefthalf.top());
				lefthalf.pop();
				lefthalf.push(n);
			}
			median=lefthalf.top();
		}else{
			if(n>median){
				lefthalf.push(righthalf.top());
				righthalf.pop();
				righthalf.push(n);
			}else{
				lefthalf.push(n);
			}
			median=lefthalf.top();
		}
		result=result+median;
	}
	ofstream output("output.txt");
	cout << result%10000 << "\n";
	output << result%10000 << "\n";
	return 0;
}
