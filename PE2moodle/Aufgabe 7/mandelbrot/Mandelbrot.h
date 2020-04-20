//
// Created by root on 18.04.20.
//

#ifndef MANDELBROTSET_MANDELBROT_H
#define MANDELBROTSET_MANDELBROT_H

#include <imconfig-SFML.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "ComplexNo.h"
class Mandelbrot {
public:
    //default constructor
    Mandelbrot(unsigned height, unsigned width)
    {
        _HEIGHT = height;
        _WIDTH = width;
        //TODO Implement slider which changes these values  ( and max iterations) during runtime
        //TODO recalculate after change
        _MinReal = -2.0;
        _MaxReal = 1.0*0.3;
        _MinImag = -1.2;
        //_MaxImag = 2.0;
        setMaxImag();
        std::cout << "MAXIMAG:"<< _MaxImag << std::endl;

    }
    Mandelbrot(unsigned height, unsigned width,double MinReal,double MaxReal,
                    double MinImag)
    {
        _HEIGHT = height;
        _WIDTH = width;
        _MinReal = MinReal;
        _MaxReal = MaxReal;
        _MinImag = MinImag;
        setMaxImag();
    }
    double getMinReal() const;
    void setMinReal(double minReal);
    double getMaxReal() const;
    void setMaxReal(double maxReal);
    double getMinImag() const;
    void setMinImag(double minImag);
    double getMaxImag() const;
    //maxImag is being calculated to avoid weird stretching
    void setMaxImag();
    void calculateMandelBrot();
    void drawToScreen();

private:
    ComplexNo calculateComplexForPixel(sf::Vector2f pos);

    sf::Color genColor(int val)
    {
        int r,g,b;
        if(val == 0)
        {
            r = 255;
            g = 0;
            b = 0;
        } else{
            if ( val < 8) {
                r = 8 * (8 - val);
                g = 0;
                b = 8* val -1;
            } else if ( val < 16)
            {
                r = 0;
                g = 8 * ( val - 8);
                b = 8 * (16- val) -1;

            }else if (val < 32){
                r = 8 * (val - 16);
                g = 8 *(16 - val) -1 ;
                b = 0;
            } else
            {
               r = 255 -(val - 30) * 4;
               g = 0;
               b = 0;
            }
        }
        return sf::Color(r,g,b);

    }
    sf::RenderWindow *_window;
public:
    sf::RenderWindow *getWindow() const;

    void setWindow(sf::RenderWindow *window);

private:
    sf::VertexArray _pixels;
    unsigned _HEIGHT;
    unsigned _WIDTH;
    unsigned _maxIterations = 100;
    double _MinReal;
    double _MaxReal;
    double _MinImag;
    double _MaxImag;


};


#endif //MANDELBROTSET_MANDELBROT_H
