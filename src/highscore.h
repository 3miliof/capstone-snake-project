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

        static int GetHighScore();

        static int GetHighScore(int searchScore);

        static void AddNewScore(int score);

    private:

        static std::vector<int> HighScores;

};

#endif