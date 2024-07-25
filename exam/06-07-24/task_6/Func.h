#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <filesystem>

struct Song {
	std::string year;
	std::string author;
	std::string title;
	std::string lyrics;
};
enum Actions {
	Delete,
	ChangeLyrics,
	AddLyricFromFile,
	SaveLyricToFile
};

void Start();
void SaveToFile(std::vector<Song>& catalog, std::string fileName);
void SaveLyricsToFile(std::vector<Song>& catalog, std::string& title);
void AddSong(std::vector<Song>& catalog);
void AddLyrics(std::vector<Song>& catalog, std::string const& title);
void AddLyricsFromFile(std::vector<Song>& catalog, std::string& title);
bool ConfirmAction(Actions const& action, std::string const& title);
bool FindSong(std::vector<Song>& catalog, std::string const& title);
std::vector<Song>::iterator FindSongIndex(std::vector<Song>& catalog, std::string const& title);
void PrintLyric(std::vector<Song>& catalog, std::string const& title);
void ChangeLyric(std::vector<Song>& catalog, std::string const& title);
void DeleteLyrics(std::vector<Song>& catalog, std::string const& title);
void AddEnter(std::string& lyric);
void ShowLyrics(std::vector<Song>& catalog, std::string const& title);
void FindByAuthor(std::vector<Song> const& catalog, std::string const& author);
void FindByWord(std::vector<Song> const& catalog, std::string word);