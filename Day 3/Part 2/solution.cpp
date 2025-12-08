#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

int check( string &s , int idx , char c ){
    for( int i=idx ; i<s.size() ; ++i ){
        if( s[i] == c ){
            return i ; 
        }
    }
    return s.size() ; 
}

ll helper( string &s ){
    int n = s.size() ; 
    vector<char> digits( 12 ) ; 
    
    int idx = -1 ; 
    for( int i=0 ; i<12 ; ++i ){
        for( char c = '9' ; c >= '0' ; c-- ){
            int first = check( s , idx+1 , c ) ; 
            int rem = 12 - i - 1 ; 
            if( first < n-rem ){
                digits[i] = c ;
                idx = first ; 
                break ; 
            } 
        }
    }

    
    ll ans = 0 ; 
    for( int digit : digits ){
        ans = ans * 10 + (digit - '0' ) ; 
    }
    return ans ; 
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