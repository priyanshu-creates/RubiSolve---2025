# 🧩 RubiSolve - 2025

**RubiSolve - 2025** is a modern, dark-themed frontend interface for solving Rubik’s Cubes using algorithmic logic. It provides an intuitive, user-friendly interface for experimenting with different cube models and algorithms — no command-line knowledge required.

---
### 🚀 Live Demo

Check out the live version of **RubiSolve - 2025** here:  
🔗 (https://rubi-solve-2025.vercel.app/)
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

### Option 1: Frontend Interface (No Setup Required)

1. Open `index.html` in your web browser.
2. Configure your settings:
   - Select the cube model
   - Choose a solving algorithm
   - Set number of shuffle moves and max search depth
3. Click **"Solve Cube"** to start solving.
4. View the original cube, the solution sequence, and the solved cube.
5. Click **"Reset"** to start over.

---

### Option 2: Command Line Interface (C++)

You can still use the original command-line version of the solver.

#### 🔧 Compile and Run:
```bash
g++ main.cpp models/cube.cpp -o a.exe
./a.exe
```

#### 📦 Batch File (Alternative):
```bash
./run.bat
```

Follow on-screen prompts to:
- Select cube model and algorithm
- Set shuffle moves and depth

---

## 🛠️ Technologies Used

- **HTML5**
- **CSS3** (Flexbox, Grid)
- **JavaScript** (Vanilla JS only)
- **C++** (Backend solver)

---

## 🚀 Future Improvements

- 🔄 Step-by-step animation of solution moves
- 🧱 3D cube rendering using **Three.js**
- 📲 Mobile-responsive design
- ✍️ Manual input of cube state
- 🌗 Dark/Light theme toggle
