#ifndef sampler_h
#define sampler_h

class Event{
  private:
    int *modes;
  protected:
  public:
    Event();
      // Empty constructor  
    Event(int p);
      // Number constructor
    Event(const Event& e);
      // Copy constructor
    ~Event();
      // Destructor
    Event operator=(const Event& e);
      // Assignment operator
    int nphotons;
    int& operator[](int);
};

class Sampler{
  private:
    double *unitary;
  protected:
  public:
    Sampler();
      // Empty constructor
    Sampler(int m, double* u);
      // Unitary constructor
    Sampler(const Sampler& S);
      // Copy constructor
    ~Sampler();
      // Destructor
    Sampler operator=(const Sampler& S);
      // Assignment operator
    Event get(int p);
      // Get a p-photon event
};

#endif
