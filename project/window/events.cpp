/** ############################################################################
 *  \file   events.cpp
 *  \author p@nsk
 *  \date   10.05.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include "events.h"

#define MOUSE_BUTTONS   1024
#define BUTTONS_COUNT   1032

/*
 ---------------------------------------------------------------------------- */

TBool     * Events::keys;
TUInt32   * Events::frames;
TUInt32     Events::current         {0};
TFloat      Events::deltaX          {0};
TFloat      Events::deltaY          {0};
TFloat      Events::x               {0};
TFloat      Events::y               {0};
TBool       Events::cursor_locked   {0};
TBool       Events::cursor_started  {0};

/*
 ---------------------------------------------------------------------------- */

/**
 * @brief Events::cursorPositionCallback
 * @param window
 * @param xpos
 * @param ypos
 ******************************************************************************/
void Events::cursorPositionCallback(
    GLFWwindow *window,
    TDouble     xpos,
    TDouble     ypos
)
{
    if (cursor_started)
    {
        deltaX += xpos - x;
        deltaY += ypos - y;
    }
    else
    {
        cursor_started = true;
    }
    x = xpos;
    y = ypos;
}

/**
 * @brief Events::mouseButtonCallback
 * @param window
 * @param button
 * @param action
 * @param mode
 ******************************************************************************/
void Events::mouseButtonCallback(
    GLFWwindow *pWindow,
    TInt        button,
    TInt        action,
    TInt        mode
)
{
    if (action == GLFW_PRESS)
    {
        keys[MOUSE_BUTTONS+button]      = true;
        frames[MOUSE_BUTTONS+button]    = current;
    }
    else if (action == GLFW_RELEASE)
    {
        keys[MOUSE_BUTTONS+button]      = false;
        frames[MOUSE_BUTTONS+button]    = current;
    }
}

/**
 * @brief Events::keyCallback
 * @param window
 * @param key
 * @param scancode
 * @param action
 * @param mode
 ******************************************************************************/
void Events::keyCallback(
    GLFWwindow *pWindow,
    TInt        key,
    TInt        scancode,
    TInt        action,
    TInt        mode
)
{
    if (action == GLFW_PRESS)
    {
        keys[key]      = true;
        frames[key]    = current;
    }
    else if (action == GLFW_RELEASE)
    {
        keys[key]      = false;
        frames[key]    = current;
    }
}

/**
 * @brief Events::initialize
 * @return
 ******************************************************************************/
TInt Events::initialize( void)
{
    GLFWwindow  *pWindow = Window::getWindow();

    keys   = new TBool  [1032]  ();
    frames = new TUInt32[1032]  ();

    glfwSetKeyCallback(pWindow, keyCallback);
    glfwSetMouseButtonCallback(pWindow, mouseButtonCallback);
    glfwSetCursorPosCallback(pWindow, cursorPositionCallback);
    return 0;
}

/**
 * @brief Events::isPressed
 * @param keycode
 * @return
 ******************************************************************************/
TBool Events::isPressed(
    TInt keycode
)
{
    if (keycode < 0 || MOUSE_BUTTONS <= keycode)
        return false;
    return keys[keycode];
}

/**
 * @brief Events::isJPressed
 * @param keycode
 * @return
 ******************************************************************************/
TBool Events::isJPressed(
    TInt keycode
)
{
    if (keycode < 0 || MOUSE_BUTTONS <= keycode)
        return false;
    return keys[keycode] && (frames[keycode] == current);
}

/**
 * @brief Events::isClicked
 * @param button
 * @return
 ******************************************************************************/
TBool Events::isClicked(
    TInt button
)
{
    TInt index = MOUSE_BUTTONS + button;
    return keys[index];
}

/**
 * @brief Events::isJClicked
 * @param button
 * @return
 ******************************************************************************/
TBool Events::isJClicked(
    TInt button
)
{
    TInt index = MOUSE_BUTTONS + button;
    return keys[index] && (frames[index] == current);
}

/**
 * @brief Events::pullEvents
 ******************************************************************************/
void Events::pullEvents( void)
{
    current++;
    deltaX = 0.0f;
    deltaY = 0.0f;
    glfwPollEvents();
}
