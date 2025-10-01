#pragma once
#include <iostream>
#include "kramdb.hpp"

int main() {
	DB::NEW();
	DB::TABLE[0].NEW();
	DB::TABLE[0].ROW[0].NEW();
	DB::TABLE[0].ROW[0].CELL[0].NEW(TYPE::Integer);
	DB::TABLE[0].ROW[0].CELL[0].cellInteger[0] = 23;
	DB::TABLE[0].ROW[0].CELL[0].NEW(TYPE::Integer);
	DB::TABLE[0].ROW[0].CELL[0].cellInteger[1] = 67;
	DB::TABLE[0].ROW[0].CELL[0].NEW(TYPE::Boolean);

	DB::TABLE[0].NEW();
	DB::TABLE[0].ROW[1].NEW();
	DB::TABLE[0].ROW[1].NEW();
	DB::TABLE[0].ROW[1].CELL[0].NEW(TYPE::Float);
	DB::TABLE[0].ROW[1].CELL[1].NEW(TYPE::String);
	DB::TABLE[0].ROW[1].CELL[1].NEW(TYPE::String);
	DB::TABLE[0].ROW[1].CELL[1].NEW(TYPE::Boolean);
	DB::TABLE[0].ROW[1].CELL[0].cellFloat[0] = 3.141592f;
	DB::TABLE[0].ROW[1].CELL[1].cellString[1] = "Hello world from database!";
	DB::TABLE[0].ROW[1].CELL[1].cellBoolean[0] = true;

	std::cout << DB::TABLE.size() << std::endl;
	std::cout << DB::TABLE[0].ROW.size() << std::endl;
	std::cout << DB::TABLE[0].ROW[0].CELL.size() << std::endl;
	std::cout << DB::TABLE[0].ROW[0].CELL[0].cellInteger.size() << std::endl;

	std::cout << DB::PRINT(DB::TABLE[0]) << std::endl;
	DB::REMOVE(DB::TABLE[0].ROW[1].CELL[1].cellString, 1);
	std::cout << DB::TREE(DB::TABLE[0]) << std::endl;
	DB::easterEgg(1);
	return 0;
}
