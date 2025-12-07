#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void update( vector<string> &grid , int n , int m ){
    for( int i=0 ; i+1<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == 'S' || grid[i][j] == '|' ){
                if( grid[i+1][j] == '.' ){
                    grid[i+1][j] = '|' ; 
                }else if( grid[i+1][j] == '^' ) {
                    grid[i+1][j] = 'X' ; 
                }
            }else if( grid[i][j] == 'X'  ){
                if( j > 0 ){
                    grid[i+1][j-1] = '|' ; 
                }
                if( j +1 < m ){
                    grid[i+1][j+1] = '|' ; 
                }
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

    cout << n << " " << m << '\n' ; 

    update( grid , n  , m  ) ; 

    ll ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == 'X'  ){
                ans++ ; 
            }
        }
    }

    cout << ans << '\n' ; 
}
int main() {
    freopen( "input.txt" , "r" , stdin ) ;  
    int t = 1 ; 
    while(t--){
        solve();
    }
    return 0;
}