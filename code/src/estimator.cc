
#include "heads/estimator.h"

Estimator::Estimator(){
/* Empty constructor. Initialise with zero points
 * return : None
 */
  npoints=0;
  maxpoints=0;
  points=new Circuit[0];
  weights=new double[0];
}

Estimator::Estimator(const Estimator& e){
/* Copy constructor. Deep copy of weighted array of Circuits
 * e      : Estimator to be copied
 * return : None
 */
  npoints=e.npoints;
  maxpoints=e.maxpoints;
  points=new Circuit[npoints];
  weights=new double[npoints];
  for (int i=0; i<npoints; i++){
    points[i]=e.points[i];
    weights[i]=e.weights[i];
  }
}

Estimator::Estimator(int n, int nmax){
/* Number constructor. Initialise with n points
 * n      : Number of points in new Estimator object
 * nmax   : Set a maximum on the number of points generated in intermediate
 *          steps (resampling)
 * return : None
 */
  npoints=n;
  maxpoints=nmax;
  points=new Circuit[npoints];
  weights=new double[npoints];
}

Estimator::~Estimator(){
/* Destructor. Free dynamic arrays of Circuits and weights
 * return : None
 */
  delete[] points;
  delete[] weights;
}

Estimator Estimator::operator=(const Estimator& e){
/* Assignment operator. Deep copy of weighted array of Circuits
 * e      : Estimator to be copied
 * return : *self
 */
  npoints=e.npoints;
  maxpoints=e.maxpoints;
  delete[] points;
  delete[] weights;
  points=new Circuit[npoints];
  weights=new double[npoints];
  for (int i=0; i<npoints; i++){
    points[i]=e.points[i];
    weights[i]=e.weights[i];
  }
  return *this;
}



