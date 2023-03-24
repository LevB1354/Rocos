#ifndef NETWORK_GDEBUG_ENGINE_H_
#define NETWORK_GDEBUG_ENGINE_H_

/**********************************************
GDebugEngine: 向图形界面输出消息的接口类
Version 1.0	beta
Author: qiuxingzhong
DATA: 2009.2.10
EMAIL: qxzzju@gmail.com
***********************************************/

#include <singleton.h>
#include <geometry.h>
#include <QUdpSocket>
#include <QMutex>
namespace{
    const int COLOR_WHITE = 0;
    const int COLOR_RED = 1;
    const int COLOR_ORANGE = 2;
    const int COLOR_YELLOW = 3;
    const int COLOR_GREEN = 4;
    const int COLOR_CYAN = 5;
    const int COLOR_BLUE = 6;
    const int COLOR_PURPLE = 7;
    const int COLOR_GRAY = 8;
    const int COLOR_BLACK = 9;
    const int COLOR_USE_RGB =10;
}

class CGDebugEngine{
public:
    CGDebugEngine();
    ~CGDebugEngine();
    void gui_debug_x(const CGeoPoint& p, int debug_color = 1,int RGB_value=0);
    void gui_debug_points(const std::vector<CGeoPoint> points, int debug_color = 1,int RGB_value=0);
    void gui_debug_line(const CGeoPoint& p1, const CGeoPoint& p2, int debug_color = 1,int RGB_value=0);
    void gui_debug_arc(const CGeoPoint& p, double r, double start_angle, double span_angle, int debug_color = 1, int RGB_value=0);
    void gui_debug_triangle(const CGeoPoint& p1, const CGeoPoint& p2, const CGeoPoint& p3, int debug_color = 1,int RGB_value=0);
    void gui_debug_robot(const CGeoPoint& p, double robot_dir, int debug_color = 1,int RGB_value=0);
    void gui_debug_msg(const CGeoPoint& p, const char* msgstr, int debug_color = 1,int RGB_value=0);
    void gui_debug_curve(const double num, const double maxLimit, const double minLimit, int debug_color = 1,int RGB_value=0);
    void send(bool);
private:
    QUdpSocket sendSocket;
    QMutex debugMutex;
};
typedef NormalSingleton< CGDebugEngine > GDebugEngine;

#endif
