#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;



void solve(){
    ll curr = 50  ; 
    string command ;
    ll ans = 0 ;  
    while( cin >> command ){
        ll num = stoll( command.substr(1) ) ;
        if( command[0] == 'L' ){
            int cost = ( curr == 0 ? 100 : curr ) ; 
            if( num >= cost ){
                ans++ ; 
                num -= cost ; 
                curr = (( -num % 100 ) + 100) % 100 ; 
                ans += num / 100 ; 
            }else {
                curr = ( curr - num + 100 ) % 100 ; 
            }
        }else{
            int next = ( curr + num ) % 100 ; 
            int rest  = 100 - curr ; 
            if( num >= rest ) {
                ans++ ; 
                num -= rest ; 
                ans += num / 100 ; 
            }
            curr = next ; 
        }
    }
    cout << ans << '\n' ; 
}


int main() {

    freopen( "input.txt" , "r" , stdin  ) ; 

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}