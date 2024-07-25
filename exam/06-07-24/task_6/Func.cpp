#include "Func.h"

unsigned short const DELAY = 700;

void Start()
{
	std::vector<Song> catalog;
	int userChoice = 1;
	Song tempObj;
	std::filesystem::create_directory("Songs");
	std::filesystem::create_directory("TextToInput");

	while (userChoice != 0)
	{
		system("cls");

		std::cout << "\tКаталог текстов песен" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << " 1. Добавление песни" << std::endl;
		std::cout << " 2. Добавление текста песни" << std::endl;
		std::cout << " 3. Удаление текста песни" << std::endl;
		std::cout << " 4. Изменение текста песни" << std::endl;
		std::cout << " 5. Отображение текста песни на экран" << std::endl;
		std::cout << " 6. Сохранение текста песни в файл" << std::endl;
		std::cout << " 7. Поиск по автору" << std::endl;
		std::cout << " 8. Поиск по конкретному слову" << std::endl;
		std::cout << " 9. Отображение списка песен" << std::endl;
		std::cout << " 0. Выход" << std::endl;
		
		do 
		{
			std::cout << ": ";
			std::cin >> userChoice;
		} while (userChoice < 0 || userChoice > 9);
		system("cls");
		int addTextChoice;
		switch (userChoice)
		{
		case 1:
			AddSong(catalog);
			break;
		case 2:
			system("cls");
			std::cout << " 1. Ввести текст с клавиатуры" << std::endl;
			std::cout << " 2. Добавить текст с файла" << std::endl;
			std::cout << ": ";

			std::cin >> addTextChoice;
			system("cls");
			std::cout << "Введите название песни: ";
			std::getline(std::cin >> std::ws, tempObj.title);

			switch (addTextChoice)
			{
			case 1:
				AddLyrics(catalog, tempObj.title);
				break;
			case 2:
				AddLyricsFromFile(catalog, tempObj.title);
				break;
			}
			break;
		case 3:
			std::cout << "Введите название песни: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			DeleteLyrics(catalog, tempObj.title);
			break;
		case 4:
			std::cout << "Введите название песни: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			ChangeLyric(catalog, tempObj.title);
			break;
		case 5:
			std::cout << "Введите название песни: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			ShowLyrics(catalog, tempObj.title);
			break;
		case 6:
			std::cout << "Введите название песни: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			SaveLyricsToFile(catalog, tempObj.title);
			break;
		case 7:
			std::cout << "Введите автора: ";
			std::getline(std::cin >> std::ws, tempObj.author);
			FindByAuthor(catalog, tempObj.author);
			break;
		case 8:
			std::cout << "Введите слово: ";
			std::getline(std::cin >> std::ws, tempObj.lyrics);
			FindByWord(catalog, tempObj.lyrics);
			break;
		case 9:
			if (!catalog.empty())
			{
				std::cout << "\tСписок песен\n" << std::endl;
				for (size_t i = 0; i < catalog.size(); ++i)
				{
					std::cout << "Автор: " << catalog[i].author << std::endl;
					std::cout << "Название: " << catalog[i].title << std::endl;
					std::cout << "=========================" << std::endl;
				}
				std::cout << "\n\tY - вернуться в меню" << std::endl;
				std::cout << ": ";
				char symb;
				std::cin >> symb;
				while (symb != 'y' && symb != 'Y')
				{
					std::cout << ": ";
					std::cin >> symb;
				}
			}
			else
			{
				std::cout << "Каталог пуст";
				Sleep(DELAY);

			}
			break;
		case 0:
			std::cout << "Выход..." << std::endl;
			break;
		default:
			break;
		}
	}
	SaveToFile(catalog, "Catalog");
}

void SaveToFile(std::vector<Song>& catalog, std::string fileName)
{
	std::ofstream outputFile("Songs\\" + fileName + ".txt");

	if (!outputFile.is_open())
	{
		std::cout << "Ошибка открытия файла!" << std::endl;
		return;
	}

	for (size_t i = 0; i < catalog.size(); ++i)
	{
		outputFile << "[" << i + 1 << "]" << std::endl;
		outputFile << " Название: " << catalog[i].title << std::endl;
		outputFile << " Автор: " << catalog[i].author<< std::endl;
		outputFile << " Год выпуска: " << catalog[i].year << std::endl;
		outputFile << " Текст: " << std::endl;
		outputFile << "  " << catalog[i].lyrics << std::endl << std::endl;
	}
	outputFile.close();
	std::cout << "Файл успешно сохранен" << std::endl;
	Sleep(DELAY);
}

void SaveLyricsToFile(std::vector<Song>& catalog, std::string& title)
{
	auto const it = FindSongIndex(catalog, title);

	if (FindSong(catalog, title))
	{
		std::ofstream fout("Songs\\" + title+".txt");
		if (fout.is_open())
		{
			fout << "Название: " << title << std::endl;
			fout << "Текст: " << std::endl;
			fout << "  " << it->lyrics << std::endl;
		}
		fout.close();
		std::cout << "Файл успешно сохранен" << std::endl;
		Sleep(DELAY);
	}
	else
	{
		std::cout << "Песня не найдена";
		Sleep(DELAY);
	}
}

void AddSong(std::vector<Song>& catalog)
{
	Song newSong;
	std::cout << "Введите название песни: ";
	std::getline(std::cin >> std::ws, newSong.title);
	std::cout << "Введите автора песни: ";
	std::getline(std::cin >> std::ws, newSong.author);
	std::cout << "Введите год выпуска песни (- если неизвестен): ";
	std::getline(std::cin >> std::ws, newSong.year);
	std::cout << "Введите текст песни (* - переход на новую строку \\ - если неизвестен): ";
	std::getline(std::cin >> std::ws, newSong.lyrics);
	if (newSong.lyrics == "-")
	{
		newSong.lyrics = "";
	}
	int size = catalog.size();
	AddEnter(newSong.lyrics);
	catalog.push_back(newSong);
	int newSize = catalog.size();

	if (size < newSize)
	{
		std::cout << "Песня успешно добавлена!" << std::endl;
	}
	else
	{
		std::cout << "Ошибка в добавлении песни!" << std::endl;
	}
}

void AddLyrics(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);

	if (it->lyrics != "")
	{
		std::cout << "У песни уже есть текст. Попробуйте изменить его" << std::endl;
		Sleep(DELAY);
		return;
	}

	std::cout << "Песня: " << title << std::endl;
	std::cout << "Введите текст (* - переход на новую строку): ";
	std::getline(std::cin >> std::ws, it->lyrics);
	std::cout << "Текст песни успешно добавлен!";

	AddEnter(it->lyrics);
	Sleep(DELAY);
}

void AddLyricsFromFile(std::vector<Song>& catalog, std::string& title)
{
	if(FindSong(catalog, title))
	{
		auto const it = FindSongIndex(catalog, title);
		system("cls");
		std::cout << "\tФайл должен находиться в папке TextToInput!\n" << std::endl;
		std::cout << "Введите название файла: ";
		std::string fileName;
		std::getline(std::cin >> std::ws, fileName);
		std::ifstream fin("TextToInput\\" + fileName + ".txt");
		std::string fileStr;
		std::string lyric = "";
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				fileStr = "";
				std::getline(fin, fileStr);
				lyric += fileStr + "*";
			}
			AddEnter(lyric);
			it->lyrics = lyric;
			std::cout << "Текст успешно добавлен" << std::endl;
			Sleep(DELAY);
		}
		else
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
			Sleep(DELAY);
		}
	}
	else
	{
		std::cout << "Песня не найдена";
		Sleep(DELAY);
	}
}

void DeleteLyrics(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);
	if (FindSong(catalog, title))
	{
		std::cout << "Песня: " << title << std::endl;
		std::cout << "Подтвердите действие: ";

		if (ConfirmAction(Actions::Delete, title))
		{
			system("cls");
			it->lyrics = "";
			std::cout << "Песня: " << title << std::endl;
			std::cout << "Текст успешно удален";
		}
		else
		{
			std::cout << "Действие отменено" << std::endl;
		}
	}
	else
	{
		std::cout << "Песня не найдена";
		Sleep(DELAY);
	}
}

void ChangeLyric(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);
	if(FindSong(catalog, title))
	{
		std::cout << "Песня: " << it->title << std::endl;
		std::cout << "Текст: " << std::endl;
		PrintLyric(catalog, it->title);

		std::cout << "Введите новый текст(* - переход на новую строку): ";
		std::string newLyric;
		std::getline(std::cin >> std::ws, newLyric);

		AddEnter(newLyric);
		system("cls");
		std::cout << "Песня: " << it->title << std::endl;
		std::cout << "Старый текст песни: " << it->lyrics << std::endl;
		std::cout << "Новый текст песни: \n  " << newLyric << std::endl;
		std::cout << "Подтвердите действие: ";

		if (ConfirmAction(Actions::ChangeLyrics, title))
		{
			it->lyrics = newLyric;
			std::cout << "Текст песни успешно изменен" << std::endl;
			Sleep(DELAY);
		}
		else
		{
			std::cout << "Действие отменено";
			Sleep(DELAY);
		}
	}
	else
	{
		std::cout << "Песня не найдена";
	}
}

void AddEnter(std::string& lyric)
{
	size_t pos = 0;
	while ((pos = lyric.find("*")) != std::string::npos)
	{
		lyric.replace(pos, 1, "\n  ");
	}
}

void ShowLyrics(std::vector<Song>& catalog, std::string const& title)
{
	if (FindSong(catalog, title))
	{
		std::cout << "Песня: " << title << std::endl;
		PrintLyric(catalog, title);
		std::cout << "\n\tY - вернуться в меню" << std::endl;
		std::cout << ": ";
		char symb;
		std::cin >> symb;
		while (symb != 'y' && symb != 'Y')
		{
			std::cout << ": ";
			std::cin >> symb;
		}
	}
	else
	{
		std::cout << "Песня не найдена!";
		Sleep(DELAY);
	}
	
}

void PrintLyric(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);
	std::cout << "  " << it->lyrics << std::endl;
}

bool ConfirmAction(Actions const& action, std::string const& title)
{
	char symb;
	switch (action)
	{
	case Delete:
		std::cout << " Удалить текст песни \"" << title << "\"" << std::endl;
		break;
	case ChangeLyrics:
		std::cout << " Изменить текст песни \"" << title << "\"" << std::endl;
		break;
	case AddLyricFromFile:
		std::cout << " Добавить текст песни \""<< title << "\" с файла" << std::endl;
		break;
	}
	std::cout << "\tY - да\t\tN - нет";
	std::cout << ":";
	std::cin >> symb;
	if (symb == 'y' || symb == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<Song>::iterator FindSongIndex(std::vector<Song>& catalog, std::string const& title)
{
	auto it = std::find_if(catalog.begin(), catalog.end(), [&](Song const& song)
		{
			return song.title == title;
		});
	return it;
}

bool FindSong(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);

	if (it == catalog.end())
	{
		return false;
	}
	return true;
}

void FindByAuthor(std::vector<Song> const& catalog, std::string const& author)
{
	std::cout << "Автор: " << author << std::endl;
	std::cout << "Песни: " << std::endl;
	for (size_t i = 0; i < catalog.size(); ++i)
	{
		if (catalog[i].author == author)
		{
			std::cout << "  " << catalog[i].title << std::endl;
		}
	}
	std::cout << "\n\tY - вернуться в меню" << std::endl;
	std::cout << ": ";
	char symb;
	std::cin >> symb;
	while (symb != 'y' && symb != 'Y')
	{
		std::cout << ": ";
		std::cin >> symb;
	}
}

void FindByWord(std::vector<Song> const& catalog, std::string word)
{
	std::cout << "Слово: " << word << std::endl;
	for (int i = 0; i < catalog.size(); i++) {
		if (catalog[i].lyrics.find(word) != std::string::npos) 
		{
			std::cout << "Автор: " << catalog[i].author << " Песня: "<< catalog[i].title << std::endl;
		}
	}
	std::cout << "\n\tY - вернуться в меню" << std::endl;
	std::cout << ": ";
	char symb;
	std::cin >> symb;
	while (symb != 'y' && symb != 'Y')
	{
		std::cout << ": ";
		std::cin >> symb;
	}
}