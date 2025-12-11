#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<ll,ll> ;
using range = tuple<ll,ll,ll,ll> ; // r1 r2 c1 c2  

pi getPt( string &s ){
    ll a = 0;  
    ll b = 0 ; 
    bool fl = true ; 
    for( char c : s ){
        if( c == ','){
            fl = !fl ; 
        }else if( fl ){
            a = a*10 + ( c - '0' ) ; 
        }else {
            b = b*10 + ( c - '0' ) ; 
        }
    }
    return { a,b } ; 
}

ll getArea( pi &a , pi &b ){
    ll ans = (abs( a.first - b.first ) + 1) * ( abs( a.second - b.second ) + 1 )  ; 
    return ans ; 
}



bool isPossible( pi &a , pi &b , vector<range> &ranges  ){
    for( range r : ranges ){
        ll r1 = get<0>(r) ; 
        ll r2 = get<1>(r) ; 
        ll c1 = get<2>(r) ; 
        ll c2 = get<3>(r) ; 
        
        ll x1 = min( a.first , b.first ) ; 
        ll x2 = max( a.first , b.first ) ;
        ll y1 = min( a.second , b.second ) ; 
        ll y2 = max( a.second , b.second ) ; 


        if( x1 >= r2 || r1 >= x2 || y1 >= c2 || c1 >= y2 ){
            continue ; 
        }else {
            return false ; 
        }

    }

    return true ; 
}

void solve(){
    string temp = "" ; 
    vector<pi> pts ; 
    while( cin >> temp ){
        pts.push_back( getPt( temp ) ) ; 
    }

    int n = pts.size() ; 

    vector<range> ranges ; 

    sort( all(pts) ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( i+1<n && pts[i+1].first == pts[i].first  ){
            ll c1 = pts[i].second ; 
            ll c2 = pts[i+1].second ;
            if( c2 - c1 > 1 ){
                ranges.push_back( { pts[i].first , pts[i].first , c1 + 1 , c2 - 1 } ) ; 
            } 
        }
    }

    for( int i=0 ; i<n ; ++i ){
        swap( pts[i].first , pts[i].second ) ; 
    }

    sort( all(pts) ) ; 

    for( int i=0 ; i<n ; ++i ){
        if( i+1<n && pts[i+1].first == pts[i].first  ){
            ll r1 = pts[i].second ; 
            ll r2 = pts[i+1].second ;
            if( r2 - r1 > 1 ){
                ranges.push_back( { r1 + 1 , r2 - 1 , pts[i].first , pts[i].first } ) ; 
            } 
        }
    }

    

    for( int i=0 ; i<n ; ++i ){
        swap( pts[i].first , pts[i].second ) ; 
    }
    
    ll ans = 0 ;    

    for( int i=0 ; i<n ; ++i ){
        for( int j=i+1 ; j<n ; ++j ){
            if( isPossible( pts[i] , pts[j] , ranges ) ){
                ans = max( ans , getArea( pts[i] , pts[j] ) ) ; 
            }
        }
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