#include"../include/player.hpp"

using namespace JumpGame;

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
}

Player::~Player(){
}

int Player::get_x(){
    return this->x;
}

int Player::get_y(){
    return this->y;
}