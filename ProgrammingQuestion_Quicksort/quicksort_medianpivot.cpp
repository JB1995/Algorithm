#include<bits/stdc++.h>
using namespace std;
int getmedian(vector < int > &arr, int l, int r){
    int mid=l+(r-l)/2;
    if((arr[mid]>arr[l]&&arr[mid]<arr[r])||(arr[mid]>arr[r]&&arr[mid]<arr[l])){
        return mid;
    }else if((arr[l]>arr[mid]&&arr[l]<arr[r])||(arr[l]<arr[mid]&&arr[l]>arr[r])){
        return l;
    }
    return r;
}
int quicksort(vector < int > &arr, int l, int r){
    int med=getmedian(arr, l, r);
    swap(arr[med], arr[l]);
    int pivot = arr[l];
    int pindex=l+1;
    for(int i=l+1; i<=r; i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[l], arr[pindex-1]);
    return pindex-1;
}
long long partition(vector < int > &arr, int l, int r){
    if(l>=r){
        return 0;
    }
    long long count=0;
    int pindex=quicksort(arr, l, r);
    count+=partition(arr, l, pindex-1);
    count+=partition(arr, pindex+1, r);
    return count+(r-l);
}
int main(){
    ifstream file("quicksort_input.txt");
    int n=0;
    string str;
    vector < int > arr;
    while(getline(file, str)){
        arr.push_back(stoi(str));
        n++;
    }
    ofstream fp;
    fp.open("quicksort_medianpivot_output.txt");
    fp << partition(arr, 0, n-1);
    fp.close();
    return 0;
}