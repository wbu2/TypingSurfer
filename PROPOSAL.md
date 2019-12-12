<!-- Write your proposal here! Make sure to use properly-formatted Markdown! -->
# Final Project Proposal 

## Description
For my final project I will make a typing game where the user must type the words that appear on the screen as fast as possible. The theme of the game centers around avoiding traffic in a three-lane road. Other cars serve as obstacles in each lane, and so the player must type the word on another lane to avoid crashing into the car. For example, if one is in the middle lane and a car is in front, one could type the word that appears on the right lane to switch to the right lane. The game will run increasingly faster as time progresses. 

## Background
In AP Computer Science class I learned the basics of game design when I recreated the board game King of Tokyo. Having had a lot of fun creating this game, I am excited to create an original game of my making. Additionally, I have always enjoyed using typing websites such as [TypeRacer](https://play.typeracer.com) and playing endless-runners such as Subway Surfers, and so combining the two is something I look forward to doing. 

## External Libraries
I will use [ofxControlPanel](https://github.com/ofTheo/ofxControlPanel) to display live score and text input.

## Timeline
**End of Week 1:** 
* Setup app layout
* Create and draw start menu
* Draw the game screen
* Implement player input tracking

**End of Week 2:**
* Implement obstacle collision 
* Implement movement of car in lanes
* Implement word display in each lane

**End of Week 3:**
* Create and draw game over screen
* Implement game logic

**Stretch Goals**
* Add ability for user to jump over obstacles
* Keep track of and display WPM (Words Per Minute)
* Create different themed maps that user can choose from 
* Add option to select different cars

## MVP
I will have a simple GUI where there are three lanes designed by 3 horizontal lines and a word on each lane. Rectangles will move down each lane. If they intersect a static horizontal line across the screen before the word in the lane is typed then the game is over. If the word is typed then a new word will replace the old word. The score at the end will be displayed as the number of words typed. 
