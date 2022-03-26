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
/* ----- Function to Token Vector of String ----- */
vector<string> ConverstStringTovectorToken(string InputString){
    vector<string> TokenVector;

    istringstream ireadString(InputString);
    string s;

    while (ireadString >> s){
        TokenVector.push_back(s);
    }
    return TokenVector;
}
/* ----- Function to Create Set of Tokens in Input String ----- */
set<string> ConverstStringToSetTokens(string InputString, string InputString2){
    set<string> TokenSet;

    istringstream ireadString(InputString);
    string str;

    while (ireadString >> str){
        TokenSet.insert(str);
    }
    istringstream ireadString2(InputString2);
    string str2;

    while (ireadString2 >> str2){
        TokenSet.insert(str2);
    }
    return TokenSet;
}

/* ----- Function to Count the Frequency of Terms of Input string ----- */
map<string, int> CountTermFrequency(vector<string> input, set<string> setToken){
    map<string, int> Term;
    for (int i = 0; i < input.size(); i++) {
        Term[input[i]]++;
    }
    set<string, greater<string>>::iterator itr;

    for (itr = setToken.begin(); itr != setToken.end(); itr++) {
        string check = *itr;
        if (Term.find(check) == Term.end()){
            Term.insert(pair<string, int>(check, 0));
        }
    }
    return Term;
}

/* ----- Function for fing Dot Product of Two Vectors ----- */
int dotProduct(vector<int> v1, vector<int> v2){
    int product = 0;
    for (int i = 0; i < v1.size(); ++i){
        product += v1[i] * v2[i];
    }
    return product;
}

double magnitude(vector<int> v){
    return std::sqrt(dotProduct(v, v));
}

void writeResult(const char *filename, double result){
    std::ofstream file(filename);
    file << "The Cosine Similarity In Document1 and Document2 is :- " << result << std::endl;
    file.close();
}

void CosineSimilarity(map<string, int> M1, map<string, int> M2){

    vector<int> v1;
    vector<int> v2;

    map<string, int>::iterator itr;
    for (itr = M1.begin(); itr != M1.end(); itr++){
        v1.push_back(itr->second);
    }
    for (itr = M2.begin(); itr != M2.end(); itr++){
        v2.push_back(itr->second);
    }

    int DotProduct = dotProduct(v1, v2);
    double Magnitude = magnitude(v1) * magnitude(v2);

    double cosine = DotProduct / Magnitude;

    writeResult("Sample-Output.txt", cosine);
    
}
/* ----- Main Function of the Program ----- */
int main(int argc, char const *argv[]){

    string Input1("Sample-Input1.txt");
    string Input2("Sample-Input2.txt");

    string ReadInput1 = readFileIntoString(Input1);
    string ReadInput2 = readFileIntoString(Input2);

    vector<string> vectorReadInput1 = ConverstStringTovectorToken(ReadInput1);
    vector<string> vectorReadInput2 = ConverstStringTovectorToken(ReadInput2);

    set<string> setToken = ConverstStringToSetTokens(ReadInput1, ReadInput2);

    map<string, int> Input1Frequency = CountTermFrequency(vectorReadInput1, setToken);
    map<string, int> Input2Frequency = CountTermFrequency(vectorReadInput2, setToken);

    CosineSimilarity(Input1Frequency, Input2Frequency);

    exit(EXIT_SUCCESS);

    return 0;
}