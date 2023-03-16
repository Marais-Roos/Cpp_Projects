#include "piece.h"
#include "board.h"

using namespace std;

//function prototypes
void pieceDefaultConstructor();
void pieceCopyConstructor();
void pieceValueConstructor();
void pieceDestructor();
void pieceGetSide();
void pieceGetPieceType();
void pieceGetX();
void pieceGetY();
void pieceSetX();
void pieceSetY();
void pieceOutputOverload();
void pieceIndexOverload();
void pieceAddOverload();

void testPieceClass();

void boardConstructor();
void boardDestructor();
void boardCheckValidation();
void boardDecrementOverload();

void testBoardClass();

int main()
{
    cout << "Running Tests!" << endl;

    testPieceClass();
    testBoardClass();

    cout << "All tests passed." << endl;

    return 0;
}

//function definitions

void testPieceClass()
{
    cout << "Testing Piece Class..." << endl << endl;

    pieceDefaultConstructor();
    pieceCopyConstructor();
    pieceValueConstructor();
    pieceDestructor();
    pieceGetSide();
    pieceGetPieceType();
    pieceGetX();
    pieceGetY();
    pieceSetX();
    pieceSetY();
    pieceOutputOverload();
    pieceIndexOverload();
    pieceAddOverload();
}

void testBoardClass()
{
    cout << "Testing board class" << endl;
    
    boardConstructor();
    boardDestructor();
    boardCheckValidation();
    boardDecrementOverload();
}

void pieceDefaultConstructor()
{
    cout << "\tTesting Piece Default Constructor...\n";

    piece* p = new piece();

    cout << "\tSuccess!\n\n";
}
void pieceCopyConstructor()
{
    cout << "\tTesting Piece Copy Constructor...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    piece* q = new piece(p);

    cout << "\tSuccess!\n\n";
}
void pieceValueConstructor()
{
    cout << "\tTesting Piece Value Based Constructor...\n";

    piece* p = new piece("rook", 'b', 0, 0);

    cout << "\tSuccess!\n\n";
}
void pieceDestructor()
{
    cout << "\tTesting Piece Destructor...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceGetSide()
{
    cout << "\tTesting Piece getSide()...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    cout << "Side: " << p->getSide() << endl;
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceGetPieceType()
{
    cout << "\tTesting Piece getPieceType()...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    cout << "Piece Type: " << p->getPieceType() << endl;
    delete p;

    cout << "\tSuccess!\n\n";

}
void pieceGetX()
{
    cout << "\tTesting Piece getX()...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    cout << "x Pos: " << p->getX() << endl;
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceGetY()
{
    cout << "\tTesting Piece getY()...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    cout << "y Pos: " << p->getY() << endl;
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceSetX()
{
    cout << "\tTesting Piece setX()...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    p->setX(1);
    cout << "new X Pos: " << p->getX() << endl;
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceSetY()
{
    cout << "\tTesting Piece setY()...\n";

    piece* p = new piece("rook", 'b', 0, 0);
    p->setY(1);
    cout << "new Y Pos: " << p->getY() << endl;
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceOutputOverload()
{
    cout << "\tTesting Piece Output Overload..\n";

    piece* p = new piece("rook", 'b', 0, 0);
    cout << *p;
    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceIndexOverload()
{
    cout << "\tTesting Piece Index Overload..\n";

    piece* p = new piece("rook", 'b', 0, 0);
    
    (*p)[1];
    (*p)[0];
    (*p)[4];

    delete p;

    cout << "\tSuccess!\n\n";
}
void pieceAddOverload()
{
    cout << "\tTesting Piece Addition Overload..\n";

    piece* p = new piece("rook", 'b', 0, 0);
    
    string move = "1,1";

    *p + move;

    cout << "new X Pos: " << p->getX() << endl;
    cout << "new Y Pos: " << p->getY() << endl;

    delete p; 

    cout << "\tSuccess!\n\n";
}

void boardConstructor()
{
    cout << "\tTesting Board Constructor..\n";
    string filename = "game1.txt";
    board* b = new board(filename);
    cout << "\tSuccess!\n\n";
}

void boardDestructor()
{
    cout << "\tTesting Board Destructor..\n";
    string filename = "game1.txt";
    board* b = new board(filename);
    delete b;
    cout << "\tSuccess!\n\n";
}

void boardCheckValidation()
{
    cout << "\tTesting Board checkIfPieceHasCheck() function..\n";
    string filename = "game1.txt";
    board* b = new board(filename);

    b->checkIfPieceHasCheck("knight", 2, 4, 0, 0);

    delete b;
    cout << "\tSuccess!\n\n";
}

void boardDecrementOverload()
{
    cout << "\tTesting Board Overloaded Decrement operator..\n";
    string filename = "game1.txt";
    board* b = new board(filename);

    --(*b);

    delete b;
    cout << "\tSuccess!\n\n";
}