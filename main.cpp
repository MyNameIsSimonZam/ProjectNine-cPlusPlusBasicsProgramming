#include <iostream>

void task1();
void task2();

int main() {
	int choice;

	do {
		std::cout << "Choose a task to run\n";
		std::cout << "1. Задача 1\n";
		std::cout << "2. Задача 2\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		default:
			std::cout << "Invalid choice...\n";
		}
	} while (choice !=1 && choice != 2);

	return 0;
}