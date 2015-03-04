#ifndef circuit_h
#define circuit_h

#include <stdexcept>

enum io_t{
  io_input,
  io_output
};

class Circuit{
  private:
    int len;
    double* params;
    double** r;       // Reflectivities
    double** phi;     // Phases
    double* input;    // Input losses
    double* output;   // Output losses
    void setoffsets(void);
      // Set the offsets into the params array
  protected:
  public:
    int nmodes;
    Circuit();
      // Empty constructor
    Circuit(int m);
      // Size constructor
    Circuit(const Circuit& C);
      // Copy constructor
    ~Circuit(void);
      // Destructor
    Circuit operator=(const Circuit& C);
      // Assignment operator
    double& reflectivity(int i, int j);
      // Return (by reference) j-th reflectivity in i-th diagonal
      // 0<=i<m-1, i<j<m
    double& phase(int i, int j);
      // Return (by reference) j-th phase in i-th diagonal
      // 0<=i<m-1, i<j<m
    double& coupling(io_t io, int i);
      // Return (by reference) the i-th input/output coupling
      // 0<=i<m
};

#endif
