#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <iomanip>

int main ()
{
	{
		std::cout << "===== vector ���� =====" << std::endl;
		
		std::vector<int> ivec;
		std::vector<unsigned char> ucvec;
		int *pi;
		unsigned char *puc;
		std::ifstream ifs ("ints.txt", std::ios::in | std::ios::binary);
		
		std::copy(std::istream_iterator<int>(ifs), std::istream_iterator<int>(), std::back_inserter(ivec));
		std::cout << "vector size = " << ivec.size() << std::endl;
		
		for (auto& ele : ivec) {
			std::cout << ele << "  ";
		}
		std::cout << std::endl;
				
		pi = reinterpret_cast<int*>(&ivec[0]);
		for (size_t i = 0; i < ivec.size(); i++) {
			printf("%d | ", pi[i]);
		}
		std::cout << std::endl;
		
		// unsigned char �� int �ڴ����ģ�Ͳ�һ�£���Ҫ���¶��� vector ����
		std::copy(ivec.begin(), ivec.end(), std::back_inserter(ucvec));
		
		/** 
			�ڴ����ģ�Ͳ�һ�£�һ�� int ռ 4 ���ֽڣ�һ�� char ����ռһ���ֽ�
		 */
		// puc = reinterpret_cast<int*>(pi);		// error
		puc = reinterpret_cast<unsigned char*>(&ucvec[0]);
		for (size_t i = 0; i < ucvec.size(); i++) {
			printf("%d | ", puc[i]);
		}
		std::cout << std::endl;
		
		ifs.close();
	}
	
	return 0;
}