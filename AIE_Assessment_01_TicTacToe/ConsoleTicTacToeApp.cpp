#include "ConsoleTicTacToeApp.h"
#include "TicTacToeGame.h"
#include "raylib.h"
#include <iostream>
#include <conio.h>

ConsoleTicTacToe::ConsoleTicTacToe()
{

}

ConsoleTicTacToe::~ConsoleTicTacToe()
{

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

char ConsoleTicTacToe::Menu()
{
    char options = 0;

    std::cout << "1: Play Game" << std::endl;
    std::cout << "2: Exit Game" << std::endl;

    std::cin >> options;
    return options;
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
        game->SetBoard(m_Location[0], m_Location[1], m_player);
        m_player++;
        if (m_player > 2)
        {
            m_player = 1;
        }
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

bool ConsoleTicTacToe::CheckWin(int board[3][3], int player)
{
    for (int r = 0; r < 3; r++) //HOZ
    {
        int num = 0;
        for (int c = 0; c < 3; c++)
        {
            if (board[r][c] == player)
            {
                num++;
            }
            if (num == 3)
            {
                return true;
            }
        }
    }

    for (int r = 0; r < 3; r++) //VERT
    {
        int num = 0;
        for (int c = 0; c < 3; c++)
        {
            if (board[c][r] == player)
            {
                num++;
            }
            if (num == 3)
            {
                return true;
            }
        }
    }

    int num = 0;
    for (int rc = 0; rc < 3; rc++) //left to right
    {
        if (board[rc][rc] == player)
        {
            num++;
        }
        if (num == 3)
        {
            return true;
        }
    }

    num = 0;
    for (int rc = 0; rc < 3; rc++) // right to left
    {
        if (board[rc][2 - rc] == player)
        {
            num++;
        }
        if (num == 3)
        {
            return true;
        }
    }
    return false;
}

void ConsoleTicTacToe::Run()
{
	Load();
}

void ConsoleTicTacToe::Load()
{
    game = new TicTacToeGame();


    if (Menu() == '1')
    {
        while (true)
        {
            DrawBoard();
            PlayerMove();
        }
        //endgame func
    }
    else
    {
        system("CLS");
    }

    
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

