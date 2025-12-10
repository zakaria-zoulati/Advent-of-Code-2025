#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<ll,ll> ;

pi getPt( string &s ){
    ll a = 0;  
    ll b = 0 ; 
    bool fl = true ; 
    for( char c : s ){
        if( c == ','){
            fl = !fl ; 
        }else if( fl ){
            a = a*10 + ( c - '0' ) ; 
        }else {
            b = b*10 + ( c - '0' ) ; 
        }
    }
    return { a,b } ; 
}

ll getArea( pi &a , pi &b ){
    ll ans = (abs( a.first - b.first ) + 1) * ( abs( a.second - b.second ) + 1 )  ; 
    return ans ; 
}

void solve(){
    string temp = "" ; 
    vector<pi> pts ; 
    while( cin >> temp ){
        pts.push_back( getPt( temp ) ) ; 
    }
    
    int n = pts.size() ; 

    for( pi p : pts ){
        cout << p.first << " " << p.second << '\n' ; 
    }

    ll ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=i+1 ; j<n ; ++j ){
            ans = max( ans , getArea( pts[i] , pts[j] ) ) ; 
        }
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