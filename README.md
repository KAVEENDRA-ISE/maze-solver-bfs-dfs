# Maze Solver using BFS and DFS

## 📌 Overview
This project implements a **Maze Solver** in **C programming language** using two fundamental graph traversal algorithms:
- **Depth-First Search (DFS)**
- **Breadth-First Search (BFS)**

The solver navigates through a grid-based maze, comparing the efficiency of DFS and BFS in terms of:
- Path optimality
- Time complexity
- Memory usage

---

## 🎯 Objectives
- Implement and visualize DFS and BFS algorithms for maze traversal.
- Compare their performance in finding valid paths.
- Highlight trade-offs between **time vs. memory** and **shortest path vs. quick exploration**.

---

## 🛠 Tech Stack
- **Language:** C  
- **Concepts:** Graph Traversal, DFS, BFS, Pathfinding  
- **Tools:** GCC Compiler / MinGW / Turbo C (for academics)  

---

## 🏗 Maze Representation
- `0` → Open path (walkable)  
- `1` → Wall (blocked)  

Example maze:
```c
int maze[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};
