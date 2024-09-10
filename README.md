# FdF

This 42 Common Core project was my initial dive into graphics programming. The project is programmed in C and uses 42's Minilibx to interface with the X server.

The aim of FdF is to visualize elevation maps using 3D wireframe rendering.

Here are some resources that might be useful if you are doing FdF:
- [Linear Algebra](https://metalbyexample.com/linear-algebra/), maths for 3D computer graphics
- [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm), line plotting
- [Game Loop Pattern](https://gameprogrammingpatterns.com/game-loop.html), main loop run by mlx_loop
- [Essence of linear algebra](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
- [42MapGenerator](https://github.com/jgigault/42MapGenerator)
- [42 Docs documentation on Minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
- [Linear Interpolation](https://en.wikipedia.org/wiki/Linear_interpolation), color gradient

## Overview
![preview-1](assets/fdf-preview-1.png)
![preview-2](assets/fdf-preview-2.png)
![preview-3](assets/fdf-preview-3.png)

## Build

### Dependencies

- [MinilibX](https://github.com/42Paris/minilibx-linux)  
`git clone https://github.com/42Paris/minilibx-linux.git lib/minilibx-linux`

### Compile

- `make all`

## Usage

`./fdf assets/maps/file.fdf`

### Controls

Shortcut | Action
:---: | ---
`Mouse Left` | Translate
`Mouse Right` | Rotate
`Mouse Scroll` | Zoom +/-
`PgUp`, `PgDn` | Z scaling +/-
`p` | Switch isometric/orthogonal projection
`r` | Reset transformations
`l` | Toggle z scaling lock/unlock
`1`, `2`, `3` | Change color palette
`Esc` | Quit
