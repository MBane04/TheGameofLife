# Conway's Game of Life in the Terminal

Conway's Game of Life is a cellular automaton devised by mathematician John Conway. It consists of a grid of cells that can be either "alive" or "dead." The state of each cell changes based on the states of its eight neighbors according to the following rules:

1. **Any live cell with fewer than two live neighbors dies (underpopulation).**
2. **Any live cell with two or three live neighbors lives on to the next generation.**
3. **Any live cell with more than three live neighbors dies (overpopulation).**
4. **Any dead cell with exactly three live neighbors becomes a live cell (reproduction).**

This implementation is currently Linux-based and provides a terminal-based visualization of the simulation.

## Build Plans

### Iteration 1: Implement GoL Algorithm - COMPLETE (09/28/24)
- 1.1 Add inter-platform support (Windows/Linux)

### Iteration 2: Build OpenGL Engine
- 2.1 Add `SimulationSetup` file to read in and save values from files
- 2.2 Add randomized initial values (hardcoded)

### Iteration 3: Render in OpenGL
- 3.1 Add pause function
- 3.2 Add placeable blocks
- 3.3 Add `saveRun` function that saves initial conditions to be run again
- 3.4 Add moving x/y axis and zoom in/out
- 3.5 Add random initial values as an option

### Iteration 4: Implement a GUI
- 4.1 Add help menu
- 4.2 Add settings tab
  - Change colors
  - Change game speed
  - Change keybindings
  - Change game length

## (Distant) Future Plans
- Parallelize using NVIDIA's CUDA library
- Integrate machine learning to try to survive
- Integrate rhythmic pulses to see if AI can find a way to disrupt or survive
