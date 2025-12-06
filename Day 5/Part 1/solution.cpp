#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

void update_ranges( vector<pair<ll,ll>> &pairs , string &s ){
    ll a = 0 ; 
    ll b = 0 ; 
    int i=0 ; 
    for(  ; i<s.size() ; ++i ){
        if( s[i] == '-' ) {
            i++ ; 
            break ; 
        }
        a = a*10 + ( s[i] - '0' ) ; 
    }
    for( ; i<s.size() ; ++i ){
        b = b*10 + ( s[i] - '0' ) ;
    }
    pairs.push_back( {a,b} ) ; 
}

bool check( vector<pair<ll,ll>> &ranges , ll id ){
    int l=0 ; 
    int r=ranges.size()-1 ; 
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        if( id >= ranges[mid].first && id <= ranges[mid].second ){
            return true ; 
        }else if( id < ranges[mid].first ){
            r = mid - 1 ; 
        }else {
            l = mid + 1 ; 
        }
    }
    return id >= ranges[l].first && id <= ranges[l].second ; 
}

void solve(){
   vector<pair<ll,ll>> ranges ; 
   string temp ; 
    while( getline(cin,temp) ){
        if( temp.empty() ) break ; 
        update_ranges( ranges , temp ) ; 
    }
    sort( all(ranges) ) ; 
    vector<ll> ids ; 
    while( cin >> temp ){
        ll id = stoll( temp ) ; 
        ids.push_back( id ) ; 
    }

    vector<pair<ll,ll>> merged_ranges ; 
    for( int i=0 ; i<ranges.size() ; ++i ){
        ll start = ranges[i].first ; 
        ll end = ranges[i].second ; 
        while( i+1<ranges.size() && ranges[i+1].first <= end ){
            end = max( end , ranges[i+1].second ) ; 
            i++ ; 
        }
        merged_ranges.push_back( { start , end } ) ; 
    }

    ll ans = 0 ; 

    for( ll id : ids ){
        if( check( merged_ranges , id ) ){
            ans++ ; 
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