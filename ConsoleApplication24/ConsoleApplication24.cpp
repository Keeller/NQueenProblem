// ConsoleApplication24.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<cstdlib>
#include<random>
#include<ctime>
#include<cmath>
using M = std::vector<int>;

class Prog
{
private:
	M pos;
	int N;
	double T = 100;
	double alpha = 0.95;
	
public:
	Prog(int N)
	{
		if ((N > 1) && (N < 4))
			throw"1<N<4";
		srand(time(NULL));
		for (int i = 0; i < N; ++i)
		{
			pos.push_back(i);
		}
		this->N = N;
	}
	
	unsigned int h(M& pos)
	{
		unsigned int res = 0;
		for (int i = 0; i < N; i++)
		{
			int k = i - 1;
			while (k >= 0)//reverse
			{
				if (pos[k] == (pos[i]+(i-k)))
					res += 1;
				if (pos[k] == (pos[i] - (i - k)))
					res += 1;
				k -= 1;
			}
			k = i + 1;
			while (k < N)//forward
			{
				if (pos[k] == (pos[i] + (k - i)))
					res += 1;
				if (pos[k] == (pos[i]) - (k - i))
					res += 1;
				k += 1;
			}
		}
		return res;
	}

	void psi(M& pos)
	{
		int i = 0;
		int j = 0;
		
		while (i == j)
		{
			i = rand() % N;
			j = rand() % N;
		}
		std::swap(pos[i],pos[j]);
	}

	void run()
	{
		std::random_device rd;
		std::default_random_engine gen(rd());
		std::uniform_real_distribution<double> distr((double)0, (double)1);
		while ((T > 0)&&(h(this->pos)!=0))
		{
			int h1 = h(this->pos);
			M v = pos;
			psi(v);
			int h2 = h(v);
			double dh = h2 - h1;
			T *= alpha;
			if (dh < 0)
				this->pos = v;
			else
			{
				double p=exp(-dh/this->T);

				if (p > distr(gen))
					this->pos = v;
				
			}


		}
	}

	void print()
	{
		std::cout << "[";
		for (int i = 0; i < N; i++)
		{
			std::cout << pos[i] << ", ";
		}
		std::cout << "]" << std::endl;
	}
};




int main()
{
	unsigned int start_time = clock();
	Prog p = Prog(8);
	p.run();
	p.print();
	unsigned int end_time = clock();
	std::cout << "Runtime: " << ((start_time - end_time)/ 1000.0) << std::endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
