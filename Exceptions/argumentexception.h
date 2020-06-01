#ifndef ARGUMENTEXCEPTION_H
#define ARGUMENTEXCEPTION_H

#include <exception>
#include <string>

class ArgumentException : public std::exception {

public:
    /**
     * @brief NotImplException: Costruttore di default
     * @param s: Specifica errore
     */
    ArgumentException(std::string s);

    /**
     * @brief argument: Specifica dell'errore
     */
    std::string argument;
};

#endif // ARGUMENTEXCEPTION_H
