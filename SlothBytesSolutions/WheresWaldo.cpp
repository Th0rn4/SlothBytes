#include <iostream>
#include <unordered_map>

using namespace std;
int main(int argc, char *argv[]) {
    
    string whereIsWaldo[6][4] = {
        {"0", "0", "0", "0"},
        {"0", "0", "0", "0"},
        {"0", "0", "0", "0"},
        {"0", "0", "0", "0"},
        {"P", "0", "0", "0"},
        {"0", "0", "0", "0"}
    };
    
/*
    string whereIsWaldo[2][4] = {
    {"c", "c", "c", "c"},
    {"c", "c", "c", "d"}
    };
    
    string whereIsWaldo[6][4] = {
    {"0", "0", "0", "0"},
    {"0", "0", "0", "0"},
    {"0", "0", "0", "0"},
    {"0", "0", "0", "0"},
    {"P", "0", "0", "0"},
    {"0", "0", "0", "0"}
    };
    
    string whereIsWaldo[3][3] = {
    {"A", "A", "A"},
    {"A", "A", "A"},
    {"A", "B", "A"}
    };
    
*/

    int numOfRows = sizeof(whereIsWaldo) / sizeof(whereIsWaldo[0]);
    int numOfColumns = sizeof(whereIsWaldo[0]) / sizeof(whereIsWaldo[0][0]);

    string oddChar = "";

    // Count the occurrences of each character
    unordered_map<string, int> charCount;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfColumns; j++) {
            charCount[whereIsWaldo[i][j]]++;
        }
    }

    // Find the outlier character
    for (auto& [char_, count] : charCount) {
        if (count == 1) {
            oddChar = char_;
            break;
        }
    }

    // Locate the outlier character
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfColumns; j++) {
            if (whereIsWaldo[i][j] == oddChar) {
                cout << "[" << i + 1 << "," << j + 1 << "]" << endl;
                break;
            }
        }
    }

    return 0;
}
