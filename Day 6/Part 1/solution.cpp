#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll helper( vector<string> &items , int col , int rows , int cols ){
    if( items[ (rows-1)*cols + col ] == "+" ){
        ll ans = 0 ; 
        for( int i=0 ; i<rows-1 ; ++i ){
            ans += stoll( items[ i*cols + col ] ) ; 
        }
        return ans ; 
    }else {
        ll ans = 1 ; 
        for( int i=0 ; i<rows-1 ; ++i ){
            ans *= stoll( items[ i*cols + col ] ) ; 
        }
        return ans ; 
    }
}

void solve(){
    vector<string> items ; 
    string temp ; 
    while( cin >> temp ){
        items.push_back( temp ) ; 
    }
    
    int n = items.size() ; 

    int ops = 0 ; 
    for( string item : items ){
        if( item == "+" || item == "*" ){
            ops++ ; 
        }
    }

    int cols = ops ; 
    int rows = n / cols ;     

    ll ans = 0 ; 
    for( int i=0 ; i<cols ; ++i ){
        ans += helper( items , i , rows , cols ) ; 
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