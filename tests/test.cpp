#include <stdio.h>
#include "catch.hpp"
#include "ofApp.h"
#include "Player.h"


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
