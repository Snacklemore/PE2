#include <iostream>
//#include "imgui.h"
//#include "imgui-SFML.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "ComplexNo.h"
#include "Mandelbrot.h"
#include <chrono>
#include <cmath>


int main() {
    Mandelbrot mbrot(712,1024);
    mbrot.calculateMandelBrot();
    sf::RenderWindow window ( sf::VideoMode(1024,712),"MandelBrot",sf::Style::Default);
    window.setPosition(sf::Vector2i(0,10));
   // ImGui::SFML::Init(window);
    mbrot.setWindow(&window);

    sf::Clock deltaClock;
    ComplexNo c(12,2);
    ComplexNo c1(2,5);
    ComplexNo c2(5,54);
    ComplexNo c3(6, 9);
    std::cout << c << std::endl;
    ComplexNo res = c + c1;
    std::cout << res << std::endl;
    res = c - c1;
    std::cout << res << std::endl;
    res = c * c1;
    std::cout << res << std::endl;
    double absolute = c1.abs();
    std::cout << absolute << std::endl;



    ////////SFML MAIN LOOP//////////
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //ImGui::SFML::ProcessEvent(event);
            //ImGuiIO& io = ImGui::GetIO();
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();

            }
        }
        //ImGui::SFML::Update(window,deltaClock.restart());
        window.clear();
        //window.draw();
        mbrot.drawToScreen();
        //ImGui::SFML::Render(window);
        window.display();

    }
    //ImGui::SFML::Shutdown();
}