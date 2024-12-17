# Rock Paper Scissors Game with Sound and Color Effects

This project implements the classic game **Rock, Paper, Scissors** in C++ with added features such as **sound effects** (using the `Beep()` function) and **colorful feedback** (using `system("color")` for CMD).

![Alt Text]([https://example.com/image.png](https://ibb.co/D91mxLw))

## Features:
- The player can play multiple rounds of the game.
- The computer randomly selects an option for each round.
- After each round, the game displays whether the player or computer won, or if the round was a draw.
- The player’s score, the computer's score, and the number of draws are tracked.
- The game also uses color coding for different outcomes:
  - Green for the player's win.
  - Red for the computer's win.
  - Yellow for a draw.
- The game plays a sound (using the `Beep()` function) when the computer wins.

## How to Play:
1. Upon starting the game, you will be prompted to input how many rounds you want to play.
2. You will then choose between "Stone (1)", "Paper (2)", and "Scissors (3)".
3. The computer will also choose an option randomly.
4. After each round, the result (win/loss/draw) is displayed, and scores are updated.
5. The game will ask if you want to play again after each session.

## Game Rules:
- **Stone (1)** beats **Scissors (3)**.
- **Scissors (3)** beats **Paper (2)**.
- **Paper (2)** beats **Stone (1)**.
- If both the player and the computer choose the same option, it’s a draw.

## Game Loop:
- The game will continue to ask if you want to play another round until you choose not to.

## How to Compile and Run:
1. Make sure you have a C++ compiler installed (e.g., MinGW, Visual Studio).
2. Compile the code:
    ```bash
    g++ -o rock-paper-scissors game.cpp
    ```
3. Run the executable:
    ```bash
    ./rock-paper-scissors
    ```

## Code Breakdown:

### 1. **Enums**:
- `enOptions`: This enum defines the three choices the player and computer can make: **Stone**, **Paper**, and **Scissors**.
- `enScoore`: This enum represents the possible results of each round: **ComputerWin**, **PlayerWin**, or **Draw**.

### 2. **Functions**:
- `RadnomNumber(int number, int from, int to)`: This function generates a random number between `from` and `to` to simulate the computer's choice.
  
- `HowManyRound()`: This function asks the player how many rounds they want to play and returns the number of rounds.

- `countanio()`: This function asks the player if they want to play again. It returns `true` to continue or `false` to stop.

- `WhatThayChoose(int choose)`: This function maps the player's or computer's choice (1, 2, or 3) to the corresponding `enOptions` value (Stone, Paper, or Scissors) and displays a message about the choice.

- `playerWinRound(enOptions PlayerChoose, enOptions ComputerChoose)`: This function compares the player’s choice with the computer's choice and returns the result of the round (Win, Loss, or Draw). It also prints the result.

- `FinalResult(int PlayerScoore, int ComputerScoore, int drawScoore)`: This function prints the final scores after all rounds are played.

- `startGame()`: This is the main game loop. It:
  - Asks how many rounds to play.
  - Loops through each round, getting the player’s input and generating the computer's choice.
  - Calls `playerWinRound()` to determine the outcome and updates scores.
  - After all rounds are completed, it calls `FinalResult()` to print the final scores.

### 3. **Sound & Color Effects**:
- The `Beep()` function is used to play a sound when the computer wins.
- The `system("color <code>")` command changes the console’s text color based on the outcome of each round.

### 4. **Random Number Generation**:
- The `RadnomNumber()` function is used to generate a random number between `1` and `3` for the computer’s selection (Stone, Paper, or Scissors).

### Libraries Used:
- `<iostream>`: For input/output operations.
- `<string>`: For string manipulations.
- `<cmath>`: For mathematical functions (though not directly used in this project, it’s included).
- `<vector>`: Not used directly in this project but could be useful for future expansion.
- `<windows.h>`: To access Windows-specific features like the `Beep()` function and the `system("color")` command.

## Example:

How Many Rounds You want play? 3 Choose From Stone[1] - Paper[2] - Scissor[3] 1 Choose is Stone Computer Turn Choose is Paper The Computer wins!
Choose From Stone[1] - Paper[2] - Scissor[3] 2 Choose is Paper Computer Turn Choose is Scissor The Computer wins!
Choose From Stone[1] - Paper[2] - Scissor[3] 3 Choose is Scissor Computer Turn Choose is Stone The Computer wins!

	--------- FinalResult ---------
	Player win : 0
	computer win : 3
	draw : 0
	------------------------------

## License:
This project is open source and available under the MIT license.
