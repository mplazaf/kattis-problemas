#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
using namespace std;
typedef long long ll;

void bt(vector<ll>& original,vector<ll>& sub1,vector<ll>& sub2,ll &min){
  if(original.empty()){
    ll suma1,suma2, dif;
    suma1=0;
    suma2=0;
    for(ll i: sub1){
      suma1+=i;
    } 
    for(ll i: sub2){
      suma2+=i;
    }
    dif=abs(suma2-suma1);
    if(dif<min){
      min=dif;
    }
    return;
  }
  else{
    ll manzana = original[0];
    original.erase(original.begin());
    //izquierda
    sub1.push_back(manzana);
    bt(original, sub1,sub2,min);
    sub1.pop_back();
    //Derecha
    sub2.push_back(manzana);
    bt(original,sub1,sub2,min);
    sub2.pop_back();

    original.insert(original.begin(),manzana);

  }
}
int main(){
  int n;
  cin>>n;
  vector<ll> manzanas;

  for(int i =0; i<n; i++){
    ll p;
    cin >>p;
    manzanas.push_back(p);
  }
  ll minimo = INT_MAX;
  vector<ll> s1,s2;
  bt(manzanas,s1,s2,minimo);
  cout<<minimo<<endl; 


  return 0;
}
