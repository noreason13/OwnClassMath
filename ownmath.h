#ifndef _OWNMATH_H_
#define _OWNMATH_H_

namespace ownmath
{
	const double dPRECISION = 1.0/100000000.0;
	const double dLN_10 = 2.302585092994;
	const double PI = 3.1415926535897932;
	const double dATAN_10=1.471127674303735;
	struct PartsOfDouble
	{
		double mantissa;
		int exponent;

	};
	class COwnMath 
	{
	public:
		template <typename Tnm>
		static Tnm ownAbs(Tnm);
		template <typename Tnm1>
		static Tnm1 ownSign(Tnm1);
		static double ownPower(double, int);
		static double ownPower(double, double);
		static double ownLn(double);
		static double ownLn(double, int *);
		static double ownInv(double);
		static double ownIntegralSimpson(double(*)(double), double, double, int);
		static PartsOfDouble getMandE(double);
		static double ownFactorial(int);
		static double ownExp(double);
		static double ownSqrt(double);
		static double toSegm0_2pi(double);
		static double toSegm_pi_pi(double);
		static double ownSin(double);
		static double ownCos(double);
		static double ownTan(double);
		static double ownATan(double);
		static double ownACos(double);
		static double ownASin(double);
		static double ownCLBW(double);
	};
}

template <typename Tnm>
Tnm ownmath::COwnMath::ownAbs(Tnm t) 
{
	return t<0?-t:t;
}
template <typename Tnm>
Tnm ownmath::COwnMath::ownSign(Tnm t)
{
	return (t<0)?-1:(t=0)?0:1;
}
#endif //OWNMATH_H