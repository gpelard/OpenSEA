#ifndef BODYWITHFORCEMATRIX_H
#define BODYWITHFORCEMATRIX_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include "armadillo"
#include "body.h"
#include "forcederivative.h"
#include "reactiveforcematrix.h"
#include "activeforcematrix.h"
#include "userforces.h"

using namespace arma;
using namespace std;

typedef complex<double> complexDouble;

class BodyWithForceMatrix
{
public:
	BodyWithForceMatrix();
	BodyWithForceMatrix(Body, UserForces);
	~BodyWithForceMatrix();
	
	//Force Coefficient Matrices
	cx_mat massMatrix;
	vector<ReactiveForceMatrix> userReactiveForceMatrix;
	vector<ReactiveForceMatrix> userCrossBodyForceMatrix;
	vector<cx_mat> userActiveForceMatrix;
	vector<ReactiveForceMatrix> hydroReactiveForceMatrix;
	vector<ReactiveForceMatrix> hydrpCrossBodyForceMatrix;
	vector<cx_mat> hydroActiveForceMatrix;

	//Hold the names of the Force Matrices which correspond to the above data structures
	vector<string> userActiveForce;
	vector<string> userReactiveForce;
	vector<string> userCrossBodyForces;
	vector<string> hydroActiveForce;
	vector<string> hydroReactiveForce;
	vector<string> hydroCrossBodyForces;
private:

};
#endif
