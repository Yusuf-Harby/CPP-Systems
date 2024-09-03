#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Book{
    int id, quantity;
    string name;
    vector<string>who; // who borrowed this book;
}B;
struct User{
    int id;
    string name;
    vector<int>borrowed; // the books borrowed with this user;
}U;
int main() {
    vector<Book>books;
    vector<User>users;
    cout << "\nLibrary Menu\n";
    cout << "1) add book\n";
    cout << "2) search books by prefix\n";
    cout << "3) print who borrowed book by name\n";
    cout << "4) print library by id\n";
    cout << "5) print library by name\n";
    cout << "6) add user\n";
    cout << "7) user borrow book\n";
    cout << "8) user return book\n";
    cout << "9) print users\n";
    cout << "10) Exit\n\n";
    while (true){
        cout << "Enter your menu choice [1 - 10]: ";
        int c; // choice
        cin >> c;
        if (c == 1){
            cout << "Enter book info: id & name & total quantity:";
            cin >> B.id >> B.name >> B.quantity;
            books.push_back(B);
        }
        else if (c == 2){
            vector<string>v;
            string prfx;
            cout << "Enter book name prefix: ";
            cin >> prfx;
            for(int i=0; i < books.size(); i++){
                string x = books[i].name.substr(0,prfx.size());
                if (x == prfx)
                    v.push_back(books[i].name);
            }
            if(v.size()){
                sort(v.begin(),v.end());
                for(int i=0; i < v.size(); i++)
                    cout << v[i] << '\n';
            }
            else
                cout << "No books with such prefix\n";
        }
        else if (c == 3){
            string b;
            bool e = false;
            cout << "Enter book name: ";
            cin >> b;
            for(int i=0; i < books.size(); i++){
                if(books[i].name == b){
                    e = true;
                    for(int j = 0; j < books[i].who.size(); j++)
                        cout << books[i].who[j] << '\n';
                    break;
                }
            }
            if(!e) cout << "Invalid book name.\n";
        }
        else if (c == 4){
            vector<pair<int, int>>v;
            for(int i=0; i < books.size(); i++){
                v.push_back({books[i].id,i});
            }
            sort(v.begin(),v.end());
            cout << '\n';
            for(int i=0; i < v.size(); i++){
                int j = v[i].second;
                cout << "id = " << books[j].id << " name = " << books[j].name << " total quantity " << books[j].quantity << " total borrowed " << books[j].who.size() << '\n';
            }
        }
        else if (c == 5){
            vector<pair<string , int>>v;
            for(int i=0; i < books.size(); i++){
                v.push_back({books[i].name,i});
            }
            sort(v.begin(),v.end());
            cout << '\n';
            for(int i=0; i < v.size(); i++){
                int j = v[i].second;
                cout << "id = " << books[j].id << " name = " << books[j].name << " total quantity " << books[j].quantity << " total borrowed " << books[j].who.size() << '\n';
            }
        }
        else if (c == 6){
            cout << "Enter user name & national id: ";
            cin >> U.name >> U.id;
            users.push_back(U);
        }
        else if (c == 7){
            cout << "Enter user name & book name: ";
            string u,b; int id;
            cin >> u >> b;
            for(int i=0; i < books.size(); i++){
                if(books[i].name == b){
                    id = books[i].id;
                    books[i].who.push_back(u);
                    break;
                }
            }
            for(int i=0; i<users.size(); i++){
                if(users[i].name == u){
                    users[i].borrowed.push_back(id);
                    break;
                }
            }
        }
        else if (c == 8){
            cout << "Enter user name & book name: ";
            string u,b; int id;
            cin >> u >> b;
            for(int i=0; i < books.size(); i++){
                if(books[i].name == b){
                    id = books[i].id;
                    for(int j =0; j < books[i].who.size(); j++){
                        if(books[i].who[j] == u){
                            books[i].who.erase(books[i].who.begin()+j);
                            break;
                        }
                    }
                    break;
                }
            }
            for(int i=0; i<users.size(); i++){
                if(users[i].name == u){
                    for(int j=0; j<users[i].borrowed.size(); j++){
                        if(users[i].borrowed[j] == id){
                            users[i].borrowed.erase(users[i].borrowed.begin()+j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        else if (c == 9){
            cout << '\n';
            for(int i=0; i < users.size(); i++){
                cout << "user " << users[i].name << " id " << users[i].id << " borrowed books ids: ";
                for(int j = 0; j < users[i].borrowed.size(); j++)
                    cout << users[i].borrowed[j] << ' ';
                cout << '\n';
            }
        }
        else if (c == 10)
            break;
    }
    return 0;
}
