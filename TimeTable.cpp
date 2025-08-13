#include<iostream>
#include <cstring>
#include<string>
using namespace std;

class Time_Table
{
    protected:
        static const int days = 5;
        static const int periods = 8;
        string schedule[days][periods];

  public:
        Time_Table() 
        {
            for (int i = 0; i < days; i++)
              for (int j = 0; j < periods; j++)
                  schedule[i][j] = "";
        }
      void displayTimetable() 
      {
        string dayNames[days] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        cout << "\n--- College Student Timetable ---\n\n";
        for (int i = 0; i < days; i++) 
        {
            cout << dayNames[i] << ":\n";
            for (int j = 0; j < periods; j++) 
            {
                cout << "  Period " << j + 1 << " (40 mins): " << (schedule[i][j].empty() ? "Free" : schedule[i][j]) << "\n";
            }
            cout << endl;
        }
    }
    
    void inputNumberOfDays() 
    {
        int no_of_days = 0;
        cout << "ENTER THE NO OF DAYS (If special class occurs): ";
        cin >> no_of_days;
    }
        
};

class StudentTimetable : public Time_Table
{
    public:
    void inputSubjects() 
    {
        string dayNames[days] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        cout << "Enter subjects for each period (8 periods/day) for 5 days:\n";

        for (int i = 0; i < days; i++) 
        {
            cout << "\n--- " << dayNames[i] << " ---\n";
            for (int j = 0; j < periods; j++) 
            {
                cout << "Enter subject for Period " << j + 1 << ": ";
                getline(cin, schedule[i][j]);
              }
          }  
      }
};
int main()
{
    StudentTimetable st;
    st.inputSubjects();
    st.displayTimetable();
    return 0;
}
