#include "Func.h"

void EditBook(Book& book, std::string title, std::string author, std::string publisher, std::string genre)
{
	book.author = author;
	book.title = title;
	book.genre = genre;
	book.publisher = publisher;
}
void PrintLibrary(std::vector<Book> const& library)
{
	for (Book book : library)
	{
		std::cout << "Название: " << book.title << std::endl;
		std::cout << "Автор: " << book.author << std::endl;
		std::cout << "===============================" << std::endl;
	}
}
std::vector<Book> FindByAuthor(std::vector<Book> const& library, std::string author)
{
	std::vector<Book> BookList;
	for (Book book : library)
	{
		if (book.author == author)
		{
			BookList.push_back(book);
		}
	}
	return BookList;
}
Book* FindBook(std::vector<Book>& library, std::string title)
{
	for (Book& book : library)
	{
		if (book.title == title)
		{
			return &book;
		}
	}
	return nullptr;
}

void SortByTitle(std::vector<Book>& library)
{
	std::sort(library.begin(), library.end(), [](Book const& book_a, Book const& book_b) 
		{
			return book_a.title < book_b.title;
		});
}
void SortByAuthor(std::vector<Book>& library)
{
	std::sort(library.begin(), library.end(), [](Book const& book_a, Book const& book_b)
		{
			return book_a.author < book_b.author;
		});
}
void SortByPublisher(std::vector<Book>& library)
{
	std::sort(library.begin(), library.end(), [](Book const& book_a, Book const& book_b) 
		{
			return book_a.publisher < book_b.publisher;
		});
}