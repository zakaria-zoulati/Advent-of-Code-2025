#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

const int dx[] = {  0,0,-1,1,-1,1,1,-1 } ; 
const int dy[] = {  -1,1,0,0,1,-1,1,-1 } ; 

void solve(){
    vector<string> grid ; 
    string curr = "" ; 
    while( cin >> curr ){
        grid.push_back( curr ) ;  
    }

    int n = grid.size() ; 
    int m = grid[0].size() ; 

    cout << n << " " << m << '\n' ; 

    vector<vector<int>> count( n , vector<int>( m , 0 ) ) ; 

    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == '@' ){
                for( int k=0 ; k<8 ; ++k ){
                    int new_x = i + dx[k] ; 
                    int new_y = j + dy[k] ;
                    if( new_x>=0 && new_y>=0 && new_x<n && new_y<m && grid[new_x][new_y] == '@' ){
                        count[i][j]++ ; 
                    } 
                }
            }
        }
    }

    int ans = 0 ; 

    queue<pair<int,int>> q ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == '@' && count[i][j] < 4 ){
                q.push( { i , j } ) ; 
                grid[i][j] = '.' ; 
                ans++ ; 
            }
        }
    }

    while( !q.empty() ){
        auto [x,y] = q.front() ;
        q.pop() ; 
        for( int i=0 ; i<8 ; ++i ){
            int new_x = x + dx[i] ; 
            int new_y = y + dy[i] ; 
            if( new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == '@' ){
                if( --count[new_x][new_y] < 4 ){
                    grid[new_x][new_y] = '.' ; 
                    ans++ ; 
                    q.push( {new_x , new_y} ) ;  
                }
            }
        }
    }

    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    freopen( "input.txt" , "r" , stdin ) ; 
    while(t--){
        solve();
    }
    return 0;
}