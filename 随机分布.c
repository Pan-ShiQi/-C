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
        printf("输入μ,σ,x1,x2\n（X1,X2取无穷输入大于或小于μ+4σ）\n用空格隔开：");
        scanf("%d %d %lf %lf",&Mu,&Sigma,&x1,&x2);
        if(Sigma <= 0 || x1>x2)
        {
            printf("σ值大于0并且x1要小于等于x2，请重新输入！\n");
            goto THIS;
        }
        else
        {
            printf("X服从于（%d,%d）\n",Mu,Sigma*Sigma);
            NormalDistri(Mu,Sigma,x1,x2);
            return 0;
        }
    }
}

int HYPER_DISTRI()			//超几何分布函数 
{
	int N , M , n , k;			//输入总样本（N），样本当中的一个种类个数（M），抽取次数（n），通过计算得知的k（调用K_put函数） 
	THIS:while(1)
	{
		printf("输入总样本点,种类个数,随机次数(N)(M)(n)\n(用空格隔开):\n");			//提示输入 
		scanf("%d %d %d",&N,&M,&n);
		if (N >= M && N >= n)			//判断输入是否正确（总样本是否大于一个种类个数和抽取次数） 
		{
			printf("X服从于(%d,%d,%d),且条件成立\n\n",N,M,n);
			int M_comp = N-M;			//计算在总样本N当中除M外的个数 
			k = K_put_function(N,M,n,M_comp,k);			//调用K_put_function函数，计算k的取值 
			system("pause");
			return 0;
		} 
		else
		{
			printf("不成立，请重新输入!\n");			//while循环判断是否成立，不成立则返回重新输入 
			goto THIS;			//goto语句跳转至whlie(第6行代码) 重新输入 
		}
	}
	return 0;
}

int main()			//主函数，未来将添加二项式分布和正态分布等... 
{
	int select;
	printf("输入选择（1.超几何分布 2.正态分布）：\n");\
	scanf("%d",&select);
	switch(select)
	{
		case 1: HYPER_DISTRI();break;
		case 2: NORMAL_DISTRI();break;
	}
}
