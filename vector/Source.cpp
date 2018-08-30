#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <iostream>


using namespace std;


class arr_data
{
public:
	vector<double> arr_;
	void cr_arr();

//	void cr_arr(double(*ff)(double));

	template <typename FUN>
	void cr_arr(FUN ff)
	{
		for (size_t i = 0; i <= N_; ++i)
		{
			double x = x1_ + (x2_ - x1_)*i / N_;
			arr_.push_back(ff(x));
		}
	}

	double get_h() const
	{
		return abs(x2_ - x1_) / N_;
	}

	size_t N_;
	double x1_, x2_;
};

void arr_data::cr_arr()
{
#if 0
	cr_arr(sin);
#else
	for (size_t i = 0; i <= N_; ++i)
	{
		double x = x1_ + (x2_ - x1_)*i / N_;
		arr_.push_back(sin(x));
	}
#endif
}

#if 0 
void arr_data::cr_arr(double(*ff)(double))
{
	for (size_t i = 0; i <= N_; ++i)
	{
		double x = x1_ + (x2_ - x1_)*i / N_;
		arr_.push_back(ff(x));
	}
}
#endif
double int1(const arr_data & vec)
{
	double sum = 0;
	double h = vec.get_h();
	for (size_t i = 0; i < vec.arr_.size() - 1; ++i)
	{
		sum +=vec.arr_[i];
	}
	return sum *h;
}

double int2(const arr_data & vec)
{
	double sum = 0;
	double h = vec.get_h();
	for (size_t i = 1; i < vec.arr_.size(); ++i)
	{
		sum += vec.arr_[i];
	}
	return sum * h;
}

double int3(const arr_data & vec)
{
	double sum = 0;
	double h = vec.get_h();
	for (size_t i = 0; i < vec.arr_.size() - 1; ++i)
	{
		sum += (vec.arr_[i]+vec.arr_[i+1])/2;
	}
	return sum * h;
}

double sss(double x)
{
	return x * x;
}

template <typename T>
struct sqrA
{
	T A_;
	T operator()(T x)
	{
		return A_ * x*x;
	}
};
void int4(int n, double s)
{
	double a, b;
//	a = 0; b = M_PI / 2;
	a = 0; b = 1;

	arr_data ans;
	ans.x1_ = a;
	ans.x2_ = b;
	ans.N_ = n;
//	ans.cr_arr(sss);
	sqrA<double> hh;
	hh.A_ = 1.;
	ans.cr_arr(hh);
	const double result1 = int1(ans);
	const double result2 = int2(ans);
	const double result3 = int3(ans);
	cout << n << " "<< s 
		<< " " << s - result1 
		<< " " << s - result2
		<< " " << s - result3
		<< endl;
}

int main()
{
	int n1;
	double a, b;
	n1 = 100;
	a = 0; b = M_PI/2;
	int4(2, 1/3.);
	int4(5, 1/3.);
	int4(10, 1/3.);
	int4(20, 1/3.);
	int4(50, 1/3.);
	int4(100, 1/3.);
	int4(200, 1/3.);
	int4(500, 1/3.);
	int4(1000, 1/3.);
	int4(2000, 1/3.);
	int4(5000, 1/3.);
	int4(10000, 1/3.);
	int4(100000, 1/3.);
	//int4(1000000, 1/3.);
	//int4(10000000, 1/3.);
}
