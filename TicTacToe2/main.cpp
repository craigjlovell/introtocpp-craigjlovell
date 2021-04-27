
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "ConsoleTicTacToeApp.h"

//#include "RaylibTicTacToeApp.h"

int main(int argc, char** argv)
{

    bool createConsoleApp = true;

    if (createConsoleApp)
    {
        ConsoleTicTacToe app;
        app.Run();
    }
    else
    {
        //RaylibTicTacToe app;
        //app.Run();
    }

    return 0;
}