#ifndef NOTIMPLEXCEPTION_H
#define NOTIMPLEXCEPTION_H

#include <exception>
#include <string>

class NotImplException : public std::exception {

public:
    /**
     * @brief NotImplException: Costruttore di default
     * @param s: Specifica errore
     */
    NotImplException(std::string s);

    /**
     * @brief argument: Specifica dell'errore
     */
    std::string argument;
};

#endif // NOTIMPLEXCEPTION_H
