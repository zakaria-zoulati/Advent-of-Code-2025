#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int> ; 
using vvi = vector<vi> ; 

vvi parser( vector<string> &moves ){
    vvi ans ; 
    for( string m : moves ){
        vector<int> curr ; 
        int num = 0 ; 
        for( int i=1 ; i<m.size() ; ++i ){
            if(m[i] == ',' || m[i] == ')' ){
                curr.push_back(num) ;
                num = 0 ;
            }else {
                num = num*10 + ( m[i] - '0' ) ; 
            }
        }
        ans.push_back(curr) ; 
    }   
    return ans ; 
}

int getBits( int n ){
    int ans = 0 ; 
    while( n > 0 ){
        ans++ ; 
        n &= n-1 ; 
    }
    return ans ; 
}

void apply( string &s , vector<int> &moves ){
    for( int pos : moves ){
        s[pos] = (s[pos] == '.' ? '#' : '.' ) ; 
    }
}

void solve(){
    string config ; 
    int ans = 0 ; 
    while( cin >> config ){
        config = config.substr( 1 , config.size() - 2 ) ; 
        vector<string> moves ; 
        string curr ; 
        while( cin >> curr ){
            if( curr[0] == '(' ){
                moves.push_back( curr ) ; 
            }else {
                break ; 
            }
        }

        vvi parsedMoves = parser( moves ) ; 
        int len = parsedMoves.size() ; 
        
        int can = len ; 
        string currState( config.size() , '.' ) ; 

        for( int i=0 ; i<(1<<len) ; ++i ){
            for( int j=0 ; j<len ; ++j ){
                if( ( i & (1<<j) ) != 0 ){
                    apply( currState , parsedMoves[j] ) ; 
                }
            }


            if( currState == config ){
                can = min( can , getBits( i )) ; 
            }

            for( int j=0 ; j<len ; ++j ){
                if( ( i & (1<<j) ) != 0 ){
                    apply( currState , parsedMoves[j] ) ; 
                }
            }
        }

        ans += can ; 
    }
    cout << ans << '\n' ; 
}

int main() {
    freopen( "input.txt" , "r" , stdin ) ;
    freopen( "out.txt" , "w" , stdout ) ;


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}