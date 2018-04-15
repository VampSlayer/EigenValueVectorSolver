// ----------------------------------------------------------------------------
// Calculates the eigenvalues of a symmetric 3x3
// matrix using Cardano's method for the eigenvalues
// Based of Joachim Kopp's Work
// https://www.mpi-hd.mpg.de/personalhomes/globes/3x3/
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eigenValueSolver.h"
#include "helpers.h"

int CalculateEigenValues(double matrix[3][3], double eigenValues[3])
{
  double c2 = -matrix[0][0] - matrix[1][1] - matrix[2][2];

	double c1 = matrix[0][0]*matrix[1][1] + matrix[0][0]*matrix[2][2] + matrix[1][1]*matrix[2][2] - 
							SquareOfTheAbsoluteOfDouble(matrix[0][1]) - 
							SquareOfTheAbsoluteOfDouble(matrix[0][2]) - 							
							SquareOfTheAbsoluteOfDouble(matrix[1][2]);

	double c0 = matrix[0][0]*SquareOfTheAbsoluteOfDouble(matrix[1][2]) +
							matrix[1][1]*SquareOfTheAbsoluteOfDouble(matrix[0][2]) +
							matrix[2][2]*SquareOfTheAbsoluteOfDouble(matrix[0][1]) -
							matrix[0][0]*matrix[1][1]*matrix[2][2] -
							2.0*(matrix[0][2]*matrix[0][1]*matrix[1][2]);

	double p = pow(c2, 2) - 3.0*c1;

	double q = -(27.0/2.0)*c0 - pow(c2, 3) + (9.0/2.0)*c2*c1;

	double theta1 = 0.25 * pow(c1, 2) * (p - c1);

	double theta2 = c0 * (q + ((27.0/4.0) * c0));

	double theta3 = 27.0 * (theta1 + theta2);

	double theta = (1.0/3.0) * atan2(sqrt(fabs(theta3)), q);

	double cosTheta = cos(theta);
	double sinTheta = sin(theta);

	double x1 = 2.0 * cosTheta;
	double x2 = -cosTheta - (sqrt(3.0) * sinTheta); 
	double x3 = -cosTheta + (sqrt(3.0) * sinTheta);

	double squareRootOfPOver3 = sqrt(fabs(p))/3.0;
	double oneThirdOfc2 = (1.0/3.0)*c2;
	
	eigenValues[0] = squareRootOfPOver3*x1 - oneThirdOfc2;
	eigenValues[1] = squareRootOfPOver3*x2 - oneThirdOfc2;
	eigenValues[2] = squareRootOfPOver3*x3 - oneThirdOfc2;

  return 0;
}
