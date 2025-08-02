#include <iostream>
#include <cstring>
#include<cstdlib>
using namespace std;

class books 
{
    char *title;
    char *author;
    char *publisher;
    float price;
    int stock;

public:
    books(const char *t, const char *a, const char *p, float pr, int s) 
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        publisher = new char[strlen(p) + 1];
        strcpy(publisher, p);
        price = pr;
        stock = s;
    }

    bool search(const char *t, const char *a) 
    {
        return (strcmp(title, t) == 0 && strcmp(author, a) == 0);
    }

    void showDetails() 
    {
        cout << "\nBook Found:\n";
        cout << "Title: " << title << "\nAuthor: " << author<< "\nPublisher: " << publisher << "\nPrice: " << price<< "\nStock: " << stock << endl;
    }

    void buyBook(int copies) 
    {
        if (copies <= stock) 
        {
            float total = price * copies;
            cout << "Total cost = Rs. " << total << endl;
            stock -= copies;
        } 
        else 
        {
            cout << "Required copies not in stock" << endl;
        }
    }

    ~books() 
    {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }
};

int main() 
{
    const int SIZE = 3;
    books* inventory[SIZE];
    inventory[0] = new books("C++ Basics", "Balagurusamy", "Pearson", 250.0, 5);
    inventory[1] = new books("C Programming "," Balagurusamy ","Mc-Graw Hill ", 300.0, 3);
    inventory[2] = new books("Python Program", "Thareja ", "O'Reilly", 400.0, 2);

    char searchTitle[50], searchAuthor[50];
    int copies;
    bool found = false;

    cout << "Enter title of the book: ";
    cin.getline(searchTitle, 50);

    cout << "Enter author of the book: ";
    cin.getline(searchAuthor, 50);

    for (int i = 0; i < SIZE; ++i)
    {
        if (inventory[i]->search(searchTitle, searchAuthor)) 
        {
            inventory[i]->showDetails();
            cout << "Enter number of copies required: ";
            cin >> copies;
            inventory[i]->buyBook(copies);
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "Book not found in inventory." << endl;
    }
    return 0;
}
