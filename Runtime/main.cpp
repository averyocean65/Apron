#include <iostream>
#include <apron/core/init.hpp>

int main(int argc, char** argv) {
	std::cout << "Hello, World!\n";
	std::cout << "Apron Init: " << init_library() << "\n";
}