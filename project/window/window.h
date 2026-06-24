/** ############################################################################
 *  \file   window.h
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <project.h>
#include <GLFW/glfw3.h>

/**
 * @brief The Window class
 ******************************************************************************/
class Window
{
    static  GLFWwindow* pWindow;
    Window() = default;

public:
    Window(const Window&) = delete;

    static  TInt    initialize  ( TInt width, TInt height, const TChar *title);
    static  void    terminate   ( void);

    static  GLFWwindow *getWindow  ( void);

    static  TBool   isShouldClose   ( void);
    static  void    setShouldClose  ( TBool flag);
    static  void    swapBuffers     ( void);
};

#endif // WINDOW_H
