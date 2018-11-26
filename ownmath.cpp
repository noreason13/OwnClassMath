#include "ownmath.h"
using namespace ownmath;

double ownmath::COwnMath::ownSqrt(double a) //квадратный корень
{
	if (a <= 0) return 0;
	else
	{
		double x = a, xp; 
		do
		{
			xp = x;
			x = (x+a/x)/2.0;
		} while (ownAbs(x-xp) >= dPRECISION);
		return x;
	}
}
double ownmath::COwnMath::ownPower(double x, int n) //целочисленная степень
{
	double X = x;
	if (n == 0) 
		return 1;
	else
	{
		int N = ownAbs<int>(n);
		for (int i=0; i<N-1; i++) 
		{
			X = X*x;
		}
	}
	return n<0?1/X:X;
}

double ownmath::COwnMath::ownPower(double x, double a) //дробная степень
{
	return ownExp(a*ownLn(x));
}
double ownmath::COwnMath::ownLn(double y, int * n)  //логарифм 
{
	double z, x;
	int i = 1;
	if (y<1) z = ownInv(y);
	else z = y;
	x = (z - 1)/(z + 1);
	double S = 0.0, a;
	do
	{
		a = 2.0*ownPower(x,i)/i;
		S += a;
		i += 2;

	} while (a >= dPRECISION);
	*n = i;
	return S;

}

double ownmath::COwnMath::ownInv(double t) //степень (-1)
{
	return 1/t;
}

double ownmath::COwnMath::ownLn(double x) //логарифм по Симпсону
{
	//int i;
	//return ownLn(x, &i);
	double z = (x<1)? ownInv(x):x;
	typedef double (*TypedFun1d)(double);
	TypedFun1d pf = ownInv;
	PartsOfDouble pod = getMandE(z);
	double M = pod.mantissa;
	int P = pod.exponent;
	double simpson = ownIntegralSimpson(pf,1.0,M,30)+P*dLN_10;
	simpson = x<1.0?-simpson:simpson;
	return simpson;
}

double ownmath::COwnMath::ownIntegralSimpson(double f(double), double a, double b, int N) //интеграл методом Симпсона
{
	if  (N<1) N = 1;
	double h = (b - a)/N;
	double x = a, s =0.0;
	int i;
	for (i=0; i<N; i++)
	{
		x = a + h*i;
		s += h/6*(f(x)+4*f(x+h/2)+f(x+h));
	}
	return s;
}

double ownmath::COwnMath::ownFactorial(int n) //факториал
{
	return n>1? n*ownFactorial(n-1):1;
}
double ownmath::COwnMath::ownExp(double x) //экспонента
{
	double a, z, y = 0.0,p=1,f=1;
	int i = 0;
	z=x<0?-x:x;
	do
	{
		a=p/f;
		p*=z;
		f*=++i;
		//a = ownPower(z, i)/ownFactorial(i);
		y += a;
		//i ++;

	} while (a >= dPRECISION);
	
	return x<0?1/y:y;
}

PartsOfDouble ownmath::COwnMath::getMandE(double x) //мантисса и экспонента действительного числа
{
	PartsOfDouble pod;
	double z=ownAbs<double>(x);
	double M;
	int P;
	if (0 == z)
	{ 
		M = 0;
		P = 0;
	}
	else
	{
		M = z;
		P = 0;
		if (z >= 1)
		{
			while(M >= 10)
			{
				M /= 10;
				P++;
			}
		}
		else
		{
			while(M < 1)
			{
				M *= 10;
				P--;
			}
		}
	}
	pod.mantissa = M;
	pod.exponent = P;
	return pod;
}
double ownmath::COwnMath::toSegm0_2pi(double x)
{
	if (x>=0)
		while (x>=2*PI)
			x-=2*PI;
	else
		while (x<0)
			x+=2*PI;
	return x;	
};
double ownmath::COwnMath::toSegm_pi_pi(double x)
{
	if (x>=0)
		while (x>PI)
			x-=2*PI;
	else
		while (x<=-PI)
			x+=2*PI;
	return x;
};
double ownmath::COwnMath::ownSin(double x)
{	
	double z=toSegm_pi_pi(x);
	double a=z;
	int i = 1;
	double s=0.0;
	while (ownAbs(a)>=dPRECISION)
	{
		s+=a;
		i+=2;
		a*=-(z*z)/i/(i-1);
	}
	return s;
}
double ownmath::COwnMath::ownCos(double x)
{
	double z=toSegm_pi_pi(x);
	double a=1;
	int i=0;
	double s=0.0;
	while (ownAbs(a)>=dPRECISION)
	{
		s+=a;
		i+=2;
		a*=-(z*z)/i/(i-1);
	}
	return s;
}
double ownmath::COwnMath::ownTan(double x)
{
	double z = ownSin(x)/ownCos(x);
	return z;
}
double ownmath::COwnMath::ownATan(double x)
{
	double z=ownAbs<double>(x),s;
	const int N=20;
	double (*pf)(double)=ownCLBW;
	if(z<=10)
		{
			if (z<=1)
				s=ownIntegralSimpson(pf,0,z,N);
			else if(z<=2)
				{
					s=ownIntegralSimpson(pf,0,1,N)+ownIntegralSimpson(pf,1,z,N);
				}
			else if(z<=3)
				{
					s=ownIntegralSimpson(pf,0,1,N)+ownIntegralSimpson(pf,1,2,N)+ownIntegralSimpson(pf,2,z,N);
				}
			else 
					s=ownIntegralSimpson(pf,0,1,N)+ownIntegralSimpson(pf,1,2,N)+ownIntegralSimpson(pf,2,3,N)+ownIntegralSimpson(pf,3,z,4*N);
		}
	else
		{
			int k=1;
			double p=-1.0/z,q=1.0/10.0,a;
			s=0;
				do
				{
					a=(p+q)/k;k+=2;p*=-p/(z*z);q=-q/(10*10);
					s+=a;

				}while(ownAbs<double>(a)>dPRECISION);
				s+=dATAN_10;
		}
	s=x<0?-s:s;
	return s;
}
 double ownmath::COwnMath::ownCLBW(double t)
 {
	 return 1.0/(1.0+t*t);
 }
 double ownmath::COwnMath::ownASin(double x)
 {
	 if(ownAbs(x)>1)
		 return -100000000;
	 else if(1 == x)
		 return PI/2;
	 else if(-1 == x)
		 return -PI/2;
	 else
		 return ownATan(x/ownSqrt(1-ownPower(x,2)));
 }
 double ownmath::COwnMath::ownACos(double x)
 {
	 return PI/2-ownASin(x);
 }