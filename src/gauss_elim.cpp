#include "gauss_elim.hpp"


/////////////////////////////////////////////
// Base Solver class
/////////////////////////////////////////////
void Solver::Print(){
  std::cout << "Fuck's sake\n";
};

void Solver::Solve( void* ){
  std::cerr << "Need to pick solver.\n";
};
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////



/////////////////////////////////////////////
// Linear solvers class
/////////////////////////////////////////////
void LinearSolvers::Setup(){
  std::cout << "Jinkys\n\n";
};


void LinearSolvers::Print(){
  std::cout << "Yabba Dabba Doo\n\n";
};


// Create the solve function for the linear solver class
void LinearSolvers::Solve( void* solver_params ){
  std::cout << "LinearSolver.\n";

  
  LinearSolverParams val = *(LinearSolverParams *)solver_params;
  //int select_solver = val.solver;

  switch(val.solver){
  case 0:
    GaussianElimination( &val );
    break;
  default:
    std::cerr << "Incorrect solver argument.\n";
  }
};


// Gaussian Elimination for the linear solver class
void LinearSolvers::GaussianElimination( LinearSolverParams* val ){
  std::cout << "Gaussian Elimination. \n";
  
  
  // Extract the input value for the Linear solver
  //LinearSolverParams val = *(LinearSolverParams *)solver_params;

  std::cout << val->solver << "Just intermediate vals\n"; 
  // Initialize the arrays used for intermediate steps
  float m[val->num_states][val->num_states];
  float b_str[val->num_states];
  float a_str[val->num_states][val->num_states];

  
  // Copy the input variables to the variables we will manipulate
  memcpy( a_str, val->A, sizeof(val->A) );
  memcpy( b_str, val->b, sizeof(val->b) );
  std::cout << "Just after memcpys\n";
  
  
  /////////////////////////////////////
  // Perform the forward elimnation to obtain the upper triangular terms
  /////////////////////////////////////
  // Increment the stage counter
  for(int k=0; k<val->num_states-1; k++){

    // Increment the row index
    for(int i=k+1; i<val->num_states; i++ ){

      // Compute the Gauss multiplier
      m[i][k] = a_str[i][k] / a_str[k][k];

      // Update the RHS of the equality Ax = b
      b_str[i] = b_str[i] - m[i][k] * b_str[k];

      // Increment the column index
      for(int j=k+1; j<val->num_states; j++){

	// Modify matrix components on LHS of Ax = b
	a_str[i][j] = a_str[i][j] - m[i][k] * a_str[k][j];
      }
    }
  }
  /////////////////////////////////////
  /////////////////////////////////////

  
  /////////////////////////////////////
  // Perform the backward substitution to obtain solution
  /////////////////////////////////////
  m_sol[val->num_states-1] = b_str[val->num_states-1] / a_str[val->num_states-1][val->num_states-1];
  for(int i = val->num_states-2; i>-1; i--){
    m_sol[i] = 0;
    for(int j=i+1; j<val->num_states; j++){
      m_sol[i] = m_sol[i] + a_str[i][j] * m_sol[j];
    }
    m_sol[i] = (b_str[i] - m_sol[i]) / a_str[i][i];
  }
  /////////////////////////////////////
  /////////////////////////////////////
};
////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
