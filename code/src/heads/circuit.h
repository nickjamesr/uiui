
enum io_t{
  input,
  output
};

class Circuit{
  private:
    int len;
    double* params;
    void setoffsets(void);
      // Set the offsets into the params array
  protected:
  public:
    Circuit();
      // Empty constructor (size implicitly zero)
    Circuit(int m);
      // Size constructor
    Circuit(const Circuit& C);
      // Copy constructor
    ~Circuit(void);
      // Destructor
    Circuit operator=(const Circuit& C);
      // Assignment operator
    int nmodes;
    double** r;
    double** phi;
    double* input;
    double* output;
};
