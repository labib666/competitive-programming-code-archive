#include <iostream>

using namespace std;

int main() {
  int Na, Nb;
  cin >> Na >> Nb;

  int result1;
  cout << "cmp " << Na << " " << Na+1 << endl; // endl auto-flushes
  cin >> result1;

  int result2;
  cout << "cmp " << Na << " " << Na+Nb << endl; // endl auto-flushes
  cin >> result2;

  if (result1 == -1) {
    cout << "end" << endl; // endl auto-flushes
  } else {
    cout << "reverse " << 1 << " " << Na+Nb << endl; // endl auto-flushes 
    cout << "reverse " << 1 << " " << Nb << endl; // endl auto-flushes 
    cout << "reverse " << Nb+1 << " " << Na+Nb << endl; // endl auto-flushes 
    cout << "end" << endl; // endl auto-flushes
  }
 
  return 0;
}
