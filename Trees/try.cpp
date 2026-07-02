#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

struct Entity {
    int x, y;
    int hp = 100;
    bool attacking = false;
    bool blocking = false;
    bool jumping = false;
    int attackTimer = 0;
    int jumpTimer = 0;
    int groundY = 300; // Ground level (adjusted for window height)

    void update() {
        if (jumpTimer > 0) {
            jumpTimer--;
            if (jumpTimer > 2) y -= 10; // Ascend (faster for pixels)
            else y += 10; // Descend
        } else {
            y = groundY; // On ground
            jumping = false;
        }
        if (attackTimer > 0) attackTimer--;
        else attacking = false;
        if (blocking && attackTimer <= 0) blocking = false; // Block wears off
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fighting Game");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error loading font!" << endl;
        return -1;
    }

    Entity p1{100, 300};
    Entity p2{600, 300};
    bool running = true;

    while (running && p1.hp > 0 && p2.hp > 0) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) running = false;
        }

        // Input Handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) running = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !p1.jumping) p1.x -= 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !p1.jumping) p1.x += 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !p1.jumping) { p1.jumping = true; p1.jumpTimer = 5; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !p1.attacking) { p1.attacking = true; p1.attackTimer = 4; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !p1.blocking) { p1.blocking = true; p1.attackTimer = 2; }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !p1.attacking) { p1.attacking = true; p1.attackTimer = 6; }

        // AI (P2 chases P1, jumps occasionally, blocks)
        if (rand() % 50 == 0 && !p2.jumping) { p2.jumping = true; p2.jumpTimer = 5; }
        if (p2.x > p1.x + 60) p2.x -= 5;
        else if (p2.x < p1.x + 40) p2.x += 5;
        if (rand() % 30 == 0 && !p2.blocking) { p2.blocking = true; p2.attackTimer = 2; }
        if (rand() % 20 == 0 && !p2.attacking) { p2.attacking = true; p2.attackTimer = 4; }

        // Combat Logic
        double dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
        if (p1.attacking && dist < 70 && !p2.blocking) {
            p2.hp -= (p1.attackTimer == 6 ? 5 : 2);
        }
        if (p2.attacking && dist < 70 && !p1.blocking) {
            p1.hp -= 2;
        }

        // Update States
        p1.update();
        p2.update();

        // Rendering
        window.clear();
        sf::Text hpText("P1 HP: " + to_string(p1.hp) + " | P2 HP: " + to_string(p2.hp), font, 20);
        hpText.setPosition(10, 10);
        window.draw(hpText);

        sf::RectangleShape p1Shape(sf::Vector2f(50, 100));
        p1Shape.setPosition(p1.x, p1.y);
        p1Shape.setFillColor(p1.attacking ? sf::Color::Blue : sf::Color::Cyan);
        window.draw(p1Shape);

        sf::RectangleShape p2Shape(sf::Vector2f(50, 100));
        p2Shape.setPosition(p2.x, p2.y);
        p2Shape.setFillColor(p2.attacking ? sf::Color::Magenta : sf::Color::Red);
        window.draw(p2Shape);

        window.display();
        sf::sleep(sf::milliseconds(30));
    }

    window.close();
    cout << (p1.hp <= 0 ? "P2 WINS!" : "P1 WINS!") << endl;
    return 0;
}