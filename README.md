# SimonSaysArduino
The classic game Simon Says on an Arduino UNO

# What I did:
Created the classic game Simon Says using a breadboard and an Arduino UNO.
<br><br>
How the game works:
1. The player presses any button to begin
2. One of the four LED lights flashes
3. The player must press the corresponding button
4. If the player is correct, the same sequence of lights plays with a new addition for the player to repeat.
		
# How I did it:
I used Arduino’s Integrated Development Environment (IDE) to program the Arduino:
- I mapped each of my LEDs and their corresponding buttons to pins on the Arduino.
- Made variables to track the current round the player is on as well as the max round (which is set to 100).
- Set constant variables, such as how long an LED should flash for and the delay after a button press.
- Split the different parts of the game into different functions, starting with the setup, which initializes the LED pins and generates a random seed for the game. 

# Problems I faced:
- **Problem:** Left-side of breadboard would not get powered
	- **Solution:** The type of breadboard I used had a “split” in its power rails, meaning I had to wire the left side to the right.

- **Problem:** LEDs did not function as intended
	- I discovered that using a Red LED caused all my other LEDs to turn off, possibly due to it drawing too much power.
	- **Solution:** I used a different LED color.
		
- **Problem:** LED logic was reversed (ON/OFF were swapped)
	- **Solution:** Swapped “HIGH” and “LOW” in my code; had to do with how I was powering LEDs.
