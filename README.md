# wordguessgame
Guess the Secret Word Game
This is a simple C++ console-based word guessing game where the player tries to guess a randomly selected secret word from a predefined list. The game allows for adding new words and keeps track of wrong guesses.

# Features
Random Word Selection: The game randomly selects a secret word from a file (secretWord.txt).
Wrong Guesses Tracker: Displays wrong guesses and limits the number of wrong attempts to 5.
Add New Words: Players can add new words to the list after each game.
Word Masking: The unguessed letters in the word are displayed as underscores _ to make the guessing process more fun.
Getting Started
Prerequisites
C++ Compiler: You need a C++ compiler such as g++ installed on your machine.
Project Files
wordguessgame.cpp: The main game code.
secretWord.txt: A file containing the list of words to be guessed by the player. Example words included are: PINEAPPLE, BANANA, GRAPE, WATERMELON, STRAWBERRY, and TANGERINE.
# Compilation and Running
 # Compile the code:
bash
Copy code
g++ wordguessgame.cpp -o wordguessgame.out

# Run the game:
bash
Copy code
./wordguessgame.out
secretWord.txt Format
The secretWord.txt file contains the list of words available for guessing. It should be structured as follows:


# How to Play
The game starts by displaying a welcome message.
You will be asked to guess the secret word by entering letters one by one.
Each wrong guess is recorded, and you are allowed up to 5 wrong guesses.
If you guess all letters of the secret word before reaching 5 wrong guesses, you win.
After the game ends, you can add a new secret word to the game if desired.

# Adding New Words
 At the end of each game, you will be prompted:
vbnet
Copy code
Would you like to add a new secret word to the game? (y/n)
If you type y, you'll be asked to enter a new word in all capital letters, which will be saved to secretWord.txt for future games.

# Project Structure
bash
Copy code
├── wordguessgame.cpp    # Main game file
├── secretWord.txt       # File containing list of secret words
└── README.md            # Project documentation
Author
Guided by: Gabriel Fernandes de Oliveira 
Coded by: Priscila Fry
Platform: Alura
License
This project is for educational purposes.
