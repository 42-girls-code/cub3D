*This project was created as part of the 42 curriculum by ilemos-c, csuomins.*

# cub3D — My First RayCaster with miniLibX

## Description

cub3D is a project inspired by the classic **Wolfenstein 3D**, considered the first First Person Shooter in video game history. The goal is to create a realistic 3D graphical representation of the inside of a maze from a first-person perspective, using the **ray-casting** technique.

The project is developed in **C** using the **MiniLibX** graphics library, applying mathematical concepts and algorithms to render textured walls, player movement, and scene file parsing in the `.cub` format.

### Mandatory Features

- 3D rendering via ray-casting with the DDA algorithm
- Different textures for each wall direction (North, South, East, West)
- Configurable floor and ceiling colors
- Player movement with `W`, `A`, `S`, `D`
- Camera rotation with the arrow keys
- Clean exit with `ESC` or window close button
- `.cub` file parser with map validation and error handling

### Bonus Features

- Wall collision detection
- Minimap system
- Mouse camera rotation

---

## Instructions

### Dependencies

- **MiniLibX** (Linux or macOS version)
- **make** and **cc**
- Math library (`-lm`)

### Compilation

```bash
# Mandatory part
make
```

### Execution

```bash
./cub3D maps/your_map.cub
```

The argument must be a scene description file with the `.cub` extension.

### `.cub` File Format

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 220,100,0
C 135,206,235

1111111
1000001
100N001
1000001
1111111
```

The map must contain only the characters `0` (empty space), `1` (wall), and `N`, `S`, `E` or `W` for the player's starting position and direction. The map must be fully enclosed by walls.

### Controls

| Key | Action |
|---|---|
| `W` `A` `S` `D` | Move the player |
| `←` `→` | Rotate the camera |
| Mouse | Rotate the camera (bonus) |
| `ESC` | Close the program |

---

## Resources

### Technical References

- [Lodev — Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — main reference for the DDA algorithm and texture rendering
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) — documentation for the graphics library used
- [Wolfenstein 3D (original game)](http://users.atw.hu/wolf3d/) — inspiration for the project
- [Raycasting in JavaScript (YouTube playlist)] (https://youtu.be/J5K8qMCB-7o?si=qVf7FB9hHZHMz0QZ) — playlist recreating Wolfenstein 3D in JavaScript using ray-casting and the DDA algorithm

### AI Usage

Artificial intelligence was used as a support tool throughout the project, mainly for:

- Researching and clarifying doubts about the ray-casting algorithm and MiniLibX
- Looking into approaches for specific implementation challenges
- Helping identify and fix bugs
- Supporting code organization within the constraints of the 42 Norm

All code was written, understood, and validated by the project authors.