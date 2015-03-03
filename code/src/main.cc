#include <iostream>

#include "heads/circuit.h"

int main(int argc, char** argv){
  int m=5;
  Circuit C(m);
  for (int d=0; d<m-1; d++){
    for (int j=d+1; j<m; j++){
      std::cout << C.r[d][j] << "," << C.phi[d][j] << std::endl;
    }
    std::cout << std::endl;
  }
  for (int i=0; i<m; i++){
    std::cout << C.input[i] << "," << C.output[i] << std::endl;
  }
}
