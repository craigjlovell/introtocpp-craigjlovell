#pragma once

class RaylibTicTacToe
{
public:
	RaylibTicTacToe();
	~RaylibTicTacToe();

	void Run();

	void Load();
	void Unload();

	void Update(float dt);
	void Draw();

protected:
private:

	int m_windowWidth = 800;
	int m_windowHeight = 450;
};
