#include<iostream>
#include<vector>

using namespace std;

bool lemonade(vector<int>arr){
    int five=0;
    int ten=0;

    for(int i=0;i<;i++){
        if(arr[i]==5){
            five++;
        }
        else if(arr[i]==10){
            if(five==0){
                return false;
            }
            five--;
            ten++;
        }
        else{
            if(ten>0 && five>0){
                ten--;
                five--;
            }
            else if(five>=3){
                five-=3;
            }
            else{
                return false;
            }
        }
    }
}

int main(){
    vector<int>arr={5,5,5,10,20};
    cout<<lemonade(arr);
    return 0;
}