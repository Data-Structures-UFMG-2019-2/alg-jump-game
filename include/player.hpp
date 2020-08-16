#ifndef PLAYER_H
#define PLAYER_H

#include"./queue/queue.hpp"
#include"./board.hpp"

namespace JumpGame{

    class Player {
        private:
            int x;
            int y;
            List::LinkedList<int>* optimal_path;
            void reconstruct_path(Board* board, int* path);
        public:
            Player(int x, int y);
            ~Player();
            int get_x();
            int get_y();
            void find_path(Board* board);
            List::LinkedList<int>* get_optimal_path();
    };

}

#endif