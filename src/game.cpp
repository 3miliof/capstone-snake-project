#include "game.h"
#include <iostream>
#include <thread>
#include <atomic>
#include "SDL.h"
#include "highscore.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}


void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  std::atomic<bool> running = true;

  HighscoreTable.LoadHighScores();

  std::thread bombThread([this, &running]() {
      while (running.load()) {
          PlaceBomb();
          std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      }
  });

  while (running.load()) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update(running);

    std::vector<SDL_Point> bombs_copy;
    {
      //Copy under mutex to make sure render gets the correct snapshot of the data before another bomb is added
      std::lock_guard<std::mutex> lock(bombs_mutex);
      bombs_copy = bombs;
    }
    renderer.Render(snake, food, bombs_copy);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle takes
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }

  if (bombThread.joinable()) {
      bombThread.join();
  }

  HighscoreTable.AddNewScore(GetScore());

  if(GetScore() > HighscoreTable.GetHighScore())
  {
    std::cout << "Thats a new high score!" << "\n";
  }
  else
  {
    std::cout << "Your ranking is: " + std::to_string(HighscoreTable.GetHighScore(GetScore())) + "\n";
  }
  
  
}

void Game::PlaceBomb()
{
  bool bombPlaced = false;
  
  while(!bombPlaced)
  {
    int x,y;
    x = random_w(engine);
    y = random_h(engine);
  
    SDL_Point newBomb;
  
    if(!snake.SnakeCell(x,y) && !(x == food.x && y == food.y))
    {
      std::lock_guard<std::mutex> lock(bombs_mutex);
      if(!BombPresent(x, y))
      {
        newBomb.x = x;
        newBomb.y = y;
        bombs.push_back(newBomb);
        bombPlaced = true;
      }
    }
  }
}

bool Game::BombPresent(int &x, int &y)
{
  for(auto& bomb : bombs)
  {
    if(bomb.x == x && bomb.y == y)
    {
      return true;
    }
  }

  return false;
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    std::lock_guard<std::mutex> lock(bombs_mutex);
    if (!snake.SnakeCell(x, y) && !BombPresent(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update(std::atomic<bool>& running) {
  if (!snake.alive) 
  {
    running = false;
    return;
  }
  
  snake.Update();
  
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }

  if(BombPresent(new_x, new_y))
  {
    snake.alive = false;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }