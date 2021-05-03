#include "ConsoleTicTacToeApp.h"
#include "TicTacToeGame.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <raylib.h>


ConsoleTicTacToe::ConsoleTicTacToe()
{
    game = new TicTacToeGame();
}

ConsoleTicTacToe::~ConsoleTicTacToe()
{
    delete game;
}

void ConsoleTicTacToe::DrawBoard()
{
    system("CLS");

    //for (int row = 0; row < 3; row++)
    //{
    //    for (int col = 0; col < 3; col++)
    //    {
    //        std::cout << "|" << game->DrawPlayer(row, col, m_Location) << "|";
    //    }
    //    std::cout << std::endl;
    //}

    std::cout << "-------" << std::endl;
    std::cout << "|" << game->DrawPlayer(0, 0, m_Location) << "|" << game->DrawPlayer(0, 1, m_Location) << "|" << game->DrawPlayer(0, 2, m_Location) << "|" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "|" << game->DrawPlayer(1, 0, m_Location) << "|" << game->DrawPlayer(1, 1, m_Location) << "|" << game->DrawPlayer(1, 2, m_Location) << "|" << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "|" << game->DrawPlayer(2, 0, m_Location) << "|" << game->DrawPlayer(2, 1, m_Location) << "|" << game->DrawPlayer(2, 2, m_Location) << "|" << std::endl;
    std::cout << "-------" << std::endl;
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
    const int ENTER = 13;

    if (key == UP)
    {
        m_Location[0]--;
    }
    if (key == DOWN)
    {
        m_Location[0]++;
    }
    if (key == LEFT)
    {
        m_Location[1]--;
    }
    if (key == RIGHT)
    {
        m_Location[1]++;
    }
    if (key == ENTER)
    {
        PlacePlayer();
    }

    return 0;
}

void ConsoleTicTacToe::Borader()//change to  verb
{

    if (m_Location[0] < 0)  m_Location[0] = 0;
    else if (m_Location[0] > 2) m_Location[0] = 2;

    if (m_Location[1] < 0) m_Location[1] = 0;
    else if (m_Location[1] > 2) m_Location[1] = 2;

}

void ConsoleTicTacToe::PlacePlayer()
{
    if (game->SetBoard(m_Location[0], m_Location[1], m_player))
    {
        m_player++;
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
        m_GameState = GameState::GAME;
    }
    else if (options == 2)
    {
        m_ShouldQuit = true;
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
    if (game->CheckWinner(1))
    {
        m_GameState = GameState::WIN;
        return true;
    }
    else if (game->CheckWinner(2))
    {
        m_GameState = GameState::WIN;
        return true;
    }
    return false;
}

void ConsoleTicTacToe::RunWinState()
{
    std::cout << "WINSCREEN" << std::endl;
    DrawBoard();

    if (game->CheckWinner(1))
    {
        std::cout << "Player X wins!" << std::endl;
    }
    else if (game->CheckWinner(2))
    {
        std::cout << "sPlayer O wins!" << std::endl;
    }
}

void ConsoleTicTacToe::Run()
{
    while (!m_ShouldQuit)
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("cls");

        if (m_GameState == GameState::MENU)
            RunMenuState();
        else if (m_GameState == GameState::GAME)
            RunGameState();
        else if (m_GameState == GameState::WIN)
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

