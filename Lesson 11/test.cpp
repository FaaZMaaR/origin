#define CATCH_CONFIG_MAIN

#include"catch2/catch_all.hpp"
#include"extended_array.h"

TEST_CASE("Mean value") {
	SECTION("int numbers") {
		ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
		REQUIRE(v1.mean() == 1.125);
	}
	SECTION("empty array") {
		ExtArray<int> v2{};
		REQUIRE(v2.mean() == 0);
	}
}

TEST_CASE("Median value") {
	SECTION("real numbers") {
		ExtArray<double> v1{ 4.5, 0.7, 10.8, -3.5 };
		REQUIRE(v1.median() == 2.6);
	}
	SECTION("empty array") {
		ExtArray<int> v2{};
		REQUIRE(v2.median() == 0);
	}
}

TEST_CASE("Mode value") {
	SECTION("int numbers") {
		ExtArray<int> v1{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
		REQUIRE(v1.mode().first == 5);
	}
	SECTION("empty array") {
		ExtArray<int> v2{};
		REQUIRE(v2.mode().first == 0);
	}
}

TEST_CASE("Mean with args") {
	SECTION("int numbers") {
		ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
		REQUIRE(v1.mean(2, 6) == 1.25);
	}
	SECTION("invalid_argument exception") {
		try {
			ExtArray<int> v2{ 4, 2, 7, 3, -5, 0, -3, 1 };
			v2.mean(7, 3);
			throw std::runtime_error("Something went wrong...");
		}
		catch (const std::exception& err) {
			REQUIRE(typeid(err).name() == typeid(std::invalid_argument).name());
		}
	}
}

TEST_CASE("CheckSum value") {
	SECTION("int values") {
		ExtArray<int> v1{ 1,0,0,1,1,1,0,1,0,0 };
		REQUIRE(v1.checkSum() == 5);
	}
	SECTION("bool values") {
		ExtArray<bool> v2{ false,false,true,false,true,false };
		REQUIRE(v2.checkSum() == 2);
	}
	SECTION("bad_typeid exception") {
		try {
			ExtArray<double> v3{ 1,0,1,0,0 };
			v3.checkSum();
			throw std::runtime_error("Something went wrong...");
		}
		catch (const std::exception& err) {
			REQUIRE(typeid(err).name() == typeid(std::bad_typeid).name());
		}
	}
	SECTION("logic_error exception") {
		try {
			ExtArray<int> v4{ 1,0,1,2,0 };
			v4.checkSum();
			throw std::runtime_error("Something went wrong...");
		}
		catch (const std::exception& err) {
			REQUIRE(typeid(err).name() == typeid(std::logic_error).name());
		}
	}
}