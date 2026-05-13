#ifndef WINDOW_H
#define WINDOW_H

#include <project.h>

class GLFWwindow;

class Window
{
public:
    static GLFWwindow* window;

    static TInt     initialize  ( TInt width, TInt height, const TChar *title);
    static void     terminate   ( void);

    static TBool    isShouldClose   ( void);
    static void     setShouldClose  ( TBool flag);
    static void     swapBuffers     ( void);
};

#endif // WINDOW_H
