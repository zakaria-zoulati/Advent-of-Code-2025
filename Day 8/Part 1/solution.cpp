#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using pt = tuple<ld,ld,ld> ; 

pt getTuple( string &s ){
    vector<ld> numbers ; 
    ld curr = 0; 
    for( char c : s ){
        if( c == ',' ){
            numbers.push_back( curr ) ; 
            curr = 0 ; 
        }else {
            curr = curr*10 + ( c - '0' ) ;  
        }
    }
    return { numbers[0] , numbers[1] , curr } ; 
}

ld getDist( pt &a , pt &b ){
    ld ans = pow(  get<0>(a) - get<0>(b) , 2 ) + pow(  get<1>(a) - get<1>(b) , 2 ) + pow(  get<2>(a) - get<2>(b) , 2 ) ; 
    ans = sqrt( ans ) ; 
    return ans ; 
}

int find( vector<int> &rep , int i ){
    if( rep[i] != i ){
        rep[i] = find( rep , rep[i] ) ;
    }
    return rep[i] ; 
}

void print( pt &p ){
    cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << '\n';    
}

bool merge( vector<int> &rep , int i , int j ){
    int r1 = find( rep , i ) ; 
    int r2 = find( rep , j ) ; 
    if( r1 == r2 ){
        return false ; 
    }
    if( r1 < r2 ){
        rep[r2] = r1 ; 
    }else {
        rep[r1] = r2 ; 
    }
    return true;
}

void solve(){
    vector<pt> pts ; 
    string temp ; 
    while( cin >> temp ){
        pts.push_back( getTuple( temp ) ) ; 
    }
    int n = pts.size() ; 
    cout << n << '\n' ; 
    
    vector<int> rep( n ) ; 
    for( int i=0 ;  i<n ; ++i ){
        rep[i] = i ; 
    }     

    vector<pt> distances ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=i+1 ; j<n ; ++j ){
            distances.push_back( { getDist( pts[i] , pts[j] ) , i , j } ) ; 
        }
    }

    sort( all( distances ) ) ; 

    for( int t=0 ; t<1000 ; ++t ){
        int i = get<1>( distances[t] ) ; 
        int j = get<2>( distances[t] ) ; 
        merge( rep , i , j ) ; 
    }

    vector<int> f( n , 0 ) ;

    for( int i=0 ; i<n ; ++i ){
        find( rep , i ) ; 
        f[ rep[i] ]++ ; 
    }

    sort( all(f) ) ; 
    ll ans = f[n-1]*f[n-2]*f[n-3] ; 
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