#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int n, m, sumaTareas, sumaQuiet;
  sumaTareas=0;
  sumaQuiet=0;
  cin >> n >> m ;
  vector<int> tasks, quiet;
  stack<int> tasksQ, quietQ;

  for(int i= 0;i<n;i++){
    int t;
    cin>>t;
    tasks.push_back(t);
    sumaTareas+=t;
  }

  for(int i= 0;i<m;i++){
    int l;
    cin>>l;
    quiet.push_back(l);
    sumaQuiet+=l;
  }
  sort(tasks.begin(),tasks.end());
  sort(quiet.begin(),quiet.end());

  for (int i = n-1; i>=0; i--){
    tasksQ.push(tasks[i]);
  }

  for (int i = m-1; i>=0; i--){
    quietQ.push(quiet[i]);
  }

  int cont=0;
  while(!tasksQ.empty() && !quietQ.empty()){
    if(quietQ.top()>=tasksQ.top()){
      cont++;
      tasksQ.pop();
    }
    quietQ.pop();
  }
  cout << cont << endl;
  return 0;
}
