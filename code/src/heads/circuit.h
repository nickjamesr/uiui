#ifndef circuit_h
#define circuit_h

class Circuit{
  private:
    int len;
    double* params;
    void setoffsets(void);
      // Set the offsets into the params array
  protected:
  public:
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
    int nmodes;
    double** r;       // Reflectivities
    double** phi;     // Phases
    double* input;    // Input losses
    double* output;   // Output losses
};

#endif
