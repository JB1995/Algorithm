#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	FILE *file = freopen("input.txt", "r", stdin);
	ll  num, res=0;
	map < ll, ll > mp;
	while(scanf("%lld", &num)>0){
		mp[num]=1;
	}
	set < ll > s;
	for(auto it=mp.begin(); it!=mp.end(); it++){
		for(int i=-10000; i<=10000; i++){
			int j=i-(it->first);
			if(i!=j && mp[j]){
				s.insert(i);
			}
		}
		cout << s.size() << "\n";
	}
	ofstream output("output.txt");
	output << s.size() << "\n";
	cout << s.size() << "\n";
	return 0;
}
