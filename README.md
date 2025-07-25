# 🧩 RubiSolve - 2025

**RubiSolve - 2025** is a modern, dark-themed frontend interface for solving Rubik’s Cubes using algorithmic logic. It provides an intuitive, user-friendly interface for experimenting with different cube models and algorithms — no command-line knowledge required.

---

### 🚀 Live Demo

Check out the live version of **RubiSolve - 2025** here:  
🔗 [https://rubi-solve-2025.vercel.app/](https://rubi-solve-2025.vercel.app/)

---

## 🌟 Features

- 🎨 **Dark Mode Interface** – Clean and modern design, easy on the eyes.
- 🧠 **Interactive Controls**
  - Choose cube models: `Cube3d`, `Cube1d`, or `Cubebit`
  - Select algorithms: `DFS`, `BFS`, `IDDFS`, or `IDASTAR`
  - Adjust shuffle moves and search depth using sliders
- 🧊 **Visual Representation** – View both original and solved cube states
- 📜 **Solution Display** – See the step-by-step solution
- 📈 **Statistics** – Track number of moves and time taken to solve

---

## 🧑‍💻 How to Use

### ✅ Option 1: Frontend Interface (No Setup Required)

1. Open `index.html` in your web browser.
2. Configure your settings:
   - Select the cube model
   - Choose a solving algorithm
   - Set number of shuffle moves and max search depth
3. Click **"Solve Cube"** to start solving.
4. View the original cube, the solution sequence, and the solved cube.
5. Click **"Reset"** to start over.

---

### 🖥️ Option 2: Command Line Interface (C++)

Use the original backend logic directly via the terminal.

#### 🔧 Compile and Run:
```bash
g++ main.cpp models/cube.cpp -o a.exe
./a.exe
```

#### 📦 Using the Batch File (Quick Run):
```bash
./run.bat
```

Follow the terminal prompts to:
- Select a cube model and algorithm
- Set number of shuffle moves and depth

---

## 🛠️ Technologies Used

- **HTML5**
- **CSS3** (Flexbox, Grid)
- **JavaScript** (Vanilla JS)
- **C++** (Backend solving logic)

---

## 🚧 Future Improvements

- 🔄 Step-by-step animation of cube-solving moves
- 🧱 3D cube rendering using **Three.js**
- 📲 Mobile-responsive UI
- ✍️ Manual cube state input support
- 🌗 Dark/Light theme toggle

---

Feel free to fork, star, and contribute to this project!
