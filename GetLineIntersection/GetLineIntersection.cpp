// GetLineIntersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
struct Line {
    Line(std::initializer_list<sf::Vector2i> vals) {
        this->Points[0] = *vals.begin();
        this->Points[1] = *(vals.begin()+1);

    }
    sf::Vector2i Points[2];
};

int main()
{
    std::cout << "Hello Line Intersection!\n";
    sf::RenderWindow window({ 800,800 }, "Intersection");
    sf::Event event;
    std::vector<Line> Lines;
    std::queue<sf::Vector2i> MouseCoords;

    sf::CircleShape dot(10);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                MouseCoords.push(sf::Mouse::getPosition(window));
            }

        }
        if (MouseCoords.size() >= 2) {
            std::cout << " Drawing Line ...\n";
            auto first = MouseCoords.front(); MouseCoords.pop();
            auto second = MouseCoords.front(); MouseCoords.pop();

            Line tempLine({first, second});
            Lines.push_back(tempLine);

        }
        window.clear();
        for (auto it : Lines) {
            sf::Vertex Line[] = {
                sf::Vector2f(it.Points[0]),
                sf::Vector2f(it.Points[1])
            };
            for (auto CheckInter : Lines) {
                //if line is not check line, check for intersection
                if (&CheckInter != &it) {
                    //intersection code 
                }
            }
            Line->color = sf::Color::White;
            
            window.draw(Line,2, sf::Lines);
        }
        window.display();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
