#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string fileName, wordToFind, line;
    int lineNr = 0;

    cout << "Podaj nazwe pliku: ";
    cin >> fileName;
    cout << "Podaj słowo do wyszukania: ";
    cin >> wordToFind;

	ifstream file(fileName);
    if(file.good()){
        while(getline(file, line)){
            lineNr++;
            if(line.find(wordToFind) != string::npos){
                cout << "Wyraz znaleziono na lini: " << lineNr << "\n";
            }
        }
    } else {
        cout << "Niepoprawna nazwa pliku\n";
    }
    
    return 0;

}
