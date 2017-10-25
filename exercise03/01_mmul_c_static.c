#include <stdio.h>
#include <stdlib.h>

#ifndef N
	#define N 1000
#endif

#define VALUE double

VALUE A[N][N];
VALUE B[N][N];
VALUE C[N][N];

int main(int argc, char** argv) {

	// determine the size of the matrices
	int s = N;
	if (argc >= 2) {
		s = atoi(argv[1]);
	}

  // A contains real values
  for (int i=0; i<s; i++) {
    for (int j=0; j<s; j++) {
      A[i][j] = i*j;
    }
  }

  // B is the identity matrix
  for (int i=0; i<s; i++) {
    for (int j=0; j<s; j++) {
      B[i][j] = (i==j)?1:0;
    }
  }

  // conduct multiplication
  for (int i=0; i<s; i++) {
    for (int k=0; k<s; k++) {
      for (int j=0; j<s; j++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  } 

	// verify result
	int success = 1;	
	for (int i=0; i<s; i++) {
		for (int j=0; j<s; j++) {
			if (A[i][j] != C[i][j]) {
				success = 0;
			}
		}
	}

	// print verification result
	printf("Verification: %s\n", (success)?"OK":"ERR");
}

