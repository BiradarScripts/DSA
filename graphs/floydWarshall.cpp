#include<iostream>
#include<vector>

using namespace std;

void shortestDistance(vector<vector<int>>&matrix,int n){
    int n=matrix.size(); 
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {0, 5, 1000, -1},
        {1000, 0, 3, 1000},
        {1000, 1000, 0, -1},
        {1000, 1000, 1000, 0}
    };

    int n=matrix.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=1e9;
            }
            if(i==j){
                matrix[i][j]=0;
            }
        }
    }
    shortestDistance(matrix,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9){
                matrix[i][j]=-1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(matrix[i][i]<0){
            cout<<"Negative cycle detected"<<endl;
            return 0;
        }
    }

    return 0;
}