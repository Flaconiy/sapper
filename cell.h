﻿#ifndef CELL_H
#define CELL_H 1


#include "libs.h"

#include <string>

class Image_ptr{
private:
    Graph_lib::Image* ptr { nullptr };
    Graph_lib::Window* win_ptr { nullptr };
public:
    Image_ptr(Graph_lib::Point p, const std::string& path);
    void reset(const std::string& path);
    void attach(Graph_lib::Window& win);
    ~Image_ptr();
};

class Button_resizable : public Graph_lib::Button
{
public:
  Button_resizable (Graph_lib::Point p, int w, int h,
                 const std::string& label,  Graph_lib::Callback cb);

  void resize (int w, int h);
};


class Cell : public Button_resizable
{
public:
  Cell(Graph_lib::Point p, int size_, Graph_lib::Callback cb);

  void attach (Graph_lib::Window &win) override;

  void set_bomb (bool bomb) { bombed = bomb; }
  void set_flag (bool flag) { flaged = flag; }
  void set_open ()          { opened = true; }

  bool is_bombed () const { return bombed; }
  bool is_flaged () const { return flaged; }
  bool is_opened () const { return opened; }

  int bombs_around{ 0 }; // TODO: в отдельные методы

  Image_ptr img_ptr;

private:
  bool bombed{ false };
  bool flaged{ false };
  bool opened{ false };
};


#endif // CELL_H
