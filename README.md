## 🛠️ Project Structure

```
E1.cpp/
│
├── data/                   <-- Input Files
│   ├── transmission1.txt
│   ├── transmission2.txt
│   ├── mcode1.txt
│   ├── mcode2.txt
│   └── mcode3.txt
│
├── include/                <-- Head files (.h)
│   ├── Scanner.h           (Silvana)
│   ├── Palindrome.h        (Leonel)
│   └── Similarity.h        (Angel)
│
├── src/                    <-- Implementation (.cpp) & Main
│   ├── Scanner.cpp
│   ├── Palindrome.cpp
│   ├── Similarity.cpp
│   └── main.cpp            (Entry Point)
│
├── .gitignore
└── README.md
```

# Malicious Stream Analyzer (C++)

This project is a text file analysis tool designed to detect malicious code patterns, find symmetric sequences (palindromes), and compare the similarity between different data streams.

## 👥 Team Members
* **Silvana Farías A01178494** - Pattern Search Algorithms

* **Leonel Bailón A01286177** - Symmetry and Palindrome Analysis

* **Ángel Sánchez A00837790** - Stream Comparison

## 🚀 Features
The program processes 5 input files (`transmission1.txt`, `transmission2.txt`, `mcode1.txt`, `mcode2.txt`, `mcode3.txt`) and performs the following tasks:

1. **Malicious Code Detection:** Checks for malicious code sequences in the transmissions, indicating the exact starting position.

2. **Palindrome Search:** Identifies the longest mirrored sequence within each transmission to detect potential code spoofing techniques.

3. **Similarity Analysis:** Finds the longest common substring between the two main transmissions.

## 🔍 Notes

The main.cpp must read the data/casoX files with the full path, so you need to change the path once you clone this repo at your saved directory, all changes in getPath()
```
"C:\\Your\\Path\\Goes\\Here\\data\\casoX\\"
```

### 1. Clone this repo
Open your terminal and execute this command:
```
git clone https://github.com/herrdelta83/Reto_TransmisionMaliciosa_Equipo3.git
```

### 2. Create your branch
```
git checkout -b feature/name-of-your-task
```

### 3. Compilation
```
g++ -std=c++11 src/main.cpp src/Palindrome.cpp src/Scanner.cpp src/Similarity.cpp -Iinclude -o main
```
