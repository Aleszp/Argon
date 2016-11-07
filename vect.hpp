#ifndef _VECT_HPP_
#define _VECT_HPP_

class vect
{
	public:
		double x;
		double y;
		double z;
	
		double len(){return sqrt(x*x+y*y+z*z);}
		double len2(){return x*x+y*y+z*z;}
		
		vect operator+(const vect&, const vect&);
		vect operator-(const vect&, const vect&);
};


#endif
