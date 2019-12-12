## 11/17
I was able to create the project using the openframeworks generator.

## 11/18
I implemented the basic enum for game states but was having trouble adding external libraries. Turns out I had to move my project into the openframeworks project folder then add libraries through the generator.

## 11/19
Methods from the ofxCenteredTrueTypeFont library are giving errors. I fixed this by including the main method in this library in my app.h. I drew the start and game screens with ofImage and the font with TrueType font. However, I do not know how to change the font color. Although I have displayed words in each lane and the live word the player is typing, I plan on creating a new UI for displaying what the user types. 

## 12/2
I researched how to create a linear perspective and decided that I will create lane markers and animate them diagonally to produce the illusion. 

## 12/3 
After animating the perspective, I realized that it did not create the illusion I had hoped for. Now I will decide to simply create a bird's eye view perspective for the game. However, I will put aside animating the lane markers to create the game logic in order to better reach my MVP.

## 12/4
I decided to split the things I draw into separate helper methods. However, I kept on running into issues with the drawLane() method as it encompassed several draw methods. I fixed this by moving around the different draw methods in the for loop of the drawLane() method. Additionally, I cannot seem to have pop_back working on user_input when backspace is pressed. I have to create two instances of pop_back in the keyPressed() method for this to work. 
* Need to fix backspace key press
* Need to create obstacle collision

## 12/5
I decided that I will continue with my original linear perspective idea as I realized I could simply animate the illusion with a couple images. I drew 3 frames of the lane markers and drew them continously to create the movement effect. I also drew the diagonal movement of the left most lane. 
 * Need to fully implement obstacle animations 
 * Need to implement collision

## 12/6
I managed to draw obstacles in each lane but am unable to figure out how to randomize this process. I also managed to have collision working. 
* Need to randomize obstacles
* Need to clean up code
* Need to make game end menu 
* Need to add buttons
* Need to add scoring system

## 12/7
I decided that I would randomize by adding an obstacle after the first osbstacle reached the halfway mark. One pesky issue I ran into was that when my drawObstacle function changed the position of a passed in obstacle, the actual obstacle did not have its position changed. I realized that I needed to make the passed in object a reference to the actual object. However, my game kept crashing. I realized that the way I moved obstacles did not account for the non-uniform movement of random obstacles. This allowed drawing of a random obstacle until it reached the halfway point where my game crashed again. I fixed this after I realized I had to split my drawGame and updating the obstacle position. I created two separate functions and utilized ofApp::update() to fix this issue. I have finished MVP minus the score tracking system.
* Need to clean up code
* Need to make game end menu
* Need to add stylistic touches such as buttons
* Need to add scoring system

## 12/8
I added the score tracking system and decided to change my start screen to play a video. I started to clean my code by creating a constants header file and creating constants. I also added the rule that the player cannot jump lanes.
