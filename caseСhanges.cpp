#include <iostream>
#include <string>
#include <locale>
#include <codecvt>  // Для wstring_convert
#include <algorithm>

std::wstring stringToWstring(const std::string &str) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(str);
}

std::string wstringToString(const std::wstring &wstr) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.to_bytes(wstr);
}

std::wstring toUpperRussian(const std::wstring &str) {
	std::locale loc("ru_RU.UTF-8"); // Указываем русскую локаль
	std::wstring result = str;
	for (wchar_t& c : result) {
		c = std::toupper(c, loc);
	}
	return result;
}

int main()
{

	std::string chLetter; // Переменная которая хранит всего один символ.
	//setlocale(LC_ALL, "Russian"); // Перевод кодирования символов на русский (Макрос LC_ALL относится ко всем категориям локализации(Всё переводит на Русский)).
	//							  // Короче русские символы корректно отображаются.
	std::cout << "Введите букву нижнего регистра:\n\n" << std::endl;
	/*std::wcin >> chLetter;*/
	std::getline(std::cin, chLetter);
	std::wstring wide_string = stringToWstring(chLetter);
	//chLetter = chLetter - 32; // Способ которым переводят нижний регистр в верхний регистр.
	std::wstring upperCaseString = toUpperRussian(wide_string);
	std::string FinalResult = wstringToString(upperCaseString);
	std::cout << "\nТа же буква в верхнем регистре: " << FinalResult << ".\n\n" << std::endl;
	return 0;
}