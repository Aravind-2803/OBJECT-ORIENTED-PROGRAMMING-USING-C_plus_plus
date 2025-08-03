//create a class named faculty (faculty_id int ,name char array ,courses_handled string array)
//print the name of courses handled by the faculty on getting the faculty_id as input



#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Faculty 
{
private:
    int faculty_id;
    char name[50];
    string courses_handled[5]; // Assuming max 5 courses

public:
    Faculty(int id, const char* n, string courses[], int count) 
    {
        faculty_id = id;
        strcpy(name, n);
        for (int i = 0; i < count; i++) 
	{
            courses_handled[i] = courses[i];
        }
    }

    // Friend function declaration
    friend void printCourses(Faculty** facultyArray, int n, int search_id);
};

// Friend function to access private members
void printCourses(Faculty** facultyArray, int n, int search_id) 
{
    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (facultyArray[i]->faculty_id == search_id) 
	{
            cout << "Faculty Name: " << facultyArray[i]->name << endl;
            cout << "Courses Handled:\n";
            for (const auto& course : facultyArray[i]->courses_handled) 
	    {
                if (course != "")  // Only print non-empty courses
                    cout << "- " << course << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Faculty ID not found.\n";
    }
}

int main() 
{
    int n = 2; // number of faculty

    // Creating array of pointers to Faculty
    Faculty** facultyArray = new Faculty*[n];

    // Courses for each faculty
    string courses1[] = {"Math", "Physics", "AI"};
    string courses2[] = {"Chemistry", "Biology"};

    // Creating objects using new
    facultyArray[0] = new Faculty(1, "Alice", courses1, 3);
    facultyArray[1] = new Faculty(2, "Bob", courses2, 2);

    int search_id;
    cout << "Enter Faculty ID to search: ";
    cin >> search_id;

    // Call friend function
    printCourses(facultyArray, n, search_id);

    return 0;
}
