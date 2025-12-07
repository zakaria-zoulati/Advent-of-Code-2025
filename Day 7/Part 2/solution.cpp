#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void update( vector<string> &grid , vector<vector<ll>> &dp , int n , int m ){
    for( int i=0 ; i<m ; ++i ){
        dp[n-1][i] = 1 ;
    }

    for( int i=n-2 ; i>=0 ; --i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == '^' ){
                dp[i][j] = dp[i+1][j-1] + dp[i+1][j+1] ; 
            }else  {
                dp[i][j] = dp[i+1][j] ; 
            }
        }
    }

}

void solve(){
    vector<string> grid ; 
    string temp ; 
    while( cin >> temp ){
        grid.push_back( temp ) ; 
    }

    int n = grid.size() ; 
    int m = grid[0].size() ; 

    vector<vector<ll>> dp( n , vector<ll>( m , 0 ) )  ;    

    update( grid , dp , n  , m  ) ; 

    for( int i=0 ; i<m ; ++i ){
        if( grid[0][i] == 'S' ){
            cout << dp[0][i] << '\n' ; 
            return  ; 
        }
    }
}
int main() {
    freopen( "input.txt" , "r" , stdin ) ;  
    int t = 1 ; 
    while(t--){
        solve();
    }
    return 0;
}