# Dining Philosophers Problem
I’ve implemented a simulation of the Dining Philosophers Problem in C using threads and mutexes. In this problem, philosophers sit around a table with a bowl of spaghetti and alternate between eating, thinking, and sleeping. To eat, a philosopher needs two forks—one from their left and one from their right. After eating, they return the forks and start sleeping, then resume thinking. The simulation ends if a philosopher starves. The goal is to ensure no philosopher starves, as they don't communicate or know if another is starving.

**PLACEHOLDER**
## 👀 YouTube Video: Code-Princess/Mein erstes selbst programmiertes 2D Computer Spiel/Berry-Princess-Game/Retro-Style🍓👸
<!-- YouTube video cards from https://github.com/DenverCoder1/github-readme-youtube-cards -->
<!-- https://ytcards.demolab.com/?id=<video ID>&title=<video+title>&lang=en&timestamp=<video publish date in Unix time format>&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5&duration=<video duration in seconds> "<video title>") -->
<!-- BEGIN YOUTUBE-CARDS -->
[![Code-Princess/Mein erstes selbst programmiertes 2D Computer Spiel/Berry-Princess-Game/Retro-Style](https://ytcards.demolab.com/?id=uH6tfKEWT6Y&title=Code-Princess/Mein+erstes+selbst+programmiertes+2D+Computer+Spiel/Berry-Princess-Game/Retro-Style&lang=en&timestamp=1721426400&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=850&border_radius=5&duration=262 "Code-Princess/Mein erstes selbst programmiertes 2D Computer Spiel/Berry-Princess-Game/Retro-Style")](https://youtu.be/uH6tfKEWT6Y?si=ZQqomfBc4khFFNkN)
<!-- END YOUTUBE-CARDS -->
## Input arguments
Do not run this programm with more than 200 philosophers. Do not run with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms. My program accepts following inputs arguments:
| Argument                                | Description                                                                                         |
|-----------------------------------------|-----------------------------------------------------------------------------------------------------|
| **number_of_philosophers**              | The number of philosophers and forks.                                                               |
| **time_to_die**                         | A philosopher dies if they don't start eating within this time since their last meal or the simulation start. |
| **time_to_eat**                         | The time required for a philosopher to eat, during which they need two forks.                        |
| **time_to_sleep**                       | The time a philosopher spends sleeping.                                                             |
| **number_of_times_each_philosopher_must_eat** (optional) | The simulation stops if all philosophers have eaten this many times. If not provided, it stops when a philosopher dies. |
## Prerequisites
Please note that this program is only compatible with Linux or macOS. Ensure that you have a C-compiler e.g. cc installed on your operating system.
## Installation
To install the project follow these steps in your terminal:
```
git clone git@github.com:Code-Princess/philo.git
cd philo
make
```
## Run the simulation
To run the simulation, use this command in your terminal. You can either have 4 input arguments, e.g.
```
./philo 4 310 200 100
```
Or you can have 5 input arguments, e.g.
```
./philo 5 800 200 200 7
```
Here are some input arguments and the expected results:
| Test Case  | Command                     | Expected Result                                                                      |
|------------|-----------------------------|--------------------------------------------------------------------------------------|
| Test 1     | `./philo 1 800 200 200`     | The philosopher should not eat and should die.                                       |
| Test 2     | `./philo 5 800 200 200`     | No philosopher should die.                                                           |
| Test 3     | `./philo 5 800 200 200 7`   | No philosopher should die, and the simulation should stop when each has eaten 7 times.|
| Test 4     | `./philo 4 410 200 200`     | No philosopher should die.                                                           |
| Test 5     | `./philo 4 310 200 100`     | One philosopher should die.                                                          |




