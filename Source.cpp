#include <iostream>
#include <string>

/*Задача 1
Напишите программу, которая принимает от пользователя текст (то есть некоторую строку)
и ещё слово (то есть ещё строку) и подсчитывает, сколько раз слово встречается в тексте.
Более точно: сколько в данном тексте существует позиций,
начиная с которых можно прочитать данное слово.

Замечание. Если вводить строку обычным способом с помощью команды std::cin >> s,
то С++ проигнорирует все символы после первого пробела, потому что пробел
по умолчанию считается концом вводимой строки. Чтобы ввести строку с пробелами,
нужно вместо команды
std::cin >> str;
использовать команду
std::getline(std::cin, str);

Пример ввода
mama myla ramu
my
Ответ: 1.
Пример ввода:
abudabudabdab
dab
Ответ: 3.*/

void task1() {
	std::string str, word;
	int result = 0;

	std::cin.ignore(10000, '\n');
	std::cout << "Please, input the string: ";
	std::getline(std::cin, str);
	std::cout << "Please, input the word: ";
	std::getline(std::cin, word);

	for (int i = 0; i <= str.length() - word.length(); ++i) {
		if (str[i] == word[0]) {
			for (int j = 0; j < word.length(); ++j) {
				if (str[i + j] != word[j])
					break;
				else if (j == word.length() - 1) ++result;
			}
		}
	}
	std::cout << "Result is: " << result << "\n";
};

/*Задача 2
Напишите программу, которая проверяет, верно ли, что данная строка представляет из себя
некоторую другую строку, повторённую несколько раз.
Например, строка dabudabudabu — это трижды повторённая строка dabu.
Строка kapkap — это дважды повторённая строка kap. А вот строку abdabdab
или строку gogolmogol нельзя представить как повторение некоторой другой строки.
На вход программа должна принимать строку и выдавать ответ Yes,
если строка является повторением некоторой другой строки, и No, если это не так.
*/

void task2() {
	std::string str;
	std::cout << "Input a word: ";
	std::cin >> str;

	bool match = false;

	for (int startPos = 1; startPos <= str.length() / 2; ++startPos) {

		if (str.length() % startPos != 0) continue;

		std::string pattern = str.substr(0, startPos);
		match = true;

		for (int i = 0; i < str.length(); ++i) {
			if (str[i] != pattern[i % startPos]) {
				match = false;
				break;
			}
		}
		if (match) break;
	}
	if (match) std::cout << "Yes\n";
	else std::cout << "No\n";
};






