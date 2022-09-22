#include "appboard.h"
#include "position.h"
#include "cmath"
#include "string"

using namespace abalone;

AppBoard::AppBoard(Game * game): _game(game)
{
    _scene = new QGraphicsScene();
    double rad = 50;
    _game->initialize();

    for(int i = 0 ; i < _game->getBoard().getRow(); i++){
        for(int j = 0 ; j <  _game->getBoard().getColumn(); j++){
            Position pos = Position(_game->getBoard().getLetterCoord(i),_game->getBoard().getIntCoord(j));
            Status status = _game->getBoard().getSquare(pos).getStatus();
            if(!(status == Status::OUTSIDE)){
                plateau[i][j] = new HexaCell(rad,sqrt(3)*(j+i*0.5)*rad,1.5*i*rad,nullptr,status);
            }
        }
    }

    _view = new QGraphicsView(_scene);
    this->addWidget(_view);

    _view->setRenderHint(QPainter::Antialiasing);
    _view->setRenderHint(QPainter::TextAntialiasing);
    _view->setCacheMode(QGraphicsView::CacheBackground);
    _view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    _view->setDragMode(QGraphicsView::ScrollHandDrag);
}

void AppBoard::displayBoard(){
    for(int i = 0 ; i < _game->getBoard().getRow(); i++){
        for(int j = 0 ; j <  _game->getBoard().getColumn(); j++){
            Position pos = Position(_game->getBoard().getLetterCoord(i),_game->getBoard().getIntCoord(j));
            Status status = _game->getBoard().getSquare(pos).getStatus();
            if(!(status == Status::OUTSIDE)){
                _scene->addItem(plateau[i][j]);
            }
        }
    }
}

void AppBoard::update(){
    for(int i = 0 ; i < _game->getBoard().getRow(); i++){
        for(int j = 0 ; j <  _game->getBoard().getColumn(); j++){
            Position pos = Position(_game->getBoard().getLetterCoord(i),_game->getBoard().getIntCoord(j));
            Status status = _game->getBoard().getSquare(pos).getStatus();
            if(!(status == Status::OUTSIDE)){
                plateau[i][j]->setStatus(status);
                plateau[i][j]->update();
            }
        }
    }
}

std::string AppBoard::getMove(){
    std::string command;
    for(int i = 0 ; i < _game->getBoard().getRow(); i++){
        for(int j = 0 ; j <  _game->getBoard().getColumn(); j++){
            Position pos = Position(_game->getBoard().getLetterCoord(i),_game->getBoard().getIntCoord(j));
            Status status = _game->getBoard().getSquare(pos).getStatus();
            if(!(status == Status::OUTSIDE)){
                if(plateau[i][j]->getSelected()==2){
                    command.insert(0,1,_game->getBoard().getLetterCoord(i));
                    command.insert(1,1,char(_game->getBoard().getIntCoord(j+'0')));
                    plateau[i][j]->setSelected(0);
                }else if(plateau[i][j]->getSelected()==1){
                    command.push_back(_game->getBoard().getLetterCoord(i));
                    command.append(std::to_string(_game->getBoard().getIntCoord(j)));
                    plateau[i][j]->setSelected(0);
                }
            }
        }
    }
    return command;
}

AppBoard::~AppBoard()
{

}
