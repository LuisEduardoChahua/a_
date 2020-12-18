#ifndef CLIONPROYECT_PARTICLE_H
#define CLIONPROYECT_PARTICLE_H
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class particle {
private:
    double rx_, ry_;
    double vx_, vy_;
    int count_;
    double r_;
    double mass_;
    int red, gr, blu;
    
    public:
    particle(double rx, double ry, double vx, double vy,
    double r, double mass, int red, int gr, int blu):
    rx_(rx), ry_(ry), vx_(vx), vy_(vy),r_(r),
    mass_(mass), red(red), gr(gr), blu(blu){};
    inline int count() { return count_;}
    void move(double dt);
    void draw(sf::RenderWindow* window);
    double timeToHit(particle* other);
    double timeToHitVerticalWall();
    double timeToHitHorizontalWall();
    void bounceOff(particle* &other);
    void bounceOffVerticalWall();
    void bounceOffHorizontalWall();
    double kineticEnergy();
};

#endif //CLIONPROYECT_PARTICLE_H
