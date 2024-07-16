#include<iostream>
#include<vector>

using namespace std;

int check(vector<int>count,int num,int min,int max){
    int low=min;
    int high=max;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid==num){
            return count[mid-min];
        }
        else if(mid>num){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;

    // Find min and max of arr
    int min = arr[0];
    int max = arr[0];
    for(int j = 1; j < n; j++) {
        if(arr[j] < min) {
            min = arr[j];
        }
        if(arr[j] > max) {
            max = arr[j];
        }
    }
    
    vector<int> count(max - min + 1, 0);
    
    // Count occurrences of each element
    for(int j = 0; j < n; j++) {
        count[arr[j] - min]++;
    }
    
    // Compute cumulative count
    for(int j = 1; j < count.size(); j++) {
        count[j] += count[j - 1];
    }
    
    for(int i = 0; i < q; i++) {
        long long a;
        cin >> a;
        if(a<min){
            cout<<0<<endl;
        }else if(a>max){
            cout<<n<<endl;
        }
        else{
             cout << check(count, a, min, max) << endl;
        }
    }

    return 0;
}
