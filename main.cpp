#include <iostream>
#include <string>
using namespace std;
int main() {
    const int N = 1e4;
    string name[N];
    int age[N];
    int salary[N];
    char gender[N];
    int employees_counter = -1;
    while (true){
        cout << "\nEnter your choice\n";
        cout << "1) Add new employee\n";
        cout << "2) Print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update Salary by name\n";
        int choice;
        cin >> choice;
        if(choice == 1){
            employees_counter++;
            cout << "Enter name: ";
            cin >> name[employees_counter];
            cout << "Enter age: ";
            cin >> age[employees_counter];
            cout << "Enter salary: ";
            cin >> salary[employees_counter];
            cout << "Enter gender (M/F): ";
            cin >> gender[employees_counter];
        }
        else if(choice == 2){
            for(int i = 0; i<=employees_counter; i++){
                if (age[i] == -1)
                    continue;
                cout << name[i] << ' ' << age[i] << ' ' << salary[i] << ' ' << gender[i] << '\n';
            }
        }
        else if(choice == 3){
            cout << "Enter start and end age: ";
            int start, end;
            cin >> start >> end;
            for(int i = 0; i<=employees_counter; i++){
                if(age[i] >= start && end >= age[i])
                    age[i] = -1;
            }
        }
        else if(choice == 4){
            cout << "Enter the name and salary: ";
            string _name;
            int new_salary;
            cin >> _name >> new_salary;
            for(int i = 0; i<=employees_counter; i++){
                if(name[i] == _name){
                    salary[i] = new_salary;
                    break;
                }
            }
        }
    }
    return 0;
}
