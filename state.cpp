#include <iostream>
#include <fstream>
#include <stdlib>

#include "argon.hpp"

state::state(parameters* param_)
{
	param=param_;
	
	//blok położeń	
	{
		r=new vect[param.N];
		
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
		double mnoznik[3];
		
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

					
					vect[i].x=mnoznik[0]*b[0] + mnoznik[1]*b[1] + mnoznik[2]*b[2];
					vect[i].y=mnoznik[0]*b[3] + mnoznik[1]*b[4] + mnoznik[2]*b[5];
					vect[i].z=mnoznik[0]*b[6] + mnoznik[1]*b[7] + mnoznik[2]*b[8];
				}
			}
		}
		
	}
	
	//blok pędów
	{
		p=new vect[param.N];
		
		double tmp_rnd,tmp_Ekin,tmp_Ekin2=0;
		double tmp_Pxyz[3]={0,0,0};
		double tmp_P;
		
		for(unsigned ii=0;ii<param->N;ii++)
		{
			for(unsigned iii=0;iii<3;iii++)
			{
				tmp_rnd=((double)rand()/RAND_MAX);
				if(tmp_rnd==0)
					tmp_rnd=1;
				
				tmp_Ekin=-units->kB*param->T0*log(tmp_rnd);  	//nie podzielono Ekin przez 2, bo
				tmp_Ekin2=tmp_Ekin;
				
				if(rand()%2)
					tmp_P*=-1;
				tmp->p[iii][ii]=tmp_P;
				
				tmp_Pxyz[iii]+=tmp_P;
			}
		}	
		
		
		tmp_Pxyz[0]/=param->N;
		tmp_Pxyz[1]/=param->N;
		tmp_Pxyz[2]/=param->N;		
		
		//tmp->Etot=0;
		for(unsigned ii=0;ii<param->N;ii++)
		{
			//free(Ekin[ii]);
			for(unsigned xyz=0;xyz<3;xyz++)
			{
				tmp->p[xyz][ii]-=tmp_Pxyz[xyz];
				//tmp->Etot+=tmp_Pxyz[xyz]*tmp_Pxyz[xyz];
			}
		}
		//free(Ekin);
		//tmp->Etot=sqrt(tmp->Etot);
		tmp_Ekin=0;
		for(unsigned ii=0;ii<param->N;ii++)
		{
			tmp_P=0;
			for(unsigned xyz=0;xyz<3;xyz++)
			{
				tmp_P+=tmp->p[xyz][ii]*tmp->p[xyz][ii];
			}
			tmp_Ekin+=sqrt(tmp_P);		
		}
		tmp_Ekin/=param->m;
		printf("2Ekin2 = %lf\n",tmp_Ekin2);
		printf("2Ekin = %lf\n",tmp_Ekin);
		printf("T(Ekin2) = %lf\n",tmp_Ekin2/(3*param->N*units->kB));
		printf("T(Ekin) = %lf\n",tmp_Ekin/(3*param->N*units->kB));
	}
	
	tmp->t=0;
}

state::~state()
{
	delete r[];
	delete p[];
	delete F[];
}
