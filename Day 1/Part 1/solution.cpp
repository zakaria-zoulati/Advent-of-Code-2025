#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;



void solve(){
    int curr = 50  ; 
    string command ;
    int ans = 0 ;  
    while( cin >> command ){
        int num = stoi( command.substr(1) ) ; 
        if( command[0] == 'L' ){
            curr = ( curr - num + 100 ) % 100 ; 
        }else{
            curr = ( curr + num + 100  ) % 100 ; 
        }
        if( curr == 0 ){
            ans++ ; 
        }
    }
    cout << ans << '\n' ; 
}


int main() {

    freopen( "input.txt" , "r" , stdin  ) ; 

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}