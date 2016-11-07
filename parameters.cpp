#include <iostream>
#include <fstream>
#include <stdlib>

#include "argon.hpp"

parameters::parameters(char* input)
{
	FILE *input=fopen(input,"r");
	
	if(input==NULL)
	{
		free(tmp);
		fprintf(stderr,"Nie można otworzyć pliku %s\n",file);
		exit(2);
	}
		
	int i=0;
	i+=fscanf(input,"%i",n);
	i+=fscanf(input,"%lf",m);
	i+=fscanf(input,"%lf",eps);
	i+=fscanf(input,"%lf",R);
	i+=fscanf(input,"%lf",f);
	i+=fscanf(input,"%lf",L);
	i+=fscanf(input,"%lf",a);
	i+=fscanf(input,"%lf",T0);
	i+=fscanf(input,"%lf",tau);
	i+=fscanf(input,"%u",S0);
	i+=fscanf(input,"%u",Sd);
	i+=fscanf(input,"%u",Sxyz);
	i+=fscanf(input,"%u",Sout);
	flcose(input);
	
	if(i==0)
	{
		free(tmp);
		fprintf(stderr,"Błąd czytania pliku %s\n",file);
		exit(3);
	}
	
	nm=1e-9;
	ps=1e-12;
	u=1.6605402e-27;
	kB=8.31e-3;
	
	fprintf(stderr,"S0 = %u\n",tmp->S0);
	fprintf(stderr,"Sd = %u\n",tmp->Sd);
	fprintf(stderr,"Sxyz = %u\n",tmp->Sxyz);
	fprintf(stderr,"Sout = %u\n",tmp->Sout);
}
