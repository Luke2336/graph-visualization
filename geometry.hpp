#pragma once

#include <math.h>

class Vec {
public:
  double x, y;
  Vec() : x(0), y(0) {}
  Vec(const double x, const double y) : x(x), y(y) {}
  Vec(const Vec &V) : x(V.x), y(V.y) {}
  Vec operator+(const Vec &V) const {
    return Vec(this->x + V.x, this->y + V.y);
  }
  Vec operator-(const Vec &V) const {
    return Vec(this->x - V.x, this->y - V.y);
  }
  Vec operator*(const double &c) const { return Vec(this->x * c, this->y * c); }
  Vec &operator+=(const Vec &V) {
    this->x += V.x;
    this->y += V.y;
    return *this;
  }
  Vec &operator-=(const Vec &V) {
    this->x -= V.x;
    this->y -= V.y;
    return *this;
  }
  Vec &operator*=(const double &c) {
    this->x *= c;
    this->y *= c;
    return *this;
  }
  double getNorm() const { return sqrt(x * x + y * y); }
};

class Point {
public:
  double x, y;
  Point() : x(0), y(0) {}
  Point(const double x, const double y) : x(x), y(y) {}
  Vec operator-(const Point &P) const {
    return Vec(this->x - P.x, this->y - P.y);
  }
  Point &operator+=(const Vec &V) {
    this->x += V.x;
    this->y += V.y;
    return *this;
  }
  Point &operator-=(const Vec &V) {
    this->x -= V.x;
    this->y -= V.y;
    return *this;
  }
};