#include <iostream>
#include <istream>
#include <fstream>
#include <stack>
#include "user.h"
#include "network.h"
#include "post.h"
#include "directmessage.h"
using namespace std;
int main()
{
    bool loop = true;
    network n;
    stack<int> output;
    vector<vector<int>> groups;
    string name, name1, name2, filename;
    int year, zip, input, id1, id2, score, d, loc;
    vector<int> temp, friends;
    while (loop == true)
    {
        cout << "What would you like to do?" << endl;
        cout << "1: Add a user" << endl;
        cout << "2: Add a friend connection" << endl;
        cout << "3: Remove a friend connection" << endl;
        cout << "4: Print User data" << endl;
        cout << "5: Print friends Data" << endl;
        cout << "6: Write data to file" << endl;
        cout << "7: Read data from file" << endl;
        cout << "8: Find shortest path between two users" << endl;
        cout << "9: Find number of seperate friend groups" << endl;
        cout << "10: Suggest Friends" << endl;
        cout << "11: Explore Neighbors" << endl;
        cout << "12: Exit Program" << endl;
        cin >> input;
        switch (input)
        {
            case 1:
                cout << "Enter your information please" << endl;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Year of Birth: ";
                cin >> year;
                cout << "Zip Code: ";
                cin >> zip;
                n.add_user(user(name, year, zip));
                cout << endl;
                break;
            case 2:
                cout << "Enter both names, first and last" << endl;
                cout << "Person 1: ";
                cin.ignore();
                getline(cin, name1);
                cout << "Person 2: ";
                getline(cin, name2);
                n.add_connection(name1, name2);
                break;
            case 3:
                cout << "Enter both names, first and last" << endl;
                cout << "Person 1: ";
                cin.ignore();
                getline(cin, name1);
                cout << "Person 2: ";
                getline(cin, name2);
                n.remove_connection(name1, name2);
                break;
            case 4:
                n.print_data();
                break;
            case 5:
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                n.print_friends(n.get_id(name));
                break;
            case 6:
                cout << "Please provide file name: ";
                cin >> filename;
                n.write_friends(filename.data());
                break;
            case 7:
                cout << "Please enter file name: ";
                cin >> filename;
                n.read_friends(filename.data());
                break;
            case 8:
                cout << "Enter Person 1: ";
                cin.ignore();
                getline(cin, name1);
                cout << "Enter Person 2: ";
                getline(cin, name2);
                for (int i = 0; i < output.size(); i++)
                {
                    output.pop();
                }
                temp = n.shortest_path(n.get_id(name1), n.get_id(name2));
                for (int i = 0; i < temp.size(); i++)
                {
                    output.push(temp[i]);
                }
                cout << "Distance: " << temp.size() << endl;
                while (!output.empty())
                {
                    cout << n.get_name(output.top()); 
                    output.pop();
                    if (output.size() != 0)
                    {
                        cout << " --> ";
                    }
                }
                cout << endl;
                break;
            case 9:
                groups = n.groups();
                for (int i = 0; i < groups.size(); i++)
                {
                    cout << "Set " << i << ": ";
                    for (int j = 0; j < groups[i].size(); j++)
                    {
                        cout << n.get_name(groups[i][j]) << ", ";
                    }
                    cout << endl;
                }
                break;
            case 10:
                cout << "Please enter user name: ";
                cin.ignore();
                getline(cin, name1);
                friends = n.suggest_friends(n.get_id(name1), score);
                if (friends.size() == 0)
                {
                    score = -1;
                    cout << "NONE" << endl;
                }
                for (int i = 0; i < friends.size(); i++)
                {
                    cout << n.get_name(friends[i]) << " with score of " << score << endl;
                }
                break;
            case 11:
                cout << "Please enter user name: ";
                cin.ignore();
                getline(cin, name1);
                cout << "Please enter distance from user: ";
                cin >> d;
                friends = n.distance_user(n.get_id(name1), loc, d);
                for (int i = 0; i < output.size(); i++)
                {
                    output.pop();
                }
                for (int i = 0; i < friends.size(); i++)
                {
                    output.push(friends[i]);
                }
                cout << name1 << ": ";
                while (!output.empty())
                {
                    cout << n.get_name(output.top()); 
                    output.pop();
                    if (output.size() != 0)
                    {
                        cout << " --> ";
                    }
                }
                cout << endl;
                break;
            default:  
                cout << "Either 7 was entered or a incorrect input, exiting program!" << endl;
                loop = false;
                break;
        }
    }
}