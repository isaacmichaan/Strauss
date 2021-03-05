#pragma once
#include <vector>
#include <memory>
#include <string>

class CalculatorItem;

class Calculator
{
public:
	Calculator() = default;
	~Calculator() = default;
	void run();
	std::shared_ptr<CalculatorItem> operator[](int index) const;
private:
	std::vector<std::shared_ptr<CalculatorItem>> m_calculatorItems ;
	static const std::vector<std::string> m_vector_command;
	static std::string getUserCommand();
	static void exit();
	static void help(); 
	void calculateArea();
	void calculatePerimeter();
	void drawItem();
	void findAllSameShapes() const;
	void deleteItem();
	void findMin() const;
	void findMax() const;
	void same(int index) const;
	void createShape();
	void printItemList() const;
	const int insert(std::string str, int line) const;
	void comm(std::string);
	int m_max_shapes;
	void read();
	void resize();
};



