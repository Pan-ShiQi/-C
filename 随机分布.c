#include <stdio.h>
#include <stdlib.h>
#include "HyperDistri.h"
#include "NormalDistri.h"
double NORMAL_DISTRI()
{
    int Mu,Sigma;
    double x1,x2;
    THIS:while(1)
    {
        printf("�����,��,x1,x2\n��X1,X2ȡ����������ڻ�С�ڦ�+4�ң�\n�ÿո������");
        scanf("%d %d %lf %lf",&Mu,&Sigma,&x1,&x2);
        if(Sigma <= 0 || x1>x2)
        {
            printf("��ֵ����0����x1ҪС�ڵ���x2�����������룡\n");
            goto THIS;
        }
        else
        {
            printf("X�����ڣ�%d,%d��\n",Mu,Sigma*Sigma);
            NormalDistri(Mu,Sigma,x1,x2);
            return 0;
        }
    }
}

int HYPER_DISTRI()			//�����ηֲ����� 
{
	int N , M , n , k;			//������������N�����������е�һ�����������M������ȡ������n����ͨ�������֪��k������K_put������ 
	THIS:while(1)
	{
		printf("������������,�������,�������(N)(M)(n)\n(�ÿո����):\n");			//��ʾ���� 
		scanf("%d %d %d",&N,&M,&n);
		if (N >= M && N >= n)			//�ж������Ƿ���ȷ���������Ƿ����һ����������ͳ�ȡ������ 
		{
			printf("X������(%d,%d,%d),����������\n\n",N,M,n);
			int M_comp = N-M;			//������������N���г�M��ĸ��� 
			k = K_put_function(N,M,n,M_comp,k);			//����K_put_function����������k��ȡֵ 
			system("pause");
			return 0;
		} 
		else
		{
			printf("������������������!\n");			//whileѭ���ж��Ƿ�������������򷵻��������� 
			goto THIS;			//goto�����ת��whlie(��6�д���) �������� 
		}
	}
	return 0;
}

int main()			//��������δ������Ӷ���ʽ�ֲ�����̬�ֲ���... 
{
	int select;
	printf("����ѡ��1.�����ηֲ� 2.��̬�ֲ�����\n");\
	scanf("%d",&select);
	switch(select)
	{
		case 1: HYPER_DISTRI();break;
		case 2: NORMAL_DISTRI();break;
	}
}
