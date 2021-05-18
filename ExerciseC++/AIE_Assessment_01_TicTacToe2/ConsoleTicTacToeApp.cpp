#include "ConsoleTicTacToeApp.h"
#include "TicTacToeGame.h"
#include "raylib.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

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

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "|" << game->DrawSquare(i, j, m_Location) << "|";
        }
        std::cout << std::endl;
    }
}

void ConsoleTicTacToe::PlayerMove()
{
    int button;
    button = _getch();
    
    switch (button)
    {
    case 80:
        m_Location[0]++;
        break;
    case 72:
        m_Location[0]--;
        break;
    case 77:
        m_Location[1]++;
        break;
    case 75:
        m_Location[1]--;
        break;
    case 13:
        
        PlacePlayer();        
        break;
    }

    if (m_Location[0] < 0)
    {
        m_Location[0] = 0;
    }
    else if (m_Location[0] > 2)
    {
        m_Location[0] = 2;
    }

    if (m_Location[1] < 0)
    {
        m_Location[1] = 0;
    }
    else if (m_Location[1] > 2)
    {
        m_Location[1] = 2;
    }
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
    while (!CheckWinState())
    {
        DrawBoard();
        CheckWinState();
        PlayerMove();       
    }
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
        std::cout << 1 << " wins!" << std::endl;
    }
    else if (game->CheckWinner(2))
    {
        std::cout << 2 << " wins!" << std::endl;
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

