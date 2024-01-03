#include <iostream>
#include <vector>

std::string user1;
std::string user2;
std::vector<std::string> player1move = {"", "", "", "", ""};
std::vector<std::string> player2move = {"", "", "", ""};
std::vector<std::string> board = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
int total_turns = 0;
std::string input1 = "";
std::string input2 = "";
bool winner;
bool player1turn = false;
bool player2turn = false;


// method to get user names in variables.
    void introduction() {
    std::cout << " _________\n";
    std::cout << " \n     T O E\n";
    std::cout << "     I\n";
    std::cout << " T A C\n ";
    std::cout << "_________\n";

    std::cout << "\nPlayer 1 please enter your name: ";
    std::cin >> user1;
    std::cout << "\n";
    std::cout << "Player 2 please enter your name: ";
    std::cin >> user2;
    std::cout << "\n";

    std::cout << user1 << " will be XXX's ~~~~~~ ";
    std::cout << user2 << " will be OOO's";

    std::cout << "\n" << user1 << " goes first!\n";
    std::cout << "\n";
}   

// draw grid and save spots on board to string vector to update with X's and O's
void draw_grid() {
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    std::cout << "     |     |     \n";
}


// check the players inputs. If they are on the board,
//replace board vector with X or O.
void board_update() {
    
    for (int i = 0; i <= player1move.size(); i++) 
    {
        for (int j = 0; j < board.size(); j++) 
        {
           if (player1move[i] == board[j]) 
           {
            board[j] = "X";
            draw_grid();
           } 
        }
    } 
    
    for (int i = 0; i <= player2move.size(); i++) 
    {
        for (int j = 0; j < board.size(); j++) 
        {
            if (player2move[i] == board[j]) 
            {
                board[j] = "O";
                draw_grid();
            }
        }
    }
}



// check all possiblities of X winning. check all of O winning.
// if theres a winner, return true. 
bool game_over() {
winner = false;

    // check rows to see if x one
    if ((board[0] == "X") && (board[1] == "X") && (board[2] == "X") || 
        (board[3] == "X") && (board[4] == "X") && (board[5] == "X") || 
        (board[6] == "X") && (board[7] == "X") && (board[8] == "X")) 
        {
        winner = true;
        std::cout << user1 << " wins!";
        return true;
        } 
    // check columns for X's
    else if ((board[0] == "X") && (board[3] == "X") && (board[6] == "X") || 
             (board[1] == "X") && (board[4] == "X") && (board[7] == "X") || 
             (board[2] == "X") && (board[5] == "X") && (board[8] == "X")) 
        {
        winner = true;
        std::cout << user1 << " wins!";
        return true;
        }
    // check diagonals for X's
    else if ((board[0] == "X") && (board[4] == "X") && (board[8] == "X") || 
             (board[2] == "X") && (board[4] == "X") && (board[6] == "X"))
        {
        winner = true;
        std::cout << user1 << " wins!"; 
        return true;     
        }

    // check rows for O's
    else if ((board[0] == "O") && (board[1] == "O") && (board[2] == "O") || 
             (board[3] == "O") && (board[4] == "O") && (board[5] == "O") || 
             (board[6] == "O") && (board[7] == "O") && (board[8] == "O")) 
        {
        winner = true;
        std::cout << user2 << " wins!";
        return true;
        } 
    // check columns for O's
    else if ((board[0] == "O") && (board[3] == "O") && (board[6] == "O") || 
             (board[1] == "O") && (board[4] == "O") && (board[7] == "O") || 
             (board[2] == "O") && (board[5] == "O") && (board[8] == "O")) 
        {
        winner = true;
        std::cout << user2 << " wins!";
        return true;
        }
    // check diagonals for O's
    else if ((board[0] == "O") && (board[4] == "O") && (board[8] == "O") || 
             (board[2] == "O") && (board[4] == "O") && (board[6] == "O"))
    
        {
        winner = true;
        std::cout << user2 << " wins!";
        return true;      
        } 
}


// check when total turns is 9 and no winner. 
void draw () {
    if (total_turns == 9 && game_over() == false) 
    {
        std::cout << "It's a draw!";
        return;
    } 
}


// a method that checks if player input is outside of the range or is currently
// occupied by a player
void invalid_turn() {
    bool invalid = true;
    while (invalid) 
    {
        for (int i = 0; i < board.size(); i++) 
        {
            if (input1 == board[i])
            {
                invalid = false;
                return;
            }

            if (input2 == board[i])
            {
                invalid = false;
                return;
            }
            
        }

        if (player1turn)
        {
        std::cout << "Invalid move: Please choose another space\n";
        std::cin >> input1;
        }
        else if (player2turn)
        {   
        std::cout << "Invalid move: Please choose another space\n";
        std::cin >> input2;
        }
    }
}
    


// take user input and push_back to respective player_move vectors. Update total turns. Update board after each turn. 
void playerturn() {
    while (!game_over() && total_turns < 9) 
    {
        // player 1 move input. Check if its valid through loop.
        player1turn = true;
        std::cout << "\n" << user1 << ": where would you like to move? \n";
        std::cin >> input1;
        invalid_turn();

        // if valid, push input to player vector. Update total turns. Update board.
        player1move.push_back(input1);
        std::cout << "\n";
        total_turns++;
        board_update();
        player1turn = false;

        // check if game not over. Player 2 turn.
        if (game_over() == false && total_turns < 9) 
        {   
            player2turn = true;
            std::cout << "\n" << user2 << ": where would you like to move? \n";
            std::cin >> input2;
            invalid_turn();

            // if valid, push input to player vector. Update total turns. Update board.
            player2move.push_back(input2);
            std::cout << "\n";
            total_turns++;
            board_update();
            player2turn = false;
        }

        // if game is over or total turns = 9, return and exit.
        else 
        {
        draw();
        return;
        }
    }

    return;
}
