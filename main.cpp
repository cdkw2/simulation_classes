#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>
#include "header_files/Vector2.hpp"

const int WIDTH = 20;
const int HEIGHT = 20;

class Particle {
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    char symbol;

    Particle(float x, float y, char sym = '*') : position(x, y), symbol(sym) {
        velocity = Vector2(rand() % 3 - 1, rand() % 3 - 1);
        acceleration = Vector2(0, 0.1f);
    }

    void update() {
        velocity += acceleration;
        position += velocity;

        if (position.x < 0 || position.x >= WIDTH) velocity.x *= -1;
        if (position.y < 0 || position.y >= HEIGHT) velocity.y *= -0.8f;

        position.x = std::max(0.0f, std::min((float)WIDTH - 1, position.x));
        position.y = std::max(0.0f, std::min((float)HEIGHT - 1, position.y));
    }
};

void drawParticles(const std::vector<Particle>& particles) {
    system("clear");

    char grid[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            grid[y][x] = ' ';

    for (const auto& p : particles) {
        int x = (int)p.position.x;
        int y = (int)p.position.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            grid[y][x] = p.symbol;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            std::cout << grid[y][x];
        std::cout << "\n";
    }
}

int main() {
    std::vector<Particle> particles;

    while (true) {
        if (rand() % 10 == 0)
            particles.emplace_back(WIDTH / 2, 0, '*');

        for (auto& p : particles) p.update();
        drawParticles(particles);

        /*
        This is to despawn particles when they reach ground

        particles.erase(std::remove_if(particles.begin(), particles.end(),
            [](const Particle& p) { return p.position.y >= HEIGHT - 1; }),
            particles.end());
        */

        usleep(100000);
    }
    return 0;
}