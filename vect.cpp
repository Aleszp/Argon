#include "vect.hpp"

vect operator+(const vect&a, const vect&b)
{
	vect c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	c.z=a.z+b.z;
	
	return c;
}

vect operator+(const vect&a, const vect&b)
{
	vect c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	c.z=a.z-b.z;
	
	return c;
}
