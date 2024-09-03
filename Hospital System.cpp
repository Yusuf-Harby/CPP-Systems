#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
vector<deque<pair<string,string>>>patients(21);
void add(){
    cout << "\nEnter specialization, name, statis: ";
    int s; // specialization
    string name;
    int statis;
    cin >> s >> name >> statis;
    if(patients[s].size() < 5){
        if (statis == 0)
            patients[s].push_back({name,"regular"});
        else if (statis == 1)
            patients[s].push_front({name,"urgent"});
    }
    else
        cout << "Sorry we can't add more patients for this specialization\n";
}
void print(){
    cout << "*****************************\n";
    for(int i = 1; i <= 20; i++){
        if(patients[i].size()){
            cout << "There are " << patients[i].size() << " patients in specialization " << i << '\n';
            deque<pair<string,string>>toprint = patients[i];
            while (toprint.size()){
                cout << toprint.front().first << ' ' << toprint.front().second << '\n';
                toprint.pop_front();
            }
            cout << '\n';
        }
    }
}
void get_patient(){
    cout << "\nEnter specialization: ";
    int s; // specialization
    cin >> s;
    if(patients[s].size()){
        cout << patients[s].front().first << " please go with the Dr\n";
        patients[s].pop_front();
    }
    else
        cout << "No patients at the moment. Have rest, Dr\n";
}
int main() {
    while (true){
        cout << "\nEnter your choice: \n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";
        int c; // choice
        cin >> c;
        if (c == 1)
            add();
        else if (c == 2)
            print();
        else if (c == 3)
            get_patient();
        else if (c == 4)
            break;
    }
    return 0;
}
