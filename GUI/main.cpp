/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
//---------------------------------DRILL13-------------------------------------------

/*
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
        apple.move(-x_size, y_grid);          // buggy?
        win.wait_for_button();
    }
}

*/
//-----------------------------------------LABFELVEZ----------------------------------------
/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
/*

#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{

    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{200,200}, 100, 50};

	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{200,400}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{100,100}, "badge.jpg"};

	Circle c {Point{700,700}, 100};

	Ellipse e {Point{500,500}, 100, 50};
	e.set_fill_color(Color::red);

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();
    }
    */
//------------------------------------------------------------------------------------------  
    //DRILL 12
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    
    try{
	using namespace Graph_lib;
// 1. empty Simple_window
    Point tl {100, 100};        // top left corner of window

    Simple_window win {tl, 600, 400, "Drill12 ch12.7."};
        // screen coordinate tl for top left corner
        // window size(600*400)
        // title: My window
    win.wait_for_button();      // display!

    // 2. add more examples
    // 12.7.3 Axis
    Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};   // make an Axis
    
    win.attach(xa);                 // attach xa to the window, win
    win.set_label("Drill12 ch12.7.2");  // relabel the window
    win.wait_for_button();          // display!

    Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);              // choose a color
    ya.label.set_color(Color::dark_red);    // choose a color for the text
    win.attach(ya);
    win.set_label("Drill12 ch12.7.3");
    win.wait_for_button();                  // nyomd meg a gombot GOMB

    // 12.7.4 Graphing a function
    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};  // sine curve
        // plot sin() in the range [0:100) with (0,0) at (20,150)
        // using 1000 points; scale x values*50, scale y values*50

    win.attach(sine);
    win.set_label("Drill12 ch12.7.4");
    win.wait_for_button();
    
    // 12.7.5 Polygons
    sine.set_color(Color::blue);    // we changed our mind about sine's color

    Polygon poly;                   // a polygon; a Polygon is a kind of Shape
    poly.add(Point{300, 200});      // three points make a triangle
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Drill12 ch12.7.5");
    win.wait_for_button();

    // 12.7.6 Rectangles
    Rectangle r {Point{200, 200}, 100, 50}; // top left corner, width, height
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});
    win.attach(poly_rect);

    win.set_label("Drill12 ch12.7.6");
    win.wait_for_button();

    // 12.7.7 Fill
    r.set_fill_color(Color::yellow);    // kifestő
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Drill12 ch12.7.7");
    win.wait_for_button();

    // 12.7.8 Text
    Text t {Point{150, 150}, "Hello, graphical world!"}; //szöveg kiírás, asszem balfelső saroktól
    win.attach(t);
    win.set_label("Drill12 ch12.7.8");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("Drill12 ch12.7.9");
    win.wait_for_button();

    // 12.7.9 Images
    Image ii {Point{100, 50}, "image.jpg"};
    win.attach(ii);
    win.set_label("Drill12 ch12.7.10");
    win.wait_for_button();

    ii.move(100, 200);
    win.set_label("the last bit");
    win.wait_for_button();

    // 12.7.10 And much more
    Circle c {Point{100, 200}, 50};
    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m {Point{100, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100, 20}, oss.str()};

    Image cal {Point{225, 225}, "snow_cpp.gif"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("This is the end");
    win.wait_for_button();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
}
