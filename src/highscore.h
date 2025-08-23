#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

class Highscore
{
    public:

        static void LoadHighScores();

        //Get the highest score
        static int GetHighScore();

        //Get the ranking of te new highscore
        static int GetHighScore(int searchScore);

        static void AddNewScore(int score);

    private:

        static std::vector<int> HighScores;

};

#endif