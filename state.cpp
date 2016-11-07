#include <iostream>
#include <fstream>
#include <stdlib>

#include "argon.hpp"

state::state(parameters* param_)
{
	param=param_;
	
	//blok położeń	
	{
		r=new vect[param->N];
		
		double b[9];
		
		double* a=&param.a;
		
		//x
		b[0]=*a;
		b[1]=*a/2;
		b[2]=*a/2;

		//y
		b[3]=0;
		b[4]=*a*sqrt(3)/2;
		b[5]=*a*sqrt(3)/6;
		
		//z
		b[6]=0;
		b[7]=0;
		b[8]=*a*sqrt(2.0/3.0);

		unsigned i=0;
		vect mnoznik[3];
		
		double n=param->n;
		for(int i0=0;i0<n;i0++)
		{
			mnoznik[0]=(2*i0-(n-1));
			mnoznik[0]/=2;
			for(int i1=0;i1<n;i1++)
			{
				mnoznik[1]=(2*i1-(n-1));
				mnoznik[1]/=2;
				for(int i2=0;i2<n;i2++)
				{
					i=i0+i1*n+i2*n*n;
				
					mnoznik[2]=(2*i2-(n-1));
					mnoznik[2]/=2;

					
					rptr[i][0]=mnoznik[0]*b[0] + mnoznik[1]*b[1] + mnoznik[2]*b[2];
					rptr[i][1]=mnoznik[0]*b[3] + mnoznik[1]*b[4] + mnoznik[2]*b[5];
					rptr[i][2]=mnoznik[0]*b[6] + mnoznik[1]*b[7] + mnoznik[2]*b[8];
				}
			}
		}
		
	}
}

state::~state()
{
	delete r[];
	delete p[];
	delete F[];
}
