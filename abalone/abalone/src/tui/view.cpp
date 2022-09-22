#include "view.h"
#include "utils/keyboard.hpp"

using namespace abalone;
using namespace std;

View::View(){

}

void View::displayStart(){
    cout << "=== Welcome to Abalone ===" << endl;
}

void View::displayQuit(){
    cout << "Goodbye !" << endl;
}

void View::displayOver(PlayerColor color){
    cout << "Congratulations, " << to_string(color) << " you win ! " <<  endl;
}

void View::displayHelp(){
    cout << endl;
    cout << "Here is a list of command you can use :" << endl;
    cout << "quit : to quit the game " << endl;
    cout << "help : to display the possible commands  " << endl;
    cout << endl;
}

void View::displayCurrent(PlayerColor color){
    cout << "It's your turn : " << to_string(color) << endl;
}

void View::displayError(string msg){
    cout << "ERROR : " << msg << endl;
}

void View::displayBoard(Board board){
    int a = 7;
    for(int i = 0 ; i < board.getRow(); i++){

        if(i < 5){
            a--;
        } else {
            a++;
        }
        cout<< setw(a);// permet de mettre des espaces

        cout << board.getLetterCoord(i);
        cout <<"-- ";
        for(int j = 0 ; j < board.getColumn(); j++){
            Position pos = Position(board.getLetterCoord(i),board.getIntCoord(j));
            Status status = board.getSquare(pos).getStatus();
            if(status == Status::OUTSIDE){
                cout << "";
            }else if(status == Status::BLACK){
                cout << "B ";
            }else if(status == Status::WHITE){
                cout << "W ";
            }else if(status == Status::FREE){
                cout << ". ";
            }
        }
        if(i==5){
            cout << "\\" ;
        }else if(i>5){
            cout << "\\ " << 15 - i ;
        }
        cout << endl;
    }
    cout << setw(a*3+3);
    cout << "\\ \\ \\ \\ \\ 6" << endl;
    cout << setw(a*3+3);
    cout << " 1 2 3 4 5 " << endl;
    cout << endl;
}

std::string View::askCommand(){
    cout << "Entrez votre commande : ";
    string command;
    try {
        command = nvs::lineFromKbd<string>();
        toUpper(command);
    } catch (nvs::bad_string_convert) {
        return "";
    }
    return command;
}

void View::toUpper(string & str){
    for(std::string::iterator it = str.begin(); it != str.end(); it++){
        *it = static_cast<char>(toupper(*it));
    }
}
