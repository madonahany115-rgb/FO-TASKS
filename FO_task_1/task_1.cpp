#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string Fullname;
    int ID;
    float Grade;

    cout<<"enter your fullname\n";
    getline(cin,Fullname);

    cout<<"enter your ID\n";
    cin>>ID;

    cout<<"enter your Grade\n";
    cin>>Grade;

    ofstream file;
    file.open("student.text");

    if(!file.is_open())
       {
         cout<<"error, file is not opened\n";

       }
    else{
        cout<<"file opened successfully\n";
    }

    file << "Full name: " << Fullname << endl;
    file << "ID: " << ID << endl;
    file << "Grade: " << Grade << endl;

    file.close();

    cout << "student data saved successfully." << endl;

    return 0;
}
