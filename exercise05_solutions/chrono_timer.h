#pragma once

#include <string>
#include <chrono>
#include <iostream>

class ChronoTimer {
	const std::string name;
	const std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
	ChronoTimer(const std::string& name = "Unnamed")
		: name(name),
		start(std::chrono::high_resolution_clock::now()) {
	}
	~ChronoTimer() {
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
		std::cout << "Timer - " << name << ": " << elapsed.count() << " ms " << std::endl;
	}
};
