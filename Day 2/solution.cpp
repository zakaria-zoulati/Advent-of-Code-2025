#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


bool isInvalid( ll n ){
    string s = to_string( n ) ; 
    int len = s.size() ; 
    if( len % 2 == 1 ) return false ; 
    for( int i=0 ; i<len/2 ; ++i ){
        if( s[i] != s[i+len/2] ){
            return false ; 
        }
    }
    return true ; 
}

vector<string> getItems( string &s , char sep ){
    vector<string> ans ; 
    string temp;
    for( char c : s ){
        if( c == sep ){
            ans.push_back( temp ) ; 
            temp.clear() ;  
        }else {
            temp += c ; 
        }
    }
    ans.push_back( temp ) ; 
    return ans ;
}


void solve(){
    string numbers ; 
    cin >> numbers ; 
    vector<string> intervals = getItems( numbers , ',' ) ; 
    int l = intervals.size() ; 
    
    ll ans = 0 ; 
    for( int i=0 ; i<l ; ++i ){
        vector<string> items = getItems( intervals[i] , '-' ) ; 
        ll a = stoll(items[0] ) ; 
        ll b = stoll(items[1] ) ; 
        for( ll i=a ; i<=b ; ++i ){
            if( isInvalid( i ) ){
                cout << i << '\n' ; 
                ans += i ; 
            }
        }
    }

    cout << ans << '\n' ;
}


int main() {
    int t = 1;

    freopen(  "input.txt" , "r" , stdin ) ;  

    while(t--){
        solve();
    }
    return 0;
}