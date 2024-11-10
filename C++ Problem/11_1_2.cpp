#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private: 
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* t, const char* i, int p) : price(p)
    {
        title = new char[strlen(t)+1];
        isbn = new char[strlen(i)+1];
        strcpy(title, t);
        strcpy(isbn, i);
    }
    Book(const Book& ref) : price(ref.price)
    {
        title = new char[strlen(ref.title)+1];
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }
    Book& operator=(const Book& ref)
    {
        delete[] title;
        delete[] isbn;

        title = new char[strlen(ref.title)+1];
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
    void ShowBookInfo()
    {
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
};

class EBook : public Book
{
private:
    char* DRMKey;
public:
    EBook(const char* t, const char* i, int p, const char* k)
        : Book(t, i, p)
    {
        DRMKey = new char[strlen(k)+1];
        strcpy(DRMKey, k);
    }
    EBook(const EBook& ref) : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete[] DRMKey;
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);    
        return *this;  
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout<<"인증키: "<<DRMKey<<endl;
    }
};

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
}