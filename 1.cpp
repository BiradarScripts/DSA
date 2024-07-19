#include<iostream>
#include<vector>

using namespace std;

void isCheck(vector<int>arr,vector<int>darr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==0 && darr[i]==1){
            cout<<"NO"<<endl;
            return;
        }
        else if(arr[i]==0 && darr[i]==0){
            continue;
        }
        else{
            break;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        vector<int>arr(n);
        vector<int>darr(n);
        for(int i=0;i<n;i++){
            arr[i] = s[i] - '0';
            darr[i] = t[i] - '0';
        }
        
        isCheck(arr,darr,n);

    }
}