/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** Error
*/


#include <string>
#include <exception>

namespace arcade {
    class Error : public std::exception
    {
        private:
            std::string _message;
        public:
            // constructor and destructor function
            Error(std::string msg) {_message = msg;};
            ~Error() {};
            // what function
            virtual const char *what()
            const noexcept override {return _message.c_str();}
    };
}

