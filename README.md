# Upwords

## Description
Upwords is a letter tile word game similar to Scrabble, with players building words using letter tiles on a gridded game board. Unlike Scrabble, in Upwords letters can be stacked on top of existing words to create new words. Scoring is determined by the number of letter tiles stacked in a new word. It has been implemented as a terminal-based project for the bachelor's course "Foundations of Computer Science". Starting only with the game instructions and a bonus list of Italian words, this project was developed from scratch. It's entirely written in C++, and the gameplay takes place in the terminal using ASCII symbols to represent the board.

## Features
- Player creation and management.
- Full game turn management including letter shuffling, drawing, word composing, score calculation, suggestion requests, and turn passing.
- A unique feature that provides suggestions for the highest-scoring word that can be composed with the letters in the player's hand if they are stuck.

## Installation
The project is contained within the "upwords" folder, including a build made using Qt Creator. The "ELABORATO_UPWORDS" folder contains the main file and all header files necessary for the project.
To start the game, follow these steps:
1. Ensure you have a C++ compiler installed on your system.
2. Clone the repository or download the project to your local machine.
3. Navigate to the project directory and compile the project. If you're using Qt Creator, you can open the project file and build it directly from the IDE.
4. Run the compiled executable from your terminal.

## How to Play
Launch the game from your command prompt or terminal. The game will provide on-screen instructions for inputting commands. Input is letter-based, guiding players through the entire game from start to finish.

## Dependencies
The game relies on a dictionary file named "words_italian" located in the "file parole dizionario" folder for the suggestion feature.

## Contributing
Currently, the project is a completed assignment for an academic course and is not open for contributions. However, feedback and suggestions are welcome, especially on the suggestion function.

## Support
For support or further information, please contact [your_email@example.com].
