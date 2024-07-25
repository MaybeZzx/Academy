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

		std::cout << "\t������� ������� �����" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << " 1. ���������� �����" << std::endl;
		std::cout << " 2. ���������� ������ �����" << std::endl;
		std::cout << " 3. �������� ������ �����" << std::endl;
		std::cout << " 4. ��������� ������ �����" << std::endl;
		std::cout << " 5. ����������� ������ ����� �� �����" << std::endl;
		std::cout << " 6. ���������� ������ ����� � ����" << std::endl;
		std::cout << " 7. ����� �� ������" << std::endl;
		std::cout << " 8. ����� �� ����������� �����" << std::endl;
		std::cout << " 9. ����������� ������ �����" << std::endl;
		std::cout << " 0. �����" << std::endl;
		
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
			std::cout << " 1. ������ ����� � ����������" << std::endl;
			std::cout << " 2. �������� ����� � �����" << std::endl;
			std::cout << ": ";

			std::cin >> addTextChoice;
			system("cls");
			std::cout << "������� �������� �����: ";
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
			std::cout << "������� �������� �����: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			DeleteLyrics(catalog, tempObj.title);
			break;
		case 4:
			std::cout << "������� �������� �����: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			ChangeLyric(catalog, tempObj.title);
			break;
		case 5:
			std::cout << "������� �������� �����: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			ShowLyrics(catalog, tempObj.title);
			break;
		case 6:
			std::cout << "������� �������� �����: ";
			std::getline(std::cin >> std::ws, tempObj.title);
			SaveLyricsToFile(catalog, tempObj.title);
			break;
		case 7:
			std::cout << "������� ������: ";
			std::getline(std::cin >> std::ws, tempObj.author);
			FindByAuthor(catalog, tempObj.author);
			break;
		case 8:
			std::cout << "������� �����: ";
			std::getline(std::cin >> std::ws, tempObj.lyrics);
			FindByWord(catalog, tempObj.lyrics);
			break;
		case 9:
			if (!catalog.empty())
			{
				std::cout << "\t������ �����\n" << std::endl;
				for (size_t i = 0; i < catalog.size(); ++i)
				{
					std::cout << "�����: " << catalog[i].author << std::endl;
					std::cout << "��������: " << catalog[i].title << std::endl;
					std::cout << "=========================" << std::endl;
				}
				std::cout << "\n\tY - ��������� � ����" << std::endl;
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
				std::cout << "������� ����";
				Sleep(DELAY);

			}
			break;
		case 0:
			std::cout << "�����..." << std::endl;
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
		std::cout << "������ �������� �����!" << std::endl;
		return;
	}

	for (size_t i = 0; i < catalog.size(); ++i)
	{
		outputFile << "[" << i + 1 << "]" << std::endl;
		outputFile << " ��������: " << catalog[i].title << std::endl;
		outputFile << " �����: " << catalog[i].author<< std::endl;
		outputFile << " ��� �������: " << catalog[i].year << std::endl;
		outputFile << " �����: " << std::endl;
		outputFile << "  " << catalog[i].lyrics << std::endl << std::endl;
	}
	outputFile.close();
	std::cout << "���� ������� ��������" << std::endl;
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
			fout << "��������: " << title << std::endl;
			fout << "�����: " << std::endl;
			fout << "  " << it->lyrics << std::endl;
		}
		fout.close();
		std::cout << "���� ������� ��������" << std::endl;
		Sleep(DELAY);
	}
	else
	{
		std::cout << "����� �� �������";
		Sleep(DELAY);
	}
}

void AddSong(std::vector<Song>& catalog)
{
	Song newSong;
	std::cout << "������� �������� �����: ";
	std::getline(std::cin >> std::ws, newSong.title);
	std::cout << "������� ������ �����: ";
	std::getline(std::cin >> std::ws, newSong.author);
	std::cout << "������� ��� ������� ����� (- ���� ����������): ";
	std::getline(std::cin >> std::ws, newSong.year);
	std::cout << "������� ����� ����� (* - ������� �� ����� ������ \\ - ���� ����������): ";
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
		std::cout << "����� ������� ���������!" << std::endl;
	}
	else
	{
		std::cout << "������ � ���������� �����!" << std::endl;
	}
}

void AddLyrics(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);

	if (it->lyrics != "")
	{
		std::cout << "� ����� ��� ���� �����. ���������� �������� ���" << std::endl;
		Sleep(DELAY);
		return;
	}

	std::cout << "�����: " << title << std::endl;
	std::cout << "������� ����� (* - ������� �� ����� ������): ";
	std::getline(std::cin >> std::ws, it->lyrics);
	std::cout << "����� ����� ������� ��������!";

	AddEnter(it->lyrics);
	Sleep(DELAY);
}

void AddLyricsFromFile(std::vector<Song>& catalog, std::string& title)
{
	if(FindSong(catalog, title))
	{
		auto const it = FindSongIndex(catalog, title);
		system("cls");
		std::cout << "\t���� ������ ���������� � ����� TextToInput!\n" << std::endl;
		std::cout << "������� �������� �����: ";
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
			std::cout << "����� ������� ��������" << std::endl;
			Sleep(DELAY);
		}
		else
		{
			std::cout << "������ �������� �����!" << std::endl;
			Sleep(DELAY);
		}
	}
	else
	{
		std::cout << "����� �� �������";
		Sleep(DELAY);
	}
}

void DeleteLyrics(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);
	if (FindSong(catalog, title))
	{
		std::cout << "�����: " << title << std::endl;
		std::cout << "����������� ��������: ";

		if (ConfirmAction(Actions::Delete, title))
		{
			system("cls");
			it->lyrics = "";
			std::cout << "�����: " << title << std::endl;
			std::cout << "����� ������� ������";
		}
		else
		{
			std::cout << "�������� ��������" << std::endl;
		}
	}
	else
	{
		std::cout << "����� �� �������";
		Sleep(DELAY);
	}
}

void ChangeLyric(std::vector<Song>& catalog, std::string const& title)
{
	auto const it = FindSongIndex(catalog, title);
	if(FindSong(catalog, title))
	{
		std::cout << "�����: " << it->title << std::endl;
		std::cout << "�����: " << std::endl;
		PrintLyric(catalog, it->title);

		std::cout << "������� ����� �����(* - ������� �� ����� ������): ";
		std::string newLyric;
		std::getline(std::cin >> std::ws, newLyric);

		AddEnter(newLyric);
		system("cls");
		std::cout << "�����: " << it->title << std::endl;
		std::cout << "������ ����� �����: " << it->lyrics << std::endl;
		std::cout << "����� ����� �����: \n  " << newLyric << std::endl;
		std::cout << "����������� ��������: ";

		if (ConfirmAction(Actions::ChangeLyrics, title))
		{
			it->lyrics = newLyric;
			std::cout << "����� ����� ������� �������" << std::endl;
			Sleep(DELAY);
		}
		else
		{
			std::cout << "�������� ��������";
			Sleep(DELAY);
		}
	}
	else
	{
		std::cout << "����� �� �������";
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
		std::cout << "�����: " << title << std::endl;
		PrintLyric(catalog, title);
		std::cout << "\n\tY - ��������� � ����" << std::endl;
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
		std::cout << "����� �� �������!";
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
		std::cout << " ������� ����� ����� \"" << title << "\"" << std::endl;
		break;
	case ChangeLyrics:
		std::cout << " �������� ����� ����� \"" << title << "\"" << std::endl;
		break;
	case AddLyricFromFile:
		std::cout << " �������� ����� ����� \""<< title << "\" � �����" << std::endl;
		break;
	}
	std::cout << "\tY - ��\t\tN - ���";
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
	std::cout << "�����: " << author << std::endl;
	std::cout << "�����: " << std::endl;
	for (size_t i = 0; i < catalog.size(); ++i)
	{
		if (catalog[i].author == author)
		{
			std::cout << "  " << catalog[i].title << std::endl;
		}
	}
	std::cout << "\n\tY - ��������� � ����" << std::endl;
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
	std::cout << "�����: " << word << std::endl;
	for (int i = 0; i < catalog.size(); i++) {
		if (catalog[i].lyrics.find(word) != std::string::npos) 
		{
			std::cout << "�����: " << catalog[i].author << " �����: "<< catalog[i].title << std::endl;
		}
	}
	std::cout << "\n\tY - ��������� � ����" << std::endl;
	std::cout << ": ";
	char symb;
	std::cin >> symb;
	while (symb != 'y' && symb != 'Y')
	{
		std::cout << ": ";
		std::cin >> symb;
	}
}