
#include "heads/sampler.h"

Event::Event(){
/* Empty constructor. Create an event with 1 photon in mode 0
 * return : None
 */
  nphotons=1;
  modes=new int[1];
  modes[0]=0;
}

Event::Event(int p){
/* Number constructor. Create an event with p photons, all initially in mode 0
 * p      : Number of photons
 * return : None
 */
  nphotons=p;
  modes=new int[p];
  for (int i=0; i<p; i++){
    modes[i]=0;
  }
}

Event::Event(const Event& e){
/* Copy constructor. Deep copy of memory in Event e
 * e      : Event to be copied
 * return : None
 */
  nphotons=e.nphotons;
  modes=new int[nphotons];
  for (int i=0; i<nphotons; i++){
    modes[i]=e.modes[i];
  }
}

Event::~Event(){
/* Destructor. Free memory associated with array of modes
 * return : None
 */
  delete[] modes;
}

Event Event::operator=(const Event& e){
/* Assignment operator
 * e      : Event to be copied
 * return : *this
 */
  delete[] modes;
  nphotons=e.nphotons;
  modes=new int[nphotons];
  for (int i=0; i<nphotons; i++){
    modes[i]=e.modes[i];
  }
  return *this;
} 

int& Event::operator[](int i){
/* Get the position of the i-th photon
 * i      : index of photon
 * return : reference to position of i-th photon, m[i]
 */
  if (i<0 || i>=nphotons){ // range check
    return modes[i];
  }
  else{
    return modes[i];
  }
}


