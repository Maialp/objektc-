#include <iostream>
#include <cmath>
#include "fibonacci.h"
#include "matrix.h"
#include "dummy.h"


using namespace std;

int main()
{	
	Matrix A(2);
	A.set(0,1,2);
	A.set(1,0,3);
	A.set(1,1,4);
	Matrix B(2);
	B.set(0,1,3);
	B.set(1,0,2);
	B.set(0,0,4);
	Matrix C(2);
	C.set(0,1,3);
	C.set(1,0,1.5);
	C.set(1,1,2);
	cout<<A<<endl<<B<<endl<<C<<endl;
	A += B + C;
	cout<<A<<endl<<B<<endl<<C<<endl;
	

}


