#include "appinfo.h"
#include "playerColor.h"

using namespace abalone;

AppInfo::AppInfo(Game * game, controllerGui & gui): _game(game), _gui(gui)
{
    initInterface();
    setupSignals();
}

void AppInfo::initInterface(){
    QLabel * wlcmsg = new QLabel("Bienvenue sur Abalone !");
    wlcmsg->setStyleSheet("font-family: Calibri; font-weight : bold; font-size: 30px; color : #2084df");
    this->addRow(wlcmsg);

    QLabel *dataLabel = new QLabel("Informations");
    QFont f = dataLabel->font();
    f.setUnderline(true);
    dataLabel->setFont(f);
    this->addRow(dataLabel);

    QLabel *msgBallBlack = new QLabel("Nombre de Balles Noires à éjecter : ");
    this->addRow(msgBallBlack);

    nbBlack = _game->getCurrent().getColor()==PlayerColor::BLACK?_game->getCurrent().getNbBall()-8:_game->getOpponent().getNbBall();
    nbBallBlack = new QLabel(QString().setNum(nbBlack)+"");
    this->addRow(nbBallBlack);

    QLabel *msgBallWhite = new QLabel("Nombre de Balles Blanches à éjecter : ");
    this->addRow(msgBallWhite);

    nbWhite = _game->getCurrent().getColor()==PlayerColor::WHITE?_game->getCurrent().getNbBall():_game->getOpponent().getNbBall()-8;
    nbBallWhite = new QLabel(QString().setNum(nbWhite)+"");
    this->addRow(nbBallWhite);

    QLabel *msgTurn = new QLabel("C'est au tour de : ");
    this->addRow(msgTurn);

    current = _game->getCurrent().getColor();
    labelCurrent = new QLabel("BLACK");
    this->addRow(labelCurrent);

    button = new QPushButton("Confirmer Move");
    this->addRow(button);

    msgError = new QLabel("Attention : Move Invalid ! ");
    this->addRow(msgError);
    msgError->setHidden(true);

    QLabel *rmqLabel = new QLabel("Remarque : ");
    QFont r = rmqLabel->font();
    r.setUnderline(true);
    rmqLabel->setFont(r);
    this->addRow(rmqLabel);

    QLabel *rmq = new QLabel("Pour effectuer un MoveLine, sélectionner la case de départ en\n"
                             "double cliquant sur une case pour qu'elle devienne rouge \n"
                             "et sélectionner la case d'arrivée en cliquant 1 fois");
    this->addRow(rmq);

    msgWin = new QLabel("");
    this->addWidget(msgWin);
}

void AppInfo::update(){
    nbBlack = _game->getCurrent().getColor()==PlayerColor::BLACK?_game->getCurrent().getNbBall()-8:_game->getOpponent().getNbBall()-8;
    nbBallBlack->setText(QString().setNum(nbBlack)+"");

    nbWhite = _game->getCurrent().getColor()==PlayerColor::WHITE?_game->getCurrent().getNbBall()-8:_game->getOpponent().getNbBall()-8;
    nbBallWhite->setText(QString().setNum(nbWhite)+"");

    current = _game->getCurrent().getColor();
    if(current==PlayerColor::WHITE){
        labelCurrent->setText("WHITE");
    }else{
        labelCurrent->setText("BLACK");
    }

    if(_game->isOver()){
        if(_game->getWinner()==PlayerColor::WHITE){
            msgWin->setText("Vainqueur : WHITE a gagné !");
        }else{
            msgWin->setText("Vainqueur : BLACK a gagné !");
        }
    }
}

void AppInfo::setupSignals(){
    connect(button, &QPushButton::released, this, &AppInfo::confirmedMove);
}

void AppInfo::confirmedMove(){
    if(!_gui.makeMove()){
        msgError->setHidden(false);
    }else{
        msgError->setHidden(true);
    }
    update();
}

AppInfo::~AppInfo()
{

}
