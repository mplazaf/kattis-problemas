#include<bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
  double n,m,k;
  priority_queue<double> diamPlots;
  priority_queue<double> diamCasas;

  cin >> n>>m>>k;
  for (int i=0;i<n;i++){
    int rPlot;
    cin>>rPlot;
    double dPlot = 2*rPlot;
    diamPlots.push(dPlot);
  }
  for (int i=0;i<m;i++){
    int r;
    cin>>r;
    double dCasa = 2*r;
    diamCasas.push(dCasa);
  }

  for (int i=0;i<k;i++){
    int l;
    cin>>l;
    double dCasa = (double)(1.41*l);
    diamCasas.push(dCasa);
  }

  int cont =0;

  while(!diamCasas.empty() && !diamPlots.empty()){
    if(diamCasas.top()<diamPlots.top()){
      cont++;
      diamPlots.pop();
      diamCasas.pop();
    }
    else{
      diamCasas.pop();
    }
  }

  cout<<cont<<endl;

  return 0;
}
