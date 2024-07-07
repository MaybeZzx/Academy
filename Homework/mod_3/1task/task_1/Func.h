#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Book {
	std::string title, author, publisher, genre;
};
void EditBook(Book& book, std::string title, std::string author, std::string publisher, std::string genre);
void PrintLibrary(std::vector<Book> const& library);
std::vector<Book> FindByAuthor(std::vector<Book> const& library, std::string author);
Book* FindBook(std::vector<Book>& library, std::string title);
void SortByTitle(std::vector<Book>& library);
void SortByAuthor(std::vector<Book>& library);
void SortByPublisher(std::vector<Book>& library);