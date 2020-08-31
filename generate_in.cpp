#include<fstream>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

int main(int argc, char* argv[]){
    if(argc < 5){
        std::cout << "Insuficient arguments" << std::endl;
        exit(1);
    }

    int m = atoi(argv[1]), n = atoi(argv[2]), p = atoi(argv[3]);
    std::ofstream file;
    file.open(argv[4]);
    srand(time(NULL));

    file << m << " " << n << std::endl << p << std::endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            file << rand()%((int)((m+n)/2)) << " ";
        }
        file << std::endl;
    }

    for(int i = 0; i < p; i++){
        file << rand()%m << " " << rand()%n << std::endl;
    }
}