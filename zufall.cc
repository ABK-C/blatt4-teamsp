#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


// Variablen für a,c und m
int a1 = 5;
int c1 = 3;
int m1 = 16;
int a2 = 205;
int c2 = 29573;
int m2 = 139968;

double zufall(int a, int c, int m) {
  static int Ij = 20;
  Ij = (a * Ij + c) % m;
  double u = 1.0 * Ij / m;

  return u;
}

int main() {
  using namespace std;

  int N = 100;
  int Nin = 0;

  ofstream fout("Ergebnisse.txt");
  std::vector<int> Anzahl;
  Anzahl.push_back(N);
  Anzahl.push_back(N*100);
  Anzahl.push_back(N*1000);
  Anzahl.push_back(N*10000);

  std::vector<int> a;
  a.push_back(a1);
  a.push_back(a2);
  a.push_back(c1);
  a.push_back(c2);
  a.push_back(m1);
  a.push_back(m2);

  fout << "Einstellungen      " << "N   " << "E[Nin] " << "V[Nin]  " << "Nin " << "Pi    " << "Sigma " << std::endl; 
  for (int b = 0; b <= 2; b++) {
    for (int k : Anzahl) {
      Nin = 0;
      for (int i = 0; i < k; i++) {
        
        double Zufallx = zufall(a[b], a[b+2], a[b+4]);
        Zufallx = Zufallx * 2 - 1;

        double Zufally = zufall(a[b], a[b+2], a[b+4]);
        Zufally = Zufally * 2 - 1;
        if (sqrt(pow(Zufallx, 2) + pow(Zufally, 2)) <= 1) {
          Nin++;
        }
        //std::cout << Zufallx << " " << Zufally << std::endl;
      }
      double pi = 4.0 * Nin / k;
      double p = M_PI/4;
      double E = p*k;
      double V = E*(1-p);
      double sigma = 4*sqrt(V)/k;
      

      fout << "a = " << a[b] << " c = " << a[b+2] << " m = " << a[b+4] << " " << k << " "  << E << " "  << V << " "  << Nin << " "  << pi << " "  << sigma << std::endl;
    }
  }  
  fout.close();
}
