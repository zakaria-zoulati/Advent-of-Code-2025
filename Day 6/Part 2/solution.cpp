#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

ll helper( vector<string> &items , int ind1 , int ind2 , int lines ) {
    if( items[lines-1][ind1] == '+' ){
        ll ans = 0 ; 
        for( int j=ind2-2 ; j>=ind1 ; --j ){
            ll curr = 0 ; 
            for( int i=0 ; i<lines-1 ; ++i ){
                if( items[i][j] != ' ' ){ 
                    curr = curr*10 + ( items[i][j] - '0' ) ; 
                }
            }
            ans += curr ; 
        }
        return ans ; 
    }else {
        ll ans = 1 ; 
        for( int j=ind2-2 ; j>=ind1 ; --j ){
            ll curr = 0 ; 
            for( int i=0 ; i<lines-1 ; ++i ){
                if( items[i][j] != ' ' ){
                    curr = curr*10 + ( items[i][j] - '0' ) ; 
                }
            }
            ans *= curr ; 
        }
        return ans ; 
    }
}

void solve(){
    vector<string> items ; 
    string temp ; 
    while( getline( cin , temp ) ){
        items.push_back( temp ) ; 
    }

    int line = items[0].size() ; 
    int lines = items.size() ; 
    
    vector<int> ops ; 
    for( int i=0 ; i<line ; ++i ){
        if( items[lines-1][i] == '+' || items[lines-1][i] == '*' ){
            ops.push_back( i ) ; 
        }
    }
    ops.push_back( line + 1 ) ; 

    ll ans = 0 ; 

    for( int i=0 ; i+1<ops.size() ; ++i ){
        ans += helper( items , ops[i] , ops[i+1] , lines ) ; 
    }

    cout << ans << '\n';
}


int main() {

    freopen( "input.txt" , "r" , stdin ) ; 

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}