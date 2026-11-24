
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");
    if (!outFile.is_open())
    {
        cout << "Error opening the file";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        Person p;
        cout << "Enter name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, p.name);

        cout << "Enter age: ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }

    outFile.close();

    vector<Person> persons;

    ifstream inFile("persons.txt");
    if (!inFile.is_open())
    {
        cout << "Error opening the file";
        return 1;
    }

    Person p;
    while (getline(inFile, p.name))
    {
        if (!(inFile >> p.age))
            break;

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        persons.push_back(p);
    }

    inFile.close();

    if (persons.empty())
    {
        cout << "No persons found";
        return 0;
    }

    int minAge = persons[0].age;
    int maxAge = persons[0].age;

    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < minAge)
            minAge = persons[i].age;

        if (persons[i].age > maxAge)
            maxAge = persons[i].age;
    }

    ofstream resultFile("results.txt");

    if (!resultFile.is_open())
    {
        cout << "Error opening results file";
        return 1;
    }

    resultFile << "Younger persons:" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == minAge)
        {
            resultFile << persons[i].name
                       << " " << persons[i].age << endl;
        }
    }

    resultFile << "Older persons:" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == maxAge)
        {
            resultFile << persons[i].name
                       << " " << persons[i].age << endl;
        }
    }

    resultFile.close();

    cout << "Data saved successfully!";
    cout << "\nResults saved in results.txt";

    return 0;
}
