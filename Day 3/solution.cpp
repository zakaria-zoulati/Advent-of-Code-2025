#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll helper( string &s ){
    int n = s.size() ; 
    char a = s[n-2] ; 
    char b = s[n-1] ; 
    
    vector<char> pref( n ) ; 
    pref[n-1] = s[n-1] ; 
    for( int i=n-2 ; i>=0 ; --i ){
        pref[i] = max( pref[i+1] , s[i] ) ; 
    }

    for( int i=n-3 ; i>=0 ; --i ){
        if( s[i] >= a ){
            a = s[i] ; 
            b = pref[i+1] ; 
        }
    }
    return ( a - '0' )*10 + ( b - '0' ) ; 
}

void solve(){
    string curr ;
    ll ans = 0 ;  
    while( cin >> curr ){
        ans += helper( curr ) ;
    }
    cout << ans << '\n' ;
}


int main() {

    freopen( "input.txt" , "r" , stdin ) ; 

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}