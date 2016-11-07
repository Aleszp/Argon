#ifndef _ARGON_HPP_
#define _ARGON_HPP_

class parameters
{
	public:
	
	int n;
	long N;
	double m;
	double eps;
	double R;
	double f;
	double L;
	double T0;
	double a;
	double tau;
	unsigned S0;
	unsigned Sd;
	unsigned Sxyz;
	unsigned Sout;
	
	double nm;
	double ps;
	double u;
	double kB;
	
	parameters(char* input);
	~parameters(){}	
};

class state
{
	public:
	
	vect* r;
	vect* p;
	vect* F;
	
	double V;
	double H;
	double t;
	
	parameters param;
	
	state(parameters* param_);
	~state();	
	
	void update();
};

#endif
