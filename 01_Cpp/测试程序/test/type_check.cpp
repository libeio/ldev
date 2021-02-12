#include <iostream>

class Apple;
class Orange;

class Orange
{
public:
	Orange() {}
	explicit Orange(const Apple& apple) { std::cout << "In orange" << std::endl; }
public:
	void DoSomethingWithOrange(const Orange& orange) {}
};

class Apple
{
public:
	operator Orange () const { std::cout << "In apple" << std::endl; }
};

int main() {
	Apple a;
	Orange oa(a);					// ���� Orange �п������캯��
	
	Orange o;
	o.DoSomethingWithOrange(a);		// ���� Apple �� Orange ����������

	return 0;
}
