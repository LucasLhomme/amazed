# 🐜 Amazed — Graph Flow & Maze Pathfinding in C

[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build: Make](https://img.shields.io/badge/Build-Makefile-orange.svg)](Makefile)
[![Module: B-CPE-200](https://img.shields.io/badge/Epitech-B--CPE--200-blue.svg)](https://www.epitech.eu/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

> **Amazed is a high-performance network pathfinding and multi-agent flow optimization engine** written in C (inspired by the classic *Lem-in* problem).

---

## 🎯 Overview

A colony of robotic avatars starts in an entry chamber (`##start`) of an underground maze and must reach the exit chamber (`##end`) in the minimum number of simulation cycles.

### The Constraints:
- Multiple robots can traverse the network concurrently.
- **Chamber Capacity:** Except for `##start` and `##end`, each room can hold **at most one robot** at any given turn.
- **Tunnels:** Bidirectional edges connecting rooms; a tunnel can only be traversed by one robot per cycle.
- **Optimal Turns:** The algorithm must find independent paths (vertex-disjoint paths) and balance the distribution of robots to minimize the total completion cycles.

---

## 🧠 Algorithms & Mechanics

### 1. Graph Parsing & Representation
- Parses input from standard input:
  - Number of robots: `N`
  - Rooms: `name X Y` (coordinates and identification)
  - Start / End directives: `##start` and `##end`
  - Links: `room1-room2`
- Builds an adjacency list / matrix representation of the undirected graph.

### 2. Maximum Flow & Vertex-Disjoint Paths
- Deploys **Breadth-First Search (BFS)** and **Edmonds-Karp / Dinic's Maximum Flow** techniques.
- Resolves room capacity restrictions by applying vertex-splitting ($v_{in} 	o v_{out}$ with capacity 1).
- Extracts a family of edge-disjoint and vertex-disjoint paths from `##start` to `##end`.

### 3. Simulation & Dispatcher
- Calculates turn dispatching: distributes $N$ robots across discovered paths based on path lengths.
- Formats movements per cycle in strict Epitech output syntax:
  ```text
  P1-roomA P2-roomB
  P1-roomC P2-roomA P3-roomB
  ```

---

## 🛠️ Build & Execution

```bash
make
./amazed < maps/maze_example.txt
```

---

## 📜 License

Licensed under the **MIT License with attribution** to Lucas Lhomme (Crabe).
