/*
Description
Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2
*/



// C++ program to calculate the frequency
// of each word in the given string
 
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> wordFrequency;

    string word;
    while (cin >> word) {
        wordFrequency[word]++;
    }

    for (const auto& pair : wordFrequency) {
        cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}
