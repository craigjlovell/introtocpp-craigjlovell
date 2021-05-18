#include "DataFile.h"
#include <fstream>

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	delete currentRecord;
	currentRecord = nullptr;
}

void DataFile::AddRecord(const std::string& imageFilename, const std::string& name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record();
	r->image = i;
	r->name = name;
	r->age = age;

}

// this is the old load code refacturded and redone to inprove the reading and writing of each record one at a time so its not all at the same time
DataFile::Record* DataFile::GetRecord(int index)
{

	//setting start values 
	int nameSize = 0;
	int ageSize = 0;
	int width = 0;
	int height = 0;
	int format = 0;
	int imageSize = 0;

	std::ifstream infile(filename, std::ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));
	if (index < recordCount) // if index is less than count do the bewlow items
	{

		for (int i = 0; i < recordCount; i++) //looping through all the items that the bytes dont always change on to skip doing the ones that dont change one at a time
		{
			//below read/writes the width height name and age sizes  (bytes)
			infile.read((char*)&width, sizeof(int));
			infile.read((char*)&height, sizeof(int));

			imageSize = sizeof(Color) * width * height;

			infile.read((char*)&nameSize, sizeof(int));
			infile.read((char*)&ageSize, sizeof(int));

			if (i == index)// if i is the same as index break out of for loop
			{
				break;
			}

			int sizeInfo = imageSize + nameSize + ageSize; // calculating the size info depending on the other sizes 
			infile.seekg(sizeInfo, std::ios_base::cur);
		}
	}

	char* imgdata = new char[imageSize];
	infile.read(imgdata, imageSize);

	Image img = LoadImageEx((Color*)imgdata, width, height);
	char* name = new char[nameSize + 1]; // adding one to the name size to set all after name to null characters
	int age = 0;

	for (int i = 0; i < nameSize + 1; i++) //here is where im fixing the name to only print the given letters and adding nullcharacter after the name
	{
		name[i] = '\0';
	}

	infile.read((char*)name, nameSize);
	infile.read((char*)&age, ageSize);
	

	//this sets currentrecord to a new record if it is null 
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