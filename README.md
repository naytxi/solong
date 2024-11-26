![solongheader](https://github.com/user-attachments/assets/e4c71f73-2532-474c-818b-fe018a98c1ab)
![Badge completado](https://img.shields.io/badge/STATUS-%20completed-green)

![zombie gif](https://i.pinimg.com/originals/5d/c0/b0/5dc0b09e4922c6862500eb4c1992e72e.gif)

🖐️ Hi! I'm Nay and I'm currently learning to code.

<h2>🚀ABOUT</h2>
 My first little videogame, this 42 project was the most funny and difficult to do, you play like a hungry zombie and you need to eat before continuing your path.

The "so_long" project is a 2D game developed.

The game is a sort graphical adventure where the zombie navigates through a dungeon, collecting brains. 

The main objective is to reach the exit after collecting all necessary brains.

<h2>❓HOW TO PLAY</h2>

Part 1: Reading the Map
     
     In this section, I verified that the provided map file could be opened correctly and had the .ber file extension. Then, I read the file line-by-line using get_next_line. After this, I write a t_map struct with key map attributes like the number         of players, exits, collectibles, rows, columns, and so on. During this reading process, I also created a single string representing the entire map, which came in handy when building a matrix using ft_split with \n as the delimiter.

Part 2: Starting the Game

    In this part, I used t_map along with the map matrix to construct my main game struct, t_game. This struct holds more specific game-state information, such as lists of zombies and brains, and other essential details. Here, I opened a window with        the mlx function and started rendering the static parts of the map (walls, open spaces, and collectibles) to the window. As with other graphic libraries, mlx uses an infinite loop where game events are handled. The mlx library provides hooks,           allowing certain functions to be triggered by events like keystrokes or mouse clicks.

Part 3: Game Mechanics

    Pressing the ESC or Q key ends the game, while pressing the arrow keys or W, A, S, D causes the zombie to switch directions and attempt to move accordingly. When the zombie catches a brain the collect attribute in the t_game struct is set to 1,         and increases when it continues catching all the brains.
    Finally, if a zombie reaches an exit and all collectibles have been gathered the game ends succesfully.

✈️ Welcome to my journey.
