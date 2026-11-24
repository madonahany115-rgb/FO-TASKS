#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name[20];
    int id;
    float grade;
    char choice;

    ofstream out("students.txt");

    if (!out.is_open())
    {
        cout << "error opening the file";
        return 1;
    }

    do
    {
        cout << "enter student name: ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "enter student ID: ";
        cin >> id;

        cout << "enter student grade: ";
        cin >> grade;

        out << name << ", " << id << ", " << grade << " $";

        cout << "\ndo you want to add another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    out.close();

    cout << "\nrecords saved successfully!";

    return 0;
}
