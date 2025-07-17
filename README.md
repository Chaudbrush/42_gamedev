# 42_gamedev

Just some random games I did for the 20 games challenge, for the gamedev club of 42 Lisbon. Not sure I'll do them all, but I'll update here the ones I do.

### How to Play
They all use minilibx from 42 School, you can download it from 42 Paris github, our use `make mlx` to download it.

--- 

## Pong
Was the first project I did, tried to do it only with pixels, collision is far from optimal, but kinda works. Does not have delta time at all, so performance will change a lot depending on the machine.
  - Commands:
  - `Space` starts the game
  - Player one uses `W` and `S`
  - Player two uses `Up Arrow` and `Down Arrow`

## Joyride
A recreation of Jetpack Joyride, was interesting to get into mlx transparency, collision is much better since we're calculating them with images. Has a poor implementation of delta time, so performance might change depending on the machine.
  - Commands:
  - `Space` activates the jetpack
  - `Tab` restarts the game if you die
  - Goombas don't kill you, everything else does

---
