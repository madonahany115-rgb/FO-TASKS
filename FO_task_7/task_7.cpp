#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<string> names;
    ofstream out("Students.txt");
    out << "hadeer Mahmoud" << endl;
    out << "youssef Ali" << endl;
    out << "ahmed Mostafa" << endl;
    out << "esraa Ebrahim" << endl;
    out.close();

    ifstream in("students.txt");
    string name;
    while (getline(in, name))
    {
        names.push_back(name);
    }
    in.close();

    sort(names.begin(), names.end());
    ofstream result("students.txt");

    for (int i = 0; i < names.size(); i++)
    {
        result << names[i] << endl;
    }

    result.close();
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}
