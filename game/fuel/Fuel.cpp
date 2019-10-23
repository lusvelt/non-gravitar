#include "Fuel.hpp"
#include "../../engine/Object.hpp"
#include "../../engine/Engine.hpp"


Fuel::Fuel(Shape* shape):
Object(shape){
    this->tag= "Fuel";
}

// Posiziona il fuel sul segmento s (vedi Bunker.cpp)
void Fuel::setPosition(Segment* s, int radius){
    float l = s->getLength();
    float m = s->getM();
    float m2 = m * m;
    float x1 = s->getP1().x;
    float y1 = s->getP1().y;
    float x2 = s->getP2().x;
    float y2 = s->getP2().y;
    float xm = (x1 + x2) / 2;
    float ym = (y1 + y2) / 2;
    float norm = sqrt(xm * xm + ym * ym);
    float sg = -1;
    if (ym >= 0)
        sg = 1;

    float k = (sg > 0 ? 1 : 0);
    float xb = ((m2 + 1) * (x1 + x2) + sg * 30 * sqrt(m2 + 1)) / (2 * (m2 + 1));
    float yb = s->evaluateY(xb);
    this->position = Point(xb, yb);
    this->rotation = atan(m) * 180 / M_PI + 180 * k;
    if (this->rotation < 0) this->rotation += 360;
    if (this->rotation >= 180 && xb >= radius / 2) this->rotation -= 180;
    else if (this->rotation < 180 && xb < -radius / 2) this->rotation += 180;
}

void Fuel::update(){ }

int Fuel::getFuelAmount(){
    return this->fuelAmount;
}