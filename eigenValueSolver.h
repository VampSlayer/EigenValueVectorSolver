// ----------------------------------------------------------------------------
// Calculates the eigenvalues of a symmetric 3x3
// matrix using Cardano's method for the eigenvalues
// Based of Joachim Kopp's Work
// https://www.mpi-hd.mpg.de/personalhomes/globes/3x3/
// ----------------------------------------------------------------------------
#ifndef __EIGENVALUESOLVER_H
#define __EIGENVALUESOLVER_H

int CalculateEigenValues(double matrix[3][3], double eigenValues[3]);

#endif
