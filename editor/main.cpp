#include <iostream>
#include "engine/core.hpp"

using std::cout, std::endl;
using namespace focus;

template<typename T>
void print_type(const T& thing)
{
	cout << typeid(thing).name() << endl;
}

int main(int argc, char** argv)
{
	Application app("Focus Editor");
	app.info("Editor ready");

	return 0;
}