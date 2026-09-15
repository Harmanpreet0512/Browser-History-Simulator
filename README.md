# 🌐 Browser History Simulator

A simple Browser History Simulator developed in C++ using the STL `deque` container.

The project simulates basic browser navigation features such as visiting new URLs, going back, going forward, and viewing the current and complete browsing history.

---

## 📌 Features

- 🌐 Visit a new URL
- ⬅️ Go back by a specified number of steps
- ➡️ Go forward by a specified number of steps
- 🏠 Display the current page
- 📜 Display the complete browsing history
- ❌ Exit the application
- 🔄 Automatically removes forward history when a new URL is visited

---

## 🛠️ Technologies Used

- Language: C++
- STL Container: deque
- Header Files:
  - <iostream>
  - <deque>
- Concepts:
  - Object-Oriented Programming
  - Classes and Objects
  - STL Containers
  - Deque
  - Index-based navigation
  - Conditional Statements
  - Loops
  - Switch-Case

---

## 🧠 How It Works

The program uses a deque<string> to store all visited URLs.

cpp
deque<string> history;
