# kramdb

A simple **in-RAM database system** written in C++.  
The library dynamically creates structured variables (Boolean, Integer, String, Float) inside **tables**, which are organized into **rows** and **cells**.  

---

## 📖 Table of Contents
- [Introduction](#introduction)  
- [Architecture](#architecture)  
- [Classes](#classes)  
  - [tableCellObj](#tablecellobj)  
  - [tableRowObj](#tablerowobj)  
  - [tableObj](#tableobj)  
- [Namespace DB](#namespace-db)  
  - [DB::TABLE](#dbtable)  
  - [DB::NEW](#dbnew)  
  - [DB::REMOVE](#dbremove)  
  - [DB::PRINT](#dbprint)  
  - [DB::TREE](#dbtree)  
  - [DB::createDemoTable](#dbcreatedemotable)  
  - [DB::easterEgg](#dbeasteregg)  
- [Usage Examples](#usage-examples)  
- [License](#license)  

---

## Introduction
`kramdb` is a minimalistic in-memory database engine.  
It does **not persist data to disk**, everything exists only in RAM.  
It is intended for experimentation, debugging, and simple table-based memory storage.

---

## Architecture
The data model is a **hierarchy**:
- **Database** → `DB::TABLE` (vector of tables)
- **Table** → `tableObj` (vector of rows)
- **Row** → `tableRowObj` (vector of cells)
- **Cell** → `tableCellObj` (vectors of typed variables)

Each **cell** may contain multiple variables of different types (`bool`, `int`, `string`, `float`).

---

## Classes

### `tableCellObj`
Represents a single **cell** of the table.  
Each cell can hold multiple variables of supported types.

#### Members
- `std::vector<bool> cellBoolean`  
- `std::vector<int> cellInteger`  
- `std::vector<std::string> cellString`  
- `std::vector<float> cellFloat`

#### Functions
```cpp
void NEW(TYPE type);
```
Creates a new variable inside the cell.  

- `TYPE::Boolean` → adds `false` to `cellBoolean`  
- `TYPE::Integer` → adds `0` to `cellInteger`  
- `TYPE::String` → adds empty string `""` to `cellString`  
- `TYPE::Float` → adds `0.0f` to `cellFloat`  

---

### `tableRowObj`
Represents a **row** of the table.  

#### Members
- `std::vector<tableCellObj> CELL`

#### Functions
```cpp
void NEW();
```
Creates a new **cell** in this row.

---

### `tableObj`
Represents an entire **table**.  

#### Members
- `std::vector<tableRowObj> ROW`

#### Functions
```cpp
void NEW();
```
Creates a new **row** in the table.

---

## Namespace DB

All user-facing functions and global data structures are inside the `DB` namespace.

---

### `DB::TABLE`
```cpp
std::vector<tableObj> TABLE;
```
Global container for all tables in the system.

---

### `DB::NEW`
```cpp
void NEW();
```
Creates a new table and appends it to `DB::TABLE`.

---

### `DB::REMOVE`
```cpp
template <typename T>
void REMOVE(std::vector<T>& onRemove, size_t toRemove);
```
Removes an element at index `toRemove` from any vector (tables, rows, cells, etc.).

---

### `DB::PRINT`
```cpp
std::string PRINT(tableObj& tableTemp);
```
Returns a compact string representation of the table’s contents.  

Example output:
```
DB::TABLE[0].ROW[0].CELL[0].cellInteger[0]=42
DB::TABLE[0].ROW[0].CELL[0].cellString[0]="Hello"
```

---

### `DB::TREE`
```cpp
std::string TREE(tableObj& tableTemp);
```
Pretty-prints the table in a **tree-like structure** for readability.

Example output:
```
TABLE[0]:
 | TABLE[0].ROW[0]:
 |  | TABLE[0].ROW[0].CELL[0]:
 |  |  | TABLE[0].ROW[0].CELL[0].cellInteger[0]: 42
 |  |
 |
```

---

### `DB::createDemoTable`
```cpp
void createDemoTable(tableObj& tableTemp);
```
Creates a pre-filled demo table structure (rows and cells).  
Useful for testing and debugging.

---

### `DB::easterEgg`
```cpp
std::string easterEgg(int egg);
```
Returns a fun string depending on `egg` value.  
(Currently only supports `egg = 1`.)

---

## Usage Examples

### Example 1: Creating a table with variables
```cpp
#include "kramdb.hpp"
#include <iostream>

int main() {
    // Create a new table
    DB::NEW();
    tableObj& t = DB::TABLE[0];

    // Add a row and a cell
    t.NEW();               // row 0
    t.ROW[0].NEW();        // cell 0

    // Add variables into the cell
    t.ROW[0].CELL[0].NEW(TYPE::Integer);
    t.ROW[0].CELL[0].cellInteger[0] = 42;

    t.ROW[0].CELL[0].NEW(TYPE::String);
    t.ROW[0].CELL[0].cellString[0] = "Hello";

    // Print results
    std::cout << DB::PRINT(t);
    std::cout << DB::TREE(t);

    return 0;
}
```

### Example 2: Removing a row
```cpp
// Remove first row from a table
DB::REMOVE(t.ROW, 0);
```

### Example 3: Using demo table
```cpp
tableObj demo;
DB::createDemoTable(demo);
std::cout << DB::TREE(demo);
```

### Example 4: Easter egg
```cpp
std::cout << DB::easterEgg(1);
```

---

## License
Licensed under **Creative Commons CC-BY-SA ©2025**.  
See [LICENCE.txt](LICENCE.txt).

---
