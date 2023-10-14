#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard
{
public:
  enum class Color
  {
    WHITE,
    BLACK
  };

  class Piece
  {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const
    {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    /// Defined in each derived class to return the chess piece representation
    /// @return a string with the chess piece representation.
    virtual std::string representation() const = 0;
  };

  class King : public Piece
  {
  public:
    King(Color color) : Piece(color) {}
    std::string type() const override { return color_string() + " king"; }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override
    {
      // Can only move one square in any direction (3,3) to (4,4) is ok
      if (abs(to_x - from_x) <= 1 && abs(to_y - from_y) <= 1)
        return true;
      else
        return false;
    }

    // Returns a string representation WK for white king and BK for black king
    std::string representation() const override
    {
      return color == Color::WHITE ? "WKi" : "BKi";
    }
  };

  class Knight : public Piece
  {
  public:
    Knight(Color color) : Piece(color) {}
    std::string type() const override { return color_string() + " knight"; }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override
    {
      // L shape move (3,3) to (4,5) is ok, 1 x and 2 y
      if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 2)
        return true;
      // L shape move (3,3) to (5,4) is ok, 2 in x and 1 y
      else if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 1)
        return true;
      else
        return false;
    }

    // Returns a string representation WN for white knight and BN for black knight
    std::string representation() const override
    {
      return color == Color::WHITE ? "WKn" : "BKn";
    }
  };

  /// This function is called after each move on the board.
  function<void()> after_piece_move = []() {};

  ChessBoard()
  {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  void print_board() const
  {
    cout << " " << endl; // To provide space

    for (int y = 7; y >= 0; --y)
    {
      cout << y + 1 << " "; // Print the row number
      for (int x = 0; x < 8; ++x)
      {
        if (squares[x][y]) // checks if there is a piece in the square (matrix position)
        {
          cout << squares[x][y]->representation() << " "; // Print the piece representation in the matrix position
        }
        else
        {
          cout << "... "; // Print three dots for empty squares to keep the alignment
        }
      }
      cout << endl;
    }
    cout << "   A   B   C   D   E   F   G   H" << endl;
    cout << " " << endl; // To provide space
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to)
  {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from)
    {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y))
      {
        cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_to = squares[to_x][to_y];
        if (piece_to)
        {
          if (piece_from->color != piece_to->color)
          {
            cout << piece_to->type() << " is being removed from " << to << endl;
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              cout << king->color_string() << " lost the game" << endl;
          }
          else
          {
            // piece in the from square has the same color as the piece in the to square
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
          }
        }
        piece_to = move(piece_from);
        after_piece_move(); // Call after piece move function
        return true;
      }
      else
      {
        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
        return false;
      }
    }
    else
    {
      cout << "no piece at " << from << endl;
      return false;
    }
  }
};

// This class is used to print the chess board after each move
class ChessBoardPrint
{
public:
  ChessBoardPrint(ChessBoard &board) : board(board)
  {
    // Lambda function that prints the board after each move:
    board.after_piece_move = [this]()
    {
      print();
    };
  }

  void print() const
  {
    // Print the chess board using the chess board print function
    board.print_board();
  }

private:
  const ChessBoard &board;
};

int main()
{
  ChessBoard board;
  ChessBoardPrint boardPrint(board);

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;

  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  cout << "starting board:" << endl;
  boardPrint.print();

  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}