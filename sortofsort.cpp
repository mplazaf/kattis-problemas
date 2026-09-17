#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, contador;
  contador = 0;
  while(contador<500){

    cin >> n;

    if(n==0){break;}
    else{
      vector<string> nombres(n);
      for (int i=0; i<n; i++){
        cin >> nombres[i];
      }
      stable_sort(nombres.begin(), nombres.end(),[](const string& a, const string& b) {
        return a.substr(0, 2) < b.substr(0, 2);});
      for (string nom : nombres){
        cout << nom << endl;
      }
      cout << endl;
    }
  }
  return 0;
}
