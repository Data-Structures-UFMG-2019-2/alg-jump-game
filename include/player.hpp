#ifndef PLAYER_H
#define PLAYER_H

namespace JumpGame{

    class Player {
        private:
            int x;
            int y;
        public:
            Player(int x, int y);
            ~Player();
            int get_x();
            int get_y();
    };

}

#endif