#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }

    vector<vector<int>>adj;

    for(int i=0;i<n-1;i++){
        string s1=words[i];
        string s2=words[i+1];
        int len=min(s1.size(),s2.size());
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }

    //do the toposort and return it
    
}