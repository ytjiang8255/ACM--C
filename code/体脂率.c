#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
女性的身体脂肪公式
参数a = 腰围-公分(腰部的周长) x 0.74
参数b = (总体重-公斤 x 0.082) + 34.89
    身体脂肪总重量-公斤 = a - b
   身体脂肪百分比= (身体脂肪总重量÷ 体重) x 100%

1. 男性的身体脂肪公式
 参数a = 腰围-公分 x 0.74
 参数b = <wbr> (体重-公斤 x 0.082) + 44.74
 身体脂肪总重量-公斤= a - b
 体脂率(身体脂肪百分比) = (身体脂肪总重量÷ 体重) x 100%
 
 
2. 体脂率：1.2×BMI+0.23×年龄-5.4-10.8×性别（男为1，女为0）
============================================================
理想的体脂肪率，男性体脂肪若超过25﹪，女性若超过30﹪则可判定为肥胖。

理想体脂率范围

男性<wbr>
30岁以下	14－20﹪
30岁以上	17－23﹪
＞25﹪		肥胖

女性
30岁以下	17－24﹪
30岁以上	20－27﹪
＞30﹪		肥胖
**/
double BMI_female(double weight, double height, double waistline, double age);

double BMI_male(double weight, double height, double waistline, double age);

int main()
{
	double weight, height, waistline, age;
	int f;
	printf("input weight(kg), height(m), waistline(cm), age:\n");
	while (scanf("%lf%lf%lf%lf", &weight, &height, &waistline, &age) && (weight && height && waistline && age))
	{
		printf("input male/female(1/0):\t");
		scanf("%d", &f);
		if (f)
			BMI_male(weight, height, waistline, age);
		else
			BMI_female(weight, height, waistline, age);

	}

	return 0;
}
double BMI_male(double weight, double height, double waistline, double age)
{
	double bmi = 0;
	printf("正常体重范围kg（%.2lf~~~%.2lf)\t超重： %.2lfkg\n", 18.5*(height*height), 25* (height*height), weight - 24 * (height*height));
	bmi = weight / (height*height);
	printf("正常BMI（18.5~~~25.0)\n你的 BMI = %.2lf\n", bmi);
	bmi = 1.2*bmi + 0.23 * age - 5.4 - 10.8;
	double a = waistline*0.74;
	double b = weight*0.082 + 44.74;
	printf("脂肪总质量 = %.2lfkg\n\n", a - b);
	printf("脂肪比 = %.2lf\n", 100*(a - b) / weight);
	printf("体脂率 = %.2lf\n", bmi);
	printf("平均体脂率 = %.2lf\n", (bmi + (100 * (a - b) / weight))/2);
	return bmi;
}
double BMI_female(double weight, double height, double waistline, double age)
{
	double bmi = 0;
	printf("正常体重范围 （%.2lf~~~%.2lf)\t超重： (%.2lf)kg\n", 18.5*(height*height), 25 * (height*height), weight - 24 * (height*height));
	bmi = weight / (height*height);
	printf("正常体重范围kg（18.5~~~25.0)\n你的 BMI = %.2lf\n", bmi);
	double a = waistline*0.74;
	double b = weight*0.082 + 44.74;
	printf("脂肪总质量 = %.2lf\n", a - b);
	printf("脂肪比 = %.2lf\n", 100*(a - b)/weight);
	bmi = 1.2*bmi + 0.23 * age - 5.4;
	printf("体脂率 = %.2lf\n", bmi);
	return bmi;
}