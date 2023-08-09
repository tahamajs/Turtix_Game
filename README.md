# Turtix Game

![Turtix Game]("Game_pic/6.png")

Turtix Game is a C++ game developed using the SFML library. It offers an interactive gameplay experience where players control a turtle, collecting stars and avoiding enemies across various maps. This readme provides essential information on running the game, modifying maps, and understanding the game's structure.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building the Game](#building-the-game)
- [Gameplay](#gameplay)
  - [Controls](#controls)
- [Modifying Maps](#modifying-maps)
  - [Map Files](#map-files)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

To compile and run Turtix Game, you need the following:

- C++ Compiler (e.g., g++)
- SFML Library (Simple and Fast Multimedia Library)
- Make utility

Ensure you have the necessary dependencies installed on your system before proceeding.

### Building the Game

1. Clone the repository or download the source code and extract it to a directory of your choice.
git clone https://github.com/tahamajs/Turtix_Game.git


2. Open a terminal and navigate to the game directory.
cd Turtix_Game


3. Use the provided makefile to build the game.
make 


## Gameplay

The goal of Turtix Game is to control the turtle character, collect stars, and avoid enemies to reach the end of each map. The game features multiple maps, each with varying levels of difficulty.

### Controls

- **Arrow keys:** Move the turtle character.
- **Spacebar:** Jump.
- **Esc:** Pause the game.

## Modifying Maps

You can customize Turtix Game by modifying the maps, adding new levels, or changing the position of stars and enemies.

### Map Files

Map files are text files representing the game levels. Each character in the map corresponds to an element:

- `.`: Empty space
- `#`: Solid ground
- `*`: Star
- `T`: Turtle (player's character)
- `E`: Enemy

Feel free to edit the existing map files or create new ones to add more levels and challenges to the game.

## Screenshots

![Gameplay](gameplay1.jpg)
_Gameplay screenshot showcasing the turtle character collecting stars._

## Contributing

Contributions are welcome! If you'd like to make improvements or add new features, fork this repository, create a new branch, and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---

Have fun playing and customizing Turtix Game! If you encounter any issues or have questions, feel free to contact us at [your@email.com](mailto:your@email.com).




