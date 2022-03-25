#include <bits/stdc++.h>
using namespace std;

/* ----- Funtion to Read the data from Input File and Convert it in to string ----- */
string readFileIntoString(const string &path){
    auto readString = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()){
        cerr << "Could not open the file - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    readString << input_file.rdbuf();
    return readString.str();
}

/* ----- Main Function of the Program ----- */
int main(int argc, char const *argv[]){

    string Input1("Sample-Input1.txt");
    string Input2("Sample-Input2.txt");

    string readInput1 = readFileIntoString(Input1);
    string readInput2 = readFileIntoString(Input2);


    exit(EXIT_SUCCESS);

    return 0;
}