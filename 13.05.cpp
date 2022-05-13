#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct reader
{
    string name;
    unsigned year, month, number;
};

class book
{
    public:

    string title; //название
    vector <string> authors;
    unsigned int year; //год издания
    string publisher; //издательство
    unsigned int pages; //кол-во страниц
};

class cathalog_book : public book
{
    public:

    using book::title;
    using book::authors;
    using book::year;
    using book::publisher;
    using book::pages;

    public:

    unsigned int ID; //идентификатор в каталоге
    unsigned int quantity; //общее кол-во экземплятов
    unsigned int instances; //кол-во экземпляров в наличии

    vector <reader> picked; //список читателей

    void add_reader (string &name, unsigned year, unsigned month, unsigned number)
    {
        reader new_r {name, year, month, number};

        picked.push_back (new_r);
    }
};

class cathalog
{
    vector <cathalog_book> books;

    public:

    void add_book (cathalog_book& new_book) 
    {                                       
        books.push_back (new_book); 

        // books[books.size() - 1].picked.clear(); //TODO: подумать насчет очистки списка читателей
    }

    int delete_book (unsigned ID_)
    {
        for (auto i = books.begin(); i != books.end(); ++i)
            if (i->ID == ID_)
            {
                books.erase (i);
                return 0;
            }

        return -1;
    }

    void show_info (unsigned ID_)
    {
        for (auto i = books.begin(); i != books.end(); ++i)
            if (i->ID == ID_)
            {
                std::cout << i->title << std::endl;
                
                for (auto j = i->picked.begin(); j != i->picked.end(); ++j)
                    std::cout << j->name << " " << j->year << std::endl;
            }
    }

    unsigned find (string &title_, vector <string> &authors_)
    {
        for (auto i = books.begin(); i != books.end(); ++i)
            if (i->title == title_)
            {
                int count = 0;

                for (auto j = authors_.begin(); j != authors_.end(); ++j)
                {
                    for (auto k = i->authors.begin(); k != i->authors.end(); ++k)
                        if (*k == *j)
                        {
                            ++count;
                            break;
                        }
                }

                if (count == authors_.size())
                    return i->ID;
            }

        return 0;
    }
};

int main()
{
    cathalog_book b;
    string name = "Kate";

    b.title = "Math";
    b.ID = 10;
    b.add_reader (name, 2022, 4, 5);

    cathalog c;

    c.add_book (b);

    c.show_info (10);
}
