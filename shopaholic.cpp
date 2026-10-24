#include <bits/stdc++.h>
#include <queue>
using namespace std;


typedef long long ll;

int main(){
  int n;
  cin>>n;
  priority_queue<int> pq;

  for (int i=0; i<n ; i++){
    int p;
    cin>>p;
    pq.push(p);
  }
  ll desc=0;
  while(pq.size()>=3){
    pq.pop();
    pq.pop();
    desc+=pq.top();
    pq.pop();
  }
  cout << desc << endl;
  return 0;
}
