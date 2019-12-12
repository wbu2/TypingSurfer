#include <stdio.h>
#include "catch.hpp"
#include "ofApp.h"
#include "Player.h"
#include "Constants.h"


TEST_CASE("Player Collision"){
    ofApp game;
    Player p;
    p.SetPosition(0, 5);
    p.SetLane(0);
    Obstacle o;
    o.SetPosition(0, 5);
    o.SetLane(0);
    
    REQUIRE(game.Collided(o,p));
}

TEST_CASE("Update Position Correctly"){
    ofApp game;
    Player p;
    Obstacle o;
    
    SECTION("Player Position Update"){
        game.UpdatePlayerPosition(0, p);
        REQUIRE((p.GetPosition().x == constants::kLeftPlayerX));
        REQUIRE((p.GetPosition().y == constants::kPlayerY));
    }
    SECTION("Obstacle Position Update"){
        o.SetSpeed(constants::kObstacleSpeed);
        o.SetLane(0);
        game.UpdateObstacle(o);
        
        REQUIRE(o.GetPosition().x == (constants::kLeftObstacleStartX - constants::kDirectionMagnitude * o.GetSpeed()));
        REQUIRE(o.GetPosition().y == (int)(constants::kDownMagnitude * o.GetSpeed()));
    }
}

TEST_CASE("Read Text File Correctly"){
    FileReader reader;
    reader.ReadWords("input.txt");
    REQUIRE(reader.GetFileWords()[13] == "aardvark");
}
