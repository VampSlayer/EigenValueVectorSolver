#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eigenValueSolver.c"
#include "eigenValueSolver.h"
#include "helpers.c"
#include "helpers.h"

int main(){

  double matrix[3][3];

	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[1][0] = 2;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[2][0] = 3;
	matrix[2][1] = 6;
	matrix[2][2] = 9;

  double eigenValues[3];

  CalculateEigenValues(matrix, eigenValues);

  for(int i = 0; i < 3; i++)
  {
     printf("%f\n",eigenValues[i]);
  }

  return 0;
}
