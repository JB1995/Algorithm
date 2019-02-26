#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll merge(vector<int> &arr, int l, int mid, int r){
    int i=l, j=mid+1;
    ll count=0;
    vector <int> temp;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }else{
            count+=(mid-i+1);
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=r){
        temp.push_back(arr[j++]);
    }
    for(int i=l; i<=r; i++){
        arr[i]=temp[i-l];
    }
    return count;
}
ll countinversion(vector<int> &arr, int l, int r){
    if(l>=r){
        return 0;
    }
    int mid=l+(r-l)/2;
    ll count=0;
    count=countinversion(arr, l, mid);
    count+=countinversion(arr, mid+1, r);
    count+=merge(arr, l, mid, r);
    return count;
}
int main(){
    ifstream file("countinversion_input.txt");
    int n=0;
    vector < int > arr;
    string str;
    while(getline(file, str)){
        arr.push_back(stoi(str));
        n++;
    }
    ofstream fp;
    fp.open("countinversion_output.txt");
    fp << countinversion(arr, 0, n-1) << "\n";
    fp.close();
    return 0;
}