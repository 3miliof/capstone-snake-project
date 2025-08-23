# CPPND: Capstone Snake Game Example

Built upon the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://github.com/udacity/CppND-Capstone-Snake-Game).

## Instructions to run
Make a build directory in the top level directory: mkdir build && cd build
Compile: cmake .. && make
Run it: ./SnakeGame.

## New behaviours
- Food will either increase or decrease the speed of the snake. This is to be random and hidden from the user for extra difficulty
- Red "poison" will spawn every 2 seconds to add increased difficulty to the game. If these are eaten the game will end.
- Highscores will be saved to a file and a ranking is output at the end of the game

## Rubric Points Addressed:
### Compiling and Testing (All Rubric Points REQUIRED)

| Criteria | Evidence |
| -------- | -------- |
| The submission must compile and run without errors on the Udacity project workspace. | Runs without errors | 

### Loops, Functions, I/O - meet at least 2 criteria

| Criteria | Evidence |
| -------- | -------- |
| The project demonstrates an understanding of C++ functions and control structures. | Examples - while loop in Game::PlaceFood() line 134, if statement in Game::PlaceFood() line 141, for loop in Renderer::Render() line 56. |
| The project reads data from a file and process the data, or the program writes data to a file. | Added Highscore.h and .cpp to create, read from and write to a highscore file to persist between games. |
| The project uses arrays or vectors and uses constant variables. | std::vector line 26 game.h, const variables used GameObject.h setters. |


### Object Oriented Programming - meet at least 3 criteria

| Criteria | Evidence |
| -------- | -------- |
| One or more classes are added to the project with appropriate access specifiers for class members. | Multiple new classes added, all with access modifiers, GameObject.h example of getters and setters to protect non-const position variables. |
|Overloaded functions allow the same function to operate on different parameters. | Highscore::GetHighScore() and HighScore::GetHighScore(int) example of overloaded function |
|Classes follow an appropriate inheritance hierarchy with virtual and override functions. | Both Food types inherit from Food class, extended from base GameObject class. FastFood and SlowFood have seperate implementations of pure virtual CalculateMultiplierSpeed |

### Memory Management - meet at least 3 criteria

| Criteria | Evidence |
| -------- | -------- |
| The project makes use of references in function declarations. | GameObject.h::SetPosition takes an int reference for each x and y. |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | Game::PlaceFood() line 145 and line 149, causes previous food object to go out of scope and be collected on creation of the new food object. |
| The project follows the Rule of 5. | Originally the only class using a destructor was Renderer. This was removed so no class uses any of the 5 special functions, and therefore the rule is not violated |
| The project uses smart pointers instead of raw pointers. | Game.h line 25 uses a shared ptr to a "Food" object. |

### Concurrency - meet at least 2 criteria

| Criteria | Evidence |
| -------- | -------- |
| The project uses multithreading. | Game.cpp line 32 uses a seperate thread to spawn new bombs every 2 seconds |
| A mutex or lock is used in the project. | Game.cpp line 49 mutex used to copy the contents of bomb locations to avoid it being changed before a snapshot is taken to be used for rendering |

