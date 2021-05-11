#include "DataFile.h"
#include <fstream>

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}

void DataFile::AddRecord(const std::string& imageFilename, const std::string& name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record();
	r->image = i;
	r->name = name;
	r->age = age;

}

DataFile::Record* DataFile::GetRecord(int index)
{
	int nameSize = 0;
	int ageSize = 0;
	int width = 0;
	int height = 0;
	int format = 0;
	int imageSize = 0;

	std::ifstream infile(filename, std::ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));
	if (index < recordCount)
	{

		for (int i = 0; i < recordCount; i++)
		{

			infile.read((char*)&width, sizeof(int));
			infile.read((char*)&height, sizeof(int));

			imageSize = sizeof(Color) * width * height;

			infile.read((char*)&nameSize, sizeof(int));
			infile.read((char*)&ageSize, sizeof(int));

			if (i == index)
			{
				break;
			}

			int sizeInfo = imageSize + nameSize + ageSize;
			infile.seekg(sizeInfo, std::ios_base::cur);
		}
	}

	char* imgdata = new char[imageSize];
	infile.read(imgdata, imageSize);

	Image img = LoadImageEx((Color*)imgdata, width, height);
	char* name = new char[nameSize + 1];
	int age = 0;

	for (int i = 0; i < nameSize + 1; i++)
	{
		name[i] = '\0';
	}

	infile.read((char*)name, nameSize);
	infile.read((char*)&age, ageSize);
	
	if (currentRecord == nullptr)
	{
		currentRecord = new Record;
	}

	currentRecord->image = img;
	currentRecord->name = std::string(name);
	currentRecord->age = age;

	delete[] imgdata;
	delete[] name;

	infile.close();

	return currentRecord;
}

void DataFile::Save(const std::string& filename)
{

}

void DataFile::Load(const std::string& filename)
{
	this->filename = filename;
	GetRecord(0);

}

void DataFile::Clear()
{

}