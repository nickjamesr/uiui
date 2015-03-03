
#include "heads/circuit.h"

Circuit::Circuit(){
/* Empty constructor. Initialise to identity on single mode
 * return : None
 */
  nmodes=1;
  len=nmodes*(nmodes+1);
  params=new double[len];
  r=new double*[0];
  phi=new double*[0];
  setoffsets();
}

Circuit::Circuit(int m){
/* Size constructor. Initialise to the identity
 * m      : Size of new circuit
 * return : None
 */
  nmodes=m;
  len=nmodes*(nmodes+1);
  params=new double[len];
  r=new double*[m-1];
  phi=new double*[m-1];
  setoffsets();
  for (int i=0; i<len; i++){
    params[i]=i;
  }
}

Circuit::Circuit(const Circuit& C){
/* Copy constructor performing deep copy of params array
 * C      : Circuit to be copied
 * return : None
 */
  nmodes=C.nmodes;
  len=C.len;
  params=new double[len];
  for (int i=0; i<len; i++){
    params[i]=C.params[i];
  }
  r=new double*[nmodes-1];
  phi=new double*[nmodes-1];
  setoffsets();
}

Circuit::~Circuit(){
/* Destructor. Free all dynamic memory.
 * return : None
 */
  delete[] params;
  delete[] r;
  delete[] phi;
}

Circuit Circuit::operator=(const Circuit &C){
/* Assignment operator. Deep copy params array in circuit C. Return reference to
 * self.
 * C      : Circuit to be copied
 * return : *this
 */
  delete[] params;
  delete[] r;
  delete[] phi;
  nmodes=C.nmodes;
  len=C.len;
  params=new double[len];
  for (int i=0; i<len; i++){
    params[i]=C.params[i];
  }
  r=new double*[nmodes-1];
  phi=new double*[nmodes-1];
  setoffsets();
  return *this;
}

void Circuit::setoffsets(void){
  // Do the losses. These are easy
  input=params+nmodes*(nmodes-1);
  output=params+nmodes*(nmodes);
  // Do the reflectivities and phase shifts
  for (int d=0; d<nmodes-1; d++){
    // Do the d-th diagonal
    r[d]=params+(nmodes-2)*(nmodes-3)/2-1-(nmodes-2-d)*(nmodes-3-d)/2+d;
    phi[d]=r[d]+nmodes*(nmodes-1)/2;
  }
}
