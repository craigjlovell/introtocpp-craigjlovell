#include "DataFile.h"
#include <fstream>



DataFile::DataFile()
{
    recordCount = 0;
}



DataFile::~DataFile()
{
}
// include parameters and returns types when commenting



DataFile::Record* DataFile::GetRecord(int index)
{
    std::ifstream infile(m_filename, std::ios::binary);

    int nameSize = 0;
    int ageSize = 0;
    int width = 0;
    int height = 0;
    int format = 0;
    int imageSize = 0;



    recordCount = 0;
    if (index < recordCount)
    {
        for (int i = 0; i < recordCount; i++)
        {
            infile.read((char*)&width, sizeof(int));
            infile.read((char*)&height, sizeof(int));



            infile.read((char*)&nameSize, sizeof(int));
            infile.read((char*)&ageSize, sizeof(int));



            imageSize = sizeof(Color) * width * height;



            if (i == index)
                break;



            infile.seekg(imageSize + nameSize + ageSize, std::ios::cur);




        }
    }
    char* imgdata = new char[imageSize];
    infile.read(imgdata, imageSize);



    Image img = LoadImageEx((Color*)imgdata, width, height);
    char* name = new char[nameSize];
    int age = 0;



    infile.read((char*)name, nameSize);
    infile.read((char*)&age, ageSize);
    if (m_record == nullptr)
    {
        m_record = new Record();
    }
    m_record->image = img;
    m_record->name = name;
    m_record->age = age;



    delete[] imgdata;
    delete[] name;



    return m_record;
}



//loads records from the file
void DataFile::Load(const std::string& filename)
{
    this->m_filename = filename;
}