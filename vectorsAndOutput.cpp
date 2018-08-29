#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//walk the vector *ahem array* and output
void doOutput (*vector<int> v) {
  for (auto &x : v) // so we don't make new copies 
  {
    cout << x << endl;
  }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> suspiciousArray;
    
    
    doOutput (*suspiciousArray);
    
    return 0;
}
