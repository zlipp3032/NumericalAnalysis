#include <iostream>
#include <vector>

#include "gauss_elim.hpp"



int main(int argc, char *argv[]){

  std::cout << "Scooby Dooby Doo!\n";


  /////////////////////////////////////////////
  // Initialize the LinearSolverParams struct
  /////////////////////////////////////////////
  LinearSolverParams this_solver;
  this_solver.solver = 0;
  this_solver.num_states = NUM_STATES;

  this_solver.A[0][0] = 3.2;
  this_solver.A[0][1] = 1.2;
  this_solver.A[0][2] = 2.2;
  this_solver.A[1][0] = 2;
  this_solver.A[1][1] = -1;
  this_solver.A[1][2] = 2.9;
  this_solver.A[2][0] = 6.4;
  this_solver.A[2][1] = 2.3;
  this_solver.A[2][2] = -3.2;
  
  this_solver.b[0] = -4;
  this_solver.b[1] = 3;
  this_solver.b[2] = -2;
  /////////////////////////////////////////////
  /////////////////////////////////////////////


  /////////////////////////////////////////////
  // Example of how to use polymorphism
  /////////////////////////////////////////////
  Solver *s;
  LinearSolvers ls;
  s  = &ls;

  //virtual function, binded at runtime (Runtime polymorphism)
  s->Print(); 
  s->Solve( &this_solver );
  /////////////////////////////////////////////
  /////////////////////////////////////////////
  /////////////////////////////////////////////

  std::cout << "Solution x, to Ax = b: \n";
  for(int i =0; i<this_solver.num_states; i++){
    std::cout << this_solver.x[i] << "\n";
  }


  return 0;
}

