#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  priority_queue<int, vector<int>, greater<int>> pq;

  cin >> n >> m;
  vector<pair<int,int>> W;

  for(int i=0;i<n; i++){
    int a,s;
    cin >> a >> s;
    W.push_back({a, a+s});
  }
  sort(W.begin(),W.end());

  int cont = 0;
  pq.push(W[0].second);

  for(int i = 1; i < n; i++){
    int llegada = W[i].first;
    int salida = W[i].second;
    while(!pq.empty() && llegada - pq.top() > m
          && pq.top() <= llegada){
        pq.pop();
    }
    if(!pq.empty() && pq.top() <= llegada){
        cont++;
        pq.pop();
    }
    pq.push(salida);
  } 
  cout << cont << endl;
  return 0;
}
