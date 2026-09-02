#include <iostream>
#include <string>
#include <vector>
#include <set>

int x,y,level;
using namespace std;
int main(){
  cin >> x >> y;
  int arr[x];
  set<int > nivMario;
  for(int i= 0; i<x; i++){
    arr[i]=i;
  }
  for(int i= 0; i<y; i++){
    cin >> level;
    arr[level] = -1;
  }
  for (int i=0; i<x; i++){
    if(arr[i] >= 0){
      nivMario.insert(i);
    }
  }
  for (int nivel: nivMario) {
    cout << nivel << endl;
  }
  cout << "Mario got "+to_string(x - nivMario.size())+" of the dangerous obstacles."<<endl;;
  return 0;
}
