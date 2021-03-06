/*
   ARPACK++ v1.0 8/1/1997
   c++ interface to ARPACK code.

   MODULE BSMatrxB.h
   Function template for the one dimensional discrete Laplacian
   on the interval [0, 1], with zero Dirichlet boundary conditions.

   Matrix A is generated in symmetric band format, which means that
   only the main diagonal and the lower or the upper band of the 
   matrix are stored.

   ARPACK Authors
      Richard Lehoucq
      Danny Sorensen
      Chao Yang
      Dept. of Computational & Applied Mathematics
      Rice University
      Houston, Texas
*/

#ifndef BSMATRXB_H
#define BSMATRXB_H

#include <math.h>

template<class FLOAT, class INT>
void BandMatrixB(INT n, INT& nD, FLOAT* &A, char uplo='L')

{

  // Defining internal variables.

  INT    i;
  FLOAT  h, df, dd;

  // Defining constants.

  h  = 1.0/FLOAT(n+1);
  dd = 2.0/h;
  df = -1.0/h;

  // Defining the upper (or lower) bandwidth.

  nD  = 1;

  // Creating output vector A.

  A   = new FLOAT[2*n];

  if (uplo == 'L') {

    for (i=0; i<n; i++) {
      A[2*i] = dd;
      if (n-i-1) A[2*i+1] = df;
    }

  }
  else {

    for (i=0; i<n; i++) {
      if (i) A[2*i]  = df;
      A[2*i+1] = dd;
    }

  }
    
} // BandMatrixB.

#endif // BSMATRXB_H

