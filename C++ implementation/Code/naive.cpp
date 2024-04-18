#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void search(const string& pat, const string& txt) {
    int M = pat.size();
    int N = txt.size();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string txt, pat;
    string txt_file, pat_file;

    cout << "Enter the path of the text file: ";
    cin >> txt_file;
    ifstream txt_input(txt_file);

    if (!txt_input.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    getline(txt_input, txt);

    txt_input.close();

    cout << "Enter the path of the pattern file: ";
    cin >> pat_file;
    ifstream pat_input(pat_file);

    if (!pat_input.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    getline(pat_input, pat);

    pat_input.close();

    // Function call
    search(pat, txt);
    return 0;
}
