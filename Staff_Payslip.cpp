#include <iostream>
#include <string>
using namespace std;

class Staff
{
    int staff_id;
    string name;
    float salary;

public:

    void accept()
    {
        cout << "Enter Staff ID: ";
        cin >> staff_id;

        cout << "Enter Staff Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> salary;
    }

    void display()
    {
        float DA = salary * 0.25;
        float HRA = 800;
        float ITax = salary * 0.15;

        float gross = salary + DA + HRA;
        float net = gross - ITax;

        cout << "\n-----------------------------";
        cout << "\n       STAFF PAY SLIP";
        cout << "\n-----------------------------";

        cout << "\nStaff ID     : " << staff_id;
        cout << "\nName         : " << name;
        cout << "\nBasic Salary : " << salary;
        cout << "\nDA (25%)     : " << DA;
        cout << "\nHRA          : " << HRA;
        cout << "\nI-Tax (15%)  : " << ITax;
        cout << "\nGross Salary : " << gross;
        cout << "\nNet Salary   : " << net;

        cout << "\n-----------------------------\n";
    }

    bool compare(Staff s)
    {
        return name > s.name;
    }
};

int main()
{
    Staff s[100], temp;
    int n, i, j;

    cout << "Enter number of staff: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter details of Staff " << i + 1 << endl;
        s[i].accept();
    }

    // Sorting by name using Bubble Sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s[j].compare(s[j + 1]))
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    cout << "\nStaff Details Sorted By Name\n";

    for (i = 0; i < n; i++)
    {
        s[i].display();
    }

    return 0;
}