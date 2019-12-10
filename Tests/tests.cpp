//
//  tests.cpp
//  project-tests
//
//  Created by William Bu on 12/9/19.
//

#include <stdio.h>
#include "catch.hpp"
#include "ofApp.h"
#include "Player.h"


TEST_CASE("Draw Player Position Correctly"){
    shared_ptr<ofApp> game(new ofApp());
    game->drawPlayer(0);
    REQUIRE(true);
}
