#pragma once
#include <exception>

class Container_error: public std::exception {};
class Is_empty: public Container_error {};

class Shapes_error : public std::exception {};
class Bad_rect : public Shapes_error {};

