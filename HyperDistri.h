//�����ηֲ��ⲿ�������� 
#include <stdio.h> 
#include <math.h>
#include"fact.h"			//�ⲿ�ļ� 
extern float E_D_X(int N,int M,int n)
{
	float E_X = (float)n*(float)N/(float)M;
	float D_X = E_X*(1-(float)N/(float)M);
	printf("����Ϊ��%f\n",E_X);
	printf("����Ϊ��%f\n",D_X);
}

extern int HyperDistri_function(int N,int M,int n,int M_comp,int k)			//�����ηֲ����㺯�� 
{
    double C_M_k = fact(M)/fact(k)/fact(M-k);  			//C M k
    double C_NM_nk = fact(N-M)/fact(n-k)/fact(N-M-n+k);  			//C N-M n-k
    double C_N_n = fact(n)*fact(N-n);  			//C N n		δ����fact(N)	
    double P_X = C_M_k*C_NM_nk*C_N_n/fact(N);			//��˲�����fact(N) 
    printf("P(X = %d) = %.3lf \n",k,P_X);  			//�� K_put_function���ú������� P(X = k) 
}

extern int K_put_function(int N,int M,int n,int M_comp,int k)			//K_put_function����������k��ȡֵ �����ж�k��ȡֵ�� 
{
	//����Ϊ�ж�k��ȡֵ n �� M_comp �� M
	if(n >= M_comp)
	{
		k = n-M_comp;
		if (n >= M)
		{
			for(k;k<=M;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//kȡֵ(n-N+M ~ M)
			}	
		}
		else
		{
			for(k;k<=n;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//kȡֵ(n-N+M ~ n) 
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
				HyperDistri_function(N,M,n,M_comp,k);			//kȡֵ(0 ~ M) 
			}
		}
		else
		{
			for(k;k<=n;k++)
			{
				printf("k = %d\t",k);
				HyperDistri_function(N,M,n,M_comp,k);			//kȡֵ(0 ~ n) 
			}
		}
	}
	printf("\n");
	E_D_X(N,M,n);
}
