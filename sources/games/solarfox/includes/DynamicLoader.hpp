/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** DynamicLoader
*/

#pragma once
#include <exception>
#include <string>
#include <dlfcn.h>
#include <string.h>

namespace arcade
{
    class DynamicLoadingException : public std::exception
    {
        public:
            DynamicLoadingException(std::string msg);
            ~DynamicLoadingException();

            virtual const char *what()
                const noexcept override;
            std::string _message;
    };
    class DynamicLoader
    {
        public:
            static constexpr int ERROR_BUF_SIZE = 80;
            DynamicLoader(const char *filename, int flags = RTLD_NOW);
            DynamicLoader(const DynamicLoader &src) = delete;
            virtual ~DynamicLoader();
            void open();
            void close();
            void *lookup(const char *symbolStr);
            void throwException(const char *errorStr);
        private:
            const std::string m_filename;
            const int m_flags;
            void *m_dynamicHandle;
    };
}