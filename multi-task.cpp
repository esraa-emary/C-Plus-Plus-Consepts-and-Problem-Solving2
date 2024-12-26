// Author: Esraa Emary Abd El-Salam
// ID: 20230054
// Section: S19
// TA: Ahmed Ihab
// Version: 1

/////////////////////////////////////////////// Headers-Set ////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Set {
private:
    vector<T> vec;
    vector<T> *pointer = &vec;
public:
    void addItem(T item) {
        auto it = find(vec.begin(), vec.end(), item);                 // check that the element doesn't exist.
        if (it == vec.end()) vec.push_back(item);
        sort(vec.begin(), vec.end());
    }

    void removeItem(T item) {
        auto it = find(vec.begin(), vec.end(), item);
        if (it != vec.end()) {
            vec.erase(it);
            cout << "Deleted successfully!\n";
        } else {
            cout << "This item doesn't exist in the set.\n";
        }
    }

    int returnNumber() {
        return vec.size();
    }

    void checkItem(T item) {
        auto it = find(vec.begin(), vec.end(), item);
        if (it != vec.end()) {
            cout << "Yes, this item exist in the set.\n";
        } else {
            cout << "No, this item doesn't exist in the set.\n";
        }
    }

    void returnPointer() {
        int index = 1;
        if (vec.empty()) {
            cout << "\nThe set is empty\n";
            return;
        }
        cout << endl << "The values in the set are:\n";
        for (T value: *pointer) {
            cout << "Value " << index << ": " << value << endl;
            index ++;
        }
    }
};

/////////////////////////////////////////////// Headers-Label ////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class LabelGenerator {
protected:
    string prefix;
    int start;
public:
    LabelGenerator();
    LabelGenerator(string pre, int st);
    virtual string nextLabel();
};

class FileLabelGenerator : public LabelGenerator {
private:
    string fileName;
    vector<string> lines;
public:
    FileLabelGenerator(string pre, int st, string fn);
    string nextLabel() override;
    void setVector(vector<string> li);
};

////////////////////////////////////////////////// Implementation-Set ///////////////////////////////////////////////////////

string getChoice() {
    string choice;
    cout << "What do you want to do ?\n[1] Add a new item to the set.\n[2] Remove an item from the set.\n"
            "[3] Return the number of items in the set.\n[4] Determine if an item is a member of the set.\n"
            "[5] Return a pointer to a dynamically created array containing each item in the set.\n[6] Exit.\n";
    cout << "Enter your answer:";
    getline(cin, choice);                                       // take the input then check its validity.
    while (true) {
        if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
            cout << "\nPlease enter a valid choice!\n\n";
            cout << "What do you want to do ?\n[1] Add a new item to the set.\n[2] Remove an item from the set.\n"
                    "[3] Return the number of items in the set.\n[4] Determine if an item is a member of the set.\n"
                    "[5] Return a pointer to a dynamically created array containing each item in the set.\n[6] Exit.\n";
            cout << "Enter your answer:";
            getline(cin, choice);
            continue;
        } else break;
    }
    return choice;
}

string getNumItem() {
    string item;
    getline(cin, item);
    bool flag;
    while (true) {                                              // get the item and check that the item is a number.
        flag = false;
        for (int i = 0; i < item.size(); ++i) {
            if (!(item[i] == 46 || (item[i] > 47 && item[i] < 58))) {
                cout << "\nPlease enter a valid item:";
                getline(cin, item);
                flag = true;
                break;
            }
        }
        if (flag) continue;
        else return item;
    }
}

void stringSet() {                                              // calling functions with strings.
    Set<string> mySet;
    string item;
    while (true) {
        string choice = getChoice();
        if (choice == "1") {
            cout << "\nPlease enter the item to add in the set:";
            getline(cin, item);
            mySet.addItem(item);
            cout << endl;
        } else if (choice == "2") {
            cout << "\nPlease enter the item to remove from the set:";
            getline(cin, item);
            mySet.removeItem(item);
            cout << endl;
        } else if (choice == "3") {
            int num = mySet.returnNumber();
            cout << "\nNumber of items in the set is: " << num << endl;
            cout << endl;
        } else if (choice == "4") {
            cout << "\nPlease enter the item to check if it exist in the set:";
            getline(cin, item);
            mySet.checkItem(item);
            cout << endl;
        } else if (choice == "5") {
            mySet.returnPointer();
            cout << endl;
        } else break;
    }
}

void numberSet() {                                              // calling functions with numbers.
    Set<float> mySet;
    string item;
    while (true) {
        string choice = getChoice();
        if (choice == "1") {
            cout << "\nPlease enter the item to add in the set:";
            item = getNumItem();
            float floatItem = stof(item);
            mySet.addItem(floatItem);
            cout << endl;
        } else if (choice == "2") {
            cout << "\nPlease enter the item to remove from the set:";
            item = getNumItem();
            float floatItem = stof(item);
            mySet.removeItem(floatItem);
            cout << endl;
        } else if (choice == "3") {
            int num = mySet.returnNumber();
            cout << "\nNumber of items in the set is: " << num << endl;
            cout << endl;
        } else if (choice == "4") {
            cout << "\nPlease enter the item to check if it exist in the set:";
            item = getNumItem();
            float floatItem = stof(item);
            mySet.checkItem(floatItem);
            cout << endl;
        } else if (choice == "5") {
            mySet.returnPointer();
            cout << endl;
        } else break;
    }
}

//////////////////////////////////////////////// Implementation-Label ///////////////////////////////////////////////////////

LabelGenerator::LabelGenerator() {
    prefix = "Figure";
    start = 1;
}

LabelGenerator::LabelGenerator(string pre, int st) {
    prefix = pre;
    start = st;
}

string LabelGenerator::nextLabel() {
    string pattern = prefix + ' ' + to_string(start);
    start++;
    return pattern;
}

FileLabelGenerator::FileLabelGenerator(std::string pre, int st, string fn) {
    prefix = pre;
    start = st;
    fileName = fn;
}

void FileLabelGenerator::setVector(vector<string> li) {
    lines = li;
}

string FileLabelGenerator::nextLabel() {
    if (start > lines.size()) {
        cout << "There is no " + prefix + " labels greater than " + to_string(lines.size());
        return "";
    }
    string pattern = prefix + " " + to_string(start) + " : " + lines[start - 1];
    start++;
    return pattern;
}

void takeInput(string &pre, string &st, string &num) {
    cout << "\nPlease enter prefix you want:";                    // getting prefix.
    getline(cin, pre);

    while (true) {                                          // getting number to start from.
        bool flag = false;
        cout << "Please enter number to start from:";
        getline(cin, st);
        string s = st;

        for (int i = 0; i < s.size(); ++i) {                  // remove spaces and end lines from the file.
            s.erase(remove(s.begin(), s.end(), '\n'), s.end());
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < 49 || s[i] > 57) {
                flag = true;
                cout << "Invalid number!\nPlease enter a positive number." << endl << endl;
                break;
            }
        }
        if (flag) continue;
        else {
            st = s;
            break;
        }
    }

    while (true) {                                          // getting number of iterations.
        bool flag = false;
        cout << "Please enter number of labels:";
        getline(cin, num);
        string s = num;

        for (int i = 0; i < s.size(); ++i) {                  // remove spaces and end lines from the file.
            s.erase(remove(s.begin(), s.end(), '\n'), s.end());
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < 49 || s[i] > 57) {
                flag = true;
                cout << "Invalid number!\nPlease enter a positive number." << endl << endl;
                break;
            }
        }
        if (flag) continue;
        else {
            num = s;
            break;
        }
    }
}

vector<string> takeFile(string &fileName) {
    string fileContent, s = "";
    stringstream content;
    vector<string> lines;
    cout << "Please enter file name:";
    while (true) {
        getline(cin, fileName);                               // get file name and check the validity of format.
        if (fileName.size() < 5) {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please enter a valid file name :";
            continue;
        }
        if (fileName.substr(fileName.size() - 4, 4) != ".txt") {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please enter a valid file name :";
            continue;
        }
        ifstream file(fileName);
        if (!file.good()) {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please enter a valid file name :";
            continue;
        }
        content << file.rdbuf();
        break;
    }
    fileContent = content.str();
    for (int i = 0; i < fileContent.size(); ++i) {
        if (fileContent[i] == '\n') {
            lines.push_back(s);
            s = "";
        } else {
            s += fileContent[i];
        }
    }
    lines.push_back(s);
    return lines;
}

/////////////////////////////////////////////// Functions ///////////////////////////////////////////////////////

void sett(){
    string item, choice, choiceType;
    cout << "======================== WELCOME TO MY PROGRAM! ========================\n";
    cout << "-----> This program generate a set that implement some functions. <-----\n\n";

    cout << "What type of items do you want?\n[1] Strings.\n[2] Numbers.\n[3] Exit.\n";
    cout << "Enter your answer:";
    getline(cin, choiceType);                                           // take the input then check its validity.
    while (true) {
        if (choiceType != "1" && choiceType != "2" && choiceType != "3") {
            cout << "\nPlease enter a valid choice!\n\n";
            cout << "What type of items do you want?\n[1] Strings.\n[2] Numbers.\n[3] Exit.\n";
            cout << "Enter your answer:";
            getline(cin, choiceType);
            continue;
        } else break;
    }
    cout << endl;
    if (choiceType == "1") stringSet();
    else if (choiceType == "2") numberSet();
    cout << endl << "Thanks for using my program :)";
}

void label(){
    string choice, pre, st, num, fileName;
    int intSt, intNum;
    cout << "This program generate a series of names that form a sequential pattern.\n" <<
         "Also it reads from the file and label lines.\n";
    while (true) {
        cout << "What do you want to do ?\n[1] Label Generator.\n[2] File Label Generator.\n[3] Exit.\n";
        cout << "Enter your answer:";
        getline(cin, choice);
        while (true) {
            if (choice != "1" && choice != "2" && choice != "3") {
                cout << "\nPlease enter a valid choice!\n\n";
                cout << "What do you want to do ?\n[1] Label Generator.\n[2] File Label Generator.\n[3] Exit.\n";
                cout << "Enter your answer:";
                getline(cin, choice);
                continue;
            } else break;
        }

        if (choice == "1") {
            takeInput(pre, st, num);
            intSt = stoi(st);
            intNum = stoi(num);
            LabelGenerator figureNumbers(pre, intSt);
            cout << endl << pre << " numbers:\n";
            for (int i = 0; i < intNum; i++) {
                if (i < intNum - 1) cout << figureNumbers.nextLabel() << ", ";
                else cout << figureNumbers.nextLabel();
            }
            cout << endl << endl;

            cout << "More " << pre << "s:\n";
            for (int i = 0; i < intNum; i++) {
                if (i < intNum - 1) cout << figureNumbers.nextLabel() << ", ";
                else cout << figureNumbers.nextLabel();
            }
            cout << endl << endl;
        } else if (choice == "2") {
            takeInput(pre, st, num);
            intSt = stoi(st);
            intNum = stoi(num);
            vector<string> lines = takeFile(fileName);
            FileLabelGenerator figureLabels(pre, intSt, fileName);
            figureLabels.setVector(lines);

            cout << endl << pre << " labels:\n";
            for (int i = 0; i < intNum; i++) {
                cout << figureLabels.nextLabel() << endl;
                if (i + intSt > lines.size()) break;
            }
            cout << endl;
        } else break;
    }
    cout << endl << "Thanks for using my program :)";
}

////////////////////////////////////////////////// Main ///////////////////////////////////////////////////////

int main() {
    cout << "======================== WELCOME TO MY APPLICATION! ========================\n\n";

    while (true) {
        string choice;
        cout << "What do you want?\n" << "[1] Set.\n" << "[2] Label Generator.\n"
             << "[3] Exit.\n";
        getline(cin, choice);
        while (true) {
            if (choice != "1" && choice != "2" && choice != "3") {
                cout << "Please enter a valid choice!\n\n";
                cout << "What do you want?\n" << "[1] Set.\n" << "[2] Label Generator.\n"
                     << "[3] Exit.\n";
                getline(cin, choice);
                continue;
            }
            break;
        }
        cout << endl;
        if (choice == "1") sett();
        else if (choice == "2") label();
        else if (choice == "3") break;
    }

    cout << "THANKS FOR USING OUR APPLICATION :)";
    cout << "\t\tSEE YOU LATER...\n";
    return 0;
}
