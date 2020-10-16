//输出最短最大数段
#include<stdio.h>
void gs_BF(int A[], int n);
void gs_IC(int A[], int n);
int gs_DC(int A[], int lo_DC, int hi_DC);
int max(int num1, int num2);

int main(void)
{
	int A[20] = { 1,-2,7,2,6,-9,5,6,-12,-8,13,0,0,-3,1,-2,8,0,-5,3 };
	int n = 20;

	/*for (int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	printf("\n");*/

	gs_BF(A, n);
	gs_IC(A, n);
	int t = gs_DC(A, 0, n - 1);

	printf("\n%d\n", t);

	return 0;
}

void gs_BF(int A[], int n)
{
	int lo, hi, sum, term, delta;
	int min = 0, max = 0;
	sum = A[0];
	term = 0;
	delta = 0;
	for (lo = 0; lo < n; lo++)
	{
		for (hi = lo; hi < n; hi++)
		{
			term = 0;
			for (int i = lo; i <= hi; i++)
			{
				term += A[i];
				if (/*((term = sum) && (hi - lo <= delta)) || */term > sum)//该怎么输出多个结果呢？
				{
					sum = term;
					delta = hi - lo;
					min = lo;
					max = hi;
				}
			}
		}
	}
	printf("%d, %d, %d, %d\n", sum, term, min, max);
	for (int i = min; i <= max; i++)
		printf("%d\t", A[i]);
}

void gs_IC(int A[], int n) 
{
	int lo_IC, hi_IC, sum_IC, term_IC, delta_IC;
	int min_IC = 0, max_IC = 0;
	sum_IC = A[0];
	term_IC = 0;
	delta_IC = 0;
	for (lo_IC = 0; lo_IC < n; lo_IC++)
	{
		term_IC = 0;
		for (hi_IC = lo_IC; hi_IC < n; hi_IC++)
		{
			term_IC += A[hi_IC];
			if (term_IC > sum_IC)
			{
				sum_IC = term_IC;
				min_IC = lo_IC;
				max_IC = hi_IC;
			}
		}
	}
	printf("%d, %d, %d, %d\n", sum_IC, term_IC, min_IC, max_IC);
	for (int i = min_IC; i <= max_IC; i++)
		printf("%d\t", A[i]);
}

int gs_DC(int A[], int lo_DC, int hi_DC)
{
	if (hi_DC - lo_DC < 2) return A[lo_DC];

	int sL, gsL, sR, gsR, mi, i;
	mi = (lo_DC + hi_DC) >> 1;

	gsL = A[mi - 1];sL= 0; i = mi;
	for (; i >= lo_DC; --i)
	{
		if (gsL < (sL += A[i]))
			gsL = sL;
	}

	gsR = A[mi]; sR = 0; i = mi;
	for (; i <= hi_DC; i++)
	{
		if (gsR < (sR += A[i]))
			gsR = sR;
	}
	/*printf("%d\n", max);*/
	return max(gsL + gsR, max(gs_DC(A, lo_DC, mi - 1), gs_DC(A, mi, hi_DC)));
}

int max(int num1, int num2)
{
	return num1 >= num2 ? num1 : num2;
}