#include<stdio.h>
extern int fact (int j)			//HyperDistri.c 6 ~ 9 �н��е��ô��� 
{
	if(j == 0)			//�ж��Ƿ������ �� 0 �Ľ׳�Ϊ 1 �� 
	{
		return j = 1;			//���� 1  
	}
	else			//temp = j * temp ���� 
	{
		int temp = 1;
		for(j;j>0;j--)
		{
			temp = j * temp;
		}
		return temp;			//�������˽�� 
	}
} 
