#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class ReadClass {
public:
    void showClass() {
        ifstream file("main.cpp");
        if (!file.is_open()) {
            cerr << "Unable to open file" << endl;
            return;
        }

        string line;
        regex classPattern("\\bclass\\s+(\\w+)");
        smatch match;
        vector<string> classes;

        while (getline(file, line)) {
            if (regex_search(line, match, classPattern)) {
                classes.push_back(match[1]);
            }
        }

        file.close();

        cout << classes.size() << " class in main.cpp" << endl;
        for (const string& className : classes) {
            cout << "class " << className << endl;
        }
    }
};


class myString{
    private:
        string m_str;
    public:
        myString(string s){
            m_str = s;
        }

};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
