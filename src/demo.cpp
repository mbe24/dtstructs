#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <unbound_array.hpp>

using namespace datastructures;
using namespace std;

template<typename T, size_t ALPHA, size_t BETA>
auto testArray(UnboundArray<T, ALPHA, BETA> &a, int num) -> void;

auto main(int argc, char** argv) -> int
{

	int num = 1000000;

	std::cout << "Test of datastruct UnboundArray<int, 4, 2>" << std::endl;
	UnboundArray<int, 4, 2> a;
	testArray(a, num);
	
	std::cout << "Test of datastruct UnboundArray<int, 3, 2>" << std::endl;
	UnboundArray<int, 4, 2> b;
	testArray(b, num);
	
	std::cout << "Test of datastruct UnboundArray<int, 5, 3>" << std::endl;
	UnboundArray<int, 4, 2> c;
	testArray(c, num);

	return 0;
}

template<typename T, size_t ALPHA = 4, size_t BETA = 2>
auto testArray(UnboundArray<T, ALPHA, BETA> &a, int num) -> void 
{
	struct timeval start, end;
	//std::cout << std::endl << "Size is " << a.size() << std::endl << std::endl;

	gettimeofday(&start, NULL);
	for (int i = 0; i < num; ++i)
	{
		a.pushBack(i);
		//std::cout << "Adding " << i << " to UnboundArray." << std::endl;
	}

	//std::cout << std::endl << "Size is " << a.size() << std::endl;

	//for (int i = 0; i < num; ++i) {
	//std::cout << "array[" << i << "] = " << a->operator [](i) << std::endl;
	//}

	for (int i = num - 1; i >= 0; i--)
	{
		a.popBack();
		//int c = a.popBack();
		//std::cout << "Popping " << c << std::endl;
	}
	gettimeofday(&end, NULL);
	long mtime, seconds, useconds;

	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;

	mtime = ((seconds) * 10000000 + useconds) / 1000;

	//std::cout << std::endl << "Size is " << a.size() << std::endl << std::endl;
	std::cout << "Time elapsed: " << mtime << "ms." << std::endl;
}