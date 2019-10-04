#include "Info.hpp"

Info::Info(Object* obj, Point position) {
    type = "ObjectInfo";
    object = obj;
    object->setPosition(position);
    text = NULL;
}

Info::Info(Text* text, Point position) {
    type = "TextInfo";
    this->text = text;
    this->text->setPosition(position);
    object = NULL;
}

string Info::getType() {
    return type;
}

Object* Info::getObject() {
    return object;
}

Text* Info::getText() {
    return text;
}

void Info::update() { }