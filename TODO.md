# TODO

## Player Movement
Player movement is currently not working. <br>
I think it could be due to the revised `Input` class, `Player.cpp` and the new `Timer` class.

#### Files:
- `Player.cpp` -> `Player::handleEvents();` 
- `Input.cpp` & `Input.h`
- `Timer.cpp` & `Timer.h`

## Camera Class
The camera class is currently not working. <br>
It is not tracking the player as intended. <br>

#### Files:
- `Camera.cpp` & `Camera.h`
- `Game.cpp` -> `Game::render();`
