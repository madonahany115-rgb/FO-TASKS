#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
string x,y,z;
ifstream in("fruit.txt");
if(in.is_open()) {
        cout<<"file opened successfully\n";
}
else {
      cout<<"error, file is not opened\n";
}
in>>x>>y>>z;
cout<<x<<"\n"<<y<<"\n"<<z;
in.close();
fstream out("fruit.txt" ,ios::app);
out<<"\nFresh Fruits";
out.close();


    return 0;
}
