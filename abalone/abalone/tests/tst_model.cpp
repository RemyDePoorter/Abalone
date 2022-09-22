#include <catch2/catch.hpp>
#include <abalonecore.h>

using namespace abalone;

TEST_CASE("Test some moves on board in Black Side")
{
    Board board = Board();

    SECTION("Board"){
        REQUIRE(board.getRow()==9);
        REQUIRE(board.getColumn()==9);
        REQUIRE(board.getSquare(Position('I',1)).isOutside());
        REQUIRE(board.getSquare(Position('I',5)).isOutside()==false);
        REQUIRE(board.getSquare(Position('E',2)).isFree());
        REQUIRE(board.getSquare(Position('D',8)).isFree());
        Game game = Game();
        game.initialize();
        REQUIRE(game.isMyOwn(Position('H',5),PlayerColor::WHITE));
        REQUIRE(game.isMyOwn(Position('B',5),PlayerColor::BLACK));
        REQUIRE(game.isInsidePos(Position('E',5)));
        REQUIRE(game.isInsidePos(Position('E',10))==false);
        REQUIRE(board.getLetterCoord(8)=='A');
        REQUIRE(board.getLetterCoord(0)=='I');
        REQUIRE(board.getIntCoord(8)==9);
        REQUIRE(board.getIntCoord(1)==2);
    }

    SECTION("Starting line move A1B1"){
        Position pos1 = Position('A',1);
        Position pos2 = Position('B',1);
        Position pos3 = Position('C',1);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        board.moveLine(pos1,pos3);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::BLACK);
    }

    SECTION("Starting line move A1B2"){
        Position pos1 = Position('A',1);
        Position pos2 = Position('B',2);
        Position pos3 = Position('C',3);
        Position pos4 = Position('D',4);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        board.put(pos3,Status::BLACK);
        board.moveLine(pos1,pos4);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
    }

    SECTION("Starting lateral move c3c5d3"){
        Position pos1 = Position('C',3);
        Position pos2 = Position('C',4);
        Position pos3 = Position('C',5);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        board.put(pos3,Status::BLACK);
        Position pos4 = Position('D',3);
        Position pos5 = Position('D',4);
        Position pos6 = Position('D',5);
        board.moveLateral(pos1,pos3,pos4);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos6).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::FREE);


    }
    SECTION("Starting lateral move c3c4d4"){
        Position pos1 = Position('C',3);
        Position pos2 = Position('C',4);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        Position pos5 = Position('D',4);
        Position pos6 = Position('D',5);
        board.moveLateral(pos1,pos2,pos5);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos6).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::FREE);
    }
    SECTION("Starting lateral move B1B2C1"){
        Position pos1 = Position('B',1);
        Position pos2 = Position('B',2);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        Position pos5 = Position('C',1);
        Position pos6 = Position('C',2);
        board.moveLateral(pos1,pos2,pos5);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos6).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::FREE);
    }

}

TEST_CASE("Test some moves on board in White Side")
{
    Board board = Board();

    SECTION("Starting line move I5H4"){
        Position pos1 = Position('I',5);
        Position pos2 = Position('H',4);
        Position pos3 = Position('G',3);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        board.moveLine(pos1,pos3);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::WHITE);
    }

    SECTION("Starting line move I5H5"){
        Position pos1 = Position('I',5);
        Position pos2 = Position('H',5);
        Position pos3 = Position('G',5);
        Position pos4 = Position('F',5);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        board.put(pos3,Status::WHITE);
        board.moveLine(pos1,pos4);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
    }

    SECTION("Starting lateral move G5G7F5"){
        Position pos1 = Position('G',5);
        Position pos2 = Position('G',6);
        Position pos3 = Position('G',7);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        board.put(pos3,Status::WHITE);
        Position pos4 = Position('F',5);
        Position pos5 = Position('F',6);
        Position pos6 = Position('F',7);
        board.moveLateral(pos1,pos3,pos4);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos6).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::FREE);


    }
    SECTION("Starting lateral move G5G6F4"){
        Position pos1 = Position('G',5);
        Position pos2 = Position('G',6);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        Position pos5 = Position('F',4);
        Position pos6 = Position('F',5);
        board.moveLateral(pos1,pos2,pos5);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos6).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::FREE);
    }
    SECTION("Starting lateral move H4H5G3"){
        Position pos1 = Position('H',4);
        Position pos2 = Position('H',5);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        Position pos5 = Position('G',3);
        Position pos6 = Position('G',4);
        board.moveLateral(pos1,pos2,pos5);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos6).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos1).getStatus()==Status::FREE);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::FREE);
    }
}

TEST_CASE("Test Black vs White"){

    Board board = Board();
    Game game = Game();
    SECTION("2B vs 1W Push Outside Right"){
        Position pos1 = Position('E',7);
        Position pos2 = Position('E',8);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        Position pos3 = Position('E',9);
        board.put(pos3,Status::WHITE);
        Position pos4 = Position('E',10);
        board.moveLine(pos1,pos4);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::BLACK);
        REQUIRE(game.isInsidePos(pos4)==false);
    }
    SECTION("3B vs 1W Push Outside Right"){
        Position pos1 = Position('E',6);
        Position pos2 = Position('E',7);
        Position pos3 = Position('E',8);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        board.put(pos3,Status::BLACK);
        Position pos4 = Position('E',9);
        board.put(pos4,Status::WHITE);
        Position pos5 = Position('E',10);
        board.moveLine(pos1,pos5);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::BLACK);
        REQUIRE(game.isInsidePos(pos5)==false);
    }

    SECTION("2B vs 1W Push Inside Right"){
        Position pos1 = Position('E',6);
        Position pos2 = Position('E',7);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        Position pos3 = Position('E',8);
        board.put(pos3,Status::WHITE);
        Position pos4 = Position('E',9);
        board.moveLine(pos1,pos4);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::WHITE);
    }
    SECTION("3B vs 1W Push Inside Right"){
        Position pos1 = Position('E',5);
        Position pos2 = Position('E',6);
        Position pos3 = Position('E',7);
        board.put(pos1,Status::BLACK);
        board.put(pos2,Status::BLACK);
        board.put(pos3,Status::BLACK);
        Position pos4 = Position('E',8);
        board.put(pos4,Status::WHITE);
        Position pos5 = Position('E',9);
        board.moveLine(pos1,pos5);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::BLACK);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::WHITE);
    }
}

TEST_CASE("Test White vs Black"){

    Board board = Board();
    Game game = Game();
    SECTION("2W vs 1B Push Outside Left"){
        Position pos1 = Position('E',3);
        Position pos2 = Position('E',2);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        Position pos3 = Position('E',1);
        board.put(pos3,Status::BLACK);
        Position pos4 = Position('E',0);
        board.moveLine(pos1,pos4);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::WHITE);
        REQUIRE(game.isInsidePos(pos4)==false);
    }
    SECTION("3W vs 1W Push Outside Left"){
        Position pos1 = Position('E',4);
        Position pos2 = Position('E',3);
        Position pos3 = Position('E',2);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        board.put(pos3,Status::WHITE);
        Position pos4 = Position('E',1);
        board.put(pos4,Status::BLACK);
        Position pos5 = Position('E',0);
        board.moveLine(pos1,pos5);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::WHITE);
        REQUIRE(game.isInsidePos(pos5)==false);
    }

    SECTION("2B vs 1W Push Inside Left"){
        Position pos1 = Position('E',4);
        Position pos2 = Position('E',3);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        Position pos3 = Position('E',2);
        board.put(pos3,Status::BLACK);
        Position pos4 = Position('E',1);
        board.moveLine(pos1,pos4);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::BLACK);
    }
    SECTION("3B vs 1W Push Inside Right"){
        Position pos1 = Position('E',5);
        Position pos2 = Position('E',4);
        Position pos3 = Position('E',3);
        board.put(pos1,Status::WHITE);
        board.put(pos2,Status::WHITE);
        board.put(pos3,Status::WHITE);
        Position pos4 = Position('E',2);
        board.put(pos4,Status::BLACK);
        Position pos5 = Position('E',1);
        board.moveLine(pos1,pos5);
        REQUIRE(board.getSquare(pos2).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos3).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos4).getStatus()==Status::WHITE);
        REQUIRE(board.getSquare(pos5).getStatus()==Status::BLACK);
    }
}


TEST_CASE("Test Game"){
    Game game = Game();
    SECTION("swapPlayer"){
        REQUIRE(game.getCurrent().getColor()==PlayerColor::BLACK);
        REQUIRE(game.getOpponent().getColor()==PlayerColor::WHITE);
        game.swapPlayers();
        REQUIRE(game.getCurrent().getColor()==PlayerColor::WHITE);
        REQUIRE(game.getOpponent().getColor()==PlayerColor::BLACK);
    }
    SECTION("decrement nb Ball"){
        game.removeBall();
        REQUIRE(game.getOpponent().getNbBall()==13);
    }
}

TEST_CASE("Test Square"){
    SECTION("Construction + test Square"){
        Square s = Square();
        REQUIRE(s.isFree());
        s.put(Status::BLACK);
        REQUIRE(s.isMyOwn(PlayerColor::BLACK));
        s.put(Status::WHITE);
        REQUIRE(s.isMyOwn(PlayerColor::WHITE));
        s.remove();
        REQUIRE(s.isFree());
        s.put(Status::OUTSIDE);
        REQUIRE(s.isOutside());
        REQUIRE(s.getStatus()==Status::OUTSIDE);
        Square s2 = Square();
        REQUIRE(s2.getStatus()!=s.getStatus());

    }
}

TEST_CASE("Player"){
    Player p = Player();
    REQUIRE(p.getColor()==PlayerColor::BLACK);
    REQUIRE(p.getNbBall()==14);
    Player p2 = Player(PlayerColor::WHITE);
    REQUIRE(p2.getColor()==PlayerColor::WHITE);
}


