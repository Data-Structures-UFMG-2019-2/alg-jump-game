#include<string>

#include"./board.hpp"
#include"./player.hpp"

namespace JumpGame{

    class Game {
        private:
            int players_number = 0;
            int* order = nullptr;
            int rounds = 0;
            int running_players = 0;
            Board* board = nullptr;
            Player** players = nullptr;
        public:
            Game(std::string input_path);
            ~Game();
            Board* get_board();
            Player** get_players();
            int get_rounds();
            int run_round();
            void set_order();
            void merge_sort(int left, int right);
            void merge(int left, int middle, int right);
    };

}