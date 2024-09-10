#include <iostream>
#include <random>

int max_doors = 3;

int Random(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, max_doors);
    return dist(gen);
}

bool find(bool change_choise, bool show_game){

    int true_answer      = Random();
    int machine_answer   = Random();
    int wrong_answer     = Random(); 
    int new_answer       = Random();
     
    while (wrong_answer == true_answer)  wrong_answer = Random();

    if (show_game == true) {
        std::cout <<  "       " << machine_answer <<  "       |      " << wrong_answer << "      |" ;
    }
    
    if (change_choise == true) {
        for (new_answer = 1; new_answer == machine_answer || new_answer == wrong_answer; new_answer++) {}
        machine_answer = new_answer;
        if (show_game == true) {
            std::cout <<  "          " << machine_answer <<  "         |";
        }
    }

    int result = machine_answer == true_answer ? 1 : 0;
    if (show_game == true) {
        std::cout << "      " << true_answer << "      " << "|   " << result << std::endl;;
    }
    return result;
}

int main(){
    std::string input;
    int games; 
    bool show_game;

    std::cout << "How many games?" << std::endl;
    std::cin >> games;
    

    do {
    int wins_f = 0;
    int loses_f = 0;
    int wins_t = 0;
    int loses_t = 0;

    std::cout << "Show game? 1/0 " << std::endl;
    std::cin >> show_game;

    if (show_game == true) {
        std::cout <<  "machine answer | wrong door  | true answer |  Win? " << std::endl;
    }

    for (int i = 0; i < games; i++) {
        find(false, show_game) ? wins_f++ : loses_f++;
    }

    if (show_game == true) {
        std::cout << std::endl <<  "machine answer | wrong door  | new machine answer | true answer |  Win? " << std::endl;
    }

    for (int i = 0; i < games; i++) {
        find(true, show_game) ? wins_t++ : loses_t++;
    }
    
    std::cout << std::endl << "Non Change choise  | " << wins_f << " / " << loses_f << " |   " << (static_cast<double>(wins_f)/games*100) << "%" << std::endl;
    std::cout << "Change choise      | " << wins_t << " / " << loses_t << " |   " << (static_cast<double>(wins_t)/games*100) << "%" << std::endl << std::endl;
    } while (input.empty());
    
    return 0;
}