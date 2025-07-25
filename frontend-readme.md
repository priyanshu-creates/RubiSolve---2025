# RubiSolve - 2025 

This is a modern, dark-themed frontend interface for the RubiSolve - 2025 application. It provides a user-friendly way to interact with the solver without using the command line.

## Features

- **Dark Mode Interface**: Easy on the eyes with a modern, sleek design
- **Interactive Controls**: Select cube model, algorithm, shuffle moves, and search depth
- **Visual Cube Representation**: See both the original and solved cube states
- **Solution Display**: View the sequence of moves needed to solve the cube
- **Statistics**: Track the number of moves and solving time

## How to Use

### Option 1: Using the Frontend Interface

1. Open `index.html` in your web browser
2. Configure your settings:
   - Select a cube model (Cube3d, Cube1d, or Cubebit)
   - Choose a solving algorithm (DFS, BFS, IDDFS, or IDASTAR)
   - Adjust the number of shuffle moves using the slider
   - Set the maximum search depth using the slider
3. Click the "Solve Cube" button to start the solving process
4. View the original cube, solution moves, and solved cube
5. Use the "Reset" button to start over with new settings

### Option 2: Using the Command Line (Original Method)

You can still use the original command-line interface:

1. Compile the program: `g++ main.cpp models/cube.cpp -o a.exe`
2. Run the executable: `./a.exe`
3. Follow the prompts to select cube model, algorithm, shuffle moves, and search depth

Or use the batch file for quick execution:

```
./run.bat
```

## Integration Notes

The frontend currently provides a simulated interface to demonstrate the user experience. To fully integrate with the C++ backend:

1. Create a simple API server (using Node.js, Python, etc.) that can execute the C++ program
2. Modify the JavaScript to make API calls to this server instead of using simulated data
3. Parse the command-line output from the C++ program and return it to the frontend

## Technologies Used

- HTML5
- CSS3 (with modern features like Grid and Flexbox)
- Vanilla JavaScript (no dependencies)

## Future Improvements

- Add 3D visualization of the cube using Three.js
- Implement step-by-step animation of the solution
- Add ability to manually input a cube state
- Create a mobile-responsive design
- Add a dark/light theme toggle