#include <iostream>
#include <apron/core/init.hpp>

int main(int argc, char** argv) {
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Apron Init: " << init_library() << std::endl;
}