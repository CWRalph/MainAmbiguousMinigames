#pragma once
#pragma region SDL
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <random>
#include <thread>
#include <future>
#include <mutex>
#include <cmath>
#include "raylib.h"

#pragma endregion SDL

//Standard Containers
#pragma region Containers
#include <vector>
#include <list>
#include <unordered_map>
#include <iterator>

#pragma endregion Container

using std::cout;
using std::string;
using std::vector;
using std::thread;
using std::list;
using std::mutex;
using std::fstream;
using std::ifstream;
using std::ostream;
using std::stringstream;
using std::ofstream;
using std::unordered_map;
using std::future;
using std::to_string;
using std::stoi;
using std::stof;
using std::stod;
using std::stoll;
using std::stold;
using std::stoull;


#define ULL unsigned long long

static const int screenHeight = 950;
static const int screenWidth = 950;

enum class GameScreen { TITLE, FALLINGMETAL, PULLEDPORK, FIREWALL, DUCK, LOW_KEY, MICROSOFT, LOCKSMITH, MICROCHIPS, SHAKE_SPEAR , FRANCE};
