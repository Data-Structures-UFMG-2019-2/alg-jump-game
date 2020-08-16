#include<string>

#include"./board.hpp"
#include"./player.hpp"

namespace JumpGame{

    class Game {
        private:
            int players_number = 0;
            Board* board = nullptr;
            Player** players = nullptr;
        public:
            Game(std::string input_path);
            ~Game();
            Board* get_board();
    };

}