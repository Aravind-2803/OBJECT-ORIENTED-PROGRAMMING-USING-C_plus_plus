#include <iostream>
#include <string>
#include <map>
using namespace std;

// Base Class
class Subject {
protected:
    string code, title, instructor;
public:
    Subject(string c = "", string t = "", string i = "")
        : code(c), title(t), instructor(i) {}

    virtual void display() {
        cout << code << " - " << title << " (" << instructor << ")";
    }
};

// Derived Class (Slot)
class Slot : public Subject {
    string slotName;
public:
    Slot(string s = "", string c = "", string t = "", string i = "")
        : Subject(c, t, i), slotName(s) {}

    string getSlot() { return slotName; }

    void display() override {
        cout << slotName << " : ";
        Subject::display();
    }
};

// TimeTable class
class TimeTable {
    map<string, Slot> slots; // Map slotName -> Slot
    string table[5][8];      // 5 days × 8 periods

public:
    void addSlot(Slot s) {
        slots[s.getSlot()] = s;
    }

    void setPeriod(int day, int period, string slot) {
        table[day][period] = slot;
    }

    void display() {
        string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

        cout << "\n----- TIMETABLE -----\n\n";
        for (int d = 0; d < 5; d++) {
            cout << days[d] << " : ";
            for (int p = 0; p < 8; p++) {
                if (table[d][p] != "")
                    cout << table[d][p] << " ";
                else
                    cout << "- ";
            }
            cout << endl;
        }

        cout << "\n----- SLOT DETAILS -----\n\n";
        for (auto &s : slots) {
            s.second.display();
            cout << endl;
        }
    }
};

int main() {
    TimeTable tt;
    int numSlots;

    cout << "Enter number of slots: ";
    cin >> numSlots;

    // Input slot details
    for (int i = 0; i < numSlots; i++) {
        string slotName, code, title, instructor;
        cin.ignore();
        cout << "\nEnter details for Slot " << (i + 1) << ":\n";
        cout << "Slot Name (A/B/C...): ";
        getline(cin, slotName);
        cout << "Subject Code: ";
        getline(cin, code);
        cout << "Subject Title: ";
        getline(cin, title);
        cout << "Instructor Name: ";
        getline(cin, instructor);

        tt.addSlot(Slot(slotName, code, title, instructor));
    }

    // Input timetable
    string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    cout << "\nEnter timetable (Enter slot name for each period, or '-' if free):\n";
    for (int d = 0; d < 5; d++) {
        cout << "\n--- " << days[d] << " ---\n";
        for (int p = 0; p < 8; p++) {
            string slot;
            cout << "Period " << (p + 1) << ": ";
            cin >> slot;
            if (slot != "-")
                tt.setPeriod(d, p, slot);
        }
    }

    // Display timetable
    tt.display();

    return 0;
}
