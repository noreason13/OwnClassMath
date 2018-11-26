#include <iostream>
#include "ownmath.h"

using std::cout;
using std::cin;
using std::endl;
using namespace ownmath;

int main()
{
	//cout << ownmath::COwnMath::ownAbs<int>(-20) << endl;
	//cout << COwnMath::ownAbs<float>(3.3f) << endl;
	//cout << COwnMath::ownPower(3.6,1) << endl;
	//cout << COwnMath::ownPower(10,-2) << endl;
	//cout << COwnMath::ownPower(17,0) << endl;
	//cout << COwnMath::ownPower(-3.16,2) << endl;
	//cout << COwnMath::ownLn(1000) << endl;
	
	int i;
	cout << ownmath::COwnMath::ownLn(20) << endl;
	cout << ownmath::COwnMath::ownLn(20,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(1) << endl;
	cout << ownmath::COwnMath::ownLn(1,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(2.718281828) << endl;
	cout << ownmath::COwnMath::ownLn(2.718281828,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(5) << endl;
	cout << ownmath::COwnMath::ownLn(5,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(10) << endl;
	cout << ownmath::COwnMath::ownLn(10,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(20) << endl;
	cout << ownmath::COwnMath::ownLn(20,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(200) << endl;
	cout << ownmath::COwnMath::ownLn(200,&i) << endl << endl;
	cout << ownmath::COwnMath::ownLn(300) << endl;
	cout << ownmath::COwnMath::ownLn(300,&i) << endl << endl;
	cout << "ln2000 = "<< ownmath::COwnMath::ownLn(2000) << endl;
	cout << ownmath::COwnMath::ownLn(2000,&i) << endl << endl;
	cout << "ln20000 = " << ownmath::COwnMath::ownLn(20000) << endl;
	cout << ownmath::COwnMath::ownLn(20000,&i) << endl << endl;
	cout << ownmath::COwnMath::ownExp(1) << endl;
	cout << ownmath::COwnMath::ownExp(0) << endl;
	cout << ownmath::COwnMath::ownExp(3) << endl;
	cout << ownmath::COwnMath::ownExp(-1) << endl;
	cout << ownmath::COwnMath::ownExp(5) << endl << endl;
	cout << ownmath::COwnMath::getMandE(123).exponent << endl;
	cout << ownmath::COwnMath::getMandE(123).mantissa << endl;
	cout << "pow(2,1.5) = " << ownmath::COwnMath::ownPower(2.0, 1.5) << endl;
	cout << "pow(2,0.5) = " << ownmath::COwnMath::ownPower(2.0, 0.5) << endl;
	cout << "pow(10,0.5) = " << ownmath::COwnMath::ownPower(10.0, 0.5) << endl;
	cout << "pow(8,1/3) = " << ownmath::COwnMath::ownPower(8.0, 1.0/3) << endl;
	cout << "pow(e,3) = " << ownmath::COwnMath::ownPower(ownmath::COwnMath::ownExp(1), 3) << endl;
	cout << "pow(e,3.0) = " << ownmath::COwnMath::ownPower(ownmath::COwnMath::ownExp(1), 3.0) << endl;
	cout << "pow(9.81,0.5) = " << ownmath::COwnMath::ownPower(9.81, 0.5) << endl;
	cout << ownmath::COwnMath::ownSqrt(9.81) << endl;
	cout << ownmath::COwnMath::ownSqrt(2.0);
	cout << endl << endl << ownmath::COwnMath::ownSign(-5) << endl;

	cout << endl << endl << endl;
	cout << ownmath::COwnMath::ownSin(PI/2) << " " << ownmath::COwnMath::ownSin(PI/4) << " " << ownmath::COwnMath::ownSin(PI/6) << endl;
	cout << ownmath::COwnMath::ownSin(PI/2+10*PI) << " " << ownmath::COwnMath::ownSin(-PI/6-10*PI) << " " << ownmath::COwnMath::ownSin(-PI/4) << endl;
	cout << endl;
	cout << ownmath::COwnMath::ownCos(0) << "  " << ownmath::COwnMath::ownCos(PI/2) << "  " << ownmath::COwnMath::ownCos(-PI/3) << endl;
	cout << ownmath::COwnMath::ownCos(PI/4-10*PI) << "  " << ownmath::COwnMath::ownCos(PI/3+10*PI) << "  " << ownmath::COwnMath::ownCos(2*PI/3-20*PI) << endl;
	cout << endl;
	cout << ownmath::COwnMath::ownTan(PI/4) << "  " << ownmath::COwnMath::ownTan(-PI*4) << "  " << ownmath::COwnMath::ownTan(PI/2) << "  " << ownmath::COwnMath::ownTan(-PI/2) << endl;
	cout << ownmath::COwnMath::ownATan(0)  <<endl;
	cout << ownmath::COwnMath::ownATan(-1)  <<endl;
	cout << ownmath::COwnMath::ownATan(3)  <<endl;
	cout << ownmath::COwnMath::ownATan(-5)  <<endl;
	cout << ownmath::COwnMath::ownATan(10)  <<endl;
	cout << ownmath::COwnMath::ownATan(-20)  <<endl;
	cout << ownmath::COwnMath::ownATan(100)  <<endl;
		cout << ownmath::COwnMath::ownASin(0.6)  <<endl;
	cin.get();
	return 0;
}