#include <cassert>

#include "constants.h"
#include "cell.h"
#include "debug.h"

Image_ptr::Image_ptr(Graph_lib::Point p, const std::string& path){
    ptr = new Graph_lib::Image(p, path);
}
void Image_ptr::reset(const std::string& path){
    MARKER;
//    assert(win_ptr);
//    assert(ptr);
    Graph_lib::Point temp = ptr->point(0);

    win_ptr->detach(*ptr);
    delete ptr;

    ptr = new Graph_lib::Image(temp, path);
    win_ptr->attach(*ptr);
    MARKER;
}
void Image_ptr::attach(Graph_lib::Window& win){
    MARKER;
    win_ptr = &win;
    win.attach(*ptr);
    MARKER;
}
Image_ptr::~Image_ptr(){
    MARKER;
    win_ptr->detach(*ptr);
    delete ptr;
    MARKER;
}


Button_resizable::Button_resizable (Graph_lib::Point p, int w, int h,
                                   const std::string& label,
                                   Graph_lib::Callback cb)
  : Button{ p, w, h, label, cb }
{ }
//Button_resizable::~Button_resizable(){
//    delete pw;
//}

Cell::Cell (Graph_lib::Point p, int size, Graph_lib::Callback cb)
  : Button_resizable{ p, size, size, "", cb },
    img_ptr{ p, img_btn_pulled }
{
//  set_img(img_btn_pulled, nullptr);
}


void Cell::attach (Graph_lib::Window &win)
{
  Button::attach(win);
  img_ptr.attach(win);
}


void Button_resizable::resize (int w, int h)
{
  pw->size(w, h);
}

