#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;

int main(){
  int c; cin>>c;
  for (int i=0;i<c;i++){
    ll l, n;
    cin >> l >> n;
    
    ll minimo= 0;
    ll maximo = 0; 
    vector<ll> posiciones;
    for(int j=0; j<n; j++){
      ll p; cin>>p;
      posiciones.push_back(p);
    }
    for(int j=0; j<n; j++){
      ll second = std::min(posiciones[j], l - posiciones[j]);
      minimo = std::max(minimo, second);
      maximo = std::max(maximo, std::max(posiciones[j], l - posiciones[j]));
    }
    cout << minimo << " " << maximo << endl;
  }

  return 0;
}
