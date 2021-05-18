#include "ConsoleTicTacToeApp.h"
#include "TicTacToeGame.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <windows.h>


ConsoleTicTacToe::ConsoleTicTacToe()
{
    m_game = new TicTacToeGame();
}

ConsoleTicTacToe::~ConsoleTicTacToe()
{
    delete m_game;
}

void ConsoleTicTacToe::DrawBoard()
{
    //for (int row = 0; row < 3; row++) // old code does same as below but in a loop
    //{
    //    for (int col = 0; col < 3; col++)
    //    {
    //        std::cout << "|" << game->DrawPlayer(row, col, m_Location) << "|";
    //    }
    //    std::cout << std::endl;
    //}

    std::cout << " " << "Tic Tac Tow" << std::endl;
    std::cout << std::endl;
    std::cout << "  " << "-------" << std::endl;
    std::cout << "  " << "|" << m_game->DrawPlayer(0, 0, m_location) << "|" << m_game->DrawPlayer(0, 1, m_location) << "|" << m_game->DrawPlayer(0, 2, m_location) << "|" << std::endl;
    std::cout << "  " << "-------" << std::endl;
    std::cout << "  " << "|" << m_game->DrawPlayer(1, 0, m_location) << "|" << m_game->DrawPlayer(1, 1, m_location) << "|" << m_game->DrawPlayer(1, 2, m_location) << "|" << std::endl;
    std::cout << "  " << "-------" << std::endl;
    std::cout << "  " << "|" << m_game->DrawPlayer(2, 0, m_location) << "|" << m_game->DrawPlayer(2, 1, m_location) << "|" << m_game->DrawPlayer(2, 2, m_location) << "|" << std::endl;
    std::cout << "  " << "-------" << std::endl;
}

int ConsoleTicTacToe::GetPressedKey()
{
    int pressedKey = -1;
    if (_kbhit())
    {
        int c = _getch();
        if (c == 224)
        {
            // this allows us to get special key character presses
            pressedKey = _getch();
        }
        else
        {
            pressedKey = c;
        }
    }
    return pressedKey;
}

int ConsoleTicTacToe::MovePlayer()
{
    Borader();

    int key = GetPressedKey();

    const int LEFT = 75;
    const int RIGHT = 77;
    const int UP = 72;
    const int DOWN = 80;
    const int SPACE = 32;

    if (key == UP)
    {
        m_location[0]--;
    }
    if (key == DOWN)
    {
        m_location[0]++;
    }
    if (key == LEFT)
    {
        m_location[1]--;
    }
    if (key == RIGHT)
    {
        m_location[1]++;
    }
    if (key == SPACE)
    {
        PlacePlayer();
        
    }

    return 0;
}

void ConsoleTicTacToe::Borader()//change to  verb
{

    if (m_location[0] < 0)  m_location[0] = 0;
    else if (m_location[0] > 2) m_location[0] = 2;

    if (m_location[1] < 0) m_location[1] = 0;
    else if (m_location[1] > 2) m_location[1] = 2;

}

void ConsoleTicTacToe::PlacePlayer()
{
    if (m_game->SetBoard(m_location[0], m_location[1], m_player))
    {
        m_player++;
        tilesPlaced++;
        if (m_player > 2)
        {
            m_player = 1;
        }
    }
}

void ConsoleTicTacToe::RunMenuState()
{
    
    std::cout << "1: Play Game" << std::endl;
    std::cout << "2: Exit Game" << std::endl;

    int options = -1;
    std::cin >> options;

    if (options == 1)
    {
        m_gameState = GameState::GAME;
    }
    else if (options == 2)
    {
        m_shouldQuit = true;
    }
}

void ConsoleTicTacToe::RunGameState()
{
    DrawBoard();
    MovePlayer();
    CheckWinState();
}

bool ConsoleTicTacToe::CheckWinState()
{
    if (m_game->CheckWinner(1))
    {
        m_gameState = GameState::WIN;
        return true;
    }
    else if (m_game->CheckWinner(2))
    {
        m_gameState = GameState::WIN;
        return true;
    }
    else if (tilesPlaced == 9)
    {
        m_gameState = GameState::WIN;
        return true;
    }
    return false;
}

void ConsoleTicTacToe::RunWinState()
{
    
    DrawBoard();
    std::cout << "WINSCREEN" << std::endl;
    if (m_game->CheckWinner(1))
    {
        std::cout << "Player X wins!" << std::endl;
    }
    else if (m_game->CheckWinner(2))
    {
        std::cout << "Player O wins!" << std::endl;
    }
    else if (tilesPlaced == 9)
    {
        std::cout << "Draw" << std::endl;
    }
    

    int key = GetPressedKey();
    const int ENTER = 13;

    if (key == ENTER)
    {
        m_game->Reset();
        m_gameState = GameState::MENU;
    }

}

void ConsoleTicTacToe::Run()
{
    while (!m_shouldQuit)
    {

        Sleep(100);
        system("cls");

        if (m_gameState == GameState::MENU)
            RunMenuState();
        else if (m_gameState == GameState::GAME)
            RunGameState();
        else if (m_gameState == GameState::WIN)
            RunWinState();
    }

    Load();

}

void ConsoleTicTacToe::Load()
{

}

void ConsoleTicTacToe::Unload()
{

}

void ConsoleTicTacToe::Update(float dt)
{

}

void ConsoleTicTacToe::Draw()
{

}