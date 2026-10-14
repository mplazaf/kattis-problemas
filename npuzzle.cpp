#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

map<char, pair<int,int>> original;


int main(){
  original.insert({'A',{1,1}});
  original.insert({'B',{2,1}});
  original.insert({'C',{3,1}});
  original.insert({'D',{4,1}});
  original.insert({'E',{1,2}});
  original.insert({'F',{2,2}});
  original.insert({'G',{3,2}});
  original.insert({'H',{4,2}});
  original.insert({'I',{1,3}});
  original.insert({'J',{2,3}});
  original.insert({'K',{3,3}});
  original.insert({'L',{4,3}});
  original.insert({'M',{1,4}});
  original.insert({'N',{2,4}});
  original.insert({'O',{3,4}});
  original.insert({'.',{4,4}});

  map<char, pair<int,int>> entrada;

  for(int i=0; i<4; i++){
    string fila;
    cin >> fila;
    for(int j=0; j<4; j++){
      char letra = fila[j];
      int numFila = j+1;
      int numColumna = i+1;
      entrada.insert({letra, {numFila,numColumna}});
    }
  }
  
  int cont = 0;
  
  for (auto elemento : entrada){
    char letra = elemento.first;
    pair<int,int> par = elemento.second;

    int x_actual = par.first;
    int y_actual = par.second;

    int x_real = original[letra].first;
    int y_real = original[letra].second;

    if (letra=='.'){
      cont = cont;
    }
    else {
      int dif_x = abs(x_real - x_actual);
      int dif_y = abs(y_real - y_actual);
      int distanciaTotal = dif_x + dif_y;
      cont += distanciaTotal;
    }
  }
  cout << cont << endl;
  return 0;
}
  
