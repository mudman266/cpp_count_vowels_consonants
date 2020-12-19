// Josh Williams
// 4/12/2020
// CSC - 234 - 81A
// Chapter 12 - Program 4 - Vowels and Consonants

// Write two functions that accept C-Strings as arguments. One should return the number of vowels in the string.
// The second should return the amount of consonants. Write a program that utilizes both functions.

#include <iostream>
#include <cstring>

using namespace std;

const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
const char consonants[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

class Counter {
    // Counter class contains C-string variable, the user's menu selection,
    // menu presentation, and the heavy lifting for the application.
public:
    char inputString[255];
    char selection;

    void showMenu() {
        // This function prints the menu to the user and stores the choice on the object to this->selection.
        char sel;
        printf("Make a selection:\n");
        printf("A) Count the vowels in the string.\n");
        printf("B) Count the consonants in the string.\n");
        printf("C) Count both, vowels and consonants, in the string.\n");
        printf("D) Enter a new string.\n");
        printf("E) Exit the program.\n");
        printf("Selection: ");
        cin >> sel;

        // Verify input.
        while (sel != 'A' && sel != 'B' && sel != 'C' && sel != 'D' && sel != 'E') {
            cout << "Enter a selection A - E: ";
            cin >> sel;
        }

        // Input verified. Update selection.
        this->selection = sel;
    }

    void processMenu() {
        // Takes action based on the current this->selection.  
        while (this->selection != 'E') {
            if (this->selection == 'A') {
                // VOWEL COUNT
                printf("\nVowels: %d\n\n", this->countVowels(this->inputString));
            }
            else if (this->selection == 'B') {
                // CONSONANT COUNT
                printf("\nConsonants: %d\n\n", this->countConsonants(this->inputString));
            }
            else if (this->selection == 'C') {
                // VOWEL AND CONSONANT COUNT
                printf("\nVowels: %d, Consonants: %d\n\n", this->countVowels(this->inputString), this->countConsonants(this->inputString));
            }
            else if (this->selection == 'D') {
                // ENTER NEW STRING
                printf("\nEnter new string less than 255 characters: ");
                cin.ignore(); // Clear input.
                cin.getline(this->inputString, 255);
            }
            else if (this->selection == 'E') {
                // QUIT PROGRAM
                exit(0);
            }
            else printf("\nInvalid menu selection.");
            this->showMenu();
        }
    }

private:
    int countVowels(char str[]) {
        // Variables
        int i = 0;
        int counter = 0;

        // Loop through the characters until we find the null or \0.
        while (str[i] != '\0') {
            // If the char matches the vowel list add 1 to the counter
            if (isVowel(tolower(str[i]))) counter++;
            i++;
        }
        return counter;
    }

    int countConsonants(char str[]) {
        // Variables
        int i = 0;
        int counter = 0;

        // Loop through the characters until we find the null or \0.
        for (int i = 0; str[i] != '\0'; i++) {
            // Unless the char matches the vowel list, add 1 to the counter
            if (isConsonant(tolower(str[i]))) counter++;
        }
        return counter;
    }

    bool isVowel(char test) {
        // Checks the passed in paramter against the vowel array.
        for (int i = 0; i < 5; i++) {
            if (test == vowels[i]) {
                // Vowel found.
                return true;
            }
        }
        // Didn't match any item in the vowel array.
        return false;
    }

    bool isConsonant(char test) {
        // Checks the passed in paramter against the consonant array.
        for (int i = 0; i < 21; i++) {
            if (test == consonants[i]) {
                // Consonant found.
                return true;
            }
        }
        // Didn't match any item in the consonant array.
        return false;
    }
};


int main()
{
    // Welcome Message
    cout << "Vowels and Consonants\n\n";

    // Create object
    Counter counter1;
    
    // Gather input from the user
    cout << "Enter a string less than 255 characters: ";
    cin.getline(counter1.inputString, 255);

    // Show the menu.
    counter1.showMenu();

    // Process the menu selection.
    counter1.processMenu();
}