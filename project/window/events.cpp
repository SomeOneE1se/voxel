#include "events.h"
#include "GLFW/glfw3.h"
#include "string.h"

#define _MOUSE_BUTTONS  1024

/**
*******************************************************************************/
TBool     * Events::_keys;
TUInt32   * Events::_frames;
TUInt32     Events::_current        = 0;
TFloat      Events::deltaX          = 0.0f;
TFloat      Events::deltaY          = 0.0f;
TFloat      Events::x               = 0.0f;
TFloat      Events::y               = 0.0f;
TBool       Events::_cursor_locked  = false;
TBool       Events::_cursor_started = false;


/**
*******************************************************************************/
void cursor_position_callback(
        GLFWwindow *window,
        TDouble     xpos,
        TDouble     ypos
){
    if (Events::_cursor_started)
    {
        Events::deltaX += xpos - Events::x;
        Events::deltaY += ypos - Events::y;
    }
    else
    {
        Events::_cursor_started = true;
    }
    Events::x = xpos;
    Events::y = ypos;
}

/**
*******************************************************************************/
void mouse_button_callback(
        GLFWwindow *window,
        TInt button,
        TInt action,
        TInt mode
){
    if (action == GLFW_PRESS)
    {
        Events::_keys[_MOUSE_BUTTONS+button]    = true;
        Events::_frames[_MOUSE_BUTTONS+button]  = Events::_current;
    }
    else if (action == GLFW_RELEASE)
    {
        Events::_keys[_MOUSE_BUTTONS+button]    = false;
        Events::_frames[_MOUSE_BUTTONS+button]  = Events::_current;
    }
}

/**
*******************************************************************************/
void key_callback(
        GLFWwindow *window,
        TInt key,
        TInt scancode,
        TInt action,
        TInt mode
){
    if (action == GLFW_PRESS)
    {
        Events::_keys[key]  = true;
        Events::_frames[key]= Events::_current;
    }
    else if (action == GLFW_RELEASE)
    {
        Events::_keys[key]  = false;
        Events::_frames[key]= Events::_current;
    }
}

/**
*******************************************************************************/
TInt Events::initialize( void)
{
    GLFWwindow *window = Window::window;
    _keys   = new TBool[1032];
    _frames = new TUInt32[1032];

    memset(_keys, false, 1032 * sizeof(TBool));
    memset(_frames, 0, 1032 * sizeof(TUInt32));

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    return 0;
}

/**
*******************************************************************************/
TBool Events::pressed(TInt keycode)
{
    if (keycode < 0 || _MOUSE_BUTTONS <= keycode)
        return false;
    return _keys[keycode];
}

/**
*******************************************************************************/
TBool Events::jpressed(TInt keycode)
{
    if (keycode < 0 || _MOUSE_BUTTONS <= keycode)
        return false;
    return _keys[keycode] && _frames[keycode] == _current;
}

/**
*******************************************************************************/
TBool Events::clicked(TInt button)
{
    TInt index = _MOUSE_BUTTONS + button;
    return _keys[index];
}

/**
*******************************************************************************/
TBool Events::jclicked(TInt button)
{
    TInt index = _MOUSE_BUTTONS + button;
    return _keys[index] && _frames[index] == _current;
}

/**
*******************************************************************************/
void Events::pullEvents( void)
{
    _current++;
    deltaX = 0.0f;
    deltaY = 0.0f;
    glfwPollEvents();
}
