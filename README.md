# C Mini-Projects Collection

This repository contains a collection of simple console-based applications written in the **C programming language**. Each project is a standalone program that demonstrates basic C concepts.

## Table of Contents
1.  [Tic-Tac-Toe Game](#1-tic-tac-toe-game)
2.  [Unit Converter](#2-unit-converter)
3.  [Rock, Paper, Scissors Game](#3-rock-paper-scissors-game)

---

### 1. Tic-Tac-Toe Game
A classic Tic-Tac-Toe game where you can play against the computer. The computer makes random moves.

#### How to Compile
To compile the program, use a C compiler like GCC:
```bash
gcc -Wall TicTacToe.c -o tictactoe
```

#### How to Run
Execute the compiled file from your terminal:
```bash
./tictactoe
```

#### Usage
- The board is a 3x3 grid.
- You play as 'X' and the computer plays as 'O'.
- When prompted, enter the row number (1-3) and then the column number (1-3) to place your mark.
- The game ends when a player gets three in a row (horizontally, vertically, or diagonally), or when the board is full (a tie).
- After each game, you'll be asked if you want to play again.

---

### 2. Unit Converter
A simple command-line tool to convert units for temperature, currency, and mass.

*Note: The currency conversion rates are hardcoded and based on values from December 2022.*

#### How to Compile
```bash
gcc -Wall unit_converter.c -o converter
```

#### How to Run
```bash
./converter
```

#### Usage
1.  **Select a category**:
    - `T` for Temperature
    - `C` for Currency
    - `M` for Mass
2.  **Select a conversion type**:
    - **Temperature**: `1` for Celsius to Fahrenheit, `2` for Fahrenheit to Celsius.
    - **Currency**: `1` for EUR to USD, `2` for EUR to GBP, `3` for EUR to CNY.
    - **Mass**: `1` for Kg to Pounds, `2` for Grams to Ounces.
3.  Enter the numeric value you wish to convert. The program will display the result and then exit.

---

### 3. Rock, Paper, Scissors Game
A console version of the classic "Rock, Paper, Scissors" game against a computer opponent. The first player to reach 10 points wins.

#### How to Compile
```bash
gcc -Wall rock_paper_scissors.c -o rps_game
```

#### How to Run
```bash
./rps_game
```

#### Usage
1.  Enter your name/nickname.
2.  Enter a name for your AI opponent.
3.  Choose your move by typing:
    - `R` for Rock
    - `P` for Paper
    - `S` for Scissors
4.  The game continues until either you or the computer scores 10 points.
5.  A summary of each round is displayed at the end of the match.

---

## Areas For Improvement
* **Tic-Tac-Toe**: Implement a more challenging AI instead of random moves.
* **Unit Converter**: Add more conversion categories (e.g., data storage, speed) and allow for reverse conversions (e.g., USD to EUR).
* **Rock, Paper, Scissors**: Allow the user to set the winning score instead of a fixed 10 points.
* **New Projects**: Add other classic console games like Hangman or a number guessing game.

---

## Author

- **Name**: Exarchou Athos
- **Student ID**: it2022134
- **Email**: it2022134@hua.gr, athosexarhou@gmail.com

---

## License
This project is licensed under the MIT License.
