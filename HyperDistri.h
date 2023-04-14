//超几何分布外部函数调用 
#include <stdio.h> 
#include <math.h>
#include"fact.h"			//外部文件 
extern float E_D_X(int N,int M,int n)
{
	float E_X = (float)n*(float)N/(float)M;
	float D_X = E_X*(1-(float)N/(float)M);
	printf("期望为：%f\n",E_X);
	printf("方差为：%f\n",D_X);
}

extern int HyperDistri_function(int N,int M,int n,int M_comp,int k)			//超几何分布计算函数 
{
    double C_M_k = fact(M)/fact(k)/fact(M-k);  			//C M k
    double C_NM_nk = fact(N-M)/fact(n-k)/fact(N-M-n+k);  			//C N-M n-k
    double C_N_n = fact(n)*fact(N-n);  			//C N n		未除以fact(N)	
    double P_X = C_M_k*C_NM_nk*C_N_n/fact(N);			//相乘并除以fact(N) 
    printf("P(X = %d) = %.3lf \n",k,P_X);  			//被 K_put_function调用后遍历输出 P(X = k) 
}

extern int K_put_function(int N,int M,int n,int M_comp,int k)			//K_put_function函数，计算k的取值 （并判断k的取值） 
{
	//以下为判断k的取值 n 与 M_comp 、 M
	if(n >= M_comp)
	{
		k = n-M_comp;
		if (n >= M)
		{
			for(k;k<=M;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//k取值(n-N+M ~ M)
			}	
		}
		else
		{
			for(k;k<=n;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//k取值(n-N+M ~ n) 
			}
		}
	}
	else
	{
		k = 0;
		if(n >= M)
		{
			for(k;k<=M;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//k取值(0 ~ M) 
			}
		}
		else
		{
			for(k;k<=n;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//k取值(0 ~ n) 
			}
		}
	}
	printf("\n");
	E_D_X(N,M,n);
}
