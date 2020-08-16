#ifndef PLAYER_H
#define PLAYER_H

#include<stack>

#include"./board.hpp"

namespace JumpGame{

    class Player {
        private:
            int id = -1;
            int x = -1;
            int y = -1;
            int last_jump = -1;
            bool winable = true;
            std::stack<int>* optimal_path = nullptr;
            void reconstruct_path(Board* board, int* path);
        public:
            Player(int id, int x, int y);
            ~Player();
            int get_id();
            int get_x();
            void set_x(int x);
            int get_y();
            void set_y(int y);
            int get_last_jump();
            void set_last_jump(int jump);
            bool can_win();
            void set_winable(bool winable);
            void find_path(Board* board);
            std::stack<int>* get_optimal_path();
    };

}

#endif