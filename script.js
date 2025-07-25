document.addEventListener('DOMContentLoaded', () => {
    // DOM Elements
    const cubeModelOptions = document.querySelectorAll('.setting-group:nth-child(1) .option');
    const algorithmOptions = document.querySelectorAll('.setting-group:nth-child(2) .option');
    const shuffleMovesSlider = document.getElementById('shuffle-moves');
    const shuffleValueDisplay = document.getElementById('shuffle-value');
    const searchDepthSlider = document.getElementById('search-depth');
    const depthValueDisplay = document.getElementById('depth-value');
    const solveButton = document.getElementById('solve-btn');
    const resetButton = document.getElementById('reset-btn');
    const originalCubeDisplay = document.getElementById('original-cube');
    const solvedCubeDisplay = document.getElementById('solved-cube');
    const solutionMovesContainer = document.getElementById('solution-moves');
    const totalMovesDisplay = document.getElementById('total-moves');
    const solveTimeDisplay = document.getElementById('solve-time');
    const loadingOverlay = document.getElementById('loading-overlay');

    // State
    let selectedCubeModel = '1'; // Default: Cube3d
    let selectedAlgorithm = '4'; // Default: IDASTAR
    let shuffleMoves = 5;
    let searchDepth = 5;
    
    // Color mapping
    const colorMap = {
        'W': 'white',
        'Y': 'yellow',
        'B': 'blue',
        'G': 'green',
        'R': 'red',
        'O': 'orange'
    };

    // Move descriptions
    const moveDescriptions = {
        'L': 'Left face clockwise',
        'L2': 'Left face 180°',
        'LP': 'Left face counter-clockwise',
        'R': 'Right face clockwise',
        'R2': 'Right face 180°',
        'RP': 'Right face counter-clockwise',
        'U': 'Up face clockwise',
        'U2': 'Up face 180°',
        'UP': 'Up face counter-clockwise',
        'D': 'Down face clockwise',
        'D2': 'Down face 180°',
        'DP': 'Down face counter-clockwise',
        'F': 'Front face clockwise',
        'F2': 'Front face 180°',
        'FP': 'Front face counter-clockwise',
        'B': 'Back face clockwise',
        'B2': 'Back face 180°',
        'BP': 'Back face counter-clockwise'
    };

    // Initialize UI
    function initUI() {
        // Update sliders display
        shuffleValueDisplay.textContent = shuffleMoves;
        depthValueDisplay.textContent = searchDepth;

        // Set up event listeners for cube model options
        cubeModelOptions.forEach(option => {
            option.addEventListener('click', () => {
                cubeModelOptions.forEach(opt => opt.classList.remove('selected'));
                option.classList.add('selected');
                selectedCubeModel = option.dataset.value;
            });
        });

        // Set up event listeners for algorithm options
        algorithmOptions.forEach(option => {
            option.addEventListener('click', () => {
                algorithmOptions.forEach(opt => opt.classList.remove('selected'));
                option.classList.add('selected');
                selectedAlgorithm = option.dataset.value;
            });
        });

        // Set up slider event listeners
        shuffleMovesSlider.addEventListener('input', () => {
            shuffleMoves = shuffleMovesSlider.value;
            shuffleValueDisplay.textContent = shuffleMoves;
        });

        searchDepthSlider.addEventListener('input', () => {
            searchDepth = searchDepthSlider.value;
            depthValueDisplay.textContent = searchDepth;
        });

        // Set up button event listeners
        solveButton.addEventListener('click', solveCube);
        resetButton.addEventListener('click', resetUI);
    }

    // Create a visual representation of the cube
    function createCubeVisualization(cubeState) {
        const cubeLayout = document.createElement('div');
        cubeLayout.className = 'cube-layout';

        // Create each face
        const faces = ['up', 'left', 'front', 'right', 'back', 'down'];
        const faceLetters = cubeState.split('\n');
        
        // Skip the first empty line if it exists
        let startIndex = faceLetters[0].trim() === '' ? 1 : 0;
        
        // Process UP face (lines 1-3)
        const upFace = createFace(faceLetters.slice(startIndex, startIndex + 3));
        upFace.className = 'cube-face face-up';
        cubeLayout.appendChild(upFace);
        
        // Process middle section (LEFT, FRONT, RIGHT, BACK) - lines 4-6
        const middleLines = faceLetters.slice(startIndex + 3, startIndex + 6);
        for (let i = 0; i < 4; i++) {
            const facePieces = [];
            for (let j = 0; j < 3; j++) {
                // Extract 3 characters for each face from the middle lines
                const line = middleLines[j];
                const startChar = i * 6 + i * 2; // Each face has 3 chars + 2 spaces
                const faceChars = line.substring(startChar, startChar + 5).trim().split(' ');
                facePieces.push(faceChars);
            }
            
            const face = document.createElement('div');
            face.className = `cube-face face-${faces[i + 1]}`; // +1 because we already did UP
            
            for (let row = 0; row < 3; row++) {
                for (let col = 0; col < 3; col++) {
                    const square = document.createElement('div');
                    square.className = `cube-square color-${colorMap[facePieces[row][col]]}`;
                    face.appendChild(square);
                }
            }
            
            cubeLayout.appendChild(face);
        }
        
        // Process DOWN face (lines 7-9)
        const downFace = createFace(faceLetters.slice(startIndex + 6, startIndex + 9));
        downFace.className = 'cube-face face-down';
        cubeLayout.appendChild(downFace);
        
        return cubeLayout;
    }

    // Helper function to create a face from text lines
    function createFace(lines) {
        const face = document.createElement('div');
        face.className = 'cube-face';
        
        for (let i = 0; i < lines.length; i++) {
            const squares = lines[i].trim().split(' ');
            for (let j = 0; j < squares.length; j++) {
                if (squares[j]) { // Skip empty strings
                    const square = document.createElement('div');
                    square.className = `cube-square color-${colorMap[squares[j]]}`;
                    face.appendChild(square);
                }
            }
        }
        
        return face;
    }

    // Simulate solving the cube
    function solveCube() {
        // Show loading overlay
        loadingOverlay.classList.remove('hidden');
        
        // Clear previous results
        originalCubeDisplay.innerHTML = '';
        solvedCubeDisplay.innerHTML = '';
        solutionMovesContainer.innerHTML = '';
        
        // Simulate API call to the backend solver
        setTimeout(() => {
            // Generate a random scrambled cube state
            const scrambledState = generateScrambledCubeState();
            
            // Display the scrambled cube
            originalCubeDisplay.appendChild(createCubeVisualization(scrambledState));
            
            // Generate solution moves
            const solutionMoves = generateSolutionMoves();
            
            // Display solution moves
            displaySolutionMoves(solutionMoves);
            
            // Display solved cube
            const solvedState = generateSolvedCubeState();
            solvedCubeDisplay.appendChild(createCubeVisualization(solvedState));
            
            // Update stats
            totalMovesDisplay.textContent = solutionMoves.length;
            solveTimeDisplay.textContent = `${Math.floor(Math.random() * 500) + 100}ms`;
            
            // Hide loading overlay
            loadingOverlay.classList.add('hidden');
        }, 1500); // Simulate processing time
    }

    // Display solution moves
    function displaySolutionMoves(moves) {
        solutionMovesContainer.innerHTML = '';
        
        if (moves.length === 0) {
            const placeholder = document.createElement('div');
            placeholder.className = 'placeholder-text';
            placeholder.textContent = 'No moves needed - cube is already solved!';
            solutionMovesContainer.appendChild(placeholder);
            return;
        }
        
        moves.forEach(move => {
            const moveElement = document.createElement('div');
            moveElement.className = 'move';
            moveElement.textContent = move;
            moveElement.title = moveDescriptions[move] || move;
            solutionMovesContainer.appendChild(moveElement);
        });
    }

    // Reset the UI
    function resetUI() {
        // Reset selections
        cubeModelOptions.forEach((opt, index) => {
            if (index === 0) opt.classList.add('selected');
            else opt.classList.remove('selected');
        });
        
        algorithmOptions.forEach((opt, index) => {
            if (index === 3) opt.classList.add('selected');
            else opt.classList.remove('selected');
        });
        
        // Reset sliders
        shuffleMovesSlider.value = 5;
        shuffleValueDisplay.textContent = '5';
        searchDepthSlider.value = 5;
        depthValueDisplay.textContent = '5';
        
        // Reset state
        selectedCubeModel = '1';
        selectedAlgorithm = '4';
        shuffleMoves = 5;
        searchDepth = 5;
        
        // Clear displays
        originalCubeDisplay.innerHTML = '<div class="cube-placeholder">Press Solve to start</div>';
        solvedCubeDisplay.innerHTML = '<div class="cube-placeholder">Solution will appear here</div>';
        solutionMovesContainer.innerHTML = '<div class="placeholder-text">Solution moves will appear here</div>';
        totalMovesDisplay.textContent = '0';
        solveTimeDisplay.textContent = '0ms';
    }

    // Generate a scrambled cube state (for demonstration)
    function generateScrambledCubeState() {
        // Create a scrambled state with some randomized colors
        const faces = ['W', 'G', 'R', 'B', 'O', 'Y'];
        const scrambledCube = [];
        
        // Create a more realistic scrambled cube by starting with a solved cube
        // and applying random changes to some squares
        
        // UP face (with some randomization)
        scrambledCube.push('      W ' + faces[Math.floor(Math.random() * faces.length)] + ' W ');
        scrambledCube.push('      ' + faces[Math.floor(Math.random() * faces.length)] + ' W ' + faces[Math.floor(Math.random() * faces.length)] + ' ');
        scrambledCube.push('      W ' + faces[Math.floor(Math.random() * faces.length)] + ' W ');
        
        // MIDDLE section (LEFT, FRONT, RIGHT, BACK)
        // First row
        let row1 = '    ';
        row1 += 'G ' + faces[Math.floor(Math.random() * faces.length)] + ' G ';
        row1 += 'R ' + faces[Math.floor(Math.random() * faces.length)] + ' R ';
        row1 += 'B ' + faces[Math.floor(Math.random() * faces.length)] + ' B ';
        row1 += 'O ' + faces[Math.floor(Math.random() * faces.length)] + ' O ';
        scrambledCube.push(row1);
        
        // Second row
        let row2 = '    ';
        row2 += faces[Math.floor(Math.random() * faces.length)] + ' G ' + faces[Math.floor(Math.random() * faces.length)] + ' ';
        row2 += faces[Math.floor(Math.random() * faces.length)] + ' R ' + faces[Math.floor(Math.random() * faces.length)] + ' ';
        row2 += faces[Math.floor(Math.random() * faces.length)] + ' B ' + faces[Math.floor(Math.random() * faces.length)] + ' ';
        row2 += faces[Math.floor(Math.random() * faces.length)] + ' O ' + faces[Math.floor(Math.random() * faces.length)] + ' ';
        scrambledCube.push(row2);
        
        // Third row
        let row3 = '    ';
        row3 += 'G ' + faces[Math.floor(Math.random() * faces.length)] + ' G ';
        row3 += 'R ' + faces[Math.floor(Math.random() * faces.length)] + ' R ';
        row3 += 'B ' + faces[Math.floor(Math.random() * faces.length)] + ' B ';
        row3 += 'O ' + faces[Math.floor(Math.random() * faces.length)] + ' O ';
        scrambledCube.push(row3);
        
        // DOWN face (with some randomization)
        scrambledCube.push('      Y ' + faces[Math.floor(Math.random() * faces.length)] + ' Y ');
        scrambledCube.push('      ' + faces[Math.floor(Math.random() * faces.length)] + ' Y ' + faces[Math.floor(Math.random() * faces.length)] + ' ');
        scrambledCube.push('      Y ' + faces[Math.floor(Math.random() * faces.length)] + ' Y ');
        
        return scrambledCube.join('\n');
    }
    
    // Helper function to generate a random row for a face (used for fully random cubes)
    function getRandomFaceRow(faces) {
        return Array(3).fill().map(() => faces[Math.floor(Math.random() * faces.length)]).join(' ');
    }

    // Generate a solved cube state
    function generateSolvedCubeState() {
        return `
      W W W 
      W W W 
      W W W 
    G G G R R R B B B O O O 
    G G G R R R B B B O O O 
    G G G R R R B B B O O O 
      Y Y Y 
      Y Y Y 
      Y Y Y 
    `;
    }

    // Generate random solution moves (for demonstration)
    function generateSolutionMoves() {
        const possibleMoves = ['R', 'L', 'U', 'D', 'F', 'B', 'R2', 'L2', 'U2', 'D2', 'F2', 'B2', 'RP', 'LP', 'UP', 'DP', 'FP', 'BP'];
        const numMoves = parseInt(shuffleMoves);
        const moves = [];
        
        for (let i = 0; i < numMoves; i++) {
            const randomIndex = Math.floor(Math.random() * possibleMoves.length);
            moves.push(possibleMoves[randomIndex]);
        }
        
        return moves;
    }

    // Initialize the UI
    initUI();
});