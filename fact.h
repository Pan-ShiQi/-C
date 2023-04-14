#include<stdio.h>
extern int fact (int j)			//HyperDistri.c 6 ~ 9 行进行调用传参 
{
	if(j == 0)			//判断是否等于零 （ 0 的阶乘为 1 ） 
	{
		return j = 1;			//返回 1  
	}
	else			//temp = j * temp 连乘 
	{
		int temp = 1;
		for(j;j>0;j--)
		{
			temp = j * temp;
		}
		return temp;			//返回连乘结果 
	}
} 
