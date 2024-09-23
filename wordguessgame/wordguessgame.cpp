/* Project: Guess the secret word guided by  Gabriel Fernandes de Oliveira
**Alura
** Priscila Fry
Compile command: g++ wordguessgame.cpp -o wordguessgame.out 
 Run command: wordguessgame.out*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void add_word(); // Function prototype for add_word. Declaring a prototype of
                // the function (void add_word();) at the top informs the compiler about its existence, even though the actual implementation is written later in the code.

string secret_word = "WATERMELON";
map<char, bool> guessed_word;
vector<char> wrong_guesses; // vector stores a list of elements

bool word_exist(char guess)
{
    /*for(int i = 0; i < secret_word.size(); i++){ //This is a longer way of coding
        if(guess == secret_word[i]){
            return true;
        }
    }*/
    for (char word : secret_word)
    { // this is a smaller version  of the for loop above
        if (guess == word)
        {
            return true;
        }
    }
    return false;
}
bool not_guessed()
{
    for (char word : secret_word)
    {
        if (!guessed_word[word])
        {
            return true;
        }
    }
    return false;
}

bool not_hanged()
{
    return wrong_guesses.size() < 5;
}

void print_welcome_message()
{

    cout << "----------------------------------" << endl;
    cout << "-------  Guessing Game!  ---------" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;

    cout << "Enter Your guess in capital letter" << endl;
}

void print_wrong_guesses()
{
    cout << "Wrong guesses: ";
    for (char word : wrong_guesses)
    {
        cout << word << " ";
    }
    cout << endl;
}

void print_guessed_word()
{
    for (char word : secret_word)
    {
        if (guessed_word[word])
        {
            cout << word << " ";
        }
        else
        {
            cout << "_  ";
        }
        // cout<<endl;
    }
}
void guess()
{
    char guess;
    cin >> guess;

    guessed_word[guess] = true;
    cout << endl
        << "Your guess is: " << guess << endl;
    if (word_exist(guess))
    {
        cout << "You got it right! Your guess is in the secret word." << endl;
    }
    else
    {
        cout << "Wrong guess, try again." << endl;
        wrong_guesses.push_back(guess); // push_back() inserts the desire element at the end of the list stored.
    }
    cout << endl;
}

void gameOver()
{
    cout << "Game over!" << endl;
    cout << "The secret word was: " << secret_word << endl;
    if (not_guessed())
    {
        cout << "You lost! Try again!" << endl;
    }
    else
    {
        cout << "Congratulations! You guessed the secret word!" << endl;
           cout << "Would you like to add a new secret word to the game?(y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            add_word();
        }
        
    }
}

vector<string> read_file()
{
    ifstream file;
    file.open("secretWord.txt"); // fstream handles the flux of data in a file
    if (file.is_open())
    {
        int numOfWords;
        file >> numOfWords;

        // cout<<"The file has: "<< numOfWords<<" words."<<endl;

        vector<string> words_of_the_file;
        for (int i = 0; i < numOfWords; i++)
        {
            string word_read;
            file >> word_read;
            // cout<<"Line "<<i<<" : "<< word_read<<endl;
            words_of_the_file.push_back(word_read);
        }
        file.close();
        cout << endl;
        return words_of_the_file;
    }
    else
    {
        cout << "secretWord file not found." << endl;
        exit(0);
    }
}

void random_word()
{
    vector<string> words = read_file();
    srand(time(NULL));
    int index_random = rand() % words.size();
    secret_word = words[index_random];
}

void save_file(vector<string> new_list)
{
    ofstream file;
    file.open("secretWord.txt");
    if (file.is_open())
    {
        file << new_list.size() << endl;

        for (string word : new_list)
        {
            file << word << endl;
        }
        file.close();
    }
    else
    {
        cout << "secretWord file not found." << endl;
        exit(0);
    }
}
void add_word()
{
    cout << "Write the new secret word with capital letters." << endl;
    string new_word;
    cin >> new_word;

    vector<string> word_list = read_file();
    word_list.push_back(new_word); // add a new word to the file

    save_file(word_list);

}

int main()
{
    print_welcome_message();
    read_file();
    random_word();

    while (not_guessed() && not_hanged())
    {

        print_wrong_guesses();
        print_guessed_word();
        guess();
    }
    gameOver();
   
}
