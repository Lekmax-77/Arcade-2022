/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** DynaminLoader
*/

#include "DynamicLoader/DynamicLoader.hpp"

arcade::DynamicLoadingException::DynamicLoadingException(std::string msg)
{
    this->_message = msg; 
}

arcade::DynamicLoadingException::~DynamicLoadingException(){};

const char *arcade::DynamicLoadingException::what() const noexcept
{
    return _message.c_str();
}

arcade::DynamicLoader::DynamicLoader(const char *filename, int flags)
    : m_filename(filename),
      m_flags(flags),
      m_dynamicHandle(nullptr)
{
}

arcade::DynamicLoader::~DynamicLoader()
{
    close();
}

void arcade::DynamicLoader::open()
{
    m_dynamicHandle = dlopen(m_filename.c_str(), m_flags);
    if (0 == m_dynamicHandle)
    {
        throwException(dlerror());
    }
    dlerror(); // Clear any existing error
}

void arcade::DynamicLoader::close()
{
    if (nullptr != m_dynamicHandle)
    {
        dlclose(m_dynamicHandle);
    }
}

void *arcade::DynamicLoader::lookup(const char *symbolStr)
{
    void *testFunc = nullptr;
    testFunc = dlsym(m_dynamicHandle, symbolStr);
    if (0 == testFunc)
    {
        throwException(dlerror());
    }
    return testFunc;
}

void arcade::DynamicLoader::throwException(const char *errorStr)
{
    char errorBuf[ERROR_BUF_SIZE];
    memset(errorBuf, '\0', sizeof(errorBuf));
    snprintf(errorBuf, sizeof(errorBuf), "%s\n", errorStr);
    throw DynamicLoadingException(errorStr);
}