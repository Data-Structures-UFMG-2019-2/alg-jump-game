#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<chrono>

#include"./include/game.hpp"
#include"./include/list/linked_list.hpp"

int main(int argc, char* argv[]){
    if(argc > 1){
        JumpGame::Game* game;
        auto start = std::chrono::high_resolution_clock::now();
        try{
            game = new JumpGame::Game(argv[1]);

            int winner = game->run_round();
            while(winner == -1){
                // game->get_board()->print_visited();
                winner = game->run_round();
            }

            auto end = std::chrono::high_resolution_clock::now(); 
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            if(argc>2){
                std::ofstream time_log_file;
                time_log_file.open("./output/time_log.csv", std::ios_base::app);
                time_log_file << game->get_board()->get_m() << "," << game->get_board()->get_n() << "," << game->get_players_number() << "," << duration.count() << std::endl;
                time_log_file.close();
            }
            
            std::cout << (char)('A'+winner) << std::endl << game->get_rounds() << std::endl;
            delete game;
        }
        catch(char const* e){
            auto end = std::chrono::high_resolution_clock::now(); 
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            if(argc>2){
                std::ofstream time_log_file;
                time_log_file.open("./output/time_log.csv", std::ios_base::app);
                time_log_file << game->get_board()->get_m() << "," << game->get_board()->get_n() << "," << game->get_players_number() << "," << duration.count() << std::endl;
                time_log_file.close();
            }
            if(game != nullptr){
                delete game;
            }
            std::cout << e << std::endl;
        }
    }
    return 0;
}