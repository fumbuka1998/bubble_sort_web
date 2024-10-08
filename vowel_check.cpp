// #include <iostream>
// using namespace std;

// int main() {
//     char c;
//     bool isLowercaseVowel, isUppercaseVowel;

//     cout << "Enter an alphabet: ";
//     cin >> c;

//     // evaluates to 1 (true) if c is a lowercase vowel
//     isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

//     // evaluates to 1 (true) if c is an uppercase vowel
//     isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

//     // show error message if c is not an alphabet
//     if (!isalpha(c))
//       printf("Error! Non-alphabetic character.");
//     else if (isLowercaseVowel || isUppercaseVowel)
//         cout << c << " is a vowel.";
//     else
//         cout << c << " is a consonant.";

//     return 0;
// }


#include <iostream>
#include <cctype>
using namespace std;

extern "C" {
    const char* checkVowelOrConsonant(char c) {
        if (!isalpha(c)) {
            return "Error! Non-alphabetic character.";
        } else {
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                return "It's a vowel.";
            } else {
                return "It's a consonant.";
            }
        }
    }
}
