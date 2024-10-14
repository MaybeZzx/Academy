#include "func.h"

/*
	—ъешь же ещЄ этих м€гких французских булок, да выпей чаю.
	C]tim ;t to` 'nb[ vzurb[ ahfywepcrb[ ,ekjr? lf dsgtq xf./
*/


int main()
{


	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string file = "text1.txt";
	Encrypt(file, 3);
}