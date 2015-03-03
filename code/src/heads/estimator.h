#ifndef estimator_h
#define estimator_h

#include "circuit.h"

class Estimator{
  private:
    int npoints;
    int maxpoints;
    Circuit* points;
    double* weights;
  protected:
  public:
    Estimator();
    Estimator(const Estimator& e);
    Estimator(int n, int nmax=0);
    ~Estimator();
    Estimator operator=(const Estimator& e);
};

#endif
