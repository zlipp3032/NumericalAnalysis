#include <iostream>
#include <vector>


// Number of states
const int NUM_STATES = 3;
const int NUM_EL_A = NUM_STATES * NUM_STATES;


struct LinearSolverParams{
  int solver;
  int num_states;
  float A[NUM_STATES][NUM_STATES];
  float b[NUM_STATES];
  float x[NUM_STATES];
  
};

struct SolutionStruct{
  float sol[NUM_STATES];
  int solver;
};
  



/////////////////////////////////////////////
// Base Solver class
/////////////////////////////////////////////
class Solver {
private:
  int m_val;
  
  
public:
  Solver(){};

  ~Solver(){};

  // - Allows for each derived function to have
  //   its own print function.
  virtual void Print(); // Note: that when we don't use
                        //       virtual, we are not able
                        //       to modify the "Solver"
                        //       base function in our
                        //       derived classes.
  virtual void Solve( void* );
  

};
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////



/////////////////////////////////////////////
// Linear solver class
/////////////////////////////////////////////
class LinearSolvers : public Solver {
private:
  // Initialize the solution array
  float m_sol[NUM_STATES];

public:
  LinearSolvers(){
    Setup();
  };

  ~LinearSolvers(){
  };

  void Setup();

  void Print();
  void Solve( void* );

  void GaussianElimination( LinearSolverParams* val );
  
};
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////


/*
class NonlinearSolvers : public Solver {
private:

public:
  NonlinearSolvers(){
    Setup();
  };

  ~NonlinearSolvers(){
  };

  void Setup();

  void Print();
  void Solve();
  
};
*/



