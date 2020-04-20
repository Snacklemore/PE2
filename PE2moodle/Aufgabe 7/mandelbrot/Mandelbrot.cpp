//
// Created by root on 18.04.20.
//

#include "Mandelbrot.h"

double Mandelbrot::getMinReal() const {
    return _MinReal;
}

void Mandelbrot::setMinReal(double minReal) {
    _MinReal = minReal;
}

double Mandelbrot::getMaxReal() const {
    return _MaxReal;
}

void Mandelbrot::setMaxReal(double maxReal) {
    _MaxReal = maxReal;
}

double Mandelbrot::getMinImag() const {
    return _MinImag;
}

void Mandelbrot::setMinImag(double minImag) {
    _MinImag = minImag;
}

double Mandelbrot::getMaxImag() const {
    return _MaxImag;
}

void Mandelbrot::setMaxImag() {
    _MaxImag = _MinImag + (_MaxReal - _MinReal)* _HEIGHT/_WIDTH;
}

ComplexNo Mandelbrot::calculateComplexForPixel(sf::Vector2f pos) {
    //instance of complex
    ComplexNo res(0,0);
    //calculate realpart
    res.setReal((_MinReal + (pos.x+200)*(_MaxReal-_MinReal)/(_WIDTH-1)) );
    //calculate imag part
    res.setImag((_MaxImag - (pos.y)*(_MaxImag-_MinImag)/(_HEIGHT-1)));
    return res;
}

void Mandelbrot::drawToScreen() {


    //do this in calcaluteMandelBrot function, only draw the array here
    /*
    */
    _window->draw(_pixels);



}

void Mandelbrot::calculateMandelBrot() {
    int offsetx = 300;
    int offsety = 300;
    for (unsigned y = 0;y<_HEIGHT;y++)
    {
        for (unsigned x = 0;x<_WIDTH;x++)
        {
            ComplexNo c = calculateComplexForPixel(sf::Vector2f(x,y));
            ComplexNo Z = c ;
            ComplexNo K(0.353,0.288);
            bool isIn = true;
            int iterations = 0;
            for (unsigned n = 0; n < _maxIterations;n++)
            {
                if(Z.abs() > 2)
                {
                    isIn = false;
                    iterations = n;
                    break;
                }
                Z = (Z*Z);
                Z = Z +c ;
            }
            if ( isIn)
            {
                //append pixel at x,y
                sf::Vertex pixel;
                pixel.position =sf::Vector2f(x,y);
                //if in color black
                pixel.color = sf::Color::Black;
                _pixels.append(pixel);
            } else
            {
                sf::Vertex pixel;
                pixel.position = sf::Vector2f(x,y);
                //if not in color appropriate to iterations
                pixel.color = genColor(iterations);
                _pixels.append(pixel);
            }
        }
    }

}

sf::RenderWindow *Mandelbrot::getWindow() const {
    return _window;
}

void Mandelbrot::setWindow(sf::RenderWindow *window) {
    _window = window;
}
