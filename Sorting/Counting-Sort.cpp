#include <bits/stdc++.h>

using namespace std;

vector<int> cnt(1000001); 

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    for(int i = 0;i < n;++i){
        cnt[v[i]]++;
    }
    for(int i = 0;i <= 1000001;++i){
        if(cnt[i]){
           while(cnt[i]){
            cout << i << " ";
            --cnt[i]; 
           
            }
        }
    }
    return 0;
}
