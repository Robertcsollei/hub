#include "xfs.h"
#include "SPIFFS.h"

XFS::XFS()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
}

XFS::~XFS()
{
    SPIFFS.end();
}

void XFS::save(const char *fileName, const char *value)
{
    File file = SPIFFS.open(fileName, FILE_WRITE);
    if (!file)
    {
        Serial.println("There was an error opening the file for writing");
        return;
    }
    if (file.print(value))
    {
        Serial.println("File was written");
    }
    else
    {
        Serial.println("File write failed");
    }
    file.close();
}

LoadedData XFS::load(const char *fileName)
{
    File file = SPIFFS.open(fileName);
    if (!file)
    {
        Serial.println("There was an error opening the file for reading");
        return {0, NULL};
    }

    size_t size = file.size();
    char *buf = new char[size];
    file.readBytes(buf, size);
    file.close();

    return {
        size,
        data : buf,
    };
}

void XFS::remove(const char *fileName)
{
    if (SPIFFS.remove(fileName))
    {
        Serial.println("File removed");
    }
    else
    {
        Serial.println("File doesn't exist");
    }
}

void XFS::clear()
{
    SPIFFS.format();
}
