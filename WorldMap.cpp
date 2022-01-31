#include "WorldMap.hpp"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
using namespace rapidjson;

void WorldMap::loadMap(std::string filename) {
    // TODO implement json loading this instead of the following
    //values.push_back( { 0, 0, 0,0} ); // -------> x   sample map of size 4 by 4
    //values.push_back( { 0,-1,-1,2} ); // |            inner vector define tiles in the x axis
    //values.push_back( { 0,-1,-1,9} ); // |            outer vector define tiles in the z axis
    //values.push_back( { 0, 0, 0,0} ); // v z
    startingPosition.x = 1.5;
    startingPosition.y = 1.5;
    startingRotation = 22.5;

    // you can use the json slides in lecture 4 as a reference
   
     ifstream fis(filename);
     IStreamWrapper isw(fis);
     Document d;
     d.ParseStream(isw);
     
     StringBuffer buffer;
     Writer<StringBuffer> writer(buffer);
     d.Accept(writer);
     const char* output = buffer.GetString();

     //std::cout << output;
     Document document;
     document.Parse(output);

     std::cout<<document["spawn"]["x"].IsFloat();
     //std::cout << document["tileMap"].GetString();
     std::cout << output;

     startingPosition.x = document["spawn"]["x"].GetFloat();
     startingPosition.y = document["spawn"]["y"].GetFloat();
     startingRotation = document["spawn"]["angle"].GetFloat();
     
     auto array = document["tileMap"].GetArray();
     
     for (int i = 0; i < array.Size(); i++) {
         std::vector<int> temp;
         for (int j = 0; j < array[i].Size(); j++) {
             temp.push_back(array[i][j].GetInt());
         }
         values.push_back(temp);
     }
}

int WorldMap::getTile(int x, int y) {
    //printf("%d \n", values.at(x).at(y));
    return values.at(x).at(y);
    //previous vers: return values.at(y).at(x);
}

int WorldMap::getWidth() {
    return values[0].size();
}

int WorldMap::getHeight() {
    return values.size();
}

glm::vec2 WorldMap::getStartingPosition() {
    return startingPosition;
}

float WorldMap::getStartingRotation() {
    return startingRotation;
}

glm::vec4 WorldMap::getFloorColor() {
    return floorColor;
}

glm::vec4 WorldMap::getCeilColor() {
    return ceilColor;
}
