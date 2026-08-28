#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int n, k;
stack<int> pila;

struct instruc {
  int tipo;
  int valor;
};

vector<string> instrucciones;

int main(){
  cin >> n >> k;
  
  for (int i = 0; i < k; i++) {
    string instruccion;
    cin >> instruccion;

    if (instruccion == "undo") {
        string cantidad;
        cin >> cantidad;
        instruccion += " " + cantidad;
    }

    instrucciones.push_back(instruccion);
  } 

  vector<instruc> procesadas;

  for(int i = 0; i < instrucciones.size(); i++) {
    string actual = instrucciones[i];
    if (actual.find("undo") != string::npos) {
        int espacio = actual.find(" ");
        string numero = actual.substr(espacio + 1);
        instruc inst;
        inst.tipo = 1;
        inst.valor = stoi(numero);
        procesadas.push_back(inst);
    }
    else {
        instruc inst;
        inst.tipo = 0;
        inst.valor = stoi(actual);
        procesadas.push_back(inst);
    }
  }

  // aqui empieza de verdad de verdad
  int pos = 0;

  for (int i=0; i< procesadas.size() ; i++) {
    if(procesadas[i].tipo == 0) {
      pos = ((pos + procesadas[i].valor) % n + n)%n; 
      pila.push(procesadas[i].valor);
    }
    else {
      for (int j = 0; j < procesadas[i].valor; j++){
        pos = ((pos - pila.top()) % n + n) % n;
        pila.pop();
      }
    }
  }
  cout << pos << endl;
  return 0;
}


