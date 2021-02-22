/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;
    // Ch 13 Drill

    // 1. Make an 800x1000 window
    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Chapter 13 Drill"};
    win.wait_for_button();

    // 2. Put an 8x8 grid of 100 pixel squares
    int x_size = 800;
    int y_size = 801;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x <= x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});    // vertical lines
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);
    win.wait_for_button();

    // 3. Make top left diagonal down all red
    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_fill_color(Color::white);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }

    win.wait_for_button();

    // 4. Add 3 copies of a 200x200 image
    Image cpp1 {Point{0,300}, "kep.jpg"};
    Image cpp2 {Point{300,600}, "kep.jpg"};
    Image cpp3 {Point{500,100}, "kep.jpg"};

    win.attach(cpp1);
    win.attach(cpp2);
    win.attach(cpp3);
    win.wait_for_button();

    // 5. Add a 100x100 image and make it move when next is pressed
    Image apple {Point{0,0}, "apple.jpg"};
    win.attach(apple);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            apple.move(100, 0);
            win.wait_for_button();
        }
        apple.move(-x_size, y_grid);          // buggy
        win.wait_for_button();
    }
}

