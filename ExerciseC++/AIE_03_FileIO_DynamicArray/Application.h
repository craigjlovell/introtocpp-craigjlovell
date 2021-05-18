#pragma once

class Application
{
public:

	Application();
	~Application();

	void Run();

	void SaveToFile(const char* filename);
	void LoadFromFile(const char* filename);

protected:

	int m_numbers_count = 0;
	int* m_numbers = nullptr;

private:

};
