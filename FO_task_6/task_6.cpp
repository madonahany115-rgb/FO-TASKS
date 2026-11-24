#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;

    ofstream out("students.txt");

    out << "ahmed" << endl;
    out << "mohamed" << endl;
    out << "sara" << endl;
    out << "mona" << endl;

    out.close();

    ifstream in("students.txt");
    ofstream temp("temp.txt");

    bool first = true;
    while (getline(in, name))
    {
       if (first)
        {
            first = false;
            continue;
        }
        temp << name << endl;
    }
    in.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    cout << "first name deleted successfully";

    return 0;
}
