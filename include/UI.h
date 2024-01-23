/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef UI_H
#define UI_H

#include <string>

/**
 * This is a virtual class that is inherited and implemented by other UI 
 * classes.
*/
class UI {
 public:
    /**
     * @brief Default constructor of UI.
    */
    UI();

    /**
     * @brief Default destructor of UI.
    */
    virtual ~UI();
    /**
    * @brief A pure virtual function. Displays the current UI to the player.
    */
    virtual void display() = 0;

    /**
     * @brief Displays the help menu elements to the user.
    */
    virtual void displayHelp();

 private:
    std::string instructions;
};


#endif // UI_H
