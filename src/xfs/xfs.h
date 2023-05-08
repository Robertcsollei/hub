#ifndef STORAGE
#define STORAGE

#include "loadedData.h"

class XFS
{
public:
    XFS();
    ~XFS();
    void save(const char *fileName, const char *value);
    LoadedData load(const char *fileName);
    void remove(const char *fileName);
    void clear();
};

#endif