#include <bits/stdc++.h>
using namespace std;

class Player{
public:
    string name;
    int position;
    int moves;
    Player(string &name){
        this->name = name;
        this->position = 0;
        this->moves = 0;
    }
    int rollDice() {
        srand(time(0));
        return (rand()%6)+1;
    }
};

class Board{
public:
    int size;
    unordered_map<int,int> snakesPositions;
    unordered_map<int,int> laddersPositions;
    Board(int size){
        this->size = size;
    }
    void movePlayer(Player &player, int jump){
        int newPosition = player.position + jump;
        if(newPosition > size) return;
        if(snakesPositions.count(newPosition))
            newPosition = snakesPositions[newPosition];
        if(laddersPositions.count(newPosition))
            newPosition = laddersPositions[newPosition];
        player.position = newPosition;
    }
    bool checkWinner(Player &player){
        if(player.position == size){
            std::cout << player.name << " wins!" << std::endl;
            return true;
        }
        return false;
    }
};

class Game{
public:
    Board board;
    std::vector<Player> players;
    std::vector<std::pair<int, int>> snakesPositions;
    std::vector<std::pair<int, int>> laddersPositions;
    Game(int boardSize, vector<string> playerNames, vector<pair<int, int>> snakesPositions, vector<pair<int, int>> laddersPositions) : board(boardSize){
        for(string playerName: playerNames){
            players.push_back(Player(playerName));
        }
        this->snakesPositions = snakesPositions;
        this->laddersPositions = laddersPositions;
        boardInitialize();
    }
    void boardInitialize(){
        for(auto it: snakesPositions){
            int head = it.first;
            int tail = it.second;
            board.snakesPositions[head] = tail;
        }
        for(auto it: laddersPositions){
            int bottom = it.first;
            int top = it.second;
            board.laddersPositions[bottom] = top;
        }
    }
    void play(){
        while(true){
            for(Player &player: players){
                int jump = player.rollDice();
                std::cout << player.name << " rolled a " << jump << std::endl;
                board.movePlayer(player, jump);
                std::cout << player.name << " is now on square " << player.position << std::endl;
                if(board.checkWinner(player)){
                    return;
                }
            }
        }
    }
};


int main() {
    // Write C++ code here
    std::vector<std::string> playerNames = {"Player 1", "Player 2", "Player 3"};
    std::vector<std::pair<int, int>> snakes = {{17, 7}, {54, 34}};
    std::vector<std::pair<int, int>> ladders = {{62, 81}, {87, 96}};
    Game game(100, playerNames, snakes, ladders);
    game.play();
    return 0;
}
