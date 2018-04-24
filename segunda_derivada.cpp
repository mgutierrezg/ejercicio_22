#include <iostream>
#include <math.h>
using namespace std;

double gaussian(double sigma,double media,double x)
{
	return exp(-pow((x-media)/sigma,2)*0.5);
}

void u_in(double* u, double delta_x, double x_min, int n,double sigma,double media,double x){
  for (int i=0; i<n; i++){
    x = x_min + i*delta_x;
    u[i] = gaussian(sigma, media, x);
    }
}
int main(){
  double delta_x = 0.03, delta_t = 0.00001;
  double x_min = 0.0, x_max = 2.0;
  double T = 0.5, D =1.0;
  double sigma = 0.1;
  double media = 1.0;
  double x=0;
  double delta_x_cuadrado = delta_x * delta_x;
  int nx = (x_max-x_min)/delta_x + 1;
  int nt = T/delta_t +1; 
  double *u_nuevo;
  double *u_viejo;
  double *u_ini;
  u_nuevo= new double[nx];
  u_viejo= new double[nx];
  u_ini = new double[nx];
  u_in(u_ini,delta_x,x_min, nx,sigma,media,x);
  u_in(u_viejo,delta_x,x_min, nx, sigma,media,x);

 
  for(int j=1;j<nt;j++){
    u_nuevo[0]=0;
    u_nuevo[nx-1]=0;
    
  for(int i=1;i<nx-1;i++)
      {
	u_nuevo[i]=(D*delta_t*((u_viejo[i+1]-2*u_viejo[i]+u_viejo[i-1]))/delta_x_cuadrado)+u_viejo[i];
      }
  for(int i=0;i<nx;i++)
      {
	u_viejo[i]=u_nuevo[i];
      }
  }
  x=0;		
  for(int i=0;i<nx;i++)
    {
      x= x_min + i*delta_x;
      cout<<x<<" "<<  u_ini[i]<< " " <<u_nuevo[i]<<endl;
    }
return
0;
  
}
