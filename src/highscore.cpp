#include "highscore.h"

std::vector<int> Highscore::HighScores;

void Highscore::AddNewScore(int score)
{
    HighScores.push_back(score);

    std::ofstream highscoreFile("highscores.txt", std::ios::trunc);
    if(!highscoreFile)
    {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    for(size_t i = 0; i < HighScores.size(); ++i)
    {
        highscoreFile << HighScores[i];
        if(i != HighScores.size() - 1)
        {
            highscoreFile << ",";
        }
    }
    highscoreFile.close();
}

int Highscore::GetHighScore()
{

    if(!HighScores.empty())
    {
        sort(HighScores.begin(), HighScores.end());
        return HighScores[HighScores.size()-1];    
    }
    else
    {
        return 0;
    }
}

int Highscore::GetHighScore(int searchScore)
{
    int index = 0;
    if(!HighScores.empty())
    {
        sort(HighScores.begin(), HighScores.end(), std::greater<int>());
        for(int score : HighScores)
        {
            index++;
            if(score == searchScore)
            {
                return index;
            }
        };    
    }
    else
    {
        return 0;
    }
}

void Highscore::LoadHighScores()
{
    std::ifstream highscoresFile("highscores.txt");

    if(!highscoresFile)
    {
        std::cerr << "Failed to open file.\n";
        return;
    }

    std::string line;
    if (std::getline(highscoresFile, line))
    {
        std::stringstream ss(line);
        std::string token;
        while(std::getline(ss, token, ','))
        {
            if(!token.empty())
            {
                HighScores.push_back(std::stoi(token));
            }
        }
    }
    highscoresFile.close();
}