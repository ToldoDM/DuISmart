#ifndef DISPLAY_H
#define DISPLAY_H


class Display
{

public:
    /**
     * @brief Display: Costruttore di default
     */
    explicit Display();

    /**
     * @brief ~Display: Distruttore virtuale puro
     */
    virtual ~Display() = 0;
};

#endif // DISPLAY_H
